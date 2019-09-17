#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class PS
{
    int ts, ms;
public:
    PS operator+(PS y);// các phương thức toán tử;
    PS operator-(PS y);
    PS operator*(PS y);
    PS operator/(PS y);
    double operator-(); //tính giá trị PS;
    friend istream&operator>>(istream& x, PS& y);// hàm toán tử nhập
    friend ostream&operator<<(ostream& x, PS y);//hàm toán tử xuất
};
istream&operator>>(istream& x, PS& y)
{
    cout<<"tu so: "; x>>y.ts;
    cout<<"mau so: "; x>>y.ms;
    return x;
}
ostream&operator<<(ostream& x, PS y)
{
    x<<y.ts<<"/"<<y.ms<<endl;
    return x;
}
PS PS::operator+(PS y)
{
    PS tg;
    tg.ts=ts*y.ms+ms*y.ts;
    tg.ms=ms*y.ms;
    return tg;
}
PS PS::operator-(PS y)
{
    PS tg;
    tg.ts=ts*y.ms-ms*y.ts;
    tg.ms=ms*y.ms;
    return tg;
}
PS PS::operator*(PS y)
{
    PS tg;
    tg.ts=ts*y.ts;
    tg.ms=ms*y.ms;
    return tg;
}
PS PS::operator/(PS y)
{
    PS tg;
    tg.ts=ts*y.ms;
    tg.ms=ms*y.ts;
    return tg;
}
double PS::operator-()//thuộc toán tử 1 ngôi, lấy trong class. class nhập a và là thuộc đối thứ nhất
{
    return (double) ts/ms;
}
int main()
{
    PS a,b;
    cout<<"nhap phan so thu nhat: "<<endl; cin>>a;
    cout<<"nhap phan so thu 2: "<<endl; cin>>b;
    PS Tong=a+b;
    PS Hieu=a-b;
    PS Tich=a*b;
    PS Thuong=a/b;
    ofstream f("Tenfile.txt",ios::app);
        f<<a<<"+"<<b<<"="<<Tong<<"="<<-Tong<<endl;
        f<<a<<"-"<<b<<"="<<Hieu<<"="<<-Hieu<<endl;
        f<<a<<"*"<<b<<"="<<Tich<<"="<<-Tong<<endl;
        f<<a<<"/"<<b<<"="<<Thuong<<"="<<-Thuong<<endl;
    f.close();
    ifstream f1("Tenfile.txt",ios::in);
        char s[200];
        while(!f1.eof())
        {
            f1.getline(s,200);
            cout<<s<<endl;
        }
        f1.close();
    return 0;
}
