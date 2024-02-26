#include<iostream>
using namespace std;

class PS{
    int tu_so, mau_so;
public:
    PS(int tu_so = 0, int mau_so = 0)
    {
        this->mau_so = mau_so;
        this->tu_so = tu_so;
    }
    ~PS(){}
    void rutgon()
    {
        int a = tu_so, b = mau_so;
        while(a != b)
        {
            if(a > b)
                a = a - b;
            else    
                b = b - a;
        }
        tu_so = tu_so / a;
        mau_so = mau_so / a;
    }
    void in()
    {
        rutgon();
        cout<< tu_so << "/" << mau_so <<endl;
    }
};
int main()
{
    PS a(7,4), b(4,8);
    a.rutgon(); b.rutgon();
    cout<<"Phan so a la: "; a.in();
    cout<<"Phan so b la: "; b.in();
}
// DONE