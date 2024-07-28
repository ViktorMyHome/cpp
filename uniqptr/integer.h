#include <stdio.h>

class Integer {
private:
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    ~Integer();
    Integer(const Integer &obj);//but here we should pass an object by value
    //Integer(Integer &&obj);//move constructor
    int GetValue()const;
    void SetValue(int value);
    void PrintValue();
};