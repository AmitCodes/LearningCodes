#include <iostream>
using namespace std;

void merge_Sort(unsigned long long p , unsigned long long r , unsigned long long A[]);
void merge_arrays(unsigned long long p,unsigned long long q,unsigned long long r,unsigned long long A[]);
unsigned long long swappings = 0;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        unsigned long long l;
        cin >>l;
        unsigned long long arr[l];
        for(unsigned long long j = 0; j <l;j++)
        {
            cin>>arr[j];
        }
        merge_Sort(0,9,arr);
        cout<< swappings << endl;
        swappings = 0;
    }
    return 0;
}

void merge_Sort(unsigned long long p , unsigned long long r , unsigned long long *A)
{
    unsigned long long q;
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

void merge_arrays(unsigned long long p , unsigned long long q,unsigned long long r , unsigned long long *A)
{
    unsigned long long strt1 = p;
    unsigned long long end1 = q;
    unsigned long long strt2 = q+1;
    unsigned long long end2 = r;
    unsigned long long temp[r-p + 1];
    unsigned long long i = 0;
    while(strt1 <= end1 && strt2 <= end2 && i <= (r-p))
    {
        if(A[strt1] < A[strt2])
        {
            temp[i] = A[strt1];
            strt1++;
        }
        else if(A[strt1] > A[strt2])
        {
            temp[i] = A[strt2];
            strt2++;
            swappings++;
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
    unsigned long long j = 0;
    while(p<=r)
    {
        A[p] = temp[j];
        j++;
        p++;
    }
}
