#include "mylabel.h"
#include <QTimer>

MyLabel::MyLabel(QWidget *parent) :

    QLabel(parent)
{
    i = 0;
    resize(800,480);
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotsChangeFont()));

}

void MyLabel::slotsChangeFont()
{
    QString str = "<center><font color = #0000ff><h2><i>Sync files finished <br>Starting to play after <font color = #ff0000 ><h1>3</h1></font> seconds</i>""</font></h2></center>";
    if(i == 0)
    {
        this->setText(str);
        i ++;
    }
    else if(i == 1)
    {
        str = "<center><font color = #0000ff><h2><i>Sync files finished <br>Starting to play after <font color = #ff0000 ><h1>2</h1></font> seconds</i>""</font></h2></center>";
        this->setText(str);
        i++;
    }
    else if(i == 2)
    {
        str = "<center><font color = #0000ff><h2><i>Sync files finished <br>Starting to play after <font color = #ff0000 ><h1>1</h1></font> second</i>""</font></h2></center>";
        this->setText(str);
    }
}
