#ifndef BASE_H
#define BASE_H
#include <string>

class Named{
    std::string name;

public:
    Named(const std::string& name);
    std::string getName() const;
    virtual ~Named();
};

class Printable : public virtual Named{
public:
    Printable(const std::string& name = "");
    virtual void print(std::ostream& out) const;
    virtual ~Printable();
};

std::ostream& operator<<(std::ostream& out, const Printable& p);
#endif // BASE_H
