#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialogsync.h"
#include "util.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //declare Util static object instance
    static Util *util;



public slots:
    void importSUNAT();
private slots:
    void syncDialog();
    void importGroups();
    void setup();
private:
    Ui::MainWindow *ui;
    DialogSync *sd;

};
#endif // MAINWINDOW_H
