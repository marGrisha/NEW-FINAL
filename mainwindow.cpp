#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DNS = new dns_shop();
    this->setWindowTitle("LOG IN");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(this,"LOGIN ERROR", "Введите имя");
        return;
    }
    DNS->setName(ui->lineEdit->text());
    DNS->show();
    this->close();
    DNS->DrawTable();
}

