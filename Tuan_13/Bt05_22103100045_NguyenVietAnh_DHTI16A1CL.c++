#include<iostream>
using namespace std;

template <class T>
class Math
{
    T a, b;
public:
    Math(T a, T b)
    {
        this-> a = a;
        this-> b = b;
    }
    T add()
    {
        return a + b;
    }
    T sub()
    {
        return a - b;
    }
    T mul()
    {
        return a * b;
    }
    float div()
    {
        while(b == 0)
        {
            cout<<"\t [!] Gia tri cua b khong hop le!"<<endl;
            cout<<"[?] Nhap lai gia tri cua b: "; cin>>b;
        }
        return (float)a / b;
    }
    T max()
    {
        return (a > b)? a : b;
    }
    void in()
    {
        cout<<"First: "<<a<<"\t Second: "<<b<<endl;
        cout<<"\t [!] Ket qua cua phep cong: "<<add()<<endl;
        cout<<"\t [!] Ket qua cua phep tru: "<<sub()<<endl;
        cout<<"\t [!] Ket qua cua phep nhan: "<<mul()<<endl;
        cout<<"\t [!] Ket qua cua phep chia: "<<div()<<endl;
    }
};
int main()
{
    Math<int> math1(5, 7);
    math1.in();
    cout<<"\t [!] So lon nhat trong hai so la: "<<math1.max()<<endl;

    Math<int> math2(8, 0);
    math2.in();
    cout<<"\t [!] So lon nhat trong hai so la: "<<math2.max()<<endl;

    Math<float> math3(7.8, 3.4);
    math3.in();
    cout<<"\t [!] So lon nhat trong hai so la: "<<math3.max()<<endl;

    // Tạm ổn ròi nha, dù cái TH bằng 0 k ổn lắm
}
