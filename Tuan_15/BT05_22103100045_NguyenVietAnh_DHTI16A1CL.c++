#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct DATE{
    int Ngay, Thang, Nam;
};

class KHACHHANG{
protected:
    string Ma, HoTen;
    DATE a;
    int SoLuong, DonGia;
public:
    virtual void nhap()
    {
        fflush(stdin);
        cout<<"Nhap ma khach hang: "; getline(cin, Ma);
        cout<<"Nhap ho ten khach hang: "; getline(cin, HoTen);
        cout<<"Nhap lan luot ngay thang nam ra hoa don: "; cin>>a.Ngay>>a.Thang>>a.Nam;
        cout<<"Nhap so luong: "; cin>>SoLuong;
        cout<<"Nhap don gia: "; cin>>DonGia;
    }
    virtual void in()
    {
        cout<<setw(20)<<Ma<<setw(20)<<HoTen<<"\t\t"<<a.Ngay<<"\\"<<a.Thang<<"\\"<<a.Nam<<setw(15)<<SoLuong<<setw(15)<<DonGia;
    }
    virtual float Thanhtien() = 0;
    int get_SoLuong()
    {
        return SoLuong;
    }
    DATE get_DATE()
    {
        return a;
    }
};

class KhachHangVietNam: public KHACHHANG{
    string DoiTuongKhachHang;
    int DinhMuc;
public:
    bool check()
    {
        return DoiTuongKhachHang == "Sinh Hoat" || DoiTuongKhachHang == "Kinh Doanh" || DoiTuongKhachHang == "San Xuat";
    }
    void nhap()
    {
        KHACHHANG::nhap();
        fflush(stdin);
        cout<<"Nhap doi tuong khach hang: "; getline(cin, DoiTuongKhachHang);
        while(check() == 0)
        {
            cout<<"\t [!] Doi tuong khach hang khong hop le!"<<endl;
            cout<<"Nhap lai doi tuong khach hang: "; getline(cin, DoiTuongKhachHang);
        }
        cout<<"Nhap dinh muc: "; cin>>DinhMuc;
    }
    void in()
    {
        KHACHHANG::in();
        cout<<setw(20)<<DoiTuongKhachHang<<setw(15)<<DinhMuc<<setw(15)<<Thanhtien()<<endl;
    }
    float Thanhtien()
    {
        if(SoLuong <= DinhMuc)
            return SoLuong * DonGia;
        return SoLuong * DonGia * DinhMuc + (SoLuong - DinhMuc) * DonGia * 2.5;
    }
};

class KhachHangNuocNgoai : public KHACHHANG{
    string QuocTich;
public:
    void nhap()
    {
        KHACHHANG::nhap();
        fflush(stdin);
        cout<<"Nhap quoc tich: "; getline(cin, QuocTich);
    }
    void in()
    {
        KHACHHANG::in();
        cout<<setw(20)<<QuocTich<<setw(15)<<Thanhtien()<<endl;
    }
    float Thanhtien()
    {
        return SoLuong * DonGia;
    }
};

void Tieude_KhachHangVietNam()
{
    cout<<setw(20)<<"Ma hoa don"<<setw(20)<<"Ho va ten"<<"\t"<<"Ngay xuat hoa don"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(20)<<"Doi tuong"<<setw(15)<<"Dinh Muc"<<setw(15)<<"Thanh tien"<<endl;
}

void Tieude_KhachHangNuocNgoai()
{
    cout<<setw(20)<<"Ma hoa don"<<setw(20)<<"Ho va ten"<<"\t"<<"Ngay xuat hoa don"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(20)<<"Quoc tich"<<setw(15)<<"Thanh tien"<<endl;
}

/** Nhập danh sách các hoá đơn*/
void nhap_nKHACHHANG(KHACHHANG *a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int sl = 0;
        cout<<"\t\t\t ------ [1] NHAP THONG TIN KHACH HANG"<<endl
            <<"\t\t [1] Nhap thong tin khach hang Viet Nam"<<endl
            <<"\t\t [2] Nhap thong tin khach hang nuoc ngoai"<<endl
            <<"\t\t [3] Thoat thao tac"<<endl
            <<"\t [?] Nhap lua chon cua ban: "; cin>>sl;
        if(sl == 1)
        {
            a[i] = new KhachHangVietNam();
            a[i]->nhap();
        }
        else if(sl == 2)
        {
            a[i] = new KhachHangNuocNgoai();
            a[i]->nhap();
        }
        else
            break;
    }
}

/** In danh sách các hoá đơn*/
void in_nKHACHHANG(KHACHHANG *a[], int n)
{
    cout<<"\t\t [!] Thong tin khach hang Viet Nam"<<endl;
    Tieude_KhachHangVietNam();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<KhachHangVietNam*>(a[i]) != NULL)
            a[i]->in();
    }
    cout<<"\t\t [!] Thong tin khach hang nuoc ngoai"<<endl;
    Tieude_KhachHangNuocNgoai();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<KhachHangNuocNgoai*>(a[i]) != NULL)
            a[i]->in();
    }
}

/** Tính tổng số lượng cho từng loại khách hàng*/
void sum_SL(KHACHHANG *a[], int n)
{
    int sum_VietNam = 0, sum_nuocngoai = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<KhachHangVietNam*>(a[i]) != NULL)
            sum_VietNam += a[i]->get_SoLuong();
        else
            sum_nuocngoai += a[i]->get_SoLuong();
    }
    cout<<"\t\t [!] Tong so luong cua khach hang Viet Nam la: "<<sum_VietNam<<endl;
    cout<<"\t\t [!] Tong so luong cua khach hang nuoc ngoai la: "<<sum_nuocngoai<<endl;
}

/** Tính trung bình thành tiền của khách hàng nước ngoài*/
void AVG_Thanhtien_nuocngoai(KHACHHANG *a[], int n)
{
    int dem = 0; float sum_Thanhtien = 0;
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<KhachHangNuocNgoai*>(a[i]) != NULL )
        {
            sum_Thanhtien += a[i]->Thanhtien();
            dem++;
        }
    }
    cout<<"\t\t [!] Trung binh thanh tien cua khach hang nuoc ngoai la: "<<sum_Thanhtien/dem<<endl;
}

/** Xuất ra hoá đơn trong tháng 9 năm 2013*/
void xuat(KHACHHANG *a[], int n)
{
    cout<<"\t\t [!] Hoa don khach hang Viet Nam trong thang 9 nam 2013"<<endl;
    Tieude_KhachHangVietNam();
    for(int i = 0; i < n; i++)
    {
        DATE x = a[i]->get_DATE();
        if(dynamic_cast<KhachHangVietNam*>(a[i]) != NULL && x.Thang == 9 && x.Nam == 2013)
            a[i]->in();
    }
    cout<<"\t\t [!] Hoa don khach hang nuoc ngoai trong thang 9 nam 2013"<<endl;
    Tieude_KhachHangNuocNgoai();
    for(int i = 0; i < n; i++)
    {
        DATE x = a[i]->get_DATE();
        if(dynamic_cast<KhachHangNuocNgoai*>(a[i]) != NULL && x.Thang == 9 && x.Nam == 2013)
            a[i]->in();
    }
}

void main_chinh()
{
    KHACHHANG *a[100]; int n;
    cout<<"\t [?] Nhap so luong khach hang can quan li: "; cin>>n;
    while(true)
    {
        int sl = 0;
        cout<<"\t\t\t ------ DANH SACH THAO TAC ------"<<endl
            <<"\t\t [1] Nhap thong tin "<<n<<" khach hang"<<endl
            <<"\t\t [2] In thong tin "<<n<<" khach hang"<<endl
            <<"\t\t [3] Tinh tong so luong dien cho tung loai khach hang"<<endl
            <<"\t\t [4] Tinh trung binh thanh tien cua khach hang nuoc ngoai"<<endl
            <<"\t\t [5] Xuat ra hoa don khach hang trong thang 9 nam 2013"<<endl
            <<"\t\t [6] Thoat chuong trinh"<<endl
            <<"\t [?] Nhap lua chon cua ban: "; cin>>sl;
        switch (sl)
        {
            case 1:
            {
                nhap_nKHACHHANG(a, n);
                cout<<"-------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 2:
            {
                in_nKHACHHANG(a, n);
                cout<<"-------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 3:
            {
                sum_SL(a, n);
                cout<<"-------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 4:
            {
                AVG_Thanhtien_nuocngoai(a, n);
                cout<<"-------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 5:
            {
                xuat(a, n);
                cout<<"-------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 6:
            {
                return;
            }
            default:
            {
                cout<<"\t\t [!] Lua chon khong hop le!"<<endl;
                cout<<"\t [?] Nhap lai lua chon: "; cin>>sl;
                break;
            }
        }
    }
}

int main()
{
    main_chinh();
}