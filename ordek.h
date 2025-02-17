#ifndef ORDEK_H
#define ORDEK_H

#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QRandomGenerator>

class ordek : public QLabel {
    Q_OBJECT
public:
    ordek(QWidget *parent = nullptr, bool isMainDuck = false);
    void createNewDuck();
    void actionDuck();

signals:
    void deadDuck();
    void runDuck();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QWidget *screenWidget;
    QTimer *duckTimer;
    bool isMainDuck;
};

#endif // ORDEK_H
