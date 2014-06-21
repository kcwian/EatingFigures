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

/*!
 * Służy do połączenia klienta z serwerem.
 */

void Dialog::on_pushButtonPolacz_clicked()
{
    emit connectToServer(ui->lineEditIP->text(),ui->lineEditPort->text().toInt());
}

/*!
 * \brief
 *
 * Ustawia wiadomość w oknie dialogowym.
 */
void Dialog::ustawWiadomosc(QString wiadomosc)
{
    ui->lineEdit->setText(wiadomosc);
}
