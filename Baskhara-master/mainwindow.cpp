#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float a, b, c, delta, x1, x2;
    a = ui->lineEdit->text().toFloat(NULL);
    b = ui->lineEdit_2->text().toFloat(NULL);
    c = ui->lineEdit_3->text().toFloat(NULL);
    delta = pow(b,2) - (4*a*c);
    ui->lineEdit_4->setText(QString("%1").arg(delta));
    if(delta<0){
        ui->label_5->setText("Não existem raizes reais");
    }
    else
        if(delta==0){
            x1 = (-b+sqrt(delta))/(2*a);
            ui->label_5->setText("Existe apenas uma raiz real que é "+ QString("%1").arg(x1));
        }
        else{
            x1 = (-b+sqrt(delta))/(2*a);
            x2 = (-b-sqrt(delta))/(2*a);
            ui->label_5->setText("Existem duas raizes reais que são: "+ QString("%1 e %2").arg(x1).arg(x2));
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->label_5->clear();
    ui->lineEdit->setFocus();
}
