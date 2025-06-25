#include<iostream>
#include<vector>
using namespace std;

bool is_possible(vector<int>&a)
{
    int reach=0;
    int i;
    for( i=0;i<a.size();i++)
    {
        if(i>reach)return false;
        reach=max(reach,i+a[i]);
    }
     return true;
}

int main()
{
    vector<int>a={0,0,1,0,4};
    if(is_possible(a))cout<<"Yes";
    else
        cout<<"no";
    return 0;
}
