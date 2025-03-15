#pragma once
#include<string>
#include<iostream>
using namespace std;

class Observer{
    public:
    virtual ~Observer(){};
    virtual void Update(const string &date) = 0;// pure virtual method
};