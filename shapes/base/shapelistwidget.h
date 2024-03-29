/*
 * @Author: MRXY001
 * @Date: 2019-11-29 15:53:37
 * @LastEditors: MRXY001
 * @LastEditTime: 2019-11-29 17:30:58
 * @Description: 左边的新装单元列表框
 */
#ifndef SHAPELISTWIDGET_H
#define SHAPELISTWIDGET_H

#include <QObject>
#include <QApplication>
#include <QListWidget>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>
#include <QDrag>
#include "globalvars.h"
#include "shapebase.h"
#include "fileutil.h"
#include "bytearrayutil.h"

#define MOVING_CURSOR_NAME tr("指针") // 选择控件的鼠标列表项的名字

class ShapeListWidget : public QListWidget
{
	Q_OBJECT
public:
    ShapeListWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void loadShapes();                     // 加载所有形状
    void loadOneShape(const QString name); // 从文件中读取一个形状
    
signals:
	
public slots:
    void slotItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    QList<ShapeBase *> shape_units; // 加载的形状单元（主窗口左边列表）

    QPoint _drag_start_pos;
    bool _has_draged;
};

#endif // SHAPELISTWIDGET_H
