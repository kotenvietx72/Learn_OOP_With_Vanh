#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class HANGHOA
{
protected:
    string ma, ten;
    float dongia;
public:
    /** Khởi tạo không tham số */
    HANGHOA()
    {
        ma = ""; ten = "";
        dongia = 0;
    }
    /** Khởi tạo có tham số*/
    HANGHOA(string ma, string ten, float dongia)
    {
        this->ma=ma;
        this->ten=ten;
        this->dongia=dongia;
    }
    ~HANGHOA(){}
    /** Hàm nhập của HANGHOA*/
    void nhap()
    {
        fflush(stdin);
        cout<<"Nhap ma hang hoa: "; getline(cin, ma);
        cout<<"Nhap ten hang hoa: "; getline(cin, ten);
        cout<<"Nhap don gia hang hoa: "; cin>>dongia;
    }
    /** Hàm in của HANGHOA*/
    void in()
    {
        cout<<setw(20)<<ma<<setw(20)<<ten<<setw(20)<<dongia;
    }
};
class MT : public HANGHOA
{
protected:
    int sl;
    float tocdo;
public:
    /**Khởi tạo không tham số */
    MT() : HANGHOA()
    {
        sl = 0; tocdo = 0;
    }
    /** Khởi tạo có tham số*/
    MT(string ma, string ten, float dongia, int sl, float tocdo)
    {
        this->ma=ma;
        this->ten=ten;
        this->dongia = dongia;
        this->sl=sl;
        this->tocdo = tocdo;
    }
    ~MT(){}
    friend istream& operator>> (istream &is, MT &a);
    friend ostream& operator<< (ostream &os, MT a);
    /** Hàm tính thành tiền*/
    float thanhtien()
    {
        return sl*dongia;
    }
};
    /** Định nghĩa toán tử >>*/
    istream& operator>> (istream &is, MT &a)
    {
        a.nhap();
        cout<<"Nhap so luong may tinh: "; is>>a.sl;
        cout<<"Nhap toc do may tinh: "; is>>a.tocdo;
        return is;
    }
    /** Định nghĩa toán tử <<*/
    ostream& operator<< (ostream &os, MT a)
    {
        a.in();
        os<<setw(15)<<a.sl<<setw(15)<<a.tocdo;
        return os;
    }
class MTXT : public MT
{
    float trongluong;
public:
    /** Khởi tạo không tham số*/
    MTXT() : MT()
    {
        trongluong = 0;
    }
    /** Khởi tạo có tham số*/
    MTXT(float trongluong) : MT(ma,ten,dongia,sl,tocdo)
    {
        this->trongluong = trongluong;
    }
    ~MTXT(){}
    /** Hàm tính phí bảo trì*/
    float baotri()
    {
        return dongia*5/100;
    }
    friend istream& operator>> (istream &is, MTXT &a);
    friend ostream& operator<< (ostream &os, MTXT a);
    friend void Y6(MTXT &a);
    string get_ma()
    {
        return ma;
    }
    string get_ten()
    {
        return ten;
    }
    float get_tocdo()
    {
        return tocdo;
    }
};
    /** Hàm định nghĩa toán tử nhập của MTXT*/
    istream& operator>> (istream &is, MTXT &a)
    {
        is>>(MT&)a;
        cout<<"Nhap trong luong may tinh xach tay: "; is>>a.trongluong;
        return is;
    }
    /** Hàm định nghĩa toán tử xuất của MTXT*/
    ostream& operator<< (ostream &os, MTXT a)
    {
        os<<(MT&)a; 
        os<<setw(25)<<a.trongluong<<endl;
        return os;
    }
    void tieude_MTXT()
    {
        cout<<setw(20)<<"Ma hang hoa"<<setw(20)<<"Ten hang hoa"<<setw(20)<<"Don gia san pham"<<setw(15)<<"So luong"<<setw(15)<<"Toc do"<<setw(25)<<"Trong luong san pham"<<endl;
    }
    /** Hàm in n_MTXT*/
    void in_nMTXT(MTXT a[], int n)
    {
        tieude_MTXT();
        for(int i = 0; i < n; i++)
        {
            cout<<a[i];
        }
    }
    /** Hàm nhập danh sách máy tính xác tay, hiển thị danh sách */
    void Y1(MTXT a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\t[?] Nhap thong tin cho MTXT thu "<<i+1<<endl;
            cin>>a[i];
        }
        cout<<"\t\t----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\t[!] Thong tin cua "<<n<<" MTXT vua nhap la"<<endl;
        tieude_MTXT();
        for(int i = 0; i < n; i++)
        {
            cout<<a[i];
        }
    }
    /** Hàm tìm thông tin máy tính xác tay theo mã máy nhập từ bàn phím*/
    void Y2(MTXT a[], int n)
    {
        string ma;
        bool check = false;
        fflush(stdin);
        cout<<"\t[?] Nhap thong tin ma may can tim kiem: "; getline(cin, ma);
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_ma() == ma)
            {
                check = true;
                break;
            }
        }
        if(check == true)
        {
            cout<<"\t[!] Thong tin ma may ban dang tim kiem"<<endl;
            tieude_MTXT();
            for(int i = 0; i < n; i++)
            {
                if(a[i].get_ma() == ma)
                {
                    cout<<a[i];
                }
            }
        }     
        if(check == false)
            cout<<"\t[!] Thong tin ma may ban dang tim kiem khong co trong danh sach"<<endl;
    }
    /** Hàm liệt kê máy tính xách tay theo tên*/
    void Y3(MTXT a[], int n)
    {
        string ten;
        fflush(stdin);
        cout<<"\t[?] Nhap ten may tinh can in: "; getline(cin, ten);
        cout<<"\t[!] Thong tin may tinh co ten "<<ten<<endl;
        tieude_MTXT();
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_ten() == ten)
                cout<<a[i];
        }
    }
    /** Hàm tính phí bảo trì của các máy tính*/
    void Y4(MTXT a[], int n)
    {
        float tong = 0;
        for(int i = 0; i < n; i++)
        {
            tong += a[i].baotri();
        }
        cout<<"\t[!] Tong phi bao tri cua "<< n << " may tinh la: "<<tong<<endl;
    }
    /** Tìm máy tính xách tay có tốc độ nhỏ nhất*/
    void Y5(MTXT a[], int n)
    {
        int min = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[min].get_tocdo() > a[i].get_tocdo())
                min = i;
        }
        cout<<"\t[!] Thong tin may tinh co toc do nho nhat"<<endl;
        tieude_MTXT();
        cout<<a[min];
    }
    /** Hàm sửa thông tin một máy tính xách tay*/
    void Y6(MTXT &a)
    {
        int check;
        cout<<"\t\t[?] Nhap thong tin cua may tinh can sua:"<<endl
            <<"\t[1] Sua ten may tinh"<<endl
            <<"\t[2] Sua ma may tinh"<<endl
            <<"\t[3] Sua don gia may tinh"<<endl
            <<"\t[4] Sua toc do may tinh"<<endl
            <<"\t[5] Sua so luong may tinh"<<endl
            <<"\t[6] Sua trong luong may tinh"<<endl;
        cout<<"\t[?] Nhap lua chon cua ban: "; cin>>check;
        switch (check)
        {
            case 1:
            {
                fflush(stdin);
                cout<<"\t[?] Nhap lai ten may tinh can sua: "; getline(cin, a.ten);
                break;
            }
            case 2:
            {
                fflush(stdin);
                cout<<"\t[?] Nhap lai ma may tinh can sua: "; getline(cin, a.ma);
                break;
            }
            case 3:
            {
                cout<<"\t[?] Nhap lai don gia may tinh can sua: "; cin>>a.dongia;
                break;
            }
            case 4:
            {
                cout<<"\t[?] Nhap lai toc do may tinh can sua: "; cin>>a.tocdo;
                break;
            }
            case 5:
            {
                cout<<"\t[?] Nhap lai so luong may tinh can sua: "; cin>>a.sl;
                break;
            }
            case 6:
            {
                cout<<"\t[?] Nhap lai trong luong may tinh can sua: "; cin>>a.trongluong;
                break;
            }
            default:
            {
                cout<<"\t[!] Yeu cau cua ban khong hop le"<<endl;
                break;
            }
        }
    }
    /** Xoá một máy tính xách tay theo mã cho trước*/
    void Y7(MTXT a[], int &n)
    {
        string ma; int index = -1;
        fflush(stdin);
        cout<<"\t[?] Nhap ma may tinh can xoa: "; getline(cin , ma);
        for(int i = 0; i < n; i++)
        {
            if(a[i].get_ma() == ma)
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            cout<<"Ma may tinh khong co trong danh sach da nhap"<<endl;
        }
        else
        {
            for(int j = index; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            cout<<"\t[!] Da xoa thong tin may tinh co ma "<<ma<<endl;
        }
    }
    /** Hàm chèn thêm một máy tính xác tay tại vị trí k*/
    void Y8(MTXT a[], int &n)
    {
        int index;
        cout<<"\t[?] Nhap vi tri may tinh can chen: "; cin>>index;
        n++;
        for(int i = n; i >= index; i--)
        {
            a[i] = a[i - 1];
        }
        cout<<"\t[!] Nhap thong tin cho may tinh vua chen"<<endl;
        cin>>a[index - 1];
    }
    /** Hàm sắp xếp danh sách theo chiều tăng dần của mã máy*/
    void Y9(MTXT a[], int &n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i].get_ma() > a[j].get_ma())
                    swap(a[i], a[j]);
            }
        }
        cout<<"\t[!] Danh sach may tinh xach tay sap xep theo chieu tang dan cua ma may"<<endl;
        in_nMTXT(a, n);
    }
    /** Hàm chính nha*/
    void main_chinh()
    {
        MTXT a[100]; int n;
        cout<<"\t[?] Nhap so luong may tinh can quan li: "; cin>>n;
        while(true)
        {
            int result;
            cout<<"\t\t\t ~~~~~~~~~~ DANH SACH THAO TAC ~~~~~~~~~~"<<endl
                <<"\t\t[1] Nhap danh sach may tinh sach tay va in danh sach"<<endl
                <<"\t\t[2] Tim thong tin may tinh xach tay theo ma may nhap tu ban phim"<<endl
                <<"\t\t[3] Liet ke may tinh xach tay theo ten"<<endl
                <<"\t\t[4] Tinh phi bao tri cua danh sach may tinh da nhap"<<endl
                <<"\t\t[5] In may tinh co toc do nho nhat"<<endl
                <<"\t\t[6] Sua thong tin mot may tinh xach tay"<<endl
                <<"\t\t[7] Xoa mot may tinh xach tay"<<endl
                <<"\t\t[8] Chen thong tin mot may tinh"<<endl
                <<"\t\t[9] Sap xep danh sach theo chieu tang dan cua ma may"<<endl
                <<"\t\t[10] In danh sach may tinh xach tay"<<endl
                <<"\t\t[11] Thoat chuong trinh"<<endl;
            cout<<"\t[?] Nhap thao tac ban muon thuc hien: "; cin>>result;
            switch(result)
            {
                case 1:
                {
                    Y1(a, n);
                    break;
                }
                case 2:
                {
                    Y2(a, n);
                    break;
                }
                case 3:
                {
                    Y3(a, n);
                    break;
                }
                case 4:
                {
                    Y4(a, n);
                    break;
                }
                case 5:
                {
                    Y5(a, n);
                    break;
                }
                case 6:
                {
                    int index;
                    cout<<"\t[?] Nhap vi tri may tinh can sua thong tin: "; cin>>index;
                    Y6(a[index - 1]);
                    break;
                }
                case 7:
                {
                    Y7(a, n);
                    break;
                }
                case 8:
                {
                    Y8(a, n);
                    break;  
                }
                case 9:
                {
                    Y9(a, n);
                    break;
                }
                case 10:
                {
                    cout<<"\t\t[!] Danh sach may tinh xach tay da nhap "<<endl;
                    in_nMTXT(a, n);
                    break;
                }
            }
            if(result == 11)
            {
                cout<<"\t\t[!] Thoat chuong trinh thanh cong"<<endl;
                break;
            }
            cout<<"\t\t----------------------------------------------------------------------------------------------------"<<endl;
        }
    }
int main()
{
    main_chinh();
    // Sau khi gõ hơn 400 dòng code thì giờ test code nha mọi ngừi
    // Vậy là code ổn rồi nha mọi người
    // DONE
}