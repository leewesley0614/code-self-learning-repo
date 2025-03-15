#include "example.h"

int main(){
    // 英雄初始化
    User* me = new User();
    me->show();

    // 穿铠甲
    Decorator1* pme1 = new Decorator1(me); 
    pme1->show();
    // 穿护膝
    Decorator2* pme2 = new Decorator2(me);
    pme2->show();
    // 穿铠甲和护膝
    Decorator2* pme3 = new Decorator2(pme1);
    pme3->show();

    delete me;
    delete pme1;
    delete pme2;
    delete pme3;
    
    return 0;
}