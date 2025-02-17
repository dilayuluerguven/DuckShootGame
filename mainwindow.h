#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ordek.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateCount();
    void deadDuck();
    void runDuck();

private:
    Ui::MainWindow *ui;
    int deadDucks = 0;
    int runDucks = 0;
};

#endif // MAINWINDOW_H
