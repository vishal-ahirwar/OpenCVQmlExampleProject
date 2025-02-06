#ifndef CVIMAGEPROVIDER_H
#define CVIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QImage>
#include<QObject>

class CvImageProvider : public QQuickImageProvider {
    Q_OBJECT  // This macro is essential for signals and slots to work

public:
    CvImageProvider(QObject*parent=nullptr);

    // Override requestImage to return the current image
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

private slots:
    void updateFrame();  // Slot to update the camera frame

signals:
    void imageUpdated(QImage img);  // Signal to notify that the image has been updated

private:
    cv::VideoCapture capture;  // OpenCV camera capture object
    QImage image;              // Current camera frame as QImage
    QTimer *timer;             // Timer to capture frames at regular intervals
};


#endif // CVIMAGEPROVIDER_H
