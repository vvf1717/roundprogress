#include <QVBoxLayout>
#include <QDebug>
#include "roundprogress.h"

RoundProgress::RoundProgress(QWidget *parent)
    : QWidget(parent), curProgress(0), overall(0)
{
    auto *L = new QVBoxLayout();
    this->setLayout(L);
}


void RoundProgress::slotSetCurProgress(int inpcur)
{
    curProgress = inpcur;
    update();
}

void RoundProgress::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.setPen(QPen(Qt::blue, 4));
    painter.drawPie (QRect ((width()/20), (height()/20), width()-(width()/10), height()-(height()/10)), 90 * 16, 16 * curProgress* 3.6);

    painter.setPen(QPen(Qt::red, 6));
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect().adjusted(width()/2-width()/5, 0, -(width()/10), 0), Qt::AlignVCenter | Qt::AlignLeft,
                     QString("%1").arg(curProgress) + "%");

}

