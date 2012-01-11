#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    int i;

signals:

public slots:
    void slotsChangeFont();

};

#endif // MYLABEL_H
