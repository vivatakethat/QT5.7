﻿#include "mainWidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    //this->resize(480,270);
    this->resize(500,600);
    this->setMaximumSize(480,270);
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));
    this->setWindowTitle("Game of nake");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/face.jpg").scaled(this->size())));
    this->setPalette(palette);

    startbtn=new QPushButton(this);
    startbtn->setIcon(QIcon(":/new/prefix1/img/start.png"));
    startbtn->setIconSize(QSize(75,75));
    startbtn->setGeometry(QRect(250,170,75,75));
    startbtn->setFlat(true);

    exitbtn=new QPushButton(this);
    exitbtn->setIcon(QIcon(":/new/prefix1/img/quit.png"));
    exitbtn->setIconSize(QSize(70,70));
    exitbtn->setGeometry(QRect(350,170,70,70));
    exitbtn->setFlat(true);
    //设置说明标签
    QFont font;
    font.setFamily("Consolas");
    font.setBold(true);
    font.setPixelSize(13);
    label=new QLabel(this);
    label->setText("README：Game of sname ,use W A S D to controll sname move");
    label->setFont(font);
    label->setGeometry(QRect(10,10,400,50));

    connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startSlot()));
}

mainWidget::~mainWidget()
{
    delete startbtn;
    delete exitbtn;
}
void mainWidget::exitSlot()
{
    if(QMessageBox::question(this,"EXIT","are sure exit the game?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        delete this;
        exit(0);
    }
}
void mainWidget::startSlot()
{

    g=new GameWidget(this);
    g->show();
}
//重写resizeEvent
/*void mainWidget::resizeEvent(QResizeEvent *)
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/face.jpg").scaled(this->size())));
    this->setPalette(palette);
    startbtn->setGeometry(QRect(this->size().width()-230,this->size().height()-100,75,75));
    exitbtn->setGeometry(QRect(this->size().width()-130,this->size().height()-100,70,70));
}*/
