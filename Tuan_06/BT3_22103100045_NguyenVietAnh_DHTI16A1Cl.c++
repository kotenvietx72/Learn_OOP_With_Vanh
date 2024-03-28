#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class MatHang
{
protected:
    string ma, ten;
    float dongia;
public:
    MatHang()
    {
        ma = ""; ten = ""; dongia = 0;
    }
    MatHang(string ma, string ten, int dongia)
    {
        this->ma = ma;
        this->ten = ten;
        this->dongia = dongia;
    }
    friend istream &operator>> (istream &is, MatHang &a);
};
    istream &operator>> (istream &is, MatHang &a)
    {
        fflush(stdin);
        cout<<"Nhap ma hang: ";getline(is, a.ma);
        cout<<"Nhap ten mat hang: "; getline(is, a.ten);
        cout<<"Nhap don gia: "; is>>a.dongia;
        return is;
    }
class BanhKeo : public MatHang
{
    string sanxuat;
public:
    BanhKeo()
    {
        ma = ""; ten = ""; dongia = 0; sanxuat = "";
    }
    BanhKeo(string ma, string ten, int dongia, string sanxuat)
    {
        this->ma = ma;
        this->ten = ten;
        this->dongia = dongia;
        this->sanxuat = sanxuat;
    }
    float chietkhau()
    {
        return dongia/100;
    }
    friend istream &operator>> (istream &is, BanhKeo &a);
    friend ostream &operator<< (ostream &os, BanhKeo &a);
    string get_ma()
    {
        return ma;
    }
};
    istream &operator>> (istream &is, BanhKeo &a)
    {
        is>>(MatHang&)a;
        fflush(stdin);
        cout<<"Nhap noi san xuat: "; getline(is, a.sanxuat);
        return is;
    }
    ostream &operator<< (ostream &os, BanhKeo &a)
    {
        cout<<setw(20)<<a.ma<<setw(20)<<a.ten<<setw(15)<<a.dongia<<setw(20)<<a.sanxuat<<endl;
        return os;
    }
    void nhap_nBanhKeo(BanhKeo a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\t[!] Nhap thong tin cho banh keo thu "<<i+1<<endl;
            cin>>a[i];
        }
    }
    void in(BanhKeo a[], int n)
    {
        cout<<"\t[!] Danh sach banh keo co ma khác M01"<<endl;
        cout<<setw(20)<<"Ma san pham"<<setw(20)<<"Ten san pham"<<setw(15)<<"Don gia"<<setw(20)<<"Noi san xuat"<<endl;
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_ma() != "M01")
                cout<<a[i];
        }
    }
int main()
{
    BanhKeo a[100]; int n;
    cout<<"\t[?] Nhap so luong mat hang can quan li: "; cin>>n;
    nhap_nBanhKeo(a, n);
    in(a, n);
}
    // Done, hơi lỗi xíu phần cin.ignore()