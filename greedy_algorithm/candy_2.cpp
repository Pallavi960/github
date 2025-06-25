#include<iostream>
#include<vector>
using namespace std;

int sol(vector<int>&a)
{
   /* int n=a.size();
    vector<int>left(n,1);
    vector<int>right(n,1);
    int ans=0;
    //left[0]=a[0];
    for(int i=1;i<a.size();i++)
    {
       if(a[i]>a[i-1])
       {

           left[i]=left[i-1]+1;
       }
       else{
        left[i]=1;
       }
    }



    //right[n-1]=a[n-1];
    for(int j=n-2;j>=0;j--)
    {
        if(a[j]>a[j+1])
        {

            right[j]=right[j+1]+1;
        }
        else{

              right[j]=1;
        }
    }

    for(int k=0;k<a.size();k++)
    {
       ans+=max(left[k],right[k]);
    }
    return ans;*/
    int n=a.size();
    int sum=1,i=1;
    while(i<n)
    {

        if(a[i]==a[i-1])
        {
            sum+=1;
            continue;
        }
       int  peak=1;
        while(i<n && a[i]>a[i-1])
        {
            peak++;
            sum+=peak;

            i++;
        }
        int down=1;
        while(i<n && a[i]<a[i-1])
        {

            sum+=down;
            down++;
            i++;
        }
        if(peak>down)
        {
            sum+=peak-down;
            i++;
        }
    }
    return sum;

}


int main()
{
    vector<int>a={1,0,2};
    cout<<sol(a);

    return 0;
}
