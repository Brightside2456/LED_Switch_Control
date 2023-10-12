#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog), arduino(new QSerialPort())
{
    ui->setupUi(this);

//    QSerialPort *arduino = new QSerialPort();

//    qDebug()<<"Its working... You can Continue";

    //This line is to check the aveilable ports and their port details (name, description, vendor and product ID etc)
//    qDebug()<<"Number of Ports: "<< QSerialPortInfo::availablePorts().length();
//        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
//    {

//        QString portname = serialPortInfo.portName();
//        QString description = serialPortInfo.description();
//        QString manufacturer = serialPortInfo.manufacturer();

//        qDebug()<<"Port Name: "<<portname;
//        qDebug()<<"Description: "<< description;
//        qDebug()<<"Manufacturer: "<< manufacturer;
//        qDebug()<<"Vendor ID: "<< serialPortInfo.vendorIdentifier();
//        qDebug()<<"Product ID: "<< serialPortInfo.productIdentifier();
//        qDebug()<<" ";
//    }
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier())
        {
            if(serialPortInfo.productIdentifier() == arduino_product_id)
            {
                if(serialPortInfo.vendorIdentifier() == arduino_vendor_id)
                {
                    qDebug()<<"Arduino is Available";
                    arduino_available = true;
                    arduino_port_name = serialPortInfo.portName();
                }
            }
        }
    }

    //check if arduino is available
    if(arduino_available)
    {
        //Configure Port
        //Setting port name to arduino port name (as attribute for the QSerialPort class instance (arduino in this case))
        arduino->setPortName(arduino_port_name);
        //Open Port for write-only mode
        arduino->open(QSerialPort::WriteOnly);
        //set baud rate (This should be equal to that set in arduino)
        arduino->setBaudRate(QSerialPort::Baud9600);
        //Set databits
        arduino->setDataBits(QSerialPort::Data8);
        //Set parity to NoParity
        arduino->setParity(QSerialPort::NoParity);
        //Set stop Bits
        arduino->setStopBits(QSerialPort::OneStop);
        //Set flow control to noe flow control
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }
    else{
        QMessageBox::warning(this, "Port Error", "Could not find arduino");
    }
}

Dialog::~Dialog()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}


void Dialog::on_led_button_clicked()
{

    if(ui->led_label->text()=="OFF")
    {
        QString value = "1";
        //    ui->led_label->setText(QString("%1").arg(value));
        ui->led_label->setText("<span style=\" font-size:14pt; font-weight:700; color:#1a5fb4;\">ON</span>");

        Dialog::update_led(value);
        qDebug()<<value;
    }
    else
    {
        QString value = "0";
        //    ui->led_label->setText(QString("%1").arg(value));
        ui->led_label->setText("OFF");

        Dialog::update_led(value);
        qDebug()<<value;
    }

}


void Dialog::update_led(QString& value)
{
    if(arduino->isWritable())
    {

        arduino->write(value.toStdString().c_str(), value.size());
    }
    else
    {
        qDebug()<<"Could Not Write to Serial";
    }
}

