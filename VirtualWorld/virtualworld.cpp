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
    connect(ui.Object_RemoveButton, &QPushButton::pressed, this, &VirtualWorld::delShape);
}

VirtualWorld::~VirtualWorld()
{}

void VirtualWorld::delShape()
{
    if (ui.treeWidget->selectedItems().size() != 0) {
        if (paintview->getSelectedNbr() != 0) {
            paintview->saveSelect();
        }
        (ControllerRemove(shapeManager).control(ui.treeWidget->selectedItems()));
        if (paintview->getSelectedNbr() != 0) {
            paintview->setSelect();
        }
    }
    else {
        if (paintview->getSelectedNbr() != 0) {
            paintview->saveSelect();
        }
        (ControllerRemove(shapeManager).control(paintview->getSave()));
        if (paintview->getSelectedNbr() != 0) {
            paintview->setSelect();
        }
    }
}

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
    if (paintview->getSelectedNbr() != 0) {
        paintview->saveSelect();
        paintview->setSelect();
    }
    
}
