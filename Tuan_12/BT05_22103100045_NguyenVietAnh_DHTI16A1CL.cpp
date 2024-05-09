#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class ISP
{
protected:
    int ThueBaoHangThang;
public:
    virtual void nhap() = 0;
    virtual int Tinh_ThueBaoHangThang() = 0;
    virtual void in() = 0;
    virtual int select() = 0;
};

class DialUp : public ISP
{
    float ThoiGianTruyCap;
public:
    DialUp()
    {
        ThueBaoHangThang = 30000;
        ThoiGianTruyCap = 0;
    }
    void nhap()
    {
        cout<<"Nhap thoi gian truy cap cua khach hang: "; cin>>ThoiGianTruyCap;
    }
    int Tinh_ThueBaoHangThang()
    {
        return ThueBaoHangThang + ThoiGianTruyCap * 30;
    }
    void in()
    {
        cout<<setw(30)<<ThoiGianTruyCap<<setw(25)<<Tinh_ThueBaoHangThang()<<endl;
    }
    int select()
    {
        return 1;
    }
};

class ADSL : public ISP
{
    int DungLuongDuLieu;
public:
    ADSL()
    {
        ThueBaoHangThang = 50000;
        DungLuongDuLieu = 0;
    }
    void nhap()
    {
        cout<<"Nhap dung luong du lieu khach hang da su dung: "; cin>>DungLuongDuLieu;
    }
    int Tinh_ThueBaoHangThang()
    {
        return ThueBaoHangThang + DungLuongDuLieu * 50;
    }
    void in()
    {
        cout<<setw(30)<<DungLuongDuLieu<<setw(25)<<Tinh_ThueBaoHangThang()<<endl;
    }
    int select()
    {
        return 2;
    }
};

class T1 : public ISP
{
public:
    T1()
    {
        ThueBaoHangThang = 2000000;
    }
    void nhap()
    {
        cout<<"\t\t[!] Khong co thong tin gi can nhap"<<endl;
    }
    int Tinh_ThueBaoHangThang()
    {
        return 2000000;
    }
    void in()
    {
        cout<<setw(25)<<ThueBaoHangThang<<endl;
    }
    int select()
    {
        return 3;
    }
};

class KhachHang
{
    string HoTen;
    ISP *tb;
public:
    void nhap()
    {
        string x;
        fflush(stdin);
        cout<<"Nhap ten khach hang: "; getline(cin, HoTen);
        cout<<"Nhap loai thue bao khach hang dang su dung: "; getline(cin, x);
        if(x == "Dial Up")
            tb = new DialUp();
        else if(x == "ADSL")
            tb = new ADSL();
        else
            tb = new T1();
        tb->nhap();
    }
    void in()
    {
        cout<<setw(25)<<HoTen;
        tb->in();
    }
    friend class QuanLy;
};

void tieude_DialUp()
{
    cout<<setw(25)<<"Ho Va Ten"<<setw(30)<<"Thoi Gian Truy Cap"<<setw(25)<<"Thue Bao Hang Thang"<<endl;
}

void tieude_ADSL()
{
    cout<<setw(25)<<"Ho Va Ten"<<setw(30)<<"Dung Luong Du Lieu"<<setw(25)<<"Thue Bao Hang Thang"<<endl;
}

void tieude_T1()
{
    cout<<setw(25)<<"Ho Va Ten"<<setw(25)<<"Thue Bao Hang Thang"<<endl;
}

class QuanLy
{
    KhachHang dskh[30];
    int SoLuongKhachHang;
public:
    /** Hàm nhập thông tin cho n Khách Hàng*/
    void nhap()
    {
        cout<<"\t [?] Nhap so luong khach hang can quan li: "; cin>>SoLuongKhachHang;
        for(int i = 0; i < SoLuongKhachHang; i++)
            {
                cout<<"\t [!] Nhap thong tin cho khach hang thu "<<i+1<<endl;
                dskh[i].nhap();
            }       
    }
    /** Hàm in thông tin cho n Khách Hàng có các kiểu thuê bao khác nhau*/
    void in()
    {
        cout<<"\t\t [!] Thong tin khach hang su dung Dial Up"<<endl;
        tieude_DialUp();
        for(int i = 0; i < SoLuongKhachHang; i++)
        {
            if(dskh[i].tb->select() == 1)
                dskh[i].in();
        }
        cout<<"\t\t [!] Thong tin khach hang su dung ADSL"<<endl;
        tieude_ADSL();
        for(int i = 0; i < SoLuongKhachHang; i++)
        {
            if(dskh[i].tb->select() == 2)
                dskh[i].in();
        }
        cout<<"\t\t [!] Thong tin khach hang su dung T1"<<endl;
        tieude_T1();
        for(int i = 0; i < SoLuongKhachHang; i++)
        {
            if(dskh[i].tb->select() == 3)
                dskh[i].in();
        }
    }
    /** hàm tính tổng tiền cước từng loại thuê bao*/
    void sum_TienCuoc()
    {
        int sum_DialUp = 0, sum_ADSL = 0, sum_T1 = 0;
        for(int i = 0; i < SoLuongKhachHang; i++)
        {
            if(dskh[i].tb->select() == 1)
                sum_DialUp += dskh[i].tb->Tinh_ThueBaoHangThang();
            else if(dskh[i].tb->select() == 2)
                sum_ADSL += dskh[i].tb->Tinh_ThueBaoHangThang();
            else
                sum_T1 += dskh[i].tb->Tinh_ThueBaoHangThang();
        }
        cout<<"\t\t [!] Tong tien cuoc cua thue bao Dial Up la: "<<sum_DialUp<<endl;
        cout<<"\t\t [!] Tong tien cuoc cua thue bao ADSL la: "<<sum_ADSL<<endl;
        cout<<"\t\t [!] Tong tien cuoc cua thue bao T1 la: "<<sum_T1<<endl;
    }
    /** Hàm tính tổng tiền cước của từng loại thuê bao*/
    void sum_TienCuoc2()
    {
        int sum = 0;
        for(int i = 0; i < SoLuongKhachHang; i++)
        {
            sum += dskh[i].tb->Tinh_ThueBaoHangThang();
        }
        cout<<"\t\t [!] Tong tien cuoc cua tat ca cac thue bao la: "<<sum<<endl;
    }
    /** Tìm và xuất thông tin thuê bao ADSL có tiền cước lớn nhất*/
    void search_and_print()
    {
        int index = 0;
        for(int i = 1; i < SoLuongKhachHang; i++)
        {
            if(dskh[i].tb->select() == 2 && dskh[i].tb->Tinh_ThueBaoHangThang() > dskh[index].tb->Tinh_ThueBaoHangThang())
                index = i;
        }
        cout<<"\t\t [!] Thong tin cua thue bao ADSL co tien cuoc lon nhat "<<endl;
        tieude_ADSL();
        dskh[index].in();
    }
};

void main_chinh()
{
    QuanLy a;
    a.nhap();
    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
    a.in();
    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
    a.sum_TienCuoc();
    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
    a.sum_TienCuoc2();
    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
    a.search_and_print();
    cout<<"---------------------------------------------------------------------------------------"<<endl<<endl;
}

int main()
{
    main_chinh();
    // Giờ mới thực sự ổn nha, giờ chạy code nè
}