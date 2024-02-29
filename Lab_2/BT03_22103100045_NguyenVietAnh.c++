#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class TS{
    string hoten;
    float toan,van;
public:
    TS()
    {
        hoten = "";
        toan = 0; van = 0;
    }
    ~TS(){}
    void nhap()
    {
        cin.ignore();
        cout<<"Nhap ten thi sinh: "; getline(cin, hoten);
        cout<<"Nhap diem toan: ";cin>>toan;
        cout<<"Nhap diem van: ";cin>>van;
    }
    void in()
    {
        cout<<setw(25)<<hoten<<setw(15)<<toan<<setw(15)<<van<<endl;
    }
    friend void nhap_nts(TS a[], int &n);
    friend void in_nts(TS a[], int n);
};
    void tieude()
    {
        cout<<setw(25)<<"Ho ten"<<setw(15)<<"Diem Toan"<<setw(15)<<"Diem Van"<<endl;
    }
    void nhap_nts(TS a[], int &n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\tNhap thong tin thi sinh thu "<<i+1<<endl;
            a[i].nhap();
            for(int j = 0; j < i; j++)
            {
                if(a[i].hoten == a[j].hoten)
                    {
                        cout<<"Thi sinh vua nhap da co ten trong danh sach!"<<endl;
                        cout<<"Thong tin thi sinh la"<<endl;
                            tieude();
                            a[j].in();
                            a[i] = a[i + 1];
                            i--;
                    }
            }
        }
    }
    void in_nts(TS a[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i].hoten > a[j].hoten)
                    swap(a[i], a[j]);
            }
        }
        tieude();
        for(int i = 0; i < n; i++)
            a[i].in();
    }
int main()
{
    TS a[100]; int n;
    cout<<"Nhap so luong sinh vien can quan li: ";cin>>n;
    nhap_nts(a, n);
    cout<<"Thong tin sinh vien sau khi sap xep giam dan"<<endl;
    in_nts(a, n);
}

