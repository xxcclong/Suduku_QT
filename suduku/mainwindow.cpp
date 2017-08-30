#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);
    widget->setMouseTracking(true);
    this->setMouseTracking(true);
    //m = new QSignalMapper(this);



   // but = new QPushButton;
    //connect(but,SIGNAL(clicked(bool)),this,SLOT(showdia()));
    //dia = new DialogChoo;

   // but->setGeometry(30,40,50,60);


    //QString fileName = QFileDialog::getOpenFileName(this,"Choose Image","x:/image",("Image File(*.*)")) ;

    ico[1] = new QIcon(":/new/prefix1/1.png");
    ico[2] = new QIcon(":/new/prefix1/2.png");
    ico[3] = new QIcon(":/new/prefix1/3.png");
    ico[4] = new QIcon(":/new/prefix1/4.png");
    ico[5] = new QIcon(":/new/prefix1/5.png");
    ico[6] = new QIcon(":/new/prefix1/6.png");
    ico[7] = new QIcon(":/new/prefix1/7.png");
    ico[8] = new QIcon(":/new/prefix1/8.png");
    ico[9] = new QIcon(":/new/prefix1/9.png");
    ico[0] = new QIcon(":/new/prefix1/0.png");

    //":/new/prefix1/1/png"

    //labpix = labpix.scaled()
    G = new QGridLayout();
    for(int i=1;i<=81;++i)
    {
        lab[i] = new QPushButton(*ico[1], "", widget);
        lab[i]->setIconSize(QSize(50, 50));
            lab[i]->setFixedSize(50,50);


      //  lab[i]->setScaledContents(true);
       //ui->lab[i]->setPixmap(QPixmap::fromImage(*img));
        G->addWidget(lab[i],(i-1)/9,(i-1)%9,1,1);
        //lab[i]->show();
    }


    for(int i=1;i<=81;++i)
    {
        QSignalMapper* m =new QSignalMapper;
        connect(lab[i], SIGNAL(clicked()), m, SLOT(map()));
        m->setMapping(lab[i],i);
        connect(m, SIGNAL(mapped(int)), this, SLOT(showdia(int)));


    }

    // 设置水平间距

    //G->setHorizontalSpacing(10);
    // 设置垂直间距
    //G->setVerticalSpacing(10);
    // 设置外间距
    //G->setContentsMargins(10, 10, 10, 10);
    centralWidget()->setLayout(G);
    //G->show();


    MainSudu = new sudu;
    createActions();
    createMenus();

}
void MainWindow::showdia(int i)
{
    qDebug()<<"dasda";
    DialogChoo diaa(this,i);
    //dia = new DialogChoo(this,i);
    diaa.setGeometry(mousex,mousey,161,141);
    diaa.exec();
    if(i == -1)
        return;
    setico(i,diaa.now);
}

MainWindow::~MainWindow()
{

}


void MainWindow::newgame()
{
    MainSudu->form();
    MainSudu->debug_print();
    MainSudu->test(MainSudu->smallx,MainSudu->smally);
    but->setText("xixi");
    but->setDisabled(true);
    return;//    start different games according to d..

}/*
void MainWindow::getmouse(QMouseEvent* m)
{
    mousex = m->pos().x();
    mousey = m->pos().y();
    return;
}
*/
void MainWindow::mouseMoveEvent ( QMouseEvent * e )//鼠标移动事件响应
{
//1.获取局部鼠标位置
//labelMousePos ->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
//2.获取全局鼠标位置

//QPoint coursePoint;
//coursePoint = QCursor::pos();//获取当前光标的位置

mousex = e->globalPos().x();
mousey = e->globalPos().y();
qDebug()<<mousex<<mousey;
//labelMousePos ->setText("("+QString::number(coursePoint.x())+","+QString::number(coursePoint.y())+")");

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

    fileMenu = menuBar() -> addMenu(tr("&File"));
    fileMenu -> addAction(newAction);
    fileMenu -> addAction(openAction);
    fileMenu -> addAction(saveAction);
    fileMenu -> addAction(saveasAction);

    infoMenu = menuBar() -> addMenu(tr("&Info"));
    infoMenu -> addAction(aboutAction);

   // difficulty = menuBar() ->addMenu((tr("&Difficulty")));


    //fileMenu -> addSeparator();
   // fileMenu -> addAction(newAction);
  //  menuBar()->addSeparator();

  //  QToolBar *bar;
    //bar -> addToolBar(tr("文件"));//创建工具栏
    //bar -> addAction(newAction);//将Action添加到工具栏，将显示Action的图标

}

void MainWindow::fill(int x,int y,int num)
{

}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"sada";
    return;
}

void MainWindow::setico(int labnum,int iconum)
{
    if(iconum == -1)
        return;
    lab[labnum]->setIcon(*ico[iconum]);
}
