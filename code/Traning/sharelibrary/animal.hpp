#ifndef _ANIMAL_HPP
#define _ANIMAL_HPP

typedef unsigned int uint;

class animal
{
private:
    uint m_number;
    uint m_size;
public:
    animal();
    animal(uint num, uint size);
    void setNum(uint num);
    void setSize(uint size);
    uint getNum();
    uint getSize();
    ~animal();
};



#endif