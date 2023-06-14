#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSerialPort>
#include<QSerialPortInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked();

    void on_btnClosePort_clicked();

    void dataRecived();
    void on_btnSendMsg_clicked();

private:
    Ui::Widget *ui;
    QSerialPort serial;
};
#endif // WIDGET_H
