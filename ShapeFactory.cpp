#include "ShapeFactory.h"

Shape* ShapeFactory::createShape(ShapeType shapeType){
    /*switch (shapeType){
        case PointType:
            return new Point();
        case RectType:
            return new Rect();
        case CircleType:
            return new Circle();
        case PolylineType:
            return new Polyline();
        case PolygonType:
            return new Polygon();
    }*/
    if (shapeType == PointType){
        return new Point();;
    }
    else{
        if (shapeType == CircleType){
            return new Circle();
        }
        else{
            if (shapeType == RectType){
                return new Rect();
            }
            else{
                if (shapeType == PolylineType){
                    return new Polyline();
                }
                else{
                    return new Polygon();
                }
            }
        }
    }
    return NULL;
}
