#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::cout << "pushbutton " << std::endl;
}



void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("Message"),tr("Hello!"));   //displays a message box
    std::cout << "Message displayed " << std::endl;
}

void MainWindow::on_pushButton_3_clicked()
{
    std::cout << "Exiting program... " << std::endl;
    exit(0);
}

void MainWindow::on_horizontalSlider_sliderMoved(int)
{
    std::cout << "Slider moved " << std::endl;
}

void MainWindow::on_spinBox_valueChanged(int)
{
    std::cout << "Value changed " << std::endl;
}
