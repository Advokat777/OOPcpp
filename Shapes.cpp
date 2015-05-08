#include <cstdlib>
#include <iostream>
#include "Shapes.h"

int Shape::count = 0;

Shape::Shape(const std::string& name) : Named(name){
    count++;
}

Shape::Shape(const Shape& shape) : Named(shape){
    count++;
}

int Shape::getCount(){
    return count;
}

Shape::~Shape(){
    count--;
}

Point::Point(const std::string name) : Named(name){
    x = rand() / (double)RAND_MAX;
    y = rand() / (double)RAND_MAX;
}

Point::Point(double x, double y, const std::string name) : Named(name), x(x), y(y){
}

void Point::print(std::ostream& out) const{
    Printable::print(out);
    out << " (x = " << x << " y = " << y << ")";
}

ShapeType Point::getShapeType() const{
    return PointType;
}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

Circle::Circle(const std::string name) : Named(name){
    r = rand() / (double)RAND_MAX;
}

Circle::Circle(const Point& center, double r, const std::string name) : Named(name), center(center), r(r){
}

void Circle::print(std::ostream& out) const{
    Printable::print(out);
    out << " ";
    out << " center = ";
    center.print(out);
    out << " radius = " << r;
    out << " square = " << M_PI*r*r;
}

ShapeType Circle::getShapeType() const{
    return CircleType;
}

Rect::Rect(const std::string name) : Named(name){
}

Rect::Rect(const Point& point1, const Point& point2, const std::string name) : Named(name), point1(point1), point2(point2){
}

void Rect::print(std::ostream& out) const{
    Printable::print(out);
    out << " point1 = ";
    point1.print(out);
    out << " point2 = ";
    point2.print(out);
}

ShapeType Rect::getShapeType() const{
    return RectType;
}

Polyline::Polyline(const std::string name) : Named(name){
    int npoints = (rand() % (MAX_POINTS - 2)) + 3;
    for (int i = 0; i < npoints; i++){
        points.push_back(Point());
    }
}

Polyline::Polyline(const XList<Point>& points, const std::string name) : Named(name), points(points){
}

void Polyline::print(std::ostream& out) const{
    Printable::print(out);
    out << " ";
    XListConstIterator<Point> iter = points.begin();
    Point* prev = NULL;
    double length = 0;
    while (iter.hasNext()){
        Point& p = iter.next();
        p.print(out);
        out << " ";
        if (prev){
            length += sqrt(pow(p.getX() - prev->getX(), 2) + pow(p.getY() - prev->getY(), 2));
        }
        prev = &p;
    }
    out << "len: " << length;
}

ShapeType Polyline::getShapeType() const{
    return PolylineType;
}

Polygon::Polygon(const std::string name) : Named(name){
    int npoints = (rand() % (MAX_POINTS - 2)) + 3;
    for (int i = 0; i < npoints; i++){
        points.push_back(Point());
    }
}

Polygon::Polygon(const XList<Point>& points, const std::string name) : Named(name), points(points){
}

void Polygon::print(std::ostream& out) const{
    Printable::print(out);
    out << " ";
    XListConstIterator<Point> iter = points.begin();
    while (iter.hasNext()){
        Point& p = iter.next();
        p.print(out);
        out << " ";
    }
}

ShapeType Polygon::getShapeType() const{
    return PolygonType;
}
