#include<iostream>
#include<vector>
using namespace std;

vector<int> min_coin(int n)
{
    vector<int>ans;
    vector<int>a={2000,500,200,100,50,20,10,5,2,1};//coins avalible
    while(n>0)
    {
        for(int i=0;i<a.size();i++)
        {
            int c=n/a[i];
            while(c--)//how many time that coin will be taken
            {
                ans.push_back(a[i]);
            }
            n=n%a[i];
        }
    }
    return ans;
}
int main()
{
    int n=243;
    vector<int>ans=min_coin(n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
