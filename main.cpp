#include <QApplication>
#include <QtWidgets>

#include "roundprogress.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.setFixedHeight(200);
    w.setFixedWidth(200);

    RoundProgress* rpr = new RoundProgress;

    QSlider* sld = new QSlider(Qt::Horizontal);
    sld->setMinimum(0);
    sld->setMaximum(100);

    QObject::connect(sld, SIGNAL(valueChanged(int)), rpr,SLOT(slotSetCurProgress(int))  );

    QVBoxLayout* vbx = new QVBoxLayout;

    vbx->addWidget(rpr);
    vbx->addWidget(sld);

    w.setLayout(vbx);

    w.show();
    return a.exec();
}
