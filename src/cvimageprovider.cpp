#include "cvimageprovider.h"
#include <QTimer>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <QDebug>

CvImageProvider::CvImageProvider(QObject*parent) : QQuickImageProvider(QQuickImageProvider::Image), capture(0) {
    image=QImage(512,512,QImage::Format_RGB888);
    image.fill(QColor("black"));
    // Open the default camera (index 0)
    if (!capture.isOpened()) {
        qWarning() << "Error: Camera not opened!";
        return;
    }
    cv::Mat frame;
    capture>>frame;
    image= QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888).rgbSwapped();
    // Create a timer to update frames regularly
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CvImageProvider::updateFrame);
    timer->start(33);  // ~30 FPS (every 33ms)
}

QImage CvImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize) {
    // Return the current image to QML
    Q_UNUSED(id);
    if (size) {
        *size = image.size();
    }
    if(requestedSize.width() > 0 && requestedSize.height() > 0) {
        image = image.scaled(requestedSize.width(), requestedSize.height(), Qt::KeepAspectRatio);
    }
    return image;
}

void CvImageProvider::updateFrame() {
    cv::Mat frame;
    capture >> frame;  // Capture a new frame from the camera
    if (frame.empty()) {
        qWarning() << "Captured frame is empty!";
        return;
    }

    // Convert the OpenCV frame to QImage
    image = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888).rgbSwapped();
    if(image.isNull())
    {
        qWarning()<<"QImage is null!";
        return;
    }
    // Emit the signal that the image has been updated
    emit imageUpdated(image);
}

