#include "showtext.h"
#include <QPainter>
#include <QTimer>

ShowText::ShowText(QWidget *parent) :
    QWidget(parent)
{
    setFont(QFont("wenquanyi", 20));

    m_text =QObject::trUtf8("中国嵌入式技术的黄埔军校－－－－中国亚嵌" "      ""中国嵌入式技术的黄埔军校－－－－中国亚嵌" "      ""中国嵌入式技术的黄埔军校－－－－中国亚嵌" "      ");
    update();

    QTimer* timer = new QTimer;
    timer->start(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(onChange()));
}

void ShowText::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen thickPen(Qt::red, 5);
    p.setPen(thickPen);
    p.drawText(0, 0, width(), height(), Qt::AlignLeft | Qt::AlignVCenter, m_text);
}

void ShowText::onChange()
{
    QChar ch = m_text.at(0);
    m_text.remove(0, 1);
    m_text.append(ch);
    update();
}

