#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job{
    int id;
    int time;
    int profit;
};
bool comp(job a,job b)
{
    return b.profit<a.profit;//reverse order sorting according to profit
}

int max_size(vector<job>&a)
{
    int max_ele=0;
    for(int i=0;i<a.size();i++)
    {
        max_ele=max(max_ele,a[i].time);
    }
    return max_ele;
}


int sol(vector<job>&a)
{
    int profit=0;
    sort(a.begin(),a.end(),comp);
    int max_ele=max_size(a);
    vector<int>temp(max_ele,0);
    for(int i=0;i<a.size();i++)
    {
        if(temp[(a[i].time-1)]!=1)
        {
            (temp[a[i].time-1])=1;
            profit+=a[i].profit;
        }
        else{
            continue;
        }

    }
    return profit;

}

int main()
{
    vector<job>a(4);
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i].id;
        cin>>a[i].time;
        cin>>a[i].profit;
    }
    cout<<sol(a);

    return 0;
}
