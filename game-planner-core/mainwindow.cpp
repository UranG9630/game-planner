#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRect rec = qApp->desktop()->availableGeometry();
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          rec.size(),
                          rec));
    ui->graphicsView->setAlignment( Qt::AlignCenter | Qt::AlignCenter );
    scena.sceneRect() = ui->graphicsView->rect();
    this->setFixedSize(rec.width()-100,rec.height()-50);
    ui->graphicsView->setFixedSize(this->size());
    this->ui->graphicsView->centerOn(this->width()/2,this->height()/2);
    QPixmap black(ui->graphicsView->size());
    black.fill(Qt::blue);
    this->setBckg(black);
    this->setMouseTracking(true);

    createActions();
    createMenus();
    obecne_pietro=0;

    QIcon ikonka("C:\\Users\\MrKub\\Documents\\game-planner\\game-planner-core\\assets\\op1.png");
    ui->pushButton->setText("");
    ui->pushButton->setIcon(ikonka);
    ui->verticalLayoutWidget->setFixedSize(this->width()*0.1,this->height());

    QPushButton *btn1 = new QPushButton("btn1");
    btn1->setText("btn1");
    ui->verticalLayout->addWidget(btn1);

    QPushButton *btn2 = new QPushButton("btn2");
    btn2->setText("btn2");
    ui->verticalLayout->addWidget(btn2);

    QPushButton *btn3 = new QPushButton("btn3");
    btn3->setText("btn3");
    ui->verticalLayout->addWidget(btn3);

    QPushButton *btn4 = new QPushButton("btn4");
    btn4->setText("btn4");
    ui->verticalLayout->addWidget(btn4);

    connect(btn1,&QAbstractButton::clicked,this,&MainWindow::btn1_clicked);
    connect(btn2,&QAbstractButton::clicked,this,&MainWindow::btn2_clicked);

    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    connect(&scena, &scene_mouse::mmoved, this, &MainWindow::mouse_moved);

    ikona = printer_icon(QPixmap("C:\\Users\\MrKub\\Documents\\game-planner\\game-planner-core\\assets\\ic1.png"),QPoint(0,0),1);
    listaikon.append(ikona);

    masterpath = "C:\\Users\\MrKub\\Documents\\game-planner\\game-planner-core\\assets\\";
    skala = 1;


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

QPixmap MainWindow::setOpacity(const QPixmap pix, double opacity){
    QPixmap nowa;
    QImage image(pix.size(), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::transparent);
    QPainter p(&image);
    p.setOpacity(opacity);
    p.drawPixmap(0, 0, pix);
    p.end();
    nowa.convertFromImage(image);
    return nowa;
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->resetTransform();
    obecne_pietro++;
    this->setBckg(QPixmap((masterpath+ "b" + QString::number(obecne_pietro) + ".jpg")));
}

void MainWindow::btn1_clicked(){
}

void MainWindow::btn2_clicked(){
    QPixmap t;
    t = background;
    printer.print_iconsV(&t,listaikon);
    this->setBckg(t);
}

void MainWindow::wheelEvent(QWheelEvent *event){
    int angle = event->angleDelta().y();
    qreal factor = 1;
    if (angle < 0) {
        factor = 1.1;
        skala*=factor;
    } else if(skala >= 0.85){
        factor = 0.9;
        skala *= factor;
    }
    qDebug()<<skala;

    ui->graphicsView->scale(factor,factor);
    //qDebug() << ui->graphicsView->width() << " " << ui->graphicsView->height();
}

void MainWindow::setBckg(QPixmap pix){
    background = pix;
    QGraphicsPixmapItem* b = new QGraphicsPixmapItem;
    b->setPixmap(background);
    b->setPos(0,0);
    qreal x = qreal(ui->graphicsView->height())/qreal(background.height());///skala;
    ui->graphicsView->resetMatrix();
    scena.clear();
    scena.sceneRect() = ui->centralwidget->rect();
    scena.addItem(b);
    ui->graphicsView->setScene(&scena);
    ui->graphicsView->scale(x,x);
    qDebug() << x;
}

void MainWindow::mouse_moved(const QGraphicsSceneMouseEvent* event){
    /*
    if((event->scenePos().x()>0) && (event->scenePos().y()>0)){
        ikona.setPos(event->scenePos());
        listaikon.append(ikona);
        printer.print_iconsV(&background,listaikon);
        this->setBckg(background);
    }
    qDebug() <<  ikona.pos;
    */
}

void QGraphicsView::wheelEvent(QWheelEvent *event){} // przeladowanie żeby scroll nie scrollowal w dół
