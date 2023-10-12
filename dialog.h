#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
//    QString *arduino = new QSerialPort();
    ~Dialog();

private slots:
    void on_led_button_clicked();
    void update_led(QString& value);


private:
    Ui::Dialog *ui;

    QSerialPort *arduino;
    QString arduino_port_name = "";
    const quint16 arduino_vendor_id = 9025;
    const quint16 arduino_product_id = 67;
    bool arduino_available = false;
    bool button_clicked = false;



};
#endif // DIALOG_H
