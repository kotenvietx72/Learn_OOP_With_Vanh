#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

ofstream output("Out.txt");

class ChuyenXe
{
protected:
    string Ma, Name;
    int SoXe, DoanhThu;
public:
    virtual void nhap()
    {
        fflush(stdin);
        cout<<"Nhap ma so chuyen xe: "; getline(cin, Ma);
        cout<<"Nhap ho ten tai xe: "; getline(cin, Name);
        cout<<"Nhap so xe: "; cin>>SoXe;
        cout<<"Nhap doanh thu: "; cin>>DoanhThu;
    }
    virtual void in()
    {
        output<<setw(20)<<Ma<<setw(20)<<Name<<setw(15)<<SoXe;
    }
    int get_DoanhThu()
    {
        return DoanhThu;
    }
};

class NoiThanh : public ChuyenXe
{
    int SoTuyen;
    float SoKmDiDuoc;
public:
    void nhap()
    {
        ChuyenXe::nhap();
        cout<<"Nhap so tuyen cua chuyen xe: "; cin>>SoTuyen;
        cout<<"Nhap so Km di duoc: "; cin>>SoKmDiDuoc;
    }
    void in()
    {
        ChuyenXe::in();
        output<<setw(15)<<SoTuyen<<setw(20)<<SoKmDiDuoc<<setw(15)<<DoanhThu<<endl;
    }
};

class NgoaiThanh : public ChuyenXe
{
    string NoiDen;
    int SoNgayDiDuoc;
public:
    void nhap()
    {
        ChuyenXe::nhap();
        fflush(stdin);
        cout<<"Nhap noi den: "; getline(cin, NoiDen);
        cout<<"Nhap so ngay di duoc: "; cin>>SoNgayDiDuoc;
    }
    void in()
    {
        ChuyenXe::in();
        output<<setw(20)<<NoiDen<<setw(20)<<SoNgayDiDuoc<<setw(15)<<DoanhThu<<endl;
    }
};

// Nhập n_ChuyenXe vào cùng 1 mảng
void nhap_nChuyenXe(ChuyenXe *a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int select = 0;
        cout<<"\t\t\t------ DANH SACH THAO TAC ------"<<endl;
        cout<<"\t\t[1] Nhap thong tin cho Chuyen Xe noi thanh"<<endl
            <<"\t\t[2] Nhap thong tin cho Chuyen Xe ngoai thanh"<<endl
            <<"\t\t[3] Thoat chuong trinh"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>select;
        if(select == 1)
        {
            a[i] = new NoiThanh();
            a[i]->nhap();
        }
        else if(select == 2)
        {
            a[i] = new NgoaiThanh();
            a[i]->nhap();
        }
        else if(select == 3)
        {
            cout<<"\t\t[!] Thoat chuong trinh...."<<endl;
            return;
        }
        else
        {
            cout<<"\t\t[!] Ban nhap sai yeu cau!"<<endl
                <<"\t\t[!] Vui long thuc hien lai lua chon"<<endl;
            i--;
        }
    }
}

// In n_ChuyenXeNoiThanh vào file + tổng doanh thu
void in_nChuyenXeNoiThanh(ChuyenXe *a[], int n)
{
    output<<"\t\t\t ------ THONG TIN CAC CHUYEN XE NOI THANH ------"<<endl;
    output<<setw(20)<<"Ma So Chuyen Xe"<<setw(20)<<"Ho Ten Tai Xe"<<setw(15)<<"Bien So Xe"<<setw(15)<<"So Tuyen"<<setw(20)<<"So Km Di Duoc"<<setw(15)<<"Doanh Thu"<<endl;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<NoiThanh*>(a[i]) == nullptr)
            a[i]->in();
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<NoiThanh*>(a[i]) == nullptr)
            sum += a[i]->get_DoanhThu();
    }
    output<<"\t\t\t[!] Doanh Thu cua cac chuyen xe Noi Thanh la: "<<sum<<endl;
}

// In n_ChuyenXeNgoaiThanh vào file + tổng doanh thu
void in_nChuyenXeNgoaiThanh(ChuyenXe *a[], int n)
{
    output<<"\t\t\t ------ THONG TIN CAC CHUYEN XE NGOAI THANH ------"<<endl;
    output<<setw(20)<<"Ma So Chuyen Xe"<<setw(20)<<"Ho Ten Tai Xe"<<setw(15)<<"Bien So Xe"<<setw(20)<<"Noi Den"<<setw(20)<<"So Ngay Di Duoc"<<setw(15)<<"Doanh Thu"<<endl;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<NgoaiThanh*>(a[i]) == nullptr)
            a[i]->in();
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<NgoaiThanh*>(a[i]) == nullptr)
            sum += a[i]->get_DoanhThu();
    }
    output<<"\t\t\t[!] Doanh Thu cua cac chuyen xe Ngoai Thanh la: "<<sum<<endl;
}

// Hàm chính của toi nha
void main_chinh()
{
    ChuyenXe *a[100]; int n;
    cout<<"\t[?] Nhap vao so luong chuyen xe can quan li: "; cin>>n;
    while(true)
    {
        int select = 0;
        cout<<"\t\t\t ---------- DANH SACH THUC HIEN ----------"<<endl;
        cout<<"\t\t[1] Nhap danh sach "<<n<<" chuyen xe"<<endl
            <<"\t\t[2] In thong tin cac xe Noi Thanh"<<endl
            <<"\t\t[3] In thong tin cac xe Ngoai Thanh"<<endl
            <<"\t\t[4] Thoat chuong trinh"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>select;
        if(select == 1)
        {
            nhap_nChuyenXe(a, n);
        }
        else if(select == 2)
        {
            in_nChuyenXeNoiThanh(a, n);
            cout<<"\t\t[!] Da in thong tin vao file!"<<endl;
        }
        else if(select == 3)
        {
            in_nChuyenXeNgoaiThanh(a, n);
            cout<<"\t\t[!] Da in thong tin vao file!"<<endl;
        }
        else 
        {
            cout<<"\t[!] Thoat chuong trinh...."<<endl;
            break;
        }
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
    }
}

int main()
{
    main_chinh();
}
// Code vẫn chạy ổn nhưng hơi hề tí