#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::newgame()
{
    qDebug()<<difficulty;
    return;//    start different games according to d..
}



void MainWindow::open()
{
    return;
}

bool MainWindow::save()
{
    return false;
}

bool MainWindow::saveas()
{
    return false;
}


void MainWindow::about()
{

    return;
}

void MainWindow::easy()
{
    difficultynum = 1;
    newgame();
}

void MainWindow::middle()
{
    difficultynum = 2;
    newgame();
}

void MainWindow::hard()
{
    difficultynum = 3;
    newgame();
}



void MainWindow::createActions()
{
    newAction = new QAction(tr("new"),this);
    newAction -> setShortcut(tr("Ctrl+n"));
    //newAction -> setStatusTip(tr("create a new game"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newgame()));

    openAction = new QAction(tr("open.."),this);
    openAction -> setShortcut((tr("Ctrl+o")));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = new QAction(tr("save"),this);
    saveAction->setShortcut(tr("Ctrl+s"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveasAction = new QAction(tr("saveas.."),this);
    saveasAction->setShortcut(tr("Shift+Ctrl+s"));
    connect(saveasAction,SIGNAL(triggered()),this,SLOT(saveas()));



    easyAction = new QAction(tr("easy"),this);
    easyAction ->setCheckable(true);
    middleAction = new QAction(tr("middle"),this);
    middleAction ->setCheckable(true);
    hardAction = new QAction(tr("hard"),this);
    hardAction ->setCheckable(true);

    connect(easyAction,SIGNAL(triggered()),this,SLOT(easy()));
    connect(middleAction,SIGNAL(triggered()),this,SLOT(middle()));
    connect(hardAction,SIGNAL(triggered()),this,SLOT(hard()));



    difficultyGroup = new QActionGroup(this);
    difficultyGroup->addAction(easyAction);
    difficultyGroup->addAction(middleAction);
    difficultyGroup->addAction(hardAction);



    aboutAction = new QAction(tr("info about.."),this);
    //aboutAction->setShortcut(tr("Ctrl+p"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));



}
void MainWindow::createMenus()
{
    infoMenu = menuBar() -> addMenu(tr("&Info"));
    infoMenu -> addAction(aboutAction);

    fileMenu = menuBar() -> addMenu(tr("&File"));
    fileMenu -> addAction(newAction);
    fileMenu -> addAction(openAction);
    fileMenu -> addAction(saveAction);
    fileMenu -> addAction(saveasAction);


   // difficulty = menuBar() ->addMenu((tr("&Difficulty")));


    //fileMenu -> addSeparator();
   // fileMenu -> addAction(newAction);
  //  menuBar()->addSeparator();

  //  QToolBar *bar;
    //bar -> addToolBar(tr("文件"));//创建工具栏
    //bar -> addAction(newAction);//将Action添加到工具栏，将显示Action的图标

}
