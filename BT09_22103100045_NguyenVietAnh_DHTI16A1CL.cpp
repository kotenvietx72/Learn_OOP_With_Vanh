#include<iostream>
#include<math.h>
using namespace std;

class PhanSo{
    int TuSo, MauSo;
public:
    PhanSo()
    {
        TuSo = 0; MauSo = 0;
    }
    friend istream& operator >>(istream &is, PhanSo &a)
    {
        cout<<"[?] Nhap tu so: "; is>>a.TuSo;
        cout<<"[?] Nhap mau so: "; is>>a.MauSo;
        return is;
    }
    friend ostream& operator <<(ostream &os, PhanSo a)
    {
        os<<a.TuSo<<" / "<<a.MauSo<<"\t";
        return os;
    }
    friend bool operator <(PhanSo a, PhanSo b)
    {
        return ((a.TuSo * 1.0 / a.MauSo) < (b.TuSo * 1.0 / b.MauSo));
    }
    friend PhanSo operator +(PhanSo a, PhanSo b)
    {
        PhanSo T;
        T.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo;
        T.MauSo = a.MauSo * b.MauSo;
        int min = (T.TuSo < T.MauSo)? T.TuSo : T.MauSo;
        for(int i = min; i > 1; i--)
        {
            if(T.TuSo % i == 0 && T.MauSo % i == 0)
            {
                T.TuSo /= i;
                T.MauSo /= i;
                break;
            }
        }
        return T;
    }
};

class SoPhuc
{
    int PhanThuc, PhanAo;
public:
    SoPhuc()
    {
        PhanThuc = 0; PhanAo = 0;
    }
    friend istream& operator >>(istream &is, SoPhuc &a)
    {
        cout<<"[?] Nhap phan thuc: "; is>>a.PhanThuc;
        cout<<"[?] Nhap phan ao: "; is>>a.PhanAo;
        return is;
    }
    friend ostream& operator <<(ostream &os, SoPhuc a)
    {
        os<<a.PhanThuc<<" + "<<a.PhanAo<<"i\t";
        return os;
    }
    friend bool operator <(SoPhuc a, SoPhuc b)
    {
        return sqrt(a.PhanThuc * a.PhanThuc + a.PhanAo * a.PhanAo) < sqrt(b.PhanThuc * b.PhanThuc + b.PhanAo * b.PhanAo);
    }
    friend SoPhuc operator +(SoPhuc a, SoPhuc b)
    {
        SoPhuc T;
        T.PhanThuc = a.PhanThuc + b.PhanThuc;
        T.PhanAo = a.PhanAo + b.PhanAo;
        return T;
    }
};

/** Hàm nhập m x n phần tử T*/
template <class T>
void nhap(T a[100][100], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<"\t [!] Nhap thong tin cho phan tu ["<<i + 1<<"]["<<j + 1<<"]"<<endl;
            cin>>a[i][j];
        }
    }
}

/** Hàm in m x n phần tử T */
template <class T>
void in(T a[100][100], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

/** Tìm phần tử lớn nhất trên mảng 2 chiều*/
template <class T>
T Max(T a[100][100], int m, int n)
{
    T max = a[0][0];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(max < a[i][j])
                max = a[i][j];
        }
    }
    return max;
}

/** Tính tổng các phần tử trên đường chéo chính*/
template <class T>
T Sum(T a[100][100], int m, int n)
{
    T sum = a[0][0];
    for(int i = 1; i < m && i < n; i++)
        sum = sum + a[i][i];
    return sum;
}

/** Sắp xếp các phần tử trên đường chéo chính theo chiều tăng dần*/
template <class T>
void SapXep(T a[100][100], int m, int n)
{
    for(int i = 0; i < m - 1 && i < n - 1; i++)
    {
        for(int j = i + 1; j < m && j < n; j++)
        {
            if(a[j][j] < a[i][i])
                swap(a[i][i], a[j][j]);
        }
    }
    cout<<"\t\t [!] Danh sach sau khi sap xep tang dan tren duong cheo chinh"<<endl;
    in(a, m, n);
}

void main_PhanSo()
{
    PhanSo a[100][100]; int m, n;
    cout<<"\t [?] Nhap so hang: "; cin>>m;
    cout<<"\t [?] Nhap so cot: "; cin>>n;
    nhap(a, m, n);
    cout<<"\t\t [!] Danh sach mang sau khi nhap"<<endl;
    in(a, m, n);
    cout<<"\t\t [!] Phan so lon nhat trong mang la: "<<Max(a, m, n)<<endl;
    cout<<"\t\t [!] Tong cac phan so tren duong cheo chinh: "<<Sum(a, m, n)<<endl;
    SapXep(a, m, n);
}

void main_SoPhuc()
{
    SoPhuc a[100][100]; int m, n;
    cout<<"\t [?] Nhap so hang: "; cin>>m;
    cout<<"\t [?] Nhap so cot: "; cin>>n;
    nhap(a, m, n);
    cout<<"\t\t [!] Danh sach mang sau khi nhap"<<endl;
    in(a, m, n);
    cout<<"\t\t [!] So phuc lon nhat trong mang la: "<<Max(a, m, n)<<endl;
    cout<<"\t\t [!] Tong cac so phuc tren duong cheo chinh: "<<Sum(a, m, n)<<endl;
    SapXep(a, m, n);
}
int main()
{
    main_PhanSo();
    main_SoPhuc();
}