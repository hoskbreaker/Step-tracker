#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QGraphicsEllipseItem>

namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();
    void ClearData();

private slots:
    void on_INICIO_clicked();
    void read();
    void DataValues(QString &Data, int n, int &i, int j);
    QString dirx(QString x, qreal &mx);
    QString diry(QString y, qreal &my);
    void diryNEW(QString y, qreal &my);
    void dirxNEW(QString x, qreal &mx);
    void dirz(QString z, qreal &mz);
    void MoveBall(qreal w, qreal h);
    void LimitBall(qreal &h, qreal &w);
    void on_PAUSE_clicked();
    void on_GAME_clicked();

private:
    Ui::Interface *ui;
    QSerialPort serial;
    QString serialBuffer;
    QString Data[4];
    QGraphicsScene *scene, *space;
    QGraphicsEllipseItem *ball;
    qreal xAxis = 0;
    qreal yAxis = 0;
    bool enable=false,game=false;
    int step =0;
    int count=1;
    int stop[3]={0,0,0};
    int lux;
};

#endif // INTERFACE_H
