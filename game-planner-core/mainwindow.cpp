#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ///background = QPixmap(ui->graphicsView->width(),ui->graphicsView->height());
    //filename = QFileDialog::getOpenFileName(this);
    //qDebug() << filename;
    background = QPixmap("C:\\Users\\MrKub\\Documents\\game-planner\\game-planner-core\\assets\\b0.jpg");
    QRect rec = qApp->desktop()->availableGeometry();
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          rec.size(),
                          rec));

    this->setFixedSize(rec.width()-100,rec.height()-50);
    ui->graphicsView->setFixedSize(this->size());
    scena.addPixmap(background.scaledToHeight(this->height()-5));
    ui->graphicsView->setScene(&scena);
    createActions();
    createMenus();
    obecne_pietro=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the program"));
    connect(exitAct, &QAction::triggered, this, &MainWindow::exit);
}

void MainWindow::createMenus()
{
    fileMenu = ui->menubar->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);
}

void MainWindow::open(){
    filename = QFileDialog::getOpenFileName(this);
    background = QPixmap(filename);
    scena.addPixmap(background.scaledToHeight(this->height()-5));
    ui->graphicsView->setScene(&scena);
}

void MainWindow::exit(){
    this->close();
}

QPixmap setOpacity(const QPixmap pix, double opacity){
    QPixmap nowa;
    QPainter *paint = new QPainter(&nowa);
    paint->setOpacity(opacity);
    paint->drawPixmap(0,0,pix);
    delete paint;
    return nowa;
}

void MainWindow::resize(){

}


void MainWindow::on_pushButton_clicked()
{
    obecne_pietro++;
    background = QPixmap(("C:\\Users\\MrKub\\Documents\\game-planner\\game-planner-core\\assets\\b" + QString::number(obecne_pietro) + ".jpg"));
    scena.clear();
    scena.addPixmap(background.scaledToHeight(this->height()-5));
    ui->graphicsView->setScene(&scena);
}
