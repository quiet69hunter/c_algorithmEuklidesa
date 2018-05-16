/*
04.05.2018      AUTHOR: Roman Herasymchuk
*/
#include <iostream>

using namespace std;
int imp1=0, imp2=0, imp3=0;
int AE1(int a, int b) // first implementation
{

    while (b>0){
            if(a<b){
                swap(a,b);
            }
            a = a-b;
            imp1++;//dominant operation
        }
    return a;
}

int AE2(int a, int b) //second implementation
{
    while(b>0){
        imp2++;//dominant operation
        a = a%b;
        swap(a,b);
    }
    return a;
}

int AE3(int a, int b) //third implementation
{
    int wynik = 1;
    while (b>0){
        imp3++; //dominant operation
        if (a<b) {swap(a,b);}
        else
        if (a%2==0 && b%2==0){
            wynik = wynik * 2;
            a /= 2;
            b /= 2;
            }
        else
        if (a%2==0 && b%2!=0){
            a /= 2;
        }
        else
        if(a%2!=0 && b%2==0){
            b /= 2;
        }
        else
            a -= b;
    }
    wynik = wynik * a;
    return wynik;
}

int main()
{
    int a, b, ae1, ae2, ae3;
    cout<<"A = ";
    cin>>a;
    cout<<"B = ";
    cin>>b;
    ae1 = AE1(a,b);
    ae2 = AE2(a,b);
    ae3 = AE3(a,b);
    cout << "1 implementation  -->  NWD(" << a << "," << b << ") = "<<ae1<<endl;
    cout<<"Count operations in 1 implementation: "<<imp1<<endl;
    cout << "2 implementation  -->  NWD(" << a << "," << b << ") = "<<ae2<<endl;
    cout<<"Count operations in 2 implementation: "<<imp2<<endl;
    cout << "3 implementation  -->  NWD(" << a << "," << b << ") = "<<ae3<<endl;
    cout<<"Count operations in 3 implementation: "<<imp3<<endl;
    return 0;
}
/*
                1test
======================================
A = 155
B = 23
1 implementation  -->  NWD(155,23) = 1
Count operations in 1 implementation: 16
2 implementation  -->  NWD(155,23) = 1
Count operations in 2 implementation: 5
3 implementation  -->  NWD(155,23) = 1
Count operations in 3 implementation: 17
=======================================

                2test
======================================
A = 121
B = 11
1 implementation  -->  NWD(121,11) = 11
Count operations in 1 implementation: 12
2 implementation  -->  NWD(121,11) = 11
Count operations in 2 implementation: 1
3 implementation  -->  NWD(121,11) = 11
Count operations in 3 implementation: 7
======================================
*/
