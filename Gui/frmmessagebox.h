﻿#ifndef FRMMESSAGEBOX_H
#define FRMMESSAGEBOX_H

#include <QtWidgets/QDialog>

namespace Ui {
class frmMessageBox;
}

class frmMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit frmMessageBox(QWidget *parent = 0);
    ~frmMessageBox();
    /**界面居中父窗口
     * @brief showParentCenter
     * @param parentFrm
     */
    void showParentCenter(QWidget *parentFrm);

    void SetMessage(const QString &msg, int type);
    void setBackground(const QString &color);
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
private slots:
    void on_btnOk_clicked();
private:
    Ui::frmMessageBox *ui;
    QPoint mousePoint;              //鼠标拖动自定义标题栏时的坐标
    bool mousePressed;              //鼠标是否按下
};

#endif // FRMMESSAGEBOX_H
