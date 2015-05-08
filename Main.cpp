#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include "Shapes.h"
#include "ShapeFactory.h"

int main(){
    const int n = 20;
    XList<Shape*> shapes;
    long ltime = time(NULL);
    size_t stime = (unsigned) ltime/2;
    srand(stime);
    for (int i = 0; i < n; i++){
        shapes.push_back(ShapeFactory::createShape((ShapeType)(rand() % (int)_ShapeTypeLast)));
    }
    std::cout << "total shapes: " << Shape::getCount() << std::endl;
    std::map<ShapeType, XList<Shape*> > shapesByType;
    XListConstIterator<Shape*> iter = shapes.begin();
    while (iter.hasNext()){
        Shape* next = iter.next();
        shapesByType[next->getShapeType()].push_back(next);
    }
    for (std::map<ShapeType, XList<Shape*> >::iterator it = shapesByType.begin(); it != shapesByType.end(); it++){
        XListConstIterator<Shape*> iter = it->second.begin();
        std::cout << "shape type: " << to_string(it->first) << std::endl;
        while (iter.hasNext()){
            Shape* next = iter.next();
            std::cout << dynamic_cast<Printable&>(*next) << std::endl;
            delete next;
        }
        std::cout << std::endl;
    }
    shapes.clear();
    std::cout << "total shapes: " << Shape::getCount() << std::endl;
    return 0;
}

