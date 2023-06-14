#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_btnRefresh_clicked();
    ui->baudBox->addItem("57600");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnRefresh_clicked()
{
    ui->portBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->portBox->addItem(info.portName());
    }
}


void Widget::on_btnOpenPort_clicked()
{
    serial.setPortName(ui->portBox->currentText());
    serial.setBaudRate(ui->baudBox->currentText().toInt());
    serial.open(QIODevice::ReadWrite);
    if(serial.isOpen())
        connect(&serial,&QSerialPort::readyRead,this,&Widget::dataRecived);
}


void Widget::on_btnClosePort_clicked()
{
    serial.close();
}

void Widget::dataRecived()
{
    QByteArray data = serial.readAll();
    ui->editRecData->append(data);
}


void Widget::on_btnSendMsg_clicked()
{
    serial.write(ui->editSendData->toPlainText().toUtf8());
}

