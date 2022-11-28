#include "ShapeFactory.h"

ShapeFactory::ShapeFactory(ShapeManager* sm) : shapeManager(sm)
{
}

void ShapeFactory::create(QString shape)
{
    ControllerAdd(shapeManager).control(shape);
}
