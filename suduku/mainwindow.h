#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QAction>
class QAction;
class Qlabel;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newgame();
    void readgame();
private:
    Ui::MainWindow *ui;
    void createMenus();
    void createActions();
    QMenu *fileMenu;
    QAction *openAction;
    QAction *newAction;
};

#endif // MAINWINDOW_H
