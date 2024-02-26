#include<iostream>
using namespace std;

class PS{
    int phan_thuc, phan_ao;
public:
    PS(int phan_thuc = 0, int phan_ao = 0)
    {
        this->phan_thuc = phan_thuc;
        this->phan_ao =  phan_ao;
    }
    ~PS(){}
    void in()
    {
        cout<< phan_thuc << " + " << phan_ao << "j" << endl;
    }
    PS tong(PS a)
    {
        PS tong;
        tong.phan_thuc = this->phan_thuc + a.phan_thuc;
        tong.phan_ao = this->phan_ao + a.phan_ao;
        return tong;
    }
};

int main()
{
    PS a(3,3), b(5,3), c(-2,7);
    a.in();
    b.in();
    c.in();
    PS tong_2 = a.tong(b);
    PS tong_3 = c.tong(tong_2);
    tong_3.in();
}