#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QAction>
#include <QActionGroup>
class QAction;
class Qlabel;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    int difficultynum = 1;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void newgame();
    void open();
    bool save();
    bool saveas();
    void about();
    void easy();
    void middle();
    void hard();

private:
    Ui::MainWindow *ui;
    void createMenus();
    void createActions();
    QMenu *fileMenu;
    QMenu *infoMenu;
    QMenu* difficulty;
    QActionGroup *difficultyGroup;
    QAction *easyAction;
    QAction *middleAction;
    QAction *hardAction;
    QAction *openAction;
    QAction *newAction;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *saveasAction;

};

#endif // MAINWINDOW_H
