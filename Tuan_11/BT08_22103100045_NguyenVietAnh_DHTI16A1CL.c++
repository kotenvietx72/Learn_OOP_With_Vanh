#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

ofstream of("File.txt");

class MatHang
{
protected:
    string Name;
    int Sl;
public:
    virtual int Ketqua() = 0;
    void nhapkho()
    {
        fflush(stdin);
        cout<<"Nhap ten mat hang can nhap: "; getline(cin, Name);
        cout<<"Nhap so luong mat hang: "; cin>>Sl;
    }
    void xuatkho()
    {
        int x;
        cout<<"\t[?] Nhap so luong san pham can xuat khoi kho: "; cin>>x;
        while(x > Sl)
        {
            cout<<"\t\t[!] So luong san pham ban nhap vuot qua so luong san pham trong kho!"<<endl;
            cout<<"[?] Nhap lai so luong san pham can xuat kho: "; cin>>x;
        }
        Sl-=x;
        cout<<"\t[!] Ban da xuat "<<x<<" mat hang "<<Name<<" ra khoi kho!"<<endl
            <<"\t[!] So luong con lai la: "<<Sl<<endl;
    }
    void inthongtin()
    {
        cout<<setw(25)<<Name<<setw(20)<<Sl<<endl;
    }
    void inthongtin_file()
    {
        of<<setw(25)<<Name<<setw(20)<<Sl<<endl;
    }
    string get_Name()
    {
        return Name;
    }
    int get_Sl()
    {
        return Sl;
    }
};

class MatHangNhapKhau : public MatHang
{
    float Thue;
public:
    int Ketqua()
    {
        return 1;
    }
    void set_Thue(float Thue)
    {
        this->Thue = Thue;
    }
};

class MatHangDaiLy : public MatHang
{
    float HoaHong;
public:
    int Ketqua()
    {
        return 2;
    }
    void set_HoaHong(float HoaHong)
    {
        this->HoaHong = HoaHong;
    }
};

void nhap_nMatHang(MatHang *a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int select = 0;
        cout<<"\t\t\t -------- DANH SACH THAO TAC --------"<<endl
            <<"\t\t [1] Nhap kho mat hang nhap khau "<<endl
            <<"\t\t [2] Nhap kho mat hang dai ly "<<endl
            <<"\t\t [3] Thoat nhap"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>select;
        while(select < 1 || select > 3)
        {
            cout<<"\t[!] Lua chon khong hop le"<<endl
                <<"\t[?] Vui long nhap lai lua chon: "; cin>>select;
        }
        if(select == 1)
        {
            a[i] = new MatHangNhapKhau();
            a[i]->nhapkho();
        }
        else if(select == 2)
        {
            a[i] = new MatHangDaiLy();
            a[i]->nhapkho();
        }
        else
        {
            return;
        }
    }
}

void xuat_MatHang(MatHang *a[], int n)
{
    string name; bool check = false; int index = -1;
    fflush(stdin);
    cout<<"\t[?] Nhap ten mat hang can xuat kho: "; getline(cin, name);
    while(check == false)
    {    
        for(int i = 0; i < n; i++)
        {
            if(a[i]->get_Name() == name)
                {
                    check = true;
                    index = i;
                }
        }
        if(check == false)
        {
            cout<<"\t\t[!] Mat hang "<<name<<" khong co trong danh sach kho hang"<<endl
                <<"\t[?] Vui long nhap lai ten mat hang: "; getline(cin, name);
        }
    }
    cout<<"\t\t ----- THONG TIN MAT HANG -----"<<endl
        <<"\t[!] Ten mat hang: "<<a[index]->get_Name()<<endl
        <<"\t[!] So luong: "<<a[index]->get_Sl()<<endl;
    a[index]->xuatkho();
}

void tieude()
{
    cout<<setw(10)<<"STT"<<setw(25)<<"Ten mat hang"<<setw(20)<<"So luong"<<endl;
}

void baocaosl(MatHang *a[], int n)
{
    cout<<"\t\t[!] Thong tin cac mat hang co o trong kho"<<endl;
    tieude();
    for(int i = 0; i < n; i++)
    {
        cout<<setw(10)<<i+1;
        a[i]->inthongtin();
    }
}

void baocaosl_NhapKhau(MatHang *a[], int n)
{
    cout<<"\t\t[!] Thong tin cac mat hang nhap khau co o trong kho"<<endl;
    tieude();
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<MatHangNhapKhau*>(a[i]) != NULL)
        {
            cout<<setw(10)<<dem+1;
            a[i]->inthongtin();
            dem++;
        }
    }
}

void baocaosl_DaiLy(MatHang *a[], int n)
{
    cout<<"\t\t[!] Thong tin cac mat hang dai ly co o trong kho"<<endl;
    tieude();
    int dem = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<MatHangDaiLy*>(a[i]) != NULL)
        {
            cout<<setw(10)<<dem+1;
            a[i]->inthongtin();
            dem++;
        }
    }
}

void tieude_file()
{
    of<<setw(10)<<"STT"<<setw(25)<<"Ten mat hang"<<setw(20)<<"So luong"<<endl;
}

void in_file(MatHang *a[], int n)
{
    of<<"\t\t\t ----- DANH SACH CAC MAT HANG TRONG KHO -----"<<endl;
    tieude_file();
    for(int i = 0; i < n; i++)
    {
        of<<setw(10)<<i+1;
        a[i]->inthongtin_file();
    }
    of<<"--------------------------------------------------------------------------------"<<endl;
    of<<"\t\t\t ----- DANH SACH CAC MAT HANG NHAP KHAU TRONG KHO -----"<<endl;
    tieude_file();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<MatHangNhapKhau*>(a[i]) != NULL)
        {
            of<<setw(10)<<i+1;
            a[i]->inthongtin_file();
        }
    }
    of<<"--------------------------------------------------------------------------------"<<endl;
    of<<"\t\t\t ----- DANH SACH CAC MAT HANG DAI LY TRONG KHO -----"<<endl;
    tieude_file();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<MatHangDaiLy*>(a[i]) != NULL)
        {
            of<<setw(10)<<i+1;
            a[i]->inthongtin_file();
        }
    }
    cout<<"\t[!] Ban da in ra file"<<endl;
}

void main_chinh()
{
    MatHang *a[100]; int n;
    cout<<"\t[?] Nhap so luong mat hang can quan ly: "; cin>>n;
    while(true)
    {
        int select = 0;
        cout<<"\t\t\t ~~~~~~ DANH SACH THAO TAC ~~~~~~"<<endl
            <<"\t\t[1] Nhap hang vao kho"<<endl
            <<"\t\t[2] Xuat hang ra kho"<<endl
            <<"\t\t[3] In thong tin cac mat hang o trong kho"<<endl
            <<"\t\t[4] In thong tin cac mat hang nhap khau o trong kho"<<endl
            <<"\t\t[5] In thong tin cac mat hang dai ly o trong kho"<<endl
            <<"\t\t[6] In thong tin cac mat hang ra file"<<endl
            <<"\t\t[7] Thoat chuong trinh"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>select;
        while(select < 1 || select > 7)
        {
            cout<<"\t[!] Lua chon cua ban khong hop le: "; cin>>select;
            cout<<"\t[?] Nhap lai lua chon cua ban: "; cin>>select;
        }
        switch (select)
        {
            case 1:
            {
                nhap_nMatHang(a, n);
                break;
            }
            case 2:
            {
                xuat_MatHang(a, n);
                break;
            }
            case 3:
            {
                baocaosl(a, n);
                break;
            }
            case 4:
            {
                baocaosl_NhapKhau(a, n);
                break;
            }
            case 5:
            {
                baocaosl_DaiLy(a, n);
                break;
            }
            case 6:
            {
                in_file(a, n);
                break;
            }
            case 7:
            {
                return;
            }
        }
    }
}

int main()
{
    main_chinh();
}