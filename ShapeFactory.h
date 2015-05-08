#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "Shapes.h"

class ShapeFactory{
public:
    static Shape* createShape(ShapeType shapeType);
};
#endif // SHAPEFACTORY_H
