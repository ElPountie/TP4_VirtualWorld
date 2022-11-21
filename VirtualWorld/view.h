#pragma once
#include "shapemanager.h"
#include "controller.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTreeWidget>


class PaintView : public QGraphicsScene, public Observer//: public QObject
{
	Q_OBJECT
private:
	ShapeManager* shapeManager;
	QVector<QGraphicsItem*> selected;
	QVector<QGraphicsItem*> tools;
	QPointF mousePos;
	QString toolbox;

public:
	PaintView(ShapeManager* = nullptr);

	void updateModel();

protected:

    void drawForeground(QPainter* painter, const QRectF& rect);

public slots:
	void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
};

class TreeView : public Observer
{
private:
	ShapeManager* shapeManager;
	QTreeWidget* treeview;

public:
	TreeView(ShapeManager* = nullptr, QTreeWidget* = nullptr);

	void updateModel();
};
