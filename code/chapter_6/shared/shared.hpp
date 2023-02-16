#ifndef _SHARED_H__
#define _SHARED_H__
#include"animal.hpp"
#include<iostream>
class Fish : public animal
{
private:
    std::string m_strType;

public:
/*
 子类调用和继承父类的构造函数方法
 1. 如果子类没有显示的调用父类的构造方法，那么会在创建子类的对象时，默认调用父类的默认无参构造函数
    + 此时是无关子类的构造函数，即不管子类是否定义了构造函数，还是显示定义了无参或者有参构造函数
    + 如果此时父类只定义了自己带参的构造函数，则会出现错误
 2. 子类显示调用父类的构造函数，则调用对应的父类的构造函数
*/
    Fish();
    Fish(std::string  str, uint num, uint size);
    ~Fish();
};




#endif