#include<iostream>
using namespace std;

class DaThuc3
{
    int bac3, bac2, bac1, bac0;
public:
    DaThuc3(int bac3 = 0, int bac2 = 0, int bac1 = 0, int bac0 = 0)
    {
        this->bac3 = bac3;
        this->bac2 = bac2;
        this->bac1 = bac1;
        this->bac0 = bac0;
    }
    friend istream &operator>> (istream &is, DaThuc3 &a);
    friend ostream &operator<< (ostream &os, DaThuc3 a);
    DaThuc3 operator+ (DaThuc3 a)
    {
        DaThuc3 dathuc3;
        dathuc3.bac3 = this->bac3 + a.bac3;
        dathuc3.bac2 = this->bac2 + a.bac2;
        dathuc3.bac1 = this->bac1 + a.bac1;
        dathuc3.bac0 = this->bac0 + a.bac0;
        return dathuc3;
    }
    DaThuc3 operator- (DaThuc3 a)
    {
        DaThuc3 dathuc3;
        dathuc3.bac3 = this->bac3 - a.bac3;
        dathuc3.bac2 = this->bac2 - a.bac2;
        dathuc3.bac1 = this->bac1 - a.bac1;
        dathuc3.bac0 = this->bac0 - a.bac0;
        return dathuc3;
    }
};
    istream &operator>> (istream &is, DaThuc3 &a)
    {
        cout<<"Nhap he so bac 3: "; is>>a.bac3;
        cout<<"Nhap he so bac 2: "; is>>a.bac2;
        cout<<"Nhap he so bac 1: "; is>>a.bac1;
        cout<<"Nhap he so bac 0: "; is>>a.bac0;
        return is;
    }
    ostream &operator<< (ostream &os, DaThuc3 a)
    {
        os<<a.bac3<<"x^3 + "<<a.bac2<<"x^2 + "<<a.bac1<<"x + "<<a.bac0<<endl;
        return os;
    }
int main()
{
    DaThuc3 a, b, tong, hieu;
    cout<<"\t[?] Nhap thong tin cho da thuc thu nhat "<<endl;
    cin>>a;
    cout<<"\t[?] Nhap thong tin cho da thuc thu hai "<<endl;
    cin>>b;
    tong = a + b;
    hieu = a - b;
    cout<<"Da thuc thu nhat vua nhap la: "<<a;
    cout<<"Da thuc thu hai vua nhap la: "<<b;
    cout<<"Tong cua hai da thuc la: "<<tong;
    cout<<"Hieu cua hai da thuc la: "<<hieu;
    // DONE
}
