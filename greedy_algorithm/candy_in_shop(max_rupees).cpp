#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//in the case of minimum code first prioraty is the low cost candy
int find_min_cost(vector<int>&candy,int k)
{
   sort(candy.begin(),candy.end());
   int cost=0;
   int i=candy.size()-1,j=0;
   while(j<i)
   {

      cost+=candy[i];//add cost of the candy
      j+=k;//get free candys
      i--;
   }
   return cost;
}


int main()
{
    vector<int>candy={5,3,2,1,4};
    cout<<find_min_cost(candy,2);
    return 0;
}
