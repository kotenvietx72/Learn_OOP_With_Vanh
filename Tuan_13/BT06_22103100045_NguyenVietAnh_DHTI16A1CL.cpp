#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
class Array
{
    T *ptr;
    int size;
public:
    Array(T arr[], int size)
    {
        this->size = size;
        ptr = new T[size];
        for(int i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }
    }
    void in()
    {
        for(int i = 0; i < size; i++)
            cout<<ptr[i]<<"\t";
        cout<<endl;
    }
    T sum()
    {
        T Sum = ptr[0];
        for(int i = 1; i < size; i++)
            Sum += ptr[i];
        return Sum;
    }
};

int main()
{
    int a[5] = {1, 5, 7, 3, 7};
    Array<int> arr1(a, 5);
    arr1.in();
    cout<<"\t [!] Tong cac gia tri trong mang la: "<<arr1.sum()<<endl;

    float b[5] = {5.6, 2.4, 5, 6.7, 1.7};
    Array<float> arr2(b, 5);
    arr2.in();
    cout<<"\t [!] Tong cac gia tri trong mang la: "<<arr2.sum()<<endl;
}