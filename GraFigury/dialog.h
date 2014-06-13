#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

/*!
 * \brief Okno Dialogowe
 *
 * Umożliwia połączenie z serwerem
 */

class Dialog : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void ustawWiadomosc(QString);

private slots:

    void on_pushButtonPolacz_clicked();

private:
    Ui::Dialog *ui;

signals:
    void connectToServer(QString,int);
};

#endif // DIALOG_H
