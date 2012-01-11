#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QLabel>
class ShowVideo;
class ShowPic;
class ShowLogo;
class ShowClock;
class ShowText;

class Frame : public QFrame
{
    Q_OBJECT
public:
    explicit Frame(QWidget *parent = 0);

    static QString strRoot;

    QLabel* bkLabel;
    ShowVideo* sv;
    ShowPic* sp;
    ShowLogo* sl;
    ShowClock* sc;
    ShowText* st;

    void init();
    void stop();

signals:

public slots:

};

#endif // FRAME_H
