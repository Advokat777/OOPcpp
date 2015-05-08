#ifndef SHAPES_H
#define SHAPES_H
#define _USE_MATH_DEFINES
#include <math.h>
#include "Base.h"
#include "XList.h"

enum ShapeType{
    PointType,
    CircleType,
    RectType,
    PolylineType,
    PolygonType,
    _ShapeTypeLast
};

inline std::string to_string(ShapeType shapeType){
    /*switch (shapeType){
        case PointType:
            return "PointType";
        case CircleType:
            return "CircleType";
        case RectType:
            return "RectType";
        case PolylineType:
            return "PolylineType";
        case PolygonType:
            return "PolygonType";
    }*/
    if (shapeType == PointType){
        return "PointType";
    }
    else{
        if (shapeType == CircleType){
            return "CircleType";
        }
        else{
            if (shapeType == RectType){
                return "RectType";
            }
            else{
                if (shapeType == PolylineType){
                    return "PolylineType";
                }
                else{
                    return "PolygonType";
                }
            }
        }
    }
    return "";
}

class Shape : public virtual Named{
    static int count;

public:
    Shape(const std::string& name = "");
    Shape(const Shape& shape);
    virtual ShapeType getShapeType() const = 0;
    static int getCount();
    virtual ~Shape();
};

class Point : public Shape, public Printable{
    double x;
    double y;

public:
    Point(const std::string name = "point");
    Point(double x, double y, const std::string name = "point");
    void print(std::ostream& out) const;
    ShapeType getShapeType() const;
    double getX() const;
    double getY() const;
};

class Circle : public Shape, public Printable{
    Point center;
    double r;

public:
    Circle(const std::string name = "circle");
    Circle(const Point& center, double r, const std::string name = "circle");
    void print(std::ostream& out) const;
    ShapeType getShapeType() const;
};

class Rect : public Shape, public Printable{
    Point point1;
    Point point2;

public:
    Rect(const std::string name = "rect");
    Rect(const Point& point1, const Point& point2, const std::string name = "rect");
    void print(std::ostream& out) const;
    ShapeType getShapeType() const;
};

class Polyline : public Shape, public Printable{
    XList<Point> points;
    static const int MAX_POINTS = 10;

public:
    Polyline(const std::string name = "polyline");
    Polyline(const XList<Point>& points, const std::string name = "polyline");
    void print(std::ostream& out) const;
    ShapeType getShapeType() const;
};

class Polygon : public Shape, public Printable{
    XList<Point> points;
    static const int MAX_POINTS = 10;

public:
    Polygon(const std::string name = "polygon");
    Polygon(const XList<Point>& points, const std::string name = "polygon");
    void print(std::ostream& out) const;
    ShapeType getShapeType() const;
};
#endif // SHAPES_H
