#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

/*! This function displays the main window of the user interface. The spinbox and horizontal slider
 *in the main window are also connected here to work together as one widget.
 */
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

/*! This function prints a message to the standard output when the first button is clicked.*/
void MainWindow::on_pushButton_clicked()
{
    std::cout << "pushbutton " << std::endl;
}


/*! This function displays an informational message window and prints a message when the
 * second button is clicked.
 */
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("Message"),tr("Hello!"));   //displays a message box
    std::cout << "Message displayed " << std::endl;
}

/*! This function displays a message to the standard output and exits the program when the
 * third button is clicked.*/
void MainWindow::on_pushButton_3_clicked()
{
    std::cout << "Exiting program... " << std::endl;
    exit(0);
}

/*! This function prints a message to standard output when the horizontal slider is moved.*/
void MainWindow::on_horizontalSlider_sliderMoved(int)
{
    std::cout << "Slider moved " << std::endl;
}

/*! This function prints a message to standard output when the spinbox value is changed.*/
void MainWindow::on_spinBox_valueChanged(int)
{
    std::cout << "Value changed " << std::endl;
}
