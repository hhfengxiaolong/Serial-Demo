﻿#ifndef NLISTWIDGET_H
#define NLISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QApplication>
#include <QDesktopServices>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileInfo>
#include <QFileIconProvider>
#include <QMessageBox>
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QList>
#include <QUrl>
#include <QByteArray>
#include <QStringList>

class NListWidget : public QListWidget
{
      Q_OBJECT
public:
    NListWidget(QWidget *parent=0);
    void setItemIcon(QListWidgetItem *item,QIcon icon);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
//    void paintEvent(QPaintEvent* event);
private:

    QPoint starPont;
private slots:
    void itemDoubleClickedSlot(QListWidgetItem *item);

};

#endif // NLISTWIDGET_H
