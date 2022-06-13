#include<iostream>
#include<string>
// #include<cstring>
using namespace std;
int main(int argc, char* argv[])
{
    cout << "argc : " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        string strOut = "argv[" + to_string(i) + "] = " + argv[i];
        cout << strOut << endl;
    }

    int breakPoint = 0;

    cout << "argc : " << argc << endl;
    for (int i = 0; i < argc; ++i) {
        string strOut = "argv[" + to_string(i) + "] = " + argv[i];
        cout << strOut << endl;
    }

    return 0;
}