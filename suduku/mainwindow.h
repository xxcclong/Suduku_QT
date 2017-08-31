#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sudukuclass.h"
#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QAction>
#include <QActionGroup>
#include <fstream>
#include <iostream>
#include <QPushButton>
#include <QColor>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QPainter>
#include <QIcon>
#include <QSignalMapper>
#include <QMouseEvent>
#include <QTimer>
#include "dialogchoo.h"
class QAction;
class Qlabel;


class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    DialogChoo* dia;
    int difficultynum = 1;
    int now = 0;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void paintEvent(QPaintEvent*);
    void longsuccess();
    void longpress(int);
    void newgame();
    void open();
    void showdia(int i =1);
    bool save();
    bool saveas();
    void about();
    void easy();
    void middle();
    void hard();
    void fill(int x,int y,int num);
    void mouseMoveEvent(QMouseEvent *event);
  //  void on_pushButton_clicked();
    void setico(int,int,int input = 0);

private:
    int markx,marky,marknum;
    bool marked[82][10];
    void mark(int,int);
    QTimer* timer;
    int longbut;
    // connected with inside game
    int wrong[82];
    int chance;// next step  all steps
    int out[10][10];



    sudu::tree* finalone;
   // QSignalMapper *m;
    int mousex,mousey;
    void createMenus();
    void createActions();
    QPushButton *lab[82];
    QGridLayout *G;
    sudu* MainSudu;
    QVBoxLayout *l;
    QPushButton* but;
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
    QIcon* ico[30];

};

#endif // MAINWINDOW_H
