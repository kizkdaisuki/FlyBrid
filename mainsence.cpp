#include "mainsence.h"
#include "ui_mainsence.h"

MainSence::MainSence(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);
}

MainSence::~MainSence()
{
    delete ui;
}

