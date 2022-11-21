#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_virtualworld.h"
#include "view.h"

class VirtualWorld : public QMainWindow
{
    Q_OBJECT

public:
    VirtualWorld(QWidget *parent = nullptr, ShapeManager* = nullptr);
    ~VirtualWorld();

public slots:
    void addShape();

private:
    Ui::VirtualWorldClass ui;
    PaintView* paintview;
    ShapeManager* shapeManager;
    TreeView* treeview;
};
