#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class GV{
    char ht[30], bc[15], cn[20];
    int t; float bl;
public:
    GV()
    {
        strcpy(this->ht,"");
        strcpy(this->bc,"");
        strcpy(this->cn,"");
        t = 0; bl = 0;
    }
    ~GV(){
        cout<<"Da xoa giao vien"<<endl;
    }
    void nhap()
    {
        cout<<"Nhap ten giao vien: "; cin.getline(ht, 30);
        cout<<"Nhap bang cap giao vien: "; cin.getline(bc, 15);
        cout<<"Nhap chuyen nganh giao vien: "; cin.getline(cn, 20);
        cout<<"Nhap tuoi giao vien: "; cin>>t;
        cout<<"Nhap bac luong: ";cin>>bl;
    }
    void in()
    {
        cout<<setw(30)<<ht<<setw(10)<<t<<setw(15)<<bc<<setw(20)<<cn<<setw(15)<<bl<<endl;
    }
    void tinhluong()
    {
        float luong = bl * 1490;
        cout<<"Luong cua giao vien la: "<<luong<<endl;
    }
};
int main()
{
    GV a, b;
    a.nhap();
    cout<<setw(30)<<"Ho ten"<<setw(10)<<"Tuoi"<<setw(15)<<"Bang cap"<<setw(20)<<"Chuyen nganh"<<setw(15)<<"Bac luong"<<endl;
    a.in();
    b.in();
    a.tinhluong();
}