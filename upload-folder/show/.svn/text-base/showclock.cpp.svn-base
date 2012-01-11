#include "showclock.h"
#include <QTimer>
#include <QTime>
#include <QPalette>
ShowClock::ShowClock(QWidget *parent) :
    QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    setNumDigits (8);

    setFrameShape(QFrame::NoFrame);		//NoFrame
    setSegmentStyle(QLCDNumber::Flat);	//FillBlack

    QPalette palette = this->palette();
    palette.setBrush(QPalette::WindowText, QBrush(QColor(255, 128, 0, 255)));			//时钟文字黄色
    setPalette(palette);

    showTime();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

}

void ShowClock::showTime()
{
        QTime time = QTime::currentTime();
        QString text = time.toString("hh:mm:ss");
//	if((time.second()%2) == 0)
//		text[2] = ' ';
//	else
//		text[5] = ' ';
        display(text);
}
