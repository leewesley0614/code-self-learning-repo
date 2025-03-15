#include "linklist.h"

int main()
{
    // 创建一个链表
    LinkList l = new Lnode;
    // 初始化一个链表
    l_listInit(l);

    if (isEmpty(l))
        std::cout << "This is an empty linklist!" << std::endl;
    std::cout<<std::endl;

    headCreate(l, 5);
    std::cout<<std::endl;
    for (int i = 1; i <= 5; i++)
    {
        Item e;
        getElem(l, i, e);
        std::cout << "Elem#" << i << ": " << e << std::endl;
    }
    std::cout<<std::endl;

    Insert(l, 3, 10);
    for (int i = 1; i <= 6; i++)
    {
        Item e;
        getElem(l, i, e);
        std::cout << "Elem#" << i << ": " << e << std::endl;
    }
    std::cout<<std::endl;

    Item e;
    Delete(l, 4, e);
    std::cout << "the elem deleted: " << e <<std::endl;
    std::cout<<std::endl;

    for(int i = 1; i <= Getlength(l); i++){
        Item s;
        getElem(l, i, s);
        std::cout << "Elem#" << i << ": " << s << std::endl;
    }
    return 0;
}