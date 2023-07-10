#include <QWidget>
#include <QPainter>


class RoundProgress : public QWidget
{
    Q_OBJECT

public:
    RoundProgress(QWidget *parent = nullptr);
    ~RoundProgress(){};
public slots:
    void slotSetCurProgress(int inpcur);
private:
    int curProgress;
    int overall;
protected:
    void paintEvent(QPaintEvent *event) override;
};
