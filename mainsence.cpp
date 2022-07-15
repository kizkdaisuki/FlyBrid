#include "mainsence.h"
#include "ui_mainsence.h"
#include <QIcon>
#include <QDesktopWidget>
#include <QDebug>
#include <QScreen>
MainSence::MainSence(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/Bird/birdIcon.ico"));
    this->m_Brid_ob = new Brid;
    this->m_Brid_ob->setParent(this);
    this->setFixedSize(this->m_Brid_ob->width(), this->m_Brid_ob->height());
    // 让小鸟飞起来
    this->m_Brid_ob->flying();
    connect(this->m_Brid_ob, &Brid::chageImg, [=](){
        this->update();
    });
    connect(this->m_Brid_ob, &Brid::moveWindow, [=](QPoint point){
        this->move(point);
        this->m_point_realpos = point;
    });
    this->m_timer = new QTimer(this);
    auto desk =  QGuiApplication::primaryScreen()->geometry(); // 获取桌面属性
    this->m_timer->start(30);
    connect(this->m_timer, &QTimer::timeout, [=](){
        if(!this->m_Brid_ob->m_b_mousedown)
            this->m_point_realpos.setX(this->m_point_realpos.x() + 5);

        if(this->m_point_realpos.x() > desk.width())
            this->m_point_realpos.setX(-this->width());
        qDebug() << "brid pos = " << this->m_point_realpos.x();
        this->move(this->m_point_realpos);
    });
    qDebug() << "desk width = " << desk.width();
    this->setTransparent();

}

MainSence::~MainSence()
{
    delete ui;
}

void MainSence::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->m_Brid_ob->m_Pixmap_brid);
}

void MainSence::setTransparent(){
    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置透明窗体  120号属性
    this->setAttribute(Qt::WA_TranslucentBackground);

    //设置窗口顶层
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    //设置起始Y位置
   //this->m_Auto_Pos.setY(desk->height()*0.5 -this->m_Bird->height());
}

