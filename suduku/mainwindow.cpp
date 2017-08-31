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
    memset(wrong,0,sizeof(wrong));
    chance = 0;
    alll = 81;
    started = 0;
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

    ico[11] = new QIcon(":/g1x.png");
    ico[12] = new QIcon(":/g2x.png");
    ico[13] = new QIcon(":/g3x.png");
    ico[14] = new QIcon(":/g5x.png");
    ico[15] = new QIcon(":/g4x.png");
    ico[16] = new QIcon(":/g6x.png");
    ico[17] = new QIcon(":/g7x.png");
    ico[18] = new QIcon(":/g8x.png");
    ico[19] = new QIcon(":/g9x.png");

    ico[21] = new QIcon(":/s1.png");
    ico[22] = new QIcon(":/s2.png");
    ico[23] = new QIcon(":/s3.png");
    ico[24] = new QIcon(":/s4.png");
    ico[25] = new QIcon(":/s5.png");
    ico[26] = new QIcon(":/s6.png");
    ico[27] = new QIcon(":/s7.png");
    ico[28] = new QIcon(":/s8.png");
    ico[29] = new QIcon(":/s9.png");



    //":/new/prefix1/1/png"

    //labpix = labpix.scaled()
    G = new QGridLayout();
    for(int i=1;i<=81;++i)
    {
        //lab[i] = new QPushButton(*ico[0], "", widget);
        lab[i] = new QPushButton;
        setico(i,0);
        lab[i]->setMouseTracking(true);
        lab[i]->setStyleSheet("background-color:transparent");

       // lan[i]->setAutoRepeat();
            //lab[i]->setFlat(true);
            lab[i]->setFixedSize(50,50);

            lab[i]->setEnabled(false);


      //  lab[i]->setScaledContents(true);
       //ui->lab[i]->setPixmap(QPixmap::fromImage(*img));
        G->addWidget(lab[i],(i-1)/9,(i-1)%9,1,1);
        //lab[i]->show();
    }
    time = new QLabel;
    G -> addWidget(time,9,0,1,9);
    time->setAlignment(Qt::Alignment (Qt::AlignHCenter));

    for(int i=1;i<=81;++i)
    {
        QSignalMapper* longm = new QSignalMapper;
        connect(lab[i],SIGNAL(pressed()),longm,SLOT(map()));
        longm->setMapping(lab[i],i);
        connect(longm,SIGNAL(mapped(int)),this,SLOT(longpress(int)));
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

    timer->stop();
    if(i>100)
    {
        i-=100;
        DialogChoo diaa(this,i);
        diaa.setGeometry(mousex,mousey,161,141);
        diaa.exec();
        if(diaa.now <= 0)
            return;
        mark(i,diaa.now);
        return;


    }
    DialogChoo diaa(this,i);
    //dia = new DialogChoo(this,i);

    diaa.setGeometry(mousex,mousey,161,141);
    diaa.exec();
    if(i == -1)
        return;

    if(diaa.now == -1)
        return;
    out[(i-1)/9+1][(i-1)%9+1] = diaa.now;
    if(!diaa.now)
    {
        if(wrong[i])
        {
            wrong[i] = 0;
            --chance;
        }
    }
    else if(MainSudu->right[(i-1)/9+1][(i-1)%9+1] != diaa.now)
    {
        if(!wrong[i])
        {
            ++chance;
            wrong[i] = 1;
        }
    }
    else
    {
        if(wrong[i])
        {
            --chance;
            wrong[i] = 0;
        }
    }
    setico(i,diaa.now);
    //qDebug()<<chance;//<<chance<<' '<<(i-1)/9+1<<' '<<(i-1)&9+1;

}

MainWindow::~MainWindow()
{

}


void MainWindow::newgame()
{
    if(gametimer!=NULL)
        delete gametimer;
    time -> setText(QString::number(0,10));
    gametimer = new QTimer;
    timenum = 0;
    gametimer->setInterval(1000);
    gametimer->start();
 connect(gametimer,SIGNAL(timeout()),this,SLOT(showtime()));
    started = true;
    for(int i=1;i<=81;++i)
        for(int j=1;j<=9;++j)
        {
            marked[i][j] = 0;
           // out[i][j] = 0;
        }
    finalone = NULL;
    marknum = 0;//  if it is marked
    MainSudu->node = new sudu::tree;
    MainSudu->clear();
    for(int i = 1;i <= 81;++i)
    {
        lab[i]->setEnabled(true);
        wrong[i] = 0;

    }
    chance = 0;
    alll = 81;
    MainSudu->form();
    finalone = MainSudu->finalone;
    //MainSudu->test(MainSudu->smallx,MainSudu->smally);
    while((finalone->depth-30)>((4-difficultynum)*8))
    {
        //qDebug()<<100;
        finalone = finalone->former;
    }
    while(finalone->depth>30)
    {
       // qDebug()<<200;
        int xx = finalone->px;
        int yy = finalone->py;
        int numnum = finalone->pnum;
        MainSudu->g[xx][yy].num = numnum;
        finalone = finalone->former;
    }
    for(int i = 1;i<=9;++i)
        for(int j = 1;j<=9;++j)
        {
            setico(9*(i-1)+j,MainSudu->g[i][j].num,1);
            out[i][j] = MainSudu->g[i][j].num;
        }

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
//qDebug()<<mousex<<mousey;
//labelMousePos ->setText("("+QString::number(coursePoint.x())+","+QString::number(coursePoint.y())+")");

}

void MainWindow::open()
{
    return;
}

bool MainWindow::save()
{
    /*
    QFile f("qrc:/../../build-Suduku-Desktop_Qt_5_6_2_clang_64bit-Debug/wocaonimabi.txt");
    if(!f.open(QIODevice::WriteOnly))
    {
        qDebug() << "Open failed.";
        return false;
    }
    else
        qDebug()<<"success";

    QDataStream out(&f);
    //out.setVersion(QDataStream::Qt_4_1);
    QString s1("123");
    quint32 n1(123);

    out << s1 ;
    out << n1 ;
    f.close();
    return true;

*/

    std::ofstream txtOutput;
    txtOutput.open(":/../../build-Suduku-Desktop_Qt_5_6_2_clang_64bit-Debug/wocaonimabi.txt");
    if(!txtOutput)
    {
        //qDebug()<<"success";
    }
    for(int i = 1;i<=9;++i)
    {
        for(int  j = 1;j<=9;++j)
        {

            if(!out[i][j])
            {
    //            qDebug()<<"* ";
                txtOutput<<"* ";
            }
            else
                {
                txtOutput<<out[i][j]<<' ';
      //          qDebug()<<out[i][j]<<' ';
                }
        }
        txtOutput<<std::endl;
    }
     txtOutput.close();
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

    Stop = new QAction(tr("resume"),this);
    Stop ->setShortcut(tr("Ctrl+t"));
    connect(Stop,SIGNAL(triggered()),this,SLOT(stopgame()));


    openAction = new QAction(tr("open.."),this);
    openAction -> setShortcut((tr("Ctrl+o")));
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction = new QAction(tr("save"),this);
    saveAction->setShortcut(tr("Ctrl+s"));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveasAction = new QAction(tr("saveas.."),this);
    saveasAction->setShortcut(tr("Shift+Ctrl+s"));
    connect(saveasAction,SIGNAL(triggered()),this,SLOT(saveas()));

    nextAction = new QAction(tr("find next"),this);
    nextAction->setShortcut(tr("Ctrl+p"));
    connect(nextAction,SIGNAL(triggered()),this,SLOT(find_next()));



    easyAction = new QAction(tr("easy"),this);
    easyAction ->setCheckable(true);
    easyAction->setShortcut(tr("Ctrl+1"));
    middleAction = new QAction(tr("middle"),this);
    middleAction ->setCheckable(true);
    middleAction->setShortcut(tr("Ctrl+2"));
    hardAction = new QAction(tr("hard"),this);
    hardAction ->setCheckable(true);
    hardAction->setShortcut(tr("Ctrl+3"));

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


    difficulty = menuBar() ->addMenu(tr("&Difficulty"));
    difficulty -> addAction(easyAction);
    difficulty -> addAction(middleAction);
    difficulty -> addAction(hardAction);

    gamemenu = menuBar() ->addMenu(tr("&Game"));
    gamemenu -> addAction(nextAction);
    gamemenu -> addAction(Stop);

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

void MainWindow::longpress(int i)
{
    longbut = i;
     timer = new QTimer;
       timer->setInterval(1000);
       timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(longsuccess()));

    //qDebug()<<67328144878237893;
}

void MainWindow::longsuccess()
{
    //qDebug()<<longbut;

    showdia(100+longbut);
}

void MainWindow::setico(int labnum, int iconum, int input)
{
    if(iconum)
    {
        --alll;
    }
    if(!input&&!iconum)
    {
        qDebug()<<"+++";
        ++alll;
    }
    //qDebug()<<labnum<<'*'<<iconum<<'*'<<input;
    if(iconum == -1)
        return;
    lab[labnum]->setIconSize(QSize(43, 42));
    if(input&&iconum)
    {
        lab[labnum]->setEnabled(false);
        iconum += 20 ;
    }

    if(!iconum)
    {
        iconum = ((labnum-1)%9)/3+1+((((labnum-1)/9))/3)*3+10;
        lab[labnum]->setIconSize(QSize(30, 30));
       // qDebug()<<iconum;
    }
    lab[labnum]->setIcon(*ico[iconum]);

    if(!alll)
    {
        if(!chance)
        QMessageBox::information(NULL, "SUDOtree", "Success", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        else
            QMessageBox::information(NULL, "SUDOtree", "Some thing wrong", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        delete gametimer;
    }
}


void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    QColor a(124,205,124);
    p.setPen(a);
    p.setBrush(a);

    for(int i=1;i<=81;++i)
    {
        for(int j = 1;j<=9;++j)
        {
            if(marked[i][j])
            {
                int x = lab[i]->pos().x();
                int y = lab[i]->pos().y();
                x += (j-1)%3*13+6;
                y += (j-1)/3*13+6;
                p.drawRect(x, y, 11, 11);
            }
        }
    }

}
void MainWindow::mark(int posi,int num)
{
    marked[posi][num] = !marked[posi][num];
}


void MainWindow::find_next()
{
    if(!started)
        return;
   // qDebug()<<"fenge";
    //MainSudu->debug_print();
    //qDebug()<<"fenge";
    if(chance)
    {
   //     qDebug()<<"no";
        return;
    }

    for(int i=1;i<=9;++i)
    {
        for(int j=1;j<=9;++j)
        {
            if(out[i][j])
            {
                std::cout<<out[i][j]<<' ';
            }
            else
                std::cout<<"* ";
        }
        std::cout<<std::endl;
    }
    MainSudu->clear();
   //   qDebug()<<MainSudu->smallx<<" "<<MainSudu->smally<<"ooooooooo";
    for(int i=1;i<=9;++i)
        for(int j=1;j<=9;++j)
        {
            if(out[i][j])
            {
                MainSudu->deny(i,j,out[i][j],1);
            }
        }
    //MainSudu->debug_print();
     out[MainSudu->smallx][MainSudu->smally] = MainSudu->right[MainSudu->smallx][MainSudu->smally];
   //  qDebug()<< out[MainSudu->smallx][MainSudu->smally];
    setico(((MainSudu->smallx-1)*9+MainSudu->smally),MainSudu->right[MainSudu->smallx][MainSudu->smally]);
   // qDebug()<<MainSudu->smallx<<' '<<MainSudu->smally;
}


void MainWindow::showtime()
{
    ++timenum;
    time->setText(QString::number(timenum,10));
}

void MainWindow::stopgame()
{
    gametimer->stop();
    QMessageBox::information(NULL, "SUDOtree", "Stopped", QMessageBox::Yes , QMessageBox::Yes);
    gametimer->start();
}
