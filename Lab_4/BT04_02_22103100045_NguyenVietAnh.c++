#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class MAYTINH
{
    string ma, ten;
    int dongia, dungluong;
    float trongluong;
public:
    MAYTINH(string ma = "", string ten = "", int dongia = 0, int dungluong = 0, float trongluong = 0)
    {
        this->ma = ma;
        this->ten = ten;
        this->dongia = dongia;
        this->dungluong = dungluong;
        this->trongluong = trongluong;
    }
    ~MAYTINH(){}
    friend istream &operator>> (istream &is, MAYTINH &a);
    friend ostream &operator<< (ostream &os, MAYTINH a);
    friend void kiemtra(MAYTINH a[], int &n);
    int tien_van_chuyen()
    {
        if(trongluong > 2)
            return 100000;
        else if(trongluong > 1)
            return 50000;
        else    
            return 30000;
    }
    bool operator== (int a)
    {
        if(dungluong == a)
            return true;
        return false;
    }
    bool operator> (MAYTINH a)
    {
        if(this->trongluong > a.trongluong)
            return true;
        return false;
    }
};
    istream &operator>> (istream &is, MAYTINH &a)
    {
        cin.ignore();
        cout<<"Nhap ma hang: "; getline(is, a.ma);
        cout<<"Nhap ten hang san xuat: "; getline(is, a.ten);
        cout<<"Nhap don gia may tinh: "; is>>a.dongia;
        cout<<"Nhap dung luong may tinh: "; is>>a.dungluong;
        cout<<"Nhap trong luong may tinh: "; is>>a.trongluong;
        return is;
    }
    ostream &operator<< (ostream &os, MAYTINH a)
    {
        os<<setw(15)<<a.ma<<setw(20)<<a.ten<<setw(15)<<a.dongia<<setw(15)<<a.dungluong<<setw(15)<<a.trongluong<<endl;
        return os;
    }
    void tieude()
    {
        cout<<setw(15)<<"Ma hang"<<setw(20)<<"Ten hang san xuat"<<setw(15)<<"Don gia"<<setw(15)<<"Dung luong"<<setw(15)<<"Trong luong"<<endl;
    }
    void in(MAYTINH a[], int n)
    {
        tieude();
        for(int i = 0; i < n; i++)
            cout<<a[i];
    }
    /** In thông tin máy tính có bộ nhớ RAM bằng 16*/
    void in1(MAYTINH a[], int n)
    {
        cout<<"\t[!] Thong tin may tinh co bo nho RAM bang 16"<<endl;
        tieude();
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 16)
                cout<<a[i];
        }
    }
    /** In thông tin máy tính sắp xếp tăng dần theo trọng lượng*/
    void in2(MAYTINH a[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] > a[j])
                    swap(a[i], a[j]);
            }
        }
        cout<<"\t[!] Danh sach may tinh sap xep tang dan ve trong luong"<<endl;
        tieude();
        for(int i = 0; i < n; i++)
            cout<<a[i];
    }
    /** Kiểm tra tên hãng SONY, chưa có thì chèn vào đầu danh sách, có rồi thì xóa khỏi danh sách*/
    void kiemtra(MAYTINH a[], int &n)
    {
        bool check = false; int index = -1;
        for(int i = 0; i < n; i++)
        {
            if(a[i].ten == "SONY")
                {
                    check = true; index = i;
                    break;
                }
        }
        if(check == false)
        {
            cout<<"\t[!] Danh sach khong co may nao co hang SONY"<<endl;
            n++;
            for(int i = n - 1; i > 0; i--)
            {
                a[i] = a[i - 1];
            }
            cout<<"\t[!] Nhap thong tin cho may tinh co hang SONY"<<endl;
            cin>>a[0];
            in(a, n);
        }
        else
        {
            cout<<"\t[!] Danh sach co may cua hang SONY"<<endl;
            for(int i = index; i < n; i++)
                a[i] = a[i + 1];
            n--;
            in(a, n);
        }
    }
int main()
{
    MAYTINH a[100]; int n;
    cout<<"Nhap so luong may tinh can quan li: "; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<"\t[?] Nhap thong tin cho may tinh thu "<<i+1<<endl;
        cin>>a[i];
    }
    kiemtra(a, n);
}