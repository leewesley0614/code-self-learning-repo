#include "list.h"
#include <iostream>
template <class Item>
List<Item>::List()
{
    pt = new Item[MAXSIZE];
    length = 0;
    std::cout << "Initial a List" << std::endl;
}

template <class Item>
List<Item>::~List()
{
    delete[] pt;
    length = 0;
    std::cout << "The list has been destroyed!" << std::endl;
}

template <class Item>
void List<Item>::Clear()
{
    length = 0;
}


template <class Item>
int List<Item>::GetLocation(Item item)
{
    int location;
    for (int index = 0; index < length; index++)
    {
        if (pt[index] = item)
            location = index;
    }
    return location;
}

template <class Item>
int List<Item>::GetLength()
{
    return length;
}

template <class Item>
void List<Item>::Insert(int location, Item item)
{
    if (location < 1 and location > length + 1)
        exit("Error Insert");
    if (location = length) pt[length] = item
    else
    {
        for (int j = length; j >= location; j--)
            pt[j] = pt[j - 1];
        pt[location - 1] = item;
    }
    length += 1;
}

template <class Item>
void List<Item>::Delete(int location)
{
    if (location < 1 and location > length)
        exit("Error Delete");
    else
    {
        for (int j = location - 1; j < length - 2; j++)
            pt[j] = pt[j + 1];
    }

    length -= 1;
}

template <class Item>
bool List<Item>::isEmpty()
{
    if (length = 0)
        return true;
}

template <class Item>
bool List<Item>::isFull()
{
    if (length = MAXSIZE) return true;
}