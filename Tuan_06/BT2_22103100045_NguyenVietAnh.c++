#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class mydate
{
protected:
    int d, m, y;
public:
    mydate()
    {
        d = 0; m = 0; y = 0;
    }
    mydate(int d, int m, int y)
    {
        this->d=d;
        this->m=m;
        this->y=y;
    }
    ~mydate(){}
    void in()
    {
        cout<<"\t"<<d<<"\\"<<m<<"\\"<<y;
    }
};
class person : public mydate
{
    string name, address;
    int phone;
public:
    person()
    {
        name = ""; address = "";
        phone = 0;
    }
    person(string name, string address, int phone)
    {
        this->name = name;
        this->address = address;
        this->phone = phone;
    }
    ~person(){}
    void in()
    {
        cout<<setw(15)<<name<<setw(15)<<address<<setw(15)<<phone;
        mydate::in();
        cout<<endl;
    }
    bool operator> (person a)
    {
        return this->y > a.y;
    }
    void nhap()
    {
        cin.ignore();
        cout<<"Nhap ten: "; getline(cin, name);
        cout<<"Nhap dia chi: "; getline(cin, address);
        cout<<"Nhap so dien thoai: "; cin>>phone;
        cout<<"Nhap lan luot ngay thang nam sinh: "; cin>>d>>m>>y;
    }
};
    void nhap_nperson(person a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<"\t[!] Nhap thong tin cho person thu "<<i+1<<endl;
            a[i].nhap();
        }
    }
    void in_nperson(person a[], int n)
    {
        cout<<setw(15)<<"Ho va ten"<<setw(15)<<"Dia chi"<<setw(15)<<"So Dien Thoai"<<setw(10)<<"Sinh"<<endl;
        for(int i = 0; i < n; i++)
        {
            a[i].in();
        }
    }
    void sapxep_tang(person a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1 ; j < n; j++)
            {
                if(a[i] > a[j])
                    swap(a[i], a[j]);
            }
        }
        cout<<"\t[!] Danh sach person theo tang dan cua nam sinh"<<endl;
        in_nperson(a, n);
    }
    void sapxep_giam(person a[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1 ; j < n; j++)
            {
                if(a[j] > a[i])
                    swap(a[i], a[j]);
            }
        }
        cout<<"\t[!] Danh sach person theo giam dan cua nam sinh"<<endl;
        in_nperson(a, n);
    }
int main()
{
    person a[100]; int n;
    cout<<"\t[?] Nhap so luong person can quan li: "; cin>>n;
    nhap_nperson(a, n);
    sapxep_giam(a, n);
    sapxep_tang(a, n);
}
// Done
