#include "virtualworld.h"
#include "controller.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm)
    : QMainWindow(parent), shapeManager(sm)
{
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttonsd
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
    connect(ui.Object_GroupButton, &QPushButton::pressed, paintview, &PaintView::groupShape);
}

VirtualWorld::~VirtualWorld()
{}

void VirtualWorld::addShape()
{
    if (ui.radioButton_Circle->isChecked()) {
        (ControllerAdd(shapeManager).control("Circle"));
    }
    else if (ui.radioButton_Rectangle->isChecked()) {
        (ControllerAdd(shapeManager).control("Rectangle"));
    }
    else if (ui.radioButton_Square->isChecked()) {
        (ControllerAdd(shapeManager).control("Square"));
    }
}
