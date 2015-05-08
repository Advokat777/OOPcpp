#include <iostream>
#include "Base.h"

Named::Named(const std::string& name) : name(name){
}

std::string Named::getName() const{
    return name;
}

Named::~Named(){
}

Printable::Printable(const std::string& name) :
    Named(name){
}

void Printable::print(std::ostream& out) const{
    out << getName();
}

Printable::~Printable(){
}

std::ostream& operator<<(std::ostream& out, const Printable& p){
    out << "[ ";
    p.print(out);
    out << " ]";
    return out;
}
