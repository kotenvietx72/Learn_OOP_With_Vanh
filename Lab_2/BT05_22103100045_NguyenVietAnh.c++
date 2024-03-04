#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class NGUOI
{
    string name, nghe, qt;
    int tuoi;
public:
    /** Hàm khởi tạo không có tham số*/
    NGUOI()
    {
        name = ""; nghe = ""; qt = "";
        tuoi = 0;
    }
    /** Hàm khởi tạo có tham số*/
    NGUOI(string name, string nghe, string qt, int tuoi)
    {
        this->name = name;
        this->nghe = nghe;
        this->qt = qt;
        this->tuoi = tuoi;
    }
    /** Hàm huỷ*/
    ~NGUOI(){}
    /** Hàm nhập thông tin 1 người*/
    void nhap()
    {
        cout<<"Nhap tuoi: ";cin>>tuoi;
        cin.ignore();
        cout<<"Nhap ten: ";getline(cin, name);
        cout<<"Nhap nghe nghiep: "; getline(cin, nghe);
        cout<<"Nhap quoc tich: "; getline(cin, qt);
    }
    /** Hàm in thông tin 1 người*/
    void in()
    {
        cout<<setw(20)<<name<<setw(10)<<tuoi<<setw(15)<<nghe<<setw(15)<<qt<<endl;
    }
    string get_qt()
    {
        return qt;
    }
    string get_name()
    {
        return name;
    }
    string get_nghe()
    {
        return nghe;
    }
    int get_tuoi()
    {
        return tuoi;
    }
};
    void tieude()
    {
        cout<<setw(20)<<"Ho va ten"<<setw(10)<<"Tuoi"<<setw(15)<<"Nghe nghiep"<<setw(15)<<"Quoc tich"<<endl;
    }
    /** Hàm nhập n người*/
    void nhap_nNGUOI(NGUOI a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\tNhap thong tin cho nguoi thu "<< i + 1<<endl;
            a[i].nhap();
        }
    }
    /** Hàm in n người*/
    void in_nNGUOI(NGUOI a[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i].get_name() > a[j].get_name())
                    swap(a[i], a[j]);
            }
        }
        tieude();
        for(int i = 0; i < n; i++)
        {
            a[i].in();
        }
    }
    /** Hàm tìm kiếm 1: Danh sách những người có nghề bác sỹ*/
    void timkiem1(NGUOI a[], int n)
    {
        cout<<"\tDANH SACH THONG TIN NGUOI CO NGHE BAC SI"<<endl;
        tieude();
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_nghe() == "Bac sy")
                a[i].in();
        }
    }
    /** Hàm tìm kiếm 2: Tìm danh sách người có quốc tịch "Campuchia", nếu có xoá người này khỏi danh sách*/
    void timkiem2(NGUOI a[], int &n)
    {
        cout<<"\tDANH SACH THONG TIN KHONG CO QUOC TICH CAMPUCHIA "<<endl;
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_qt() == "Campuchia")
                {
                    for(int j = i; j < n; j++)
                        a[j] = a[j + 1];
                }
                
        }
        n--;
    }
    /** Hàm tìm kiếm 3: Tìm danh sách có người họ tên "Trần Đại Nghĩa " không, nếu không thì chèn thêm người này vào cuối danh sách*/
    void timkiem3(NGUOI a[], int &n)
    {
        bool check = false;
        for(int i = 0; i < n ; i++)
        {
            if(a[i].get_name() == "Tran Dai Nghia")
                check = true;
        }
        if(check == true)
            cout<<"\t\"Tran Dai Nghia\" da co ten trong danh sach"<<endl;
        else
        {
            cout<<"\t\"Tran Dai Nghia\" chua co ten trong danh sach"<<endl;
            cout<<"Nhap thong tin cho ban nay"<<endl;
            a[n].nhap();
            n++;
        }
    }
    /** Hàm tìm kiếm 4: In thông tin người có tuổi cao nhất và thấp nhất trong danh sách*/
    void timkiem4(NGUOI a[], int n)
    {
        int min = 0, max = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_tuoi() < a[min].get_tuoi())
                min = i;
            if(a[i].get_tuoi() > a[max].get_tuoi())
                max = i;
        }
        cout<<"\tTHONG TIN NGUOI CO TUOI NHO NHAT"<<endl;
        tieude();
        a[min].in();
        cout<<"\tTHONG TIN NGUOI CO TUOI LON NHAT"<<endl;
        tieude();
        a[max].in();
    }
int main()
{
    NGUOI a[100]; int n;
    cout<<"Nhap so luong nguoi can quan li: ";cin>>n;
    nhap_nNGUOI(a, n);
    cout<<"\tDanh sach thong tin nguoi vua nhap"<<endl;
    in_nNGUOI(a, n);
    timkiem4(a, n);
    // DONE
}