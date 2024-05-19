#include<iostream>
using namespace std;

template <class T>
class MyPair
{
    T a, b;
public:
    MyPair(T a, T b)
    {
        this-> a = a;
        this-> b = b;
    }
    void print()
    {
        cout<<"First: "<<a<<" \t Second: "<<b<<endl;
    }
    T GetMax()
    {
        return (a > b)? a : b;
    }
};

int main()
{
    MyPair<int> Mypair1(5, 10);
    Mypair1.print();
    cout<<"\t [!] So lon nhat trong hai so nguyen la: "<<Mypair1.GetMax()<<endl;

    MyPair<float> Mypair2(7.6, 5.4);
    Mypair2.print();
    cout<<"\t [!] So lon nhat trong hai so thuc la: "<<Mypair2.GetMax()<<endl;

    MyPair<char> Mypair3('X', 'a');
    Mypair3.print();
    cout<<"\t [!] Chu cai lon nhat trong hai chu la: "<<Mypair3.GetMax()<<endl;
    // Done
}