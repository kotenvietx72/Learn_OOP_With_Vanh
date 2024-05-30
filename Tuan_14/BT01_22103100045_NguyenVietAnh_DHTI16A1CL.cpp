#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Basic
{
protected:
    int ThoiGianGoi, DonGiaGoi, LuuLuong, DonGiaInternet;
public:
    Basic()
    {
        ThoiGianGoi = 0;
        DonGiaGoi = 1000;
        LuuLuong = 0;
        DonGiaInternet = 200;
    }
    int CuocDienThoai()
    {
        return ThoiGianGoi * DonGiaGoi;
    }
    int CuocInternet()
    {
        return LuuLuong * DonGiaInternet;
    }
    void nhap()
    {
        cout<<"Nhap thoi gian goi: "; cin>>ThoiGianGoi;
        cout<<"Nhap don gia goi: "; cin>>DonGiaGoi;
        cout<<"Nhap luu luong: "; cin>>LuuLuong;
        cout<<"Nhap don gia internet: "; cin>>DonGiaInternet;
    }
    virtual void xuat()
    {
        cout<<setw(20)<<"Basic"<<setw(20)<<CuocTong()<<endl;
    }
    virtual int CuocTong()
    {
        return CuocDienThoai() * CuocInternet() * 11 / 10;
    }
    void SuDung(int ThoiGianGoi, int LuuLuong)
    {
        this->ThoiGianGoi += ThoiGianGoi;
        this->LuuLuong += LuuLuong;
    }
    int get_ThoiGianSuDung()
    {
        return ThoiGianGoi;
    }
};

class DataFree : public Basic
{
    int CuocThueBao, NguongMP;
public:
    DataFree()
    {
        CuocThueBao = 0;
        NguongMP = 0;
    }
    int CuocInternet()
    {
        if(LuuLuong <= NguongMP)
            return CuocThueBao;
        else
            return CuocThueBao + (LuuLuong - NguongMP) * DonGiaInternet;
    }
    void nhap()
    {
        Basic::nhap();
        cout<<"Nhap cuoc thue bao: "; cin>>CuocThueBao;
        cout<<"Nhap nguong mien phi: "; cin>>NguongMP;
    }
    void xuat()
    {
        cout<<setw(20)<<"DataFree"<<setw(20)<<CuocTong()<<endl;
    }
    int CuocTong()
    {
        return (CuocInternet() + CuocDienThoai()) * 11 / 10;
    }
};

class DataFix : public Basic
{
public:
    int CuocDienThoai()
    {
        return Basic::CuocDienThoai() * 9 / 10;
    }
    int CuocInternet()
    {
        return 1000000;
    }
    int CuocTong()
    {
        return (CuocDienThoai() + CuocInternet()) * 11 / 10;
    }
    void xuat()
    {
        cout<<setw(20)<<"DataFix"<<setw(20)<<CuocTong()<<endl;
    }
};

class HopDong
{
    string HoTen, CMND, DiaChi;
    Basic *GoiCuoc;
public:
    HopDong()
    {
        HoTen = "";
        CMND = "";
        DiaChi = "";
    }
    void nhap()
    {
        string x;
        fflush(stdin);
        cout<<"Nhap ho va ten: "; getline(cin, HoTen);
        cout<<"Nhap chung minh nhan dan: "; getline(cin, CMND);
        cout<<"Nhap dia chi: "; getline(cin, DiaChi);
        cout<<"Nhap goi cuoc: "; getline(cin, x);
        if(x == "Basic")
            GoiCuoc = new Basic();
        else if(x == "DataFree")
            GoiCuoc = new DataFree();
        else
            GoiCuoc = new DataFix();
    }
    void xuat()
    {
        cout<<setw(20)<<HoTen<<setw(20)<<CMND<<setw(20)<<DiaChi<<setw(20);
        GoiCuoc->xuat();
    }
    int TinhCuocCuoiThang()
    {
        return GoiCuoc->CuocTong();
    }
    int SuDung()
    {
        return GoiCuoc->get_ThoiGianSuDung();
    }
};

void TieuDe()
{
    cout<<setw(20)<<"Ho va Ten"<<setw(20)<<"Chung minh ND"<<setw(20)<<"Dia Chi"<<setw(20)<<"Ten goi cuoc"<<setw(20)<<"Tong cuoc"<<endl;
}

class DanhSachHopDong
{
    HopDong *DSHopDong[100];
    int SoHopDong;
public:
    void DangKy()
    {
        cout<<"\t [?] Nhap so luong hop dong can quan li: "; cin>>SoHopDong;
        for(int i = 0; i < SoHopDong; i++)
        {
            cout<<"\t [!] Nhap thong tin cho hop dong thu "<<i+1<<endl;
            DSHopDong[i]->nhap();
        }
    }
    void ThongBaoTienCuoc()
    {
        TieuDe();
        for(int i = 0; i < SoHopDong; i++)
        {
            DSHopDong[i]->xuat();
        }
    }
};

int main()
{
    DanhSachHopDong a;
    a.DangKy();
    a.ThongBaoTienCuoc();
}