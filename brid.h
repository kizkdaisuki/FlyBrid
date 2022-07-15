#ifndef BRID_H
#define BRID_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QPoint>
#include <QMenu>
class Brid : public QWidget
{
    Q_OBJECT
public:
    explicit Brid(QWidget *parent = nullptr);
    void flying();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    int m_i_left = 1;
    int m_i_right = 8;
    QPixmap m_Pixmap_brid;
    QTimer* m_timer;
    QPoint m_ponit_pos;
    QMenu* m_menu_exit;
    bool m_b_mousedown = false;

signals:
    void chageImg();
    void moveWindow(QPoint);
};

#endif // BRID_H
