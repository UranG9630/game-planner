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
#include <printer_core.h>
#include <QWheelEvent>
#include <QScrollBar>

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

    Ui::MainWindow *ui;
    QString filename;
    QGraphicsScene scena;
    QPixmap background;
    qreal skala = 1;
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
};
#endif // MAINWINDOW_H
