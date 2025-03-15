#include "observer.h"

class Student : public Observer
{
private:
    string _name;
    string _action; // 接受通知后行为更新
    string _state;

public:
    Student(string name, string action, string state)
    {
        _name = name;
        _action = action;
        _state = state;
    }

    virtual void Update(const string &date)
    {
        if (date == "Thursday")
        {
            cout << _name << " " << _action << endl;
        }
        else
        {
            cout << _name << " Keep " << _state << endl;
        }
    }
};