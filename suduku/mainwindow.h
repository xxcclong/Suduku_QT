#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sudukuclass.h"
#include <QMainWindow>
#include <QDebug>
#include <QCoreApplication>
#include <QMediaPlayer>
#include <QTime>
#include <QMediaPlaylist>
#include <QMenuBar>
#include <QMessageBox>
#include <QFile>
#include <QAction>
#include <QActionGroup>
#include <fstream>
#include <QSound>
#include <iostream>
#include <QPushButton>
#include <QColor>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>
#include <QPainter>
#include <QTextStream>
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
    void stopgame();
    void getMute();
    void showtime();
    void paintEvent(QPaintEvent*);
    void longsuccess();
    void longpress(int);
    void marrk(int posi,int num);
    void newgame();
    void open();
    void showdia(int i =1);
    void repeal();
    void reform();
    bool save();
    bool saveas();
    void about();
    void easy();
    void middle();
    void hard();
    void find_next();
    void fill(int x,int y,int num);
    void mouseMoveEvent(QMouseEvent *event);
  //  void on_pushButton_clicked();
    void setico(int,int,int input = 0);

private:
    struct opt
    {
        int ox,oy;
        int oformer,othen;
        int omark;
        opt()
        {
            ox = oy = oformer = othen = omark = 0;
        }
    }o[10];
    QSound *mainsound;
    int opointer;
    int showrong;
    int timenum;
    QLabel* time;
    bool started;
    int alll;
    void waitsec(int i=50);
    int markx,marky,marknum;
    bool marked[82][10];
    void mark(int,int);
    QTimer* gametimer;
    QTimer* timer;
    int longbut;
    int clickednum;
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
    QMenu *gamemenu;
    QMenu *fileMenu;
    QMenu *infoMenu;
    bool ismute;
    QAction* muteAction;
    QMenu* difficulty;
    QActionGroup *difficultyGroup;
    QAction* Stop;
    QAction* repealAction;
    QAction* reformAction;
    QAction *easyAction;
    QAction *middleAction;
    QAction* nextAction;
    QAction *hardAction;
    QAction *openAction;
    QAction *newAction;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *saveasAction;
    QIcon* ico[30];

};

#endif // MAINWINDOW_H
