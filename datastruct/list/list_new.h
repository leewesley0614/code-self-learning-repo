#include <iostream>
#define MAXSIZE 100
// 定义一个顺序表
typedef struct SList
{
    int *data;  // data
    int length; // length
} SList;

// Initialize a SList
void InitSList(SList &sl)
{
    sl.data = new int[MAXSIZE];
    sl.length = 0;
}
// Destroy a SList
void DestSList(SList &sl)
{
    delete[] sl.data;
    sl.length = 0;
}
// Clear a SList
void ClearSList(SList &sl)
{
    sl.length = 0;
}

// Get the element located i
int GetElem(SList &sl, int loc)
{
    return sl.data[loc];
}
// Get the location of the element
int GetLoc(SList &sl, int elem)
{
    for (int i = 0; i < sl.length; i++)
    {
        if (sl.data[i] == elem)
            return i;
    }
}
// pass data to the SList
void Pass(SList &sl, int n)
{
    sl.length = n;
    for (int i = 0; i < sl.length; i++)
    {
        std::cout << "Enter the Element#" << (i + 1) << std::endl;
        std::cin >> sl.data[i];
    }
}

// Insert an element at location i
bool Insert(SList &sl, int loc, int elem)
{
    if (loc < 0 || loc > sl.length)
        return false;
    if (loc = sl.length)
    {
        sl.data[loc] = elem;
        sl.length += 1;
    }
    else
    {
        for (int i = sl.length; i > loc; i--)
        {
            sl.data[i] = sl.data[i - 1];
        }
        sl.data[loc] = elem;
        sl.length += 1;
    }
    return true;
}

// Delete the elem at location i
bool Delete(SList &sl, int loc, int &elem)
{
    if (loc < 0 || loc > sl.length - 1)
        return false;
    if (loc = sl.length - 1)
    {
        elem = sl.data[loc];
        sl.length -= 1;
    }
    else
    {
        elem = sl.data[loc];
        for (int i = loc; i < sl.length - 1; i++)
        {
            sl.data[i] = sl.data[i + 1];
        }
        sl.length -= 1;
    }
    return true;
}

