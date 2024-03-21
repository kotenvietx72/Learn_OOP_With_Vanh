#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

ofstream output("Text.txt");
class OTO
{
    string ma, ten;
    float dongia, dungtich, trongluong;
public:
    OTO(string ma = "", string ten = "", float dongia = 0, float dungtich = 0, float trongluong = 0)
    {
        this->ma = ma;
        this->ten = ten;
        this->dongia = dongia;
        this->dungtich = dungtich;
        this->trongluong = trongluong;
    }
    ~OTO(){}
    float tien_van_chuyen()
    {
        if(trongluong>2)
            return 100000;
        else if(trongluong > 1)
            return 50000;
        else
            return 30000;
    }
    friend istream &operator>> (istream &is, OTO &a);
    friend ostream &operator<< (ostream &os, OTO a);
    bool operator== (float a)
    {
        return this->dungtich == a;
    }
    string get_name()
    {
        return ten;
    }
    bool operator< (OTO a)
    {
        return this->dongia < a.dongia;
    }
    friend void max(OTO a[], int n);
};
    void tieude()
    {
        output<<setw(20)<<"Ma hang"<<setw(20)<<"Ten hang san xuat"<<setw(10)<<"Don gia"<<setw(15)<<"Dung tich"<<setw(15)<<"Trong luong"<<endl;
    }
    istream &operator>> (istream &is, OTO &a)
    {
        cin.ignore();
        cout<<"Nhap ma hang: "; getline(is, a.ma);
        cout<<"Nhap ten hang san xuat: "; getline(is, a.ten);
        cout<<"Nhap don gia san pham: "; is>>a.dongia;
        cout<<"Nhap dung tich san pham: "; is>>a.dungtich;
        cout<<"Nhap trong luong san pham: "; is>>a.trongluong;
        return is;
    }
    ostream &operator<< (ostream &os, OTO a)
    {
        os<<setw(20)<<a.ma<<setw(20)<<a.ten<<setw(10)<<a.dongia<<setw(15)<<a.dungtich<<setw(15)<<a.trongluong<<endl;
        return os;
    }
    void nhap_nOTO(OTO a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\t[!] Nhap thong tin cho o to thu "<<i+1<<endl;
            cin>>a[i];
        }
    }
    void in_nOTO(OTO a[], int n)
    {
        tieude();
        for(int i = 0; i < n; i++)
        {
            output<<a[i];
        }
        cout<<"\t[!] Danh sach o to da duoc in vao tep Text.txt"<<endl;
    }
    void in_nOTO_1(OTO a[], int n)
    {
        output<<"\t[!] Thong tin o to co dung tich xilanh bang 2.5"<<endl;
        tieude();
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 2.5)
                output<<a[i];
        }
        cout<<"\t[!] Da in thong tin o to co dung tich xilanh bang 2.5 ra file"<<endl;
    }
    void check_name(OTO a[], int &n)
    {
        bool check = false; int index = -1;
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_name() == "TOYOTA")
            {
                check = true;
                index = i;
                break;
            }
        }
        if(check == true)
        {
            for(int i = index; i < n; i++)
                a[i] = a[i + 1];
            n--;
            cout<<"\t[!] Danh sach da co o to co ten hang san xuat la TOYOTA"<<endl;
        }
        else
        {
            for(int i = n; i > 0; i--)
                a[i] = a[i - 1];
            n++;
            cout<<"\t[!] Danh sach chưa co o to co ten hang san xuat la TOYOTA"<<endl;
            cout<<"\t[?] Nhap thong tin cho o to"<<endl;
            cin>>a[0]; 
        }
        in_nOTO(a, n);
    }
    void max(OTO a[], int n)
    {
        output<<"\t[!] Danh sach o to"<<endl;
        in_nOTO(a, n);
        int index = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[index] < a[i])
            {
                index = i;
            }
        }
        output<<"\t[!] Thong tin OTO co don gia lon nhat"<<endl;
        tieude();
        output<<a[index];
    }
int main()
{
    OTO a[100]; int n;
    cout<<"Nhap so luong o to can quan li: "; cin >> n;
    nhap_nOTO(a, n);
    max(a, n);
}