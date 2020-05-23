#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    background = QPixmap(ui->graphicsView->width(),ui->graphicsView->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

