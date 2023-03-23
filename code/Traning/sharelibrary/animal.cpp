#include"animal.hpp"
#include<iostream>

animal::animal():m_number(0),m_size(0)
{
    std::cout << "this is no param construct functio for animal" << std::endl;
    std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
    std::cout << "m_number = " <<  m_number << " m_size = " << m_size << std::endl;
}

animal::animal(uint num, uint size):m_number(num),m_size(size)
{
    std::cout << "this is a construct function with two param for animal" << std::endl;
    std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
    std::cout << "m_number = " <<  m_number << " m_size = " << m_size << std::endl;

}


animal::~animal()
{
    m_number = 0;
    m_size = 0;
}

void animal::setNum(uint num)
{
    m_number = num;
}
void animal::setSize(uint size)
{
    m_size = size;
}
uint animal::getNum()
{
    return m_number;
}
uint animal::getSize()
{
    return m_size;
}