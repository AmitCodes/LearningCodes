#include <iostream>
using namespace std;

void merge_Sort(int p , int r , int A[]);
void merge_arrays(int p,int q,int r,int A[]);

int main()
{
    int a[10] = {15 , 4 , 6 ,14 , 19,8 ,3,6 , 10 ,13};
    merge_Sort(0,9,a);

    for(int i = 0;i <= 9;i++)
    {
        cout<<a[i]<<endl;
    }
}

void merge_Sort(int p , int r , int *A)
{
    //cout<<"merge_sort"<<endl;
    int q;
    if(p<r)
    {
        q = (p+r)/2;
    }
    else
    {
        return;
    }
    merge_Sort(p,q,A);
    merge_Sort(q+1,r,A);
    merge_arrays(p,q,r,A);
}

void merge_arrays(int p , int q,int r , int *A)
{
    //cout<<"merge_arrays"<<"p.."<<p<<"q.."<<q<<"r.."<<r<<endl;
    int strt1 = p;
    int end1 = q;
    int strt2 = q+1;
    int end2 = r;
    int temp[r-p + 1];
    int i = 0;
    while(strt1 <= end1 && strt2 <= end2 && i <= (r-p))
    {
           // cout<<"while"<<endl;
        if(A[strt1] < A[strt2])
        {
            temp[i] = A[strt1];
            strt1++;
        }
        else if(A[strt1] > A[strt2])
        {
            //cout<<"str2>str1"<<endl;
            //cout<<"A[strt1].."<<A[strt2]<<endl;
            temp[i] = A[strt2];
            //cout<<"A done"<<endl;
            strt2++;
            //cout<<"strt2"<<strt2<<endl;
        }
        else
        {
            temp[i] = A[strt1];
            temp[i+1]= A[strt2];
            strt1++;
            strt2++;
            i++;
        }
        i++;
    }
    while(strt1 <= end1)
    {
        temp[i] = A[strt1];
        strt1++;
        i++;
    }
    while(strt2 <= end2)
    {
        temp[i] = A[strt2];
        strt2++;
        i++;
    }
    int j = 0;
    while(p<=r)
    {
        A[p] = temp[j];
        j++;
       // cout<<"...p..."<<p<<endl<<"..A[p]..."<<A[p];
        p++;
    }
}


