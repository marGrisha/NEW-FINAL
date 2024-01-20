#include "Mvideo_shop.h"
#include "ui_Mvideo_shop.h"
#include <QFile>
#include "output.h"
#include <QMessageBox>

Mvideo_shop::Mvideo_shop(QWidget *parent)
    : QDialog(parent), ui(new Ui::Mvideo_shop)
{
    ui->setupUi(this);
}

Mvideo_shop::~Mvideo_shop()
{
    delete ui;
}

void Mvideo_shop::setName(QString namme)
{
    name = namme;
}

void Mvideo_shop::WriteTable()
{
    READ();

    for (int g = 0; g < 4; g++)
    {
        auto h = this->buy[g].getname();
        QTableWidgetItem *item = new QTableWidgetItem(h);
        ui->tableWidget->setItem(g, 0, item);
    }

    for (int g = 0; g < 4; g++)
    {
        auto h = this->buy[g].getcolvo();
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(h));
        ui->tableWidget->setItem(g, 1, item);
    }

    for (int g = 0; g < 4; g++)
    {
        auto h = this->buy[g].getcena();
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(h));
        ui->tableWidget->setItem(g, 2, item);
    }
}

void Mvideo_shop::DrawTable()
{

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int k = 0; k < 5; k++)
    {
        ui->tableWidget->setColumnWidth(k, 170);
        ui->tableWidget->setRowHeight(k, 75);
    }
    this->setWindowTitle("DNS");
    WriteTable();
    pokupka = output();
}

void Mvideo_shop::push_to_list(stuff b)
{
    this->buy.push_back(b);
}

void Mvideo_shop::READ()
{
    QString str;
    QString Data_str;
    stuff t;
    QFile file("C:/Users/Documents/DNSS_SHOP/products.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            str = file.readLine();
            int j = 0;
            while (str[j] != '(')
            {
                Data_str += str[j];
                j++;
            }
            j++;
            t.setname(Data_str);
            Data_str = "";
            while (str[j] != '(')
            {
                Data_str += str[j];
                j++;
            }
            j++;
            t.setcolvo(Data_str.toInt());
            Data_str = "";
            while (j < str.size())
            {
                Data_str += str[j];
                j++;
            }
            t.setcena(Data_str.toInt());
            Data_str = "";
            push_to_list(t);
        }
    }
    file.close();
}

QString Mvideo_shop::getName()
{
    return this->name;
}

void Mvideo_shop::WRITE()
{
    int SUM = 0;
    QFile file("C:/Users/Documents/DNSS_SHOP/check.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream stream(&file);
        stream << "LOGIN: " << getName() << "\n\n";
        for (int i = 0; i < 4; i++)
        {
            stream << buy[i].getname() << " ---- " << pokupka.getTech(i) << "(col-vo) ---- " << pokupka.getTech(i) * buy[i].getcena() << "(cena)\n";
            SUM += pokupka.getTech(i) * buy[i].getcena();
        }
        stream << "\n\n\nPRICE = " << QString::number(SUM) << "\n";
    }
    QMessageBox::information(this, "Заказ", "Вы заказали товары");
    file.close();
}

void Mvideo_shop::ADD(int a)
{
    if (buy[a].getcolvo() != 0)
    {
        pokupka.setTech(a);
        buy[a].setcolvo(buy[a].getcolvo() - 1);
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(buy[a].getcolvo()));
        ui->tableWidget->setItem(a, 1, item2);
    }
}

void Mvideo_shop::on_pushButton_2_clicked()
{
    ADD(0);
}

void Mvideo_shop::on_pushButton_3_clicked()
{
    ADD(1);
}

void Mvideo_shop::on_pushButton_4_clicked()
{
    ADD(2);
}

void Mvideo_shop::on_pushButton_5_clicked()
{
    ADD(3);
}

void Mvideo_shop::on_pushButton_clicked()
{
    WRITE();
    this->close();
}
