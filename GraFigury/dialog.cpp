#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonPolacz_clicked()
{
    emit connectToServer(ui->lineEditIP->text(),ui->lineEditPort->text().toInt());
}


void Dialog::ustawWiadomosc(QString wiadomosc)
{
    ui->lineEdit->setText(wiadomosc);
}
