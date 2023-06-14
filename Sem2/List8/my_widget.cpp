#include "my_widget.h"

#include <QPainter>
#include <QLinearGradient>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
    parent->setStyleSheet("background-color: rgb(174, 173, 172);");
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // creating transparent colour
    QColor transparentRed(255, 0, 0);
    transparentRed.setAlpha(0);

    // creating magenta radial gradient
    QRadialGradient radialGrad(QPoint(-10,70), 10);
    radialGrad.setColorAt(0, QColor(Qt::GlobalColor::magenta));
    radialGrad.setColorAt(1, transparentRed);

    // creating circle
    QRect circle(-20,60,20,20);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);

    // circles
    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.drawEllipse(circle);
            painter.fillRect(circle, radialGrad);
        }
        painter.rotate(360.0 / num_disks);
    }

    // making cross
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::black)));
    QRectF rectangle1(3.0, 0.5, 1.0, 6.0);
    QRectF rectangle2(0.5, 3.0, 6.0, 1.0);
    painter.drawRect(rectangle1);
    painter.drawRect(rectangle2);
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
    {
        timer.stop();
    }
    else
    {
        timer.start(timer_interval);
    }

}
