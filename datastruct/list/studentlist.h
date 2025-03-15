#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_
#define OK 1;
#define ERROR 0;
typedef bool Status;

#include <string>
#include <iostream>

const int MAXSIZE = 100;
struct Student
{
    std::string name;   // 姓名
    std::string number; // 学号
    int age;            // 年龄
    bool operator==(Student s)
    {
        if (name != s.name)
            return false;
        else if (number != s.number)
            return false;
        else if (age != s.age)
            return false;
        else
            return true;
    }

    bool operator!=(Student s)
    {
        return !(*this == s);
    }

    void Generator()
    {
        std::cout << "Enter a Student Information(Name, Number, age):" << std::endl;
        getline(std::cin, name);
        getline(std::cin, number);
        std::cin >> age;
        std::cin.get();
    }

    void show()
    {
        std::cout << "Name: " << name << ", Number: " << number << ", Age:" << age <<std::endl;
    }
};

// 定义顺序表结构
typedef struct
{
    Student *data;
    int length;
} List;

// 顺序表的初始化
Status listInitial(List &l)
{
    l.data = new Student[MAXSIZE];
    l.length = 0;
    if (l.data)
        return OK else return ERROR;
}
// 创建顺序表
Status listCreate(List &l, int n)
{
    if (n < 1 and n > MAXSIZE)
        return ERROR;
    for (int id = 0; id < n; id++)
    {
        l.data[id].Generator();
    }
    l.length = n;
    return OK;
}

// 顺序表的销毁
Status listDestroy(List &l)
{
    delete[] l.data;
    l.length = 0;
    if (!l.data)
        return OK else return ERROR;
}

// 顺序表的清空
Status listClear(List &l)
{
    l.length = 0;
    return OK;
}

// 获取顺序表的长度
int getLength(List &l)
{
    return l.length;
}

// 获取位置为i的元素
Status getElem(List &l, int i, Student &s)
{
    if (i < 0 || i > l.length - 1)
        return ERROR else
        {
            s = l.data[i];
            return OK;
        }
}

// 查找元素e的位置
Status getLocation(List &l, Student e, int &location)
{
    int id = 0;
    while (l.data[id] != e)
    {
        id++;
    }
    if (id >= l.length)
        return ERROR else
        {
            location = id;
            return OK;
        }
}

// 在位置i插入元素e
Status Insert(List &l, int i, Student e)
{
    if (i < 0 || i > l.length)
        return ERROR;
    if (i == l.length)
        {
            l.data[i] = e;
            l.length +=1;
        }
    else
    {
        for (int j = l.length; j > i; j--)
        {
            l.data[j] = l.data[j - 1];
        }
        l.data[i] = e;
        l.length += 1;
    }
    return OK;
}

// 删除位置i的元素
Status Delete(List &l, int i)
{
    if (i < 0 || i > l.length - 1)
        return ERROR;
    if (i == l.length - 1)
        l.length -= 1;
    else
    {
        for (int j = i; j < l.length - 1; j++)
        {
            l.data[j] = l.data[j + 1];
        }
        l.length -= 1;
    }
    return OK;
}

Status listShow(List &l)
{
    if (l.length == 0) 
    {
        std::cout << "There is an empty Student List" << std::endl;
        return ERROR;
    }
    else{
        for(int i = 0; i < l.length; i++)
        {
            std::cout << "Student#" <<(i+1)<<": ";
            l.data[i].show();
        }
        return OK;
    }
}

//
#endif