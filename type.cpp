#include<iostream>  
#include<string>  
#include <limits>  
using namespace std;  
  
int main()  
{  
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "size:" << sizeof(bool);  
    cout << "\tmax:" << (numeric_limits<bool>::max)();  
    cout << "\t\tmin:" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "size:" << sizeof(char);  
    cout << "\tmax:" << (numeric_limits<char>::max)();  
    cout << "\t\tmin:" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "size:" << sizeof(signed char);  
    cout << "\tmax:" << (numeric_limits<signed char>::max)();  
    cout << "\t\tmin:" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "size:" << sizeof(unsigned char);  
    cout << "\tmax:" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\tmin:" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "size:" << sizeof(wchar_t);  
    cout << "\tmax:" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\tmin:" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "size:" << sizeof(short);  
    cout << "\tmax:" << (numeric_limits<short>::max)();  
    cout << "\t\tmin:" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "size:" << sizeof(int);  
    cout << "\tmax:" << (numeric_limits<int>::max)();  
    cout << "\tmin:" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "size:" << sizeof(unsigned);  
    cout << "\tmax:" << (numeric_limits<unsigned>::max)();  
    cout << "\tmin:" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "size:" << sizeof(long);  
    cout << "\tmax:" << (numeric_limits<long>::max)();  
    cout << "\tmin:" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "size:" << sizeof(unsigned long);  
    cout << "\tmax:" << (numeric_limits<unsigned long>::max)();  
    cout << "\tmin:" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "size:" << sizeof(double);  
    cout << "\tmax:" << (numeric_limits<double>::max)();  
    cout << "\tmin:" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "size:" << sizeof(long double);  
    cout << "\tmax:" << (numeric_limits<long double>::max)();  
    cout << "\tmin:" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "size:" << sizeof(float);  
    cout << "\tmax:" << (numeric_limits<float>::max)();  
    cout << "\tmin:" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "size:" << sizeof(size_t);  
    cout << "\tmax:" << (numeric_limits<size_t>::max)();  
    cout << "\tmin:" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "size:" << sizeof(string) << endl;  
    // << "\tmax:" << (numeric_limits<string>::max)() << "\tmin:" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}