#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QActionGroup>
#include <QAction>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QDebug>
#include <QStyle>
#include <QAbstractButton>
#include <QWheelEvent>
#include <QScrollBar>
#include <QVector>
#include <QPainter>
#include <QGraphicsPixmapItem>

#include <printer_core.h>
#include <scene_mouse.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    printer_core printer;
    printer_icon ikona;
    QVector<printer_icon> listaikon;
    QString masterpath;

    Ui::MainWindow *ui;
    QString filename;
    scene_mouse scena;
    QPixmap background;
    qreal skala;
    int obecne_pietro;
    QMenu *fileMenu;
    QActionGroup *alignmentGroup;
    QAction *openAct;
    QAction *exitAct;

    void setBckg(QPixmap pix);
    QPixmap setOpacity(const QPixmap pix, double opacity);
    void wheelEvent(QWheelEvent *event) override;
    void createActions();
    void createMenus();


private slots:
    void open();
    void exit();
    void on_pushButton_clicked();
    void btn1_clicked();
    void btn2_clicked();
    void mouse_moved(const QGraphicsSceneMouseEvent* event);
};
#endif // MAINWINDOW_H
