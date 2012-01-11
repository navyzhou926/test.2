#ifndef SHOWCLOCK_H
#define SHOWCLOCK_H

#include <QLCDNumber>

class ShowClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit ShowClock(QWidget *parent = 0);

signals:

public slots:
    void showTime();
};

#endif // SHOWCLOCK_H
