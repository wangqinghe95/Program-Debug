#include<iostream>
using namespace std;

double func(double num1, double num2) {
    if(0 == num1) {
        throw num1;
    }
    return num2/num2;
}

int func(int num){
    throw num;
}

int main()
{
    int num = -1;
    string str = "12";
    while (num <= 5)
    {
        num++;
        try
        {
            if(num == 0) {
                func(num, 2);
            }
            else if (num == 1){
                func(num);
            }
            else if(num == 2) {
                char ch = str.at(100);
                cout << "ch : " << ch << endl;
            }
            else if(num == 3) {
                throw "num = 3";
            }
            else if(num == 4) {
                char ch = str[num];
                cout << "ch : " << ch << endl;
            }
        }
        catch(int e)
        {
            cout << "int e: " << e << endl;
            cout << "num: " << num << endl;
        }
        catch(double e) {
            cout << "double e: " << e << endl;
            cout << "num: " << num << endl;
        }
        catch(const char* e) {
            cout << "string e: " << e << endl;
            cout << "num: " << num << endl;
        }
        catch(exception &e) {
            cout << "out of range" << endl;
        }
        
    }

    cout << "over" << endl;
    return 0;
    
}