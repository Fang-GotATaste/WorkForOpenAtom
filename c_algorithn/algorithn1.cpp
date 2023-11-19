#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
string Plus(string num1, string num2)
{
    string res;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int jinwei = 0;
    while (index1 >= 0 || index2 >= 0 || jinwei != 0)
    {
        int n1, n2;
        if (index1 < 0)
            n1 = 0;
        else
            n1 = num1[index1--] - '0';
        if (index2 < 0)
            n2 = 0;
        else
            n2 = num2[index2--] - '0';
        int r1 = n1 + n2 + jinwei;
        jinwei = r1 / 10;
        int r2 = r1 % 10;
        res.insert(res.begin(), r2 + '0');
    }
    return res;
}
string Minus(string num1, string num2)
{
    string res;
    int index1 = num1.size() - 1, index2 = num2.size() - 1;
    int jinwei = 0;
    while (index1 >= 0 || index2 >= 0 || jinwei != 0)
    {
        int n1, n2;
        if (index1 < 0)
            n1 = 0;
        else
            n1 = num1[index1--] - '0';
        if (index2 < 0)
            n2 = 0;
        else
            n2 = num2[index2--] - '0';
        if (n1 < n2)
        {
            n1 += 10;
            num1[index1] -= 1;
        }
        int r = n1 - n2;
        res.insert(res.begin(), r + '0');
    }
    return res;
}
int main()
{
    string num1, num2;
    getline(cin, num1);
    getline(cin, num2);
    int check1 = 0, check2 = 0;
    if (num1[0] == '-')
        check1++;
    if (num2[0] == '-')
        check2++;
    num1.erase(0, 1);
    num2.erase(0, 1);
    if ((check1 + check2) == 2)
    {
        cout << '-' << Plus(num1, num2) << endl;
        return 0;
    }
    if ((check1 + check2) == 0)
    {
        cout << Plus(num1, num2) << endl;
        return 0;
    }
    if (check1 == 1)
    {
        if(num1>num2)
            cout<<'-'<<Minus(num1,num2)<<endl;
        else cout<<Minus(num2,num1)<<endl;
    }
    else 
    {
        if(num1>num2)
            cout<<Minus(num1,num2)<<endl;
        else cout<<'-'<<Minus(num2,num1)<<endl;
    }
    return 0;
}
