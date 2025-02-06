#include "streamer.h"

Streamer::Streamer(QObject *parent)
    : QObject{parent}
{
    timer=new QTimer(this);
    timer->setInterval(33);
    timer->start();
    connect(timer,&QTimer::timeout,this,&Streamer::reload);
};

