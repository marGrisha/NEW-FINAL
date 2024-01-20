#ifndef DNS_SHOP_H
#define DNS_SHOP_H

#include <QDialog>
#include "stuff.h"
#include "output.h"

namespace Ui {
class dns_shop;
}

class dns_shop : public QDialog
{
    Q_OBJECT

public:
    explicit dns_shop(QWidget *parent = nullptr);
    ~dns_shop();
    QString getName();
    void setName(QString namme);
    void DrawTable();
    void WriteTable();
    void READ();
    void WRITE();
    void push_to_list(stuff b);
    void ADD(int a);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::dns_shop *ui;
    QString name;
    output pokupka;
    QList<stuff> buy;
};

#endif // DNS_SHOP_H
