#include"shared.hpp"

Fish::Fish(std::string  str, uint num, uint size):m_strType(str),animal(num,size)
{
    std::cout << "the function with two paramr for Fish" << std::endl;
    std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
    std::cout << "str = " << str << " num = " << num << " size = " << size <<  std::endl;
}

Fish::Fish()
{
    std::cout << "the function with no paramr for Fish" << std::endl;
    std::cout << "func = " <<  __func__ << " line = " << __LINE__ << std::endl;
}

Fish::~Fish()
{
}