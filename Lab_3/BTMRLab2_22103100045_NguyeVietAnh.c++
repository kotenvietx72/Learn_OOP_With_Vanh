#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;

struct date
{
    int ngay, thang, nam;
};
class CN
{
    int ID, tuoi;
    string name;
    date Date;
    float hsl, luong;
public:
    /** Hàm khởi tạo không tham số*/
    CN()
    {
        ID = 0; name ="";
        Date.ngay = 0; Date.thang = 0; Date.nam = 0;
        hsl = 0; luong = 0;
    }
    /** Hàm khởi tạo có tham số*/
    CN(int ID, string name, int ngay, int thang, int nam, float hsl, float luong)
    {
        this->ID = ID;
        this->name = name;
        this->Date.ngay = ngay;
        Date.thang = thang;
        Date.nam = nam;
        this->hsl = hsl;
        this->luong = luong;
    }
    /** Hàm nhập thông tin của 1 công nhân*/
    void nhap()
    {
        cout<<"Nhap ma cong nhan: "; cin>>ID;
        cin.ignore();
        cout<<"Nhap ten cong nhan: "; getline(cin, name);
        cout<<"Nhap lan luot ngay thang nam sinh cua cong nhan: "; cin>>Date.ngay>>Date.thang>>Date.nam;
        cout<<"Nhap he so luong: "; cin>>hsl;
        tinh_luong();
        tinh_tuoi();
    }
    /** Hàm in thông tin của 1 công nhân*/
    void in()
    {
        cout<<setw(15)<<ID<<setw(25)<<name<<"\t\t "<<Date.ngay<<"\\"<<Date.thang<<"\\"<<Date.nam<<setw(10)<<tuoi<<setw(15)<<hsl<<setw(15)<<luong<<endl;
    }
    /** Hàm tính lương*/
    void tinh_luong()
    {
        luong = hsl * 1500000;
    }
    /** Hàm tính tuổi*/
    void tinh_tuoi()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int nam = ltm->tm_year + 1900;
        tuoi = nam - Date.nam;
    }
    friend CN tinh_luong(CN a, CN b);
    float get_luong()
    {
        return luong;
    }
    int get_tuoi()
    {
        return tuoi;
    }
};
void tieude()
{
    cout<<setw(15)<<"Ma cong nhan"<<setw(25)<<"Ho va ten"<<setw(25)<<"Ngay thang nam sinh"<<setw(10)<<"Tuoi CN"<<setw(15)<<"He so luong"<<setw(15)<<"Luong"<<endl;
}
    /** Hàm tính lương của 2 công nhân bất kì*/
    CN tinh_luong(CN a, CN b)
    {
        CN cn;
        cn.luong = a.luong + b.luong;
        return cn;
    }
class TCN
{
    int ma, sl;
    string ten;
    float tong_luong_TOCN;
    CN cn[100];
public:
    /** Hàm nhập 1 tổ Công Nhân*/
    void nhap_TOCN()
    {
        cout<<"Nhap ma to cong nhan: "; cin>>ma;
        cout<<"Nhap so luong thanh vien cua to cong nhan: "; cin>> sl;
        cin.ignore();
        cout<<"Nhap ten cua to cong nhan: "; getline(cin, ten);
        for(int i = 0; i < sl; i++)
        {
            cout<<"\t Nhap thong tin cho cong nhan thu "<< i + 1<<endl;
            cn[i].nhap();
        }
    }
    /** Hàm in 1 tổ Công Nhân*/
    void in_TOCN()
    {
        cout<<"\tThong tin cua to cong nhan!"<<endl;
        cout<<"Ma cua to cong nhan: "<<ma<<endl;
        cout<<"Ten cua to cong nhan: "<<ten<<endl;
        cout<<"So luong thanh vien cua to cong nhan: "<<sl<<endl;
        cout<<"\tThong tin tung thanh vien cua to cong nhan!"<<endl;
        tieude();
        for(int i = 0; i < sl; i++)
            cn[i].in();
    }
    /** Hàm tính tổng lương của 1 tổ Công Nhân*/
    void tong_luong()
    {
        for(int i = 0; i < sl; i++)
        {
            tong_luong_TOCN += cn[i].get_luong();
        }
    }
    /** Hàm sắp xếp công nhân theo chiều giảm dần của lương & tìm công nhân lương cao nhất*/
    void sapxep()
    {
        for(int i = 0; i < sl - 1; i++)
        {
            for(int j = i + 1; j < sl; j++)
            {
                if(cn[i].get_luong() < cn[j].get_luong())
                    swap(cn[i], cn[j]);
            }
        }
        cout<<"\tThong tin cong nhan co luong cao nhat!"<<endl;
        tieude();
        cn[0].in();
    }
    /** Hàm thêm 1 CN vào danh sách*/
    void them(CN x)
    {
        cn[sl] = x;
        sl++;
    }
    void xoa()
    {
        for(int i = 0; i < sl; i++)
        {
            if(cn[i].get_tuoi() >= 60)
            {
                for(int j = i; j < sl; j++)
                {
                    cn[j] = cn[j + 1];
                }
                sl--;
                i--;
            }
        }
    }
};
int main()
{
    TCN a; CN b;
    a.nhap_TOCN();
    a.in_TOCN();
    // cout<<"\tNhap thong tin cua nguoi can chen vao! "<<endl;
    // b.nhap();
    // a.them(b);
    // cout<<"\tDanh sach cong nhan theo chieu giam dan cua luong & luong cua nguoi cao nhat!"<<endl;
    // a.sapxep();
    // a.in_TOCN();
    a.xoa();
    cout<<"\t Danh sach CN sau khi loc!"<<endl;
    a.in_TOCN();
    //Done
}