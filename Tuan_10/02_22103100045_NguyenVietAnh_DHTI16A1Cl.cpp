#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class DocGia
{
protected:
    string Ma, HoTen;
    int Thang;
public:
    virtual void nhap()
    {
        fflush(stdin);
        cout<<"Nhap ma doc gia: "; getline(cin, Ma);
        cout<<"Nhap ho va ten doc gia: "; getline(cin, HoTen);
        cout<<"Nhap so thang hieu luc: "; cin>>Thang;
    }
    virtual void in()
    {
        cout<<setw(20)<<Ma<<setw(20)<<HoTen<<setw(20)<<Thang;
    }
    // Tìm độc giả trẻ em có số tháng hiệu lực < 10, độc giả người lớn là giảng viên
    virtual bool find() = 0;
    // Tính tiền làm thẻ, độc giả trẻ em tiền làm thẻ bằng số tháng hiệu lực * 20000, độc giả người lớn bằng số tháng hiệu lực * 30000
    virtual int Money() = 0;
}; 

class DGTre : public DocGia
{
    int NamSinh;
public:
    void nhap()
    {
        DocGia::nhap();
        cout<<"Nhap nam sinh doc gia: "; cin>>NamSinh;
    }
    void in()
    {
        DocGia::in();
        cout<<setw(15)<<NamSinh<<setw(15)<<Money()<<endl;
    }
    bool find()
    {
        return Thang < 10;
    }
    int Money()
    {
        return Thang * 20000;
    }

};

class DGLon : public DocGia
{
    string NgheNghiep;
public:
    void nhap()
    {
        DocGia::nhap();
        fflush(stdin);
        cout<<"Nhap nghe nghiep cua doc gia: "; getline(cin, NgheNghiep);
    }
    void in()
    {
        DocGia::in();
        cout<<setw(20)<<NgheNghiep<<setw(15)<<Money()<<endl;
    }
    bool find()
    {
        return NgheNghiep == "Giang Vien"; 
    }
    int Money()
    {
        return Thang * 30000;
    }

};

void tieude_DGTre()
{
     cout<<setw(20)<<"Ma doc gia"<<setw(20)<<"Ho va ten"<<setw(20)<<"So thang hieu luc"<<setw(15)<<"Nam Sinh"<<setw(15)<<"Tien lam the"<<endl;
}

void tieude_DGLon()
{
     cout<<setw(20)<<"Ma doc gia"<<setw(20)<<"Ho va ten"<<setw(20)<<"So thang hieu luc"<<setw(20)<<"Nghe Nghiep"<<setw(15)<<"Tien lam the"<<endl;
}

// Hàm nhập thông tin cho n DocGia
void nhap_nDocGia(DocGia *a[], int n)
{
    int kq = 0;
    for(int i = 0; i < n; i++)
    {
        cout<<"\t\t\t~~~~~ [!] DANH SACH THAO TAC ~~~~~"<<endl;
        cout<<"\t\t[1] Nhap thong tin cho DGTre"<<endl
            <<"\t\t[2] Nhap thong tin cho DGLon"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>kq;
        while(kq < 0 || kq > 2)
        {
            cout<<"\t\t[!] Lua chon khong hop le!"<<endl;
            cout<<"\t[?] Vui long nhap lai lua chon cua ban: "; cin>>kq;
        }
        if(kq == 1)
        {   
            cout<<"\t\t[!] Nhap thong tin cho DGTre"<<endl;
            a[i] = new DGTre;
            a[i]->nhap();
        }
        else
        {
            cout<<"\t\t[!] Nhap thong tin cho DGLon"<<endl;
            a[i] = new DGLon;
            a[i]->nhap();
        }
    }
}

// Hàm in thông tin cho n DocGia
void in_nDocGia(DocGia *a[], int n)
{
    cout<<"\t\t[!] Thong tin cua DGTre"<<endl;
    tieude_DGTre();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<DGTre*>(a[i]) != NULL)
            a[i]->in();
    }
    cout<<"\t\t[!] Thong tin cua DGLon"<<endl;
    tieude_DGLon();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<DGLon*>(a[i]) != NULL)
            a[i]->in();
    }
}

// Hàm in thông tin cho n DocGia theo yêu cầu
void in_nDocGia2(DocGia *a[], int n)
{
    cout<<"\t\t[!] Thong tin cua DGTre co so thang hieu luc < 10"<<endl;
    tieude_DGTre();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<DGTre*>(a[i]) != NULL && a[i]->find() == true)
            a[i]->in();
    }
    cout<<"\t\t[!] Thong tin cua DGLon co nghe nghiep la Giang Vien"<<endl;
    tieude_DGLon();
    for(int i = 0; i < n; i++)
    {
        if(dynamic_cast<DGLon*>(a[i]) != NULL && a[i]->find() == true)
            a[i]->in();
    }
}

// Hàm tính tổng tiền làm thẻ của độc giả
void sum_Money(DocGia *a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i]->Money();
    }
    cout<<"\t\t[!] Tong so tien lam the la: "<<sum<<endl;
}

// Hàm chính
void Main_Program()
{
    DocGia *a[100]; int n;
    cout<<"\t[?] Nhap so luong Doc Gia can quan li: "; cin>>n;
    while(true)
    {
        int kq = 0;
        cout<<"\t\t\t ----- DANH SACH THAO TAC -----"<<endl;
        cout<<"\t\t[1] Nhap thong tin cho "<<n<<" doc gia"<<endl
            <<"\t\t[2] In thong tin "<<n<<" doc gia vua nhap"<<endl
            <<"\t\t[3] In thong tin "<<n<<" doc gia theo yeu cau de bai"<<endl
            <<"\t\t[4] Tong tien lam the cua "<<n<<" doc gia"<<endl
            <<"\t\t[5] Thoat chuong trinh"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>kq;
        while(kq < 1 || kq > 5)
        {
            cout<<"\t\t[!] Lua chon cua ban khong hop le!"<<endl;
            cout<<"\t[?] Nhap lai lua chon cua ban: "; cin>>kq;
        }
        if(kq == 1)
        {
            nhap_nDocGia(a, n);
        }
        else if(kq == 2)
        {
            in_nDocGia(a, n);
        }
        else if(kq == 3)
        {
            in_nDocGia2(a, n);
        }
        else if(kq == 4)
        {
            sum_Money(a, n);
        }
        else
        {
            cout<<"\t\t[!] Cam on ban da su dung chuong trinh"<<endl;
            cout<<"Thoat chuong trinh....."<<endl;
            return;
        }
        for(int i = 0; i < n; i++)
            cout<<endl;
    }
}
int main()
{
    Main_Program();
}
// Chạy ổn ròi nha =)))
