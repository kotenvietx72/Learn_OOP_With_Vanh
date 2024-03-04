#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct SV
{
    int sbd;
    string name;
    float toan, li, hoa, tong;
};
class SVien
{
    SV sv;
public:
    /** Khởi tạo không tham số*/
    SVien()
    {
        sv.sbd = 0;
        sv.name = "";
        sv.toan = 0; sv.li = 0; sv.hoa = 0; sv.tong = 0;
    }
    /** Khởi tạo có tham số*/
    SVien(int sbd, string name, int toan, int li, int hoa, int tong)
    {
        this->sv.sbd = sbd;
        this->sv.name = name;
        this->sv.toan = toan;
        this->sv.li = li;
        this->sv.hoa = hoa;
        this->sv.tong = tong;
    }
    /** Hàm huỷ*/
    ~SVien(){}
    /** Hàm nhập thông tin cho một sinh viên*/
    void nhap()
    {
        cin.ignore();
        cout<<"Nhap so bao danh: ";cin>>sv.sbd;
        cin.ignore();
        cout<<"Nhap ten: "; getline(cin,sv.name);
        cout<<"Nhap diem toan: ";cin>>sv.toan;
        cout<<"Nhap diem li: ";cin>>sv.li;
        cout<<"Nhap diem hoa: ";cin>>sv.hoa;
        sv.tong = sv.toan + sv.li + sv.hoa;
    }
    /** Hàm in thông tin cho một sinh viên*/
    void in()
    {
        cout<<setw(15)<<sv.sbd<<setw(20)<<sv.name<<setw(10)<<sv.toan<<setw(10)<<sv.li<<setw(10)<<sv.hoa<<setw(10)<<sv.tong<<endl;
    }
    float get_tong()
    {
        return sv.tong;
    }
};
    void tieude()
    {
        cout<<setw(15)<<"So bao danh"<<setw(20)<<"Ho va ten"<<setw(10)<<"Diem toan"<<setw(10)<<"Diem li"<<setw(10)<<"Diem hoa"<<setw(10)<<"Tong diem"<<endl;
    }
    /** Hàm nhập n sinh viên*/
    void nhap_nSV(SVien a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\tNhap thong tin cho sinh vien "<<i+1<<endl;
            a[i].nhap();
        }
    }
    /** Hàm in n sinh viên*/
    void in_nSV(SVien a[], int n)
    {
        tieude();
        for(int i = 0; i < n; i++)
        {
            a[i].in();
        }
    }
    /** Hàm in thông tin sinh vien trung tuyen*/
    void in_nSV_trungtuyen(SVien a[], int n)
    {
        cout<<"\tDANH SACH SINH VIEN TRUNG TUYEN!"<<endl;
        tieude();
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_tong() >= 20)
            {
                a[i].in();
            }
        }
    }
    /** Hàm in thông tin sinh viên thủ khoa*/
    void in_thukhoa(SVien a[], int n)
    {
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_tong() > a[max].get_tong())
                max = i;
        }
        cout<<"\tTHONG TIN SINH VIEN THU KHOA"<<endl;
        tieude();
        a[max].in();
    }
int main()
{
    SVien a[100]; int n;
    cout<<"Nhap so luong sinh vien can quan li: ";cin>>n;
    nhap_nSV(a, n);
    in_nSV_trungtuyen(a, n);
    in_thukhoa(a, n);
    // DONE
}