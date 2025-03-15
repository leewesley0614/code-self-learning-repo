#include "studentlist.h"

int main()
{
    List l;

    listInitial(l);
    int l_length = getLength(l);
    std::cout << "the length of list l: " << l_length << std::endl;

    listCreate(l, 2);
    l_length = getLength(l);
    std::cout << "the length of list l: " << l_length << std::endl;
    listShow(l);

    Student s1 = {"Foo Qiuling", "600000000", 23};

    Insert(l, 2, s1);
    listShow(l);
    l_length = getLength(l);
    std::cout << "the length of list l: " << l_length << std::endl;

    Delete(l, 0);
    listShow(l);
    l_length=getLength(l);
    std::cout << "the length of list l: " << l_length << std::endl;

    Student s2;
    getElem(l, 1, s2);
    std::cout << "the student#1: ";
    s2.show();

    int location;
    getLocation(l, s1, location);
    std::cout << "the location of student s1 is" << location <<std::endl;

    listClear(l);
    std::cout << "the length of list l: " << l_length << std::endl;

    listDestroy(l);
    return 0;
}