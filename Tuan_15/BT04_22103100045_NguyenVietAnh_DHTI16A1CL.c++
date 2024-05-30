#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct NgayGiaoDich
{
    int Ngay, Thang, Nam;
};

class QuanLy
{
protected:
    string Ma;
    NgayGiaoDich a;
    int DonGia, SoLuong;
public:
    QuanLy()
    {
        Ma = "";
        a.Ngay = 0; a.Thang = 0; a.Nam = 0;
        DonGia = 0; SoLuong = 0;
    }
    virtual float ThanhTien() = 0;
    virtual void nhap()
    {
        fflush(stdin);
        cout<<"Nhap ma giao dich: "; getline(cin, Ma);
        cout<<"Nhap lan luot ngay thang nam giao dich: "; cin>>a.Ngay>>a.Thang>>a.Nam;
        cout<<"Nhap don gia: "; cin>>DonGia;
        cout<<"Nhap so luong: "; cin>>SoLuong;
    }
    virtual void xuat()
    {
        cout<<setw(15)<<Ma<<"\t\t"<<a.Ngay<<"\\"<<a.Thang<<"\\"<<a.Nam<<setw(15)<<DonGia<<setw(15)<<SoLuong;
    }
    int get_DonGia()
    {
        return DonGia;
    }
    NgayGiaoDich get_NgayGiaoDich()
    {
        return a;
    }
};

class GiaoDichVang : public QuanLy
{
    string LoaiVang;
public:
    float ThanhTien()
    {
        return SoLuong * DonGia;
    }
    void nhap()
    {
        QuanLy::nhap();
        fflush(stdin);
        cout<<"Nhap loai vang: "; getline(cin, LoaiVang);
    }
    void xuat()
    {
        QuanLy::xuat();
        cout<<setw(15)<<LoaiVang<<endl;
    }
};

class GiaoDichTienTe : public QuanLy
{
    int TiGia;
    string LoaiTienTe;
public:
    float ThanhTien()
    {
        if(LoaiTienTe == "USD" || LoaiTienTe == "Euro")
            return SoLuong * DonGia * TiGia;
        else
            return SoLuong * DonGia;     
    }
    void nhap()
    {
        QuanLy::nhap();
        fflush(stdin);
        cout<<"Nhap loai tien te (USD/Euro/VN): "; getline(cin, LoaiTienTe);
        cout<<"Nhap ti gia: "; cin>>TiGia;
    }
    void xuat()
    {
        QuanLy::xuat();
        cout<<setw(15)<<LoaiTienTe<<setw(15)<<TiGia<<endl;
    }
};

void TieuDe_GiaoDichVang()
{
    cout<<setw(15)<<"Ma giao dich"<<setw(20)<<"Ngay giao dich"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Loai vang"<<endl;
}

void TieuDe_GiaoDichTienTe()
{
    cout<<setw(15)<<"Ma giao dich"<<setw(20)<<"Ngay giao dich"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Loai tien te"<<setw(15)<<"Ti gia"<<endl;
}

/** Hàm in*/
void In(QuanLy *a[], int n)
{
    TieuDe_GiaoDichVang();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichVang*>(a[i]) != NULL)
            a[i]->xuat();
    }
    cout<<"\t\t [!] Thong tin giao dich tien te!"<<endl;
    TieuDe_GiaoDichTienTe();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichTienTe*>(a[i]) != NULL)
            a[i]->xuat();
    }
}

/** Nhập xuất danh sách các loại giao dịch */
void Cau1(QuanLy *a[], int n)
{
    // Nhập
    for(int i = 0; i < n; i++)
    {
        int select = 0;
        cout<<"\t\t\t ------ DANH SACH THAO TAC ------"<<endl
            <<"\t\t [1] Nhap thong tin giao dich vang"<<endl
            <<"\t\t [2] Nhap thong tin giao dich tien te"<<endl
            <<"\t\t [3] Thoat thao tac"<<endl;
        cout<<"\t [?] Nhap lua chon cua ban: "; cin>>select;
        if(select == 1)
        {
            a[i] = new GiaoDichVang();
            a[i]->nhap();
        }
        else if(select == 2)
        {
            a[i] = new GiaoDichTienTe();
            a[i]->nhap();
        }
        else
        {
            break;
        }
    }
    // In
    In(a, n);
}

/** Tính tổng số lượng cho từng loại */
void Cau2(QuanLy *a[], int n)
{
    int dem_GiaoDichVang = 0, dem_GiaoDichTienTe = 0;
    for(int i = 0; i < n; i++)
        {
            if(dynamic_cast<GiaoDichVang*>(a[i]) == NULL)
                dem_GiaoDichVang++;
            else
                dem_GiaoDichTienTe++;
        }
    cout<<"\t\t [!] So luong giao dich vang la: "<<dem_GiaoDichVang<<endl;
    cout<<"\t\t [!] So luong giao dich tien te la: "<<dem_GiaoDichTienTe<<endl;
}

/** Tính trung bình thành tiền của giao dịch tiền tệ*/
void Cau3(QuanLy *a[], int n)
{
    int dem_GiaoDichTienTe = 0; float ThanhTien = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichTienTe*>(a[i]) == NULL)
        {
            dem_GiaoDichTienTe++;
            ThanhTien += a[i]->ThanhTien();
        }
    }
    cout<<"\t\t [!] Trung binh thanh tien cua giao dich tien te la: "<<ThanhTien / dem_GiaoDichTienTe<<endl;
}

/** Xuất ra các giao dịch có đơn giá > 1 tỉ*/
void Cau4(QuanLy *a[], int n)
{
    cout<<"\t\t [!] Thong tin giao dich vang co don gia lon hon 1 ti!"<<endl;
    TieuDe_GiaoDichVang();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichVang*>(a[i]) != NULL && a[i]->get_DonGia() > 1000000)
            a[i]->xuat();
    }
    cout<<"\t\t [!] Thong tin giao dich tien te co don gia lon hon 1 ti!"<<endl;
    TieuDe_GiaoDichTienTe();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<GiaoDichTienTe*>(a[i]) != NULL && a[i]->get_DonGia() > 1000000)
            a[i]->xuat();
    }
}

/** Đếm những giao dịch vàng ngày 20/3/2015*/
void Cau5(QuanLy *a[], int n)
{
    int Dem = 0;
    for(int i = 0; i < n; i++)
    {
        NgayGiaoDich u = a[i]->get_NgayGiaoDich();
        if(dynamic_cast<GiaoDichVang*>(a[i]) != NULL && u.Ngay == 20 && u.Thang == 3 && u.Nam == 2015)
            Dem++;
    }
    cout<<"\t\t [!] So luong giao dich vang ngay 20/3/2015 la: "<<Dem<<endl;
}

/** Sắp xếp danh sách theo chiều giảm của ngày giao dịch*/
void Cau6(QuanLy *a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        NgayGiaoDich x = a[i]->get_NgayGiaoDich(), y = a[i + 1]->get_NgayGiaoDich();
        if(x.Nam < y.Nam)
            swap(a[i], a[i + 1]);
        else if(x.Thang < y.Thang)
            swap(a[i], a[i + 1]);
        else if(x.Ngay < y.Ngay)
            swap(a[i], a[i + 1]);
        else
        {
            
        }
    }
}

/** Thêm giao dịch vào cuối danh sách*/
void Cau7(QuanLy *a[], int &n)
{
    QuanLy *x;
    string name; fflush(stdin);
    cout<<"\t [?] Nhap loai giao dich ban muon them vao cuoi danh sach: "; getline(cin, name);
    if(name == "Giao Dich Vang")
    {
        x = new GiaoDichVang();
        cout<<"\t\t [!] Nhap thong tin cho giao dich vang"<<endl;
        x->nhap();
        a[n] = x;
    }
    else
    {
        x = new GiaoDichTienTe();
        cout<<"\t\t [!] Nhap thong tin cho giao dich tien te"<<endl;
        x->nhap();
        a[n] = x;
    }
    n++;
}

/** Xoá giao dịch vàng ngày 20/5/2010*/
void Cau8(QuanLy *a[], int &n)
{
    for(int i = 0; i < n; i++)
    {
        NgayGiaoDich u = a[i]->get_NgayGiaoDich();
        if(dynamic_cast<GiaoDichVang*>(a[i]) != NULL && u.Ngay == 20 && u.Thang == 5 && u.Nam == 2010)
        {
            for(int j = i; j < n; j++)
                a[j] = a[j + 1];
            n--;
        }
    }
}

void main_chinh()
{
    QuanLy *a[100]; int n;
    cout<<"\t [?] Nhap so luong giao dich can quan li: "; cin>>n;
    Cau1(a, n);
    Cau2(a, n);
    Cau3(a, n);
    Cau4(a, n);
    Cau5(a, n);
    Cau6(a, n);
    Cau7(a, n);
    Cau8(a, n);
    cout<<"\t\t\t Thong tin cac giao dich sau khi bien doi"<<endl;
    In(a, n);
}

int main()
{
    main_chinh();
}