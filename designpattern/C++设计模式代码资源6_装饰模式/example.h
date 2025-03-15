#include <string>
#include <iostream>
using namespace std;
// 1. 抽象组件类，提供被装饰者的行为
class AbstractSubject
{
public:
    virtual void show() = 0; // show行为
    string str;
};
// 2. 具体组件类，实现被装饰者的行为
class User : public AbstractSubject
{
public:
    User() { this->str = "英雄初始化"; }
    void show() override
    {
        cout << this->str << endl;
    }
};

// 3. 抽象装饰器
class Decorator : public AbstractSubject{
    protected:
    AbstractSubject* pBase_;
    public:
    Decorator(AbstractSubject* pBase):pBase_(pBase){};
    virtual void show()=0;
};

// 4. 具体装饰器：为具体的组件添加责任
// Decorator1
class Decorator1 : public Decorator{
    public:
    Decorator1(AbstractSubject* user):Decorator(user){};
    void show() override{
        this->str = this->pBase_->str + "英雄之铠甲";
        cout << this->str << endl;
    }
};
// Decorator2
class Decorator2 : public Decorator{
    public:
    Decorator2(AbstractSubject* user):Decorator(user){};
    void show() override{
        this->str = this->pBase_->str + "英雄之护膝";
        cout << this->str << endl;
    }
};