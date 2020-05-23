#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <printer_core.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene scena;
    QPixmap background;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
