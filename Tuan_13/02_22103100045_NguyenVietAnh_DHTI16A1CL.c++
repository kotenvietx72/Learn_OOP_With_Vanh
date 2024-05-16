#include<iostream>
using namespace std;

class PhanSo
{
    int TuSo, MauSo;
public:
    PhanSo()
    {
        TuSo = 0; MauSo = 1;
    }
    friend istream& operator>> (istream &is, PhanSo &a)
    {
        cout<<"Nhap tu so: "; is>>a.TuSo;
        cout<<"Nhap mau so: "; is>>a.MauSo;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo a)
    {
        os<<a.TuSo<<" / "<<a.MauSo;
        return os;
    }
    friend bool operator <(PhanSo a, PhanSo b)
    {
        return a.TuSo * b.MauSo < b.TuSo * a.MauSo;
    }
    friend PhanSo operator +(PhanSo a, PhanSo b)
    {
        PhanSo x;
        x.TuSo = a.TuSo * b.MauSo + b.TuSo * a.MauSo;
        x.MauSo = a.MauSo * b.MauSo;
        int min = 0;
        min = (x.TuSo < x.MauSo)? x.TuSo: x.MauSo;
        for(int i = min; i > 1; i--)
        {
            if(x.TuSo % i == 0 && x.MauSo % i == 0)
            {
                x.TuSo /= i;
                x.MauSo /= i;
                break;
            }
        }
        return x;
    }
    friend bool operator !=(PhanSo a, PhanSo b)
    {
        return a.TuSo != b.TuSo || a.MauSo != b.MauSo;
    }
};

class SoPhuc
{
    int PhanThuc, PhanAo;
public:
    SoPhuc()
    {
        PhanThuc = 0; 
        PhanAo = 0;
    }
    friend istream& operator>> (istream &is, SoPhuc &a)
    {
        cout<<"Nhap phan thuc: "; is>>a.PhanThuc;
        cout<<"Nhap phan ao: "; is>>a.PhanAo;
        return is;
    }
    friend ostream& operator<< (ostream &os, SoPhuc a)
    {
        os<<a.PhanThuc<<" + " <<a.PhanAo<< " * i";
        return os;
    }
    friend bool operator <(SoPhuc a, SoPhuc b)
    {
        return a.PhanThuc < b.PhanThuc && a.PhanAo < b.PhanAo;
    }
    friend SoPhuc operator +(SoPhuc a, SoPhuc b)
    {
        SoPhuc sum;
        sum.PhanThuc = a.PhanThuc + b.PhanThuc;
        sum.PhanAo = a.PhanAo + b.PhanAo;
        return sum;
    }
    friend bool operator !=(SoPhuc a, SoPhuc b)
    {
        return a.PhanThuc != b.PhanThuc || a.PhanAo != b.PhanAo;
    }
};

/** Hàm nhập n phần tử*/
template <class T>
void nhap_n(T a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"\t [!] Nhap thong tin cho phan tu thu "<<i+1<<endl;
        cin>>a[i];
    }
}
/** Hàm in n phần tử*/
template <class T>
void in_n(T a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
}

/** Tìm phần tử lớn nhất trên mảng*/
template <class T>
T Max (T a[], int n)
{
    T max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(max < a[i])
            max = a[i];
    }
    return max;
}

/** Tính tổng các phần tử*/
template <class T>
T Sum (T a[], int n)
{
    T sum = a[0];
    for(int i = 1; i < n; i++)
        sum = sum + a[i];
    return sum;
}

/** Đổi chỗ hai phần tử*/
template <class T>
void Change(T &a, T &b)
{
    T index = a;
    a = b;
    b = index;
}

/** Sắp xếp các phần tử theo chiều tăng dần*/
template <class T>
void Arrange(T a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[i])
                Change(a[i], a[j]);
        }
    }
    cout<<"\t [!] Danh sach sau khi sap xep tang dan"<<endl;
    in_n(a, n);
}

/** Đếm phần tử khác giá trị cho trước*/
template <class T>
void Count(T a[], int n, T b)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b)
            count++;
    }
    cout<<"\t [!] So luong phan tu khac gia tri "<<b<<" la: "<<count<<endl;
}

/** Tìm phần tử theo giá trị X được nhập vào*/
template <class T>
void Find(T a[], int n)
{
    T b;
    cout<<"[?] Nhap gia tri can tim kiem "<<endl; cin>>b;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if((a[i] != b) == false)
            count++;
    }
    if(count == 0)
        cout<<"\t [!] Khong co gia tri can tim kiem trong mang"<<endl;
    else
        cout<<"\t [!] Co tong cong "<<count<<" gia tri "<<b<<" trong mang"<<endl;
}

/** Xoá phần tử trên mảng tại vị trí k*/
template <class T>
void Delete(T a[], int &n)
{
    int k = -1;
    cout<<"[?] Nhap vao vi tri can xoa: "; cin>>k;
    for(int i = k - 1; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    cout<<"\t [!] Danh sach sau khi xoa phan tu"<<endl;
    in_n(a, n);
}

/** Chèn thêm phần tử tại vị trí k*/
template <class T>
void Insert(T a[], int &n)
{
    int k = -1;
    cout<<"[?] Nhap vi tri can chen them phan tu: "; cin>>k;
    for(int i = n; i >= k; i--)
    {
        a[i] = a[i - 1];
    }
    n++;
    T x;
    cout<<"Nhap thong tin cho phan tu duoc chen!"<<endl;
    cin>>x;
    a[k - 1] = x;
    cout<<"\t [!] Danh sach sau khi them phan tu"<<endl;
    in_n(a, n);
}

void main_PhanSo()
{
    PhanSo a[100]; int m;
    cout<<"\t [!] Nhap so luong phan so can kiem tra: "; cin>>m;
    nhap_n(a, m);
    cout<<"\t [!] Thong tin cac phan tu da nhap"<<endl;
    in_n(a, m);
    cout<<"Phan tu lon nhat trong mang la: "<<Max(a, m)<<endl;
    cout<<"Tong cac phan tu trong mang la: "<<Sum(a, m)<<endl;
    Arrange(a, m);
    PhanSo k;
    cout<<"\t [?] Nhap vao phan so can kiem tra "<<endl; cin>>k;
    Count(a, m, k);
    Find(a, m);
    Delete(a, m);
    Insert(a, m);
    // Done rồi nha
}

void main_SoPhuc()
{
    SoPhuc a[100]; int m;
    cout<<"\t [!] Nhap so luong so phuc can kiem tra: "; cin>>m;
    nhap_n(a, m);
    cout<<"\t [!] Thong tin cac phan tu da nhap"<<endl;
    in_n(a, m);
    cout<<"Phan tu lon nhat trong mang la: "<<Max(a, m)<<endl;
    cout<<"Tong cac phan tu trong mang la: "<<Sum(a, m)<<endl;
    Arrange(a, m);
    SoPhuc k;
    cout<<"\t [?] Nhap vao so phuc can kiem tra "<<endl; cin>>k;
    Count(a, m, k);
    Find(a, m);
    Delete(a, m);
    Insert(a, m);
}
int main()
{
    //main_PhanSo();
    main_SoPhuc();
}