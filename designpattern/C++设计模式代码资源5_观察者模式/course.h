#include <iostream>
#include <string>
#include <list>
class Observer;
// --------------------------------------------------------------------------
class Subject // subject
{
public:
    virtual ~Subject() {};
    virtual void RegisterObser(Observer *obsvr) = 0;      // 登记Observer
    virtual void RemoveObser(Observer *obsve) = 0;        // 删除Observer
    virtual void NotifyObser(const std::string &msg) = 0; // 通知Observer
};
// --------------------------------------------------------------------------
class Observer // observer
{
public:
    virtual ~Observer() {};
    virtual void Update(const std::string &msg) = 0; // 更新状态
    virtual std::string getName() = 0;

protected:
    Observer() {};
};
// --------------------------------------------------------------------------
class QQGroup : public Subject // concrete subject
{
private:
    std::list<Observer *> *_observers;

public:
    QQGroup() { _observers = new std::list<Observer *>(); }
    virtual void RegisterObser(Observer *obsvr); // inherent method
    virtual void RemoveObser(Observer *obsvr);
    virtual void NotifyObser(const std::string &msg);
};

void QQGroup::RegisterObser(Observer *obsvr)
{
    _observers->push_back(obsvr);
}

void QQGroup::RemoveObser(Observer *obsvr)
{
    if (_observers->size() > 0)
    {
        _observers->remove(obsvr);
    }
}

void QQGroup::NotifyObser(const std::string &msg) // 发布通知
{
    std::cout << "Group Message " << msg << std::endl;
    std::list<Observer *>::iterator iter = _observers->begin();
    while (iter != _observers->end())
    {
        (*iter)->Update(msg);
        iter++;
    }
}
// --------------------------------------------------------------------------
class RoomMate : public Observer // concrete Observer
{
private:
    std::string _name;
    std::string _action;
    std::string _now;

public:
    RoomMate(std::string name, std::string now, std::string action)
    {
        _name = name;
        _action = action;
        _now = now;
    }
    virtual void Update(const std::string& msg){
        std::cout << "This is " << _name << std::endl;
        if(msg == "Call the roll"){
            std::cout << "Action: " << _action
            << std::endl << std::endl;
        }
        else{
            std::cout << "Go on: "<< _now
            << std::endl << std::endl;
        }
    }
    virtual std::string getName(){
        return this->_name;
    }
};