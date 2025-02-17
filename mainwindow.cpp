#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->anaEkran->setStyleSheet("border-image: url(:/img/image/arkaPlan.png);");

    QPixmap silahPixmap(":/img/image/silah.png");
    QPixmap scaledPixmap = silahPixmap.scaled(32, 32, Qt::KeepAspectRatio);
    QCursor silahCursor(scaledPixmap);
    ui->anaEkran->setCursor(silahCursor);

    ordek *ord = new ordek(ui->anaEkran, true);
    ord->setFixedSize(0,0);
    connect(ord, &ordek::deadDuck, this, &MainWindow::deadDuck);
    connect(ord, &ordek::runDuck, this, &MainWindow::runDuck);
    ord->show();

   updateCount();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deadDuck()
{
    deadDucks++;
    updateCount();
}

void MainWindow::runDuck()
{
    runDucks++;
    updateCount();
}

void MainWindow::updateCount()
{
    ui->bilgi->setText(QString("Vurulan ördek sayısı: %1\n\nKaçan ördek sayısı: %2").arg(deadDucks).arg(runDucks));
    ui->bilgi->setStyleSheet("color:red; font-size:18px");
}
