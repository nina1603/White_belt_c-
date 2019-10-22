#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 5;
    int* b = &a;
    int& c = a;
    cout << "&a = " << &a << endl;
    cout << "b = " << b << endl;
    cout << "&b = " << &b << endl;
    cout << "*b = " << *b << endl;
    cout << "c = " << c << endl;
    cout << "&c = " << &c << endl;
    return 0;
}
/*&a = 0x6dfef8
b = 0x6dfef8
&b = 0x6dfef4
*b = 5
c = 5
&c = 0x6dfef8*/
