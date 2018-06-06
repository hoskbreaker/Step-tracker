#include "interface.h"
#include "ui_interface.h"


Interface::Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    scene = new QGraphicsScene();
    QRectF rec = QRect(xAxis,yAxis,10,10);

    ball = new QGraphicsEllipseItem();
    ball->setRect(rec);
    //scene->setSceneRect(rec);
    scene->addItem(ball);

    QPen pen = QPen(Qt::black);
    QBrush brush = QBrush(Qt::red);

    ball->setPen(pen);
    ball->setBrush(brush);
}

Interface::~Interface()
{
    delete ui;
    serial.close();
}

void Interface::on_INICIO_clicked()
{
    QString puerto;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            puerto=info.portName();
            serial.setPort(info);
            serial.open(QSerialPort::ReadOnly);
    }
    ui->PUERTO->setText(puerto);

    QObject::connect(&serial,SIGNAL(readyRead()),this, SLOT(read()));

}
QString Interface::diry(QString y, qreal &my)
{
    QString value;
    if(y.toInt()>=5){

        if(y.toInt()>=10){
            value="FAST BACK";
            my = -1;
        }else{
            value="BACK";
            my = -0.5;
        }
    }else if(y.toInt()<=-5){

        if(y.toInt()<=-10){
            value="FAST FORWARD";
            my = 1;
        }else{
            value="FORWARD";
            my = 0.5;
        }
    }else{
        value=" ";
        my = 0;
    }
    return value;
}
QString Interface::dirx(QString x, qreal &mx)
{
    QString value;
    if(x.toInt()>=5){
        if(x.toInt()>=10){
            value="FAST LEFT";
            mx = 1;
        }else{
            value="LEFT";
            mx = 0.5;
        }
    }else if(x.toInt()<=-5){
       if(x.toInt()<=-1){
           value="FAST RIGHT";
           mx = -1;
        }else{
            value="RIGHT";
            mx = -0.5;
       }
    }else{
        value=" ";
        mx = 0;
    }
    return value;
}


void Interface::diryNEW(QString y, qreal &my)
{
    if(stop[1]==0){
        if(y.toInt()>=20){
            stop[1] = 1;
        }else if(y.toInt()<=-20){
            stop[1] = 2;
        }else{
            my=0;
        }
    }else if(stop[1] == 1){
        if( y.toInt()<=-10){
            stop[1] = 0;
            step++;
            my=10;
        }else{
            my=0;
        }
    }else if(stop[1] == 2){
        if(y.toInt()>=10){
            stop[1] = 0;
            step++;
            my=-10;
        }else{
            my=0;
        }
    }
}
void Interface::dirxNEW(QString x, qreal &mx)
{
    if(stop[0]==0){
        if(x.toInt()<= 5){
            //show display
            ui->graphicsView->show();
            if(lux<50){
                ui->LED->setEnabled(true);
                ui->LED->setText("LIGHT ON");
            }
            stop[0]=1;
            mx=1;
        }
    }else if(stop[0]==1){
        if(x.toInt()>= 15){
            //show display
            ui->graphicsView->hide();
            stop[0]=0;
            mx=0;
            ui->LED->setDisabled(true);
            ui->LED->setText("LIGHT OFF");
        }
    }
}

void Interface::dirz(QString z, qreal &mz)
{
    if(stop[2]==0){
        if(z.toInt()>=20){
            stop[2] = 1;
        }
    }else if(stop[2] == 1){
        if( z.toInt()<=-20){
            step++;
            stop[2] = 0;
        }
    }
    if(step == count){
        ui->STEPS->setText(QString::number(step));
        count++;
        mz=10;
    }else{
        mz=0;
    }
}
void Interface::ClearData()
{
    int i;
    for(i=0;i<4;i++){
        Data[i].clear();
    }
}
void Interface::DataValues(QString &Data, int n, int &i, int j)
{
    if(n==3){
        while(serialBuffer[i]!='\r'&& i<serialBuffer.length()){
            Data[j]=serialBuffer[i];
            i++;
            j++;
        }
    }else{
        while(serialBuffer[i]!=';' && i <serialBuffer.length()){
            Data[j]=serialBuffer[i];
            i++;
            j++;
        }
        if(i>serialBuffer.length()){
            i=4*(1+n);
        }
    }
    i++;
    if(serialBuffer[i]=='\n'){
        serialBuffer.clear();
    }
}
void Interface::MoveBall(qreal w, qreal h)
{

    //make ball focusable
    ball->setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    xAxis += w;
    yAxis += h;
    LimitBall(xAxis,yAxis);
    ball->setPos(xAxis, yAxis);
    ui->graphicsView->setScene(scene);
}

void Interface::LimitBall(qreal &w, qreal &h)
{
    //limits
    int offset = 20;
    int width = (ui->graphicsView->geometry().width())/2 ;
    int height = (ui->graphicsView->geometry().height())/2 ;
    //"don't across the limit"'s condition (Width Version)
    if(w>width-offset*2){
        w =width-offset*2;
    }else if (w<=-width-offset){
        w = -width-offset;
    }
    //"don't across the limit"'s condition (Height Version)
    if(h>height-offset*2){
        h =height-offset*2;
    }else if (h<=-height-offset){
        h = -height-offset;
    }
}

void Interface::read()
{
    int i=0,j=0,n;
    QByteArray serialData = serial.readLine();
    QString dx,dy,dz, direction;
    qreal mx,my,mz;

    serialBuffer += QString::fromStdString(serialData.toStdString());

    if(enable){
        ui->DIRECTION->setText("PAUSED");
    }else{
        //clear function
        ClearData();
        for(n=0;n<4;n++){
            DataValues(Data[n],n,i,j);
        }
        //value axis
        ui->EJE_X->setText(Data[0]);
        ui->EJE_Y->setText(Data[1]);
        ui->EJE_Z->setText(Data[2]);

        //Percentage value lux
        lux = (Data[3].toInt()/255)*100;
        ui->LUX_BAR->setValue(lux);

        //Direction Axis

        if(game){
            dx=dirx(Data[0],mx);
            dy =diry(Data[1],my);
            direction =dx +" "+ dy;
            ui->DIRECTION->setText(direction);
            //Graphics
            MoveBall(mx,my);
        }else{
            dirxNEW(Data[0],mx);
            diryNEW(Data[1],my);
            dirz(Data[2],mz);
            //Graphics
            MoveBall(mz,my);
        }
    }
}

void Interface::on_PAUSE_clicked()
{
    if(enable){
        enable = false;
    }else{
        enable = true;
    }

}

void Interface::on_GAME_clicked()
{
    if(game){
        game = false;
    }else{
        game = true;
    }
}
