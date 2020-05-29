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

#include <printer_core.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString filename;
    QGraphicsScene scena;
    QPixmap background;
    int obecne_pietro;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();
private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QActionGroup *alignmentGroup;
    QAction *openAct;
    QAction *exitAct;
    void resize();

private slots:
    void open();
    void exit();
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
