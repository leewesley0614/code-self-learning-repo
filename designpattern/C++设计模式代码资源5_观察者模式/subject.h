#include "observer.h"

class Subject
{
public:
    virtual ~Subject() {};
    virtual void addObsvr(Observer* obsvr) = 0;
    virtual void delObsvr(Observer* obsvr) = 0;
    virtual void notifyObsvr(string &date) = 0;
};