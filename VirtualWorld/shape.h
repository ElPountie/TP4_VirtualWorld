#pragma once
#include <QPointF>
#include <QGraphicsItem>

class Shape
{
public:
	QPointF pos;
	int id;
	static int current_id;

	virtual void draw() = 0;
	virtual QGraphicsItem* getGraphicsItem() const = 0;
	virtual QString type() const = 0 ;
	virtual void move(QPointF pt) = 0;
};


class Circle : public Shape
{
private:
	double radius;
public: 
	Circle();
	Circle(QPointF, double);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;
	void draw();
	void move(QPointF pt);
};

class Carre : public Shape
{
private:
	double cote;
public:
	Carre();
	Carre(QPointF p, double cot);
	QGraphicsItem* getGraphicsItem() const;
	QString type() const;
	void draw();
	void move(QPointF pt);

};

class Rectangle : public Shape
{
private:
	double hauteur, longeur;
public:
	Rectangle();
	Rectangle(QPointF pos, double haut, double lon);
	QGraphicsItem* getGraphicsItem() const;
	QString type() const;
	void draw();
	void move(QPointF pt);

};

class Groupe : public Shape
{
private:
	QVector<Shape*> listOfShape;
public:
	Groupe();
	void add(Shape* sh);
	void remove(Shape* sh);
	QVector<Shape*> getListofShape();
	void draw();
	QGraphicsItem* getGraphicsItem() const;
	QString type() const;
	void move(QPointF pt);
};