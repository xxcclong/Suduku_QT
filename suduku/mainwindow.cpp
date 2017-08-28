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
    qDebug()<<"newgame() called";
    return;
}


void MainWindow::readgame()
{
    return;
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("new"),this);
    newAction -> setShortcut(tr("Ctrl+n"));
    newAction -> setStatusTip(tr("create a new game"));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newgame()));

}
void MainWindow::createMenus()
{
    fileMenu = menuBar() -> addMenu(tr("&File"));
    fileMenu -> addAction(newAction);
    //fileMenu -> addSeparator();
   // fileMenu -> addAction(newAction);
  //  menuBar()->addSeparator();

  //  QToolBar *bar;
    //bar -> addToolBar(tr("文件"));//创建工具栏
    //bar -> addAction(newAction);//将Action添加到工具栏，将显示Action的图标

}
