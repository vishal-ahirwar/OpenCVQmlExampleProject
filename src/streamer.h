#ifndef STREAMER_H
#define STREAMER_H

#include <QObject>
#include<QTimer>

class Streamer : public QObject
{
    Q_OBJECT
public:
    explicit Streamer(QObject *parent = nullptr);

signals:
    void reload();
private:
    QTimer*timer;
};

#endif // STREAMER_H
