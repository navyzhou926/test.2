#ifndef SHOWTEXT_H
#define SHOWTEXT_H

#include <QWidget>

class ShowText : public QWidget
{
    Q_OBJECT
public:
    explicit ShowText(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

    QString m_text;

signals:

public slots:
    void onChange();

};

#endif // SHOWTEXT_H
