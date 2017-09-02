#include "dialogchoo.h"
#include "ui_dialogchoo.h"

DialogChoo::DialogChoo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChoo)
{

    //this->setWindowFlags(Qt::Dialog| Qt::FramelessWindowHint);


    //this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    //this->setStyleSheet("QDialog{background-color: transparent;}");
    this->setWindowOpacity(0.7);
    ui->setupUi(this);
}
DialogChoo::DialogChoo(QWidget *parent,int i):QDialog(parent),ui(new Ui::DialogChoo)
{
//    if(i>100)
//        pushButton_11->setText("mark");
    now = -1;
    this->setWindowFlags(Qt::Dialog| Qt::FramelessWindowHint);
    ui->setupUi(this);
}

DialogChoo::~DialogChoo()
{
    delete ui;
}



void DialogChoo::on_pushButton_clicked()
{
    now = 1;
    accept();
}

void DialogChoo::on_pushButton_4_clicked()
{
    now = 2;accept();
}

void DialogChoo::on_pushButton_7_clicked()
{
    now = 3;accept();
}

void DialogChoo::on_pushButton_2_clicked()
{
    now = 4;accept();
}

void DialogChoo::on_pushButton_5_clicked()
{
    now = 5;accept();
}

void DialogChoo::on_pushButton_8_clicked()
{
    now = 6;accept();
}

void DialogChoo::on_pushButton_3_clicked()
{
    now = 7;accept();
}

void DialogChoo::on_pushButton_6_clicked()
{
    now = 8;accept();
}

void DialogChoo::on_pushButton_9_clicked()
{
    now = 9;accept();
}

void DialogChoo::on_pushButton_10_clicked()
{
    now = 0;accept();
}

void DialogChoo::on_pushButton_11_clicked()
{
    now = -1;accept();
}


void DialogChoo::keyPressEvent(QKeyEvent *e)
{

    if(e->key()==Qt::Key_1)//判断键值，此处以S键为例
    {

          //do something
    }
    if(e->key()==Qt::Key_2)//判断键值，此处以S键为例
    {
          //do something
    }

}

