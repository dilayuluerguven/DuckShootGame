#include "ordek.h"
#include <QDebug>
#include "mainwindow.h"

ordek::ordek(QWidget *parent, bool isMainDuck) : QLabel(parent), screenWidget(parent), isMainDuck(isMainDuck)
{
    if (isMainDuck)
    {
        duckTimer = new QTimer(this);
        connect(duckTimer, &QTimer::timeout, this, &ordek::createNewDuck);
        duckTimer->start(600);
    }

    setPixmap(QPixmap(":/img/image/ducky.png"));
    setScaledContents(true);
    setFixedSize(45, 45);
}

void ordek::createNewDuck()
{
    ordek *newDuck = new ordek(screenWidget, false);
    int xPos = QRandomGenerator::global()->bounded(screenWidget->width() - 50);
    newDuck->setGeometry(QRect(xPos, 0, 50, 50));
    newDuck->show();

    connect(newDuck, &ordek::deadDuck, this, &ordek::deadDuck);
    connect(newDuck, &ordek::runDuck, this, &ordek::runDuck);

    QTimer *duckMoveTimer = new QTimer(newDuck);
    connect(duckMoveTimer, &QTimer::timeout, newDuck, &ordek::actionDuck);

    connect(duckMoveTimer, &QTimer::timeout, [newDuck, this]()
    {
        if (newDuck->geometry().top() >= screenWidget->height())
        {
            emit runDuck();
            QTimer::singleShot(100, newDuck, [newDuck]() { delete newDuck; });
        }
    });


    duckMoveTimer->start(100);
}


void ordek::actionDuck()
{
    QRect geometry = this->geometry();
    geometry.moveTop(geometry.top() + 10);
    this->setGeometry(geometry);
}

void ordek::mousePressEvent(QMouseEvent *)
{
    setPixmap(QPixmap(":/img/image/bang.png"));
    QTimer::singleShot(100, this, [this]() { delete this; });
    emit deadDuck();
}
