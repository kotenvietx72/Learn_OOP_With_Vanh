#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");
class NGUOI
{
protected:
    string HoTen;
    int NamSinh;
public:
    NGUOI()
    {
        HoTen = ""; NamSinh = 0;
    }
    NGUOI(string HoTen, int NamSinh)
    {
        this->HoTen = HoTen;
        this->NamSinh = NamSinh;
    }
    ~NGUOI(){}
    // Định nghĩa toán tử nhập cho class NGUOI
    friend istream& operator>> (istream &is, NGUOI &a)
    {
        fflush(stdin);
        cout<<"Nhap Ho Va Ten Nguoi: "; getline(is, a.HoTen);
        cout<<"Nhap Nam Sinh: "; is>>a.NamSinh;
        return is;
    }
    // Định nghĩa toán tử xuất cho class NGUOI
    friend ostream& operator<< (ostream &os, NGUOI a)
    {
        os<<setw(20)<<a.HoTen<<setw(15)<<a.NamSinh;
        return os;
    }
};
class SV
{
protected:
    string HanhKiem;
    float Diem;
public:
    SV()
    {
    
        HanhKiem = ""; Diem = 0;
    }
    ~SV(){}
    // Định nghĩa toán tử nhập cho class SV
    friend istream &operator>> (istream &is, SV &a)
    {
        fflush(stdin);
        cout<<"Nhap Hanh Kiem cua sinh vien: "; getline(is, a.HanhKiem);
        cout<<"Nhap diem cua sinh vien: "; is>>a.Diem;
        return is;
    }
    // Định nghĩa toán tử xuất cho class SV
    friend ostream &operator<< (ostream &os, SV a)
    {
        os<<setw(15)<<a.HanhKiem<<setw(10)<<a.Diem;
        return os;
    }
    float get_Diem()
    {
        return Diem;
    }
};
class SVTC : public NGUOI, public SV
{
    float HocPhi;
public:
    // Định nghĩa toán tử nhập cho class SVTC
    friend istream &operator>> (istream &is, SVTC &a)
    {
        is>>(NGUOI&)a;
        is>>(SV&)a;
        cout<<"Nhap Hoc Phi cho sinh vien: "; is>>a.HocPhi;
        return is;
    }
    // Định nghĩa toán tử xuất cho class SV
    friend ostream &operator<< (ostream &os, SVTC a)
    {
        os<<(NGUOI&)a<<(SV&)a;
        os<<setw(15)<<a.HocPhi;
        return os;
    }
    // Hàm Tính Tiền Học Bổng
    float TinhHocBong()
    {
        if(HanhKiem == "Tot" && Diem >= 8.0)
            return 5;
        else if((HanhKiem == "Kha" || HanhKiem == "Tot") && Diem >= 7.0)
            return 3;
        else
            return 0;
    }
    friend void Doc_ThongTin(SVTC a[], int &n);
};
    // Tiêu Đề SVTC
    void tieude()
    {
        output<<setw(20)<<"Ho Va Ten"<<setw(15)<<"Nam Sinh"<<setw(15)<<"Hanh Kiem"<<setw(10)<<"Diem TB"<<setw(15)<<"Hoc Phi";
    }
    // Hàm Đọc Thông Tin
    void Doc_ThongTin(SVTC a[], int &n)
    {
        input>>n;
        for(int i = 0; i < n; i++)
            input>>a[i].HoTen>>a[i].NamSinh>>a[i].HanhKiem>>a[i].Diem>>a[i].HocPhi;
    }
    // Hàm In Toàn Bộ Thông Tinh SVTC Ra Tep
    void In_ThongTin(SVTC a[], int n)
    {
        tieude();
        output<<endl;
        for(int i = 0; i < n; i++)
            output<<a[i]<<endl;
    }
    // Hàm Tìm Sinh Viên Đạt Học Bổng
    void Find_HB(SVTC a[], int n)
    {
        output<<"\t[!] Danh sach SVTC dat duoc hoc bong"<<endl;
        tieude();
        output<<setw(20)<<"So Tien Hoc Bong"<<endl;
        for(int i = 0; i < n; i++)
        {
            if(a[i].TinhHocBong() != 0)
            {
                output<<a[i];
                output<<setw(20)<<a[i].TinhHocBong()<<endl;
            }
        }
    }
    // Hàm Sắp Xếp Sinh VIên có điểm tăng dần
    void In_ThongTin1(SVTC a[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i].get_Diem() > a[j].get_Diem())
                    swap(a[i], a[j]);
            }
        }
        output<<"\t[!] Danh sach SVTC sau khi sap xep tang dan theo diem"<<endl;
        In_ThongTin(a, n);
    }
    void main_chinh()
    {
        SVTC a[100]; int n;
        Doc_ThongTin(a, n);
        output<<"\t[!] Danh sach toan bo SVTC trong tep"<<endl;
        In_ThongTin(a, n);
        Find_HB(a, n);
        In_ThongTin1(a, n);
    }
int main()
{
    main_chinh();
    return 0;
    // Done, vất vả quá =)))))
}