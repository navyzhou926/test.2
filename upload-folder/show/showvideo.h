#ifndef SHOWVIDEO_H
#define SHOWVIDEO_H

#include <QWidget>
#include <QProcess>

class ShowVideo : public QWidget
{
    Q_OBJECT
public:
    explicit ShowVideo(QWidget *parent = 0);
    virtual ~ShowVideo();

public:
    QProcess* mplayerProcess;
    QWidget* render;

signals:

public slots:

};

#endif // SHOWVIDEO_H
