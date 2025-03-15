#ifndef LIST_H_
#define LIST_H_
template <class Item>
class List
{
private:
    static const int MAXSIZE = 100;
    Item *pt;
    int length;

public:
    List();  // create a empty list
    ~List(); // destroy a list
    void Clear();
    void PassData(Item *item);
    int GetLocation(Item i);
    int GetLength();
    void Insert(int location = length, Item i);
    void Delete(int location);
    bool isEmpty();
    bool isFull();
};

#endif