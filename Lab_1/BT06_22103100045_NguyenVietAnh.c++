#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class CN{
    char ht[30], quequan[20];
    int t;
    float bl;
public:
    CN(char *ht, char *quequan, int t, float bl)
    {  
        strcpy(this->ht, ht);
        strcpy(this->quequan, quequan);
        this->t = t;
        this->bl = bl;
    }
    void in()
    {
        cout<<setw(20)<<ht<<setw(20)<<quequan<<setw(10)<<t<<setw(10)<<bl<<endl;
    }
    float tienluong()
    {
        float luong = bl * 2500;
        return luong + luong*20/100;
    }
};
int main()
{
    //CN a(a, v, 20, 5000);
    cout<<setw(20)<<"Ho ten"<<setw(20)<<"Que quan"<<setw(10)<<"Tuoi"<<setw(10)<<"Bac luong"<<endl;
    //a.in();
    //cout<<"Tien luong cua nhan vien la: " << a.tienluong();
}

// DONE, vất vả cái char quá =)))))))