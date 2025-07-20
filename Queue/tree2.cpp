#include<iostream>
using namespace std;

void sub(int *b)
{
    cout<<endl<<"value of b : "<<*b;
}

void add(int *a)
{

    cout<<a;
    sub(a);
}

int main()
{
    int a=2;
    add(&a);

}