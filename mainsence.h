#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QWidget>
#include "brid.h"
#include <QPainter>
#include <QTimer>
#include <QPoint>
QT_BEGIN_NAMESPACE
namespace Ui { class MainSence; }
QT_END_NAMESPACE

class MainSence : public QWidget
{
    Q_OBJECT

public:
    MainSence(QWidget *parent = nullptr);
    ~MainSence();

    void paintEvent(QPaintEvent *event);
    void setTransparent();
public:
    Brid* m_Brid_ob = NULL;
    QTimer* m_timer;
    QPoint m_point_realpos;
private:
    Ui::MainSence *ui;

};
#endif // MAINSENCE_H
