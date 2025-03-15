#include "subject.h"
#include <list>
class ConcreteSubject : public Subject{
    private: 
    list<Observer*>* _observer; //抽象通知机制
    public:
    ConcreteSubject(){_observer = new list<Observer*>;}
    virtual void addObsvr(Observer* obsvr){
        _observer->push_back(obsvr);
    }
    virtual void delObsvr(Observer* obsvr){
        if(_observer->size() > 0){
            _observer->remove(obsvr);
        }
    }
    virtual void notifyObsvr(string &date){ //发布通知
        cout << "Today: " << date << endl;
        list<Observer*>::iterator iter = _observer->begin();
        while(iter != _observer->end()){
            (*iter)->Update(date); //观察者更新
            iter++;
        }
    }
};
