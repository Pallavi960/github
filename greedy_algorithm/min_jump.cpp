#include<iostream>
#include<vector>
using namespace std;

int get(vector<int>&a,int index,int jump)
{
   if(index>=a.size()-1)return jump;
   int minn=INT_MAX;
   for(int i=1;i<=a[index];i++)
   {
       minn=min(minn,get(a,index+1,jump+1));
   }
   return minn;

}

int main()
{
    vector<int>a={2,3,1,1,4};
    cout<<get(a,0,0);

    return 0;
}
