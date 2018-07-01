#include <iostream>
using namespace std;

void merge_Sort(unsigned long long p , unsigned long long r , unsigned long long A[]);
void merge_arrays(unsigned long long p,unsigned long long q,unsigned long long r,unsigned long long A[]);
unsigned long long swappings = 0;

int main()
{
    unsigned long long N;
    cin>>N;
    //cout<< "...N...."<<N<<endl;
    unsigned long long l;
    unsigned long long i = 0;
    unsigned long long a[N];
    while(i < N)
    {
        //cout<<"...i..."<<i<<endl;
        cin >> a[i];
        l = a[i];
        unsigned long long arr[l];
        for(unsigned long long j = 0; j <l;j++)
        {
            cin>>arr[j];
        }
        merge_Sort(0,l-1,arr);
        cout<< swappings << endl;
        /*for(unsigned long long i = 0;i<l;i++)
        {
            cout<<arr[i]<<endl;
        }*/
        //delete []arr;
        swappings = 0;
        i++;
        //cout<<"...i..."<<i<<endl;
        //cout<<"....N..."<<N;
    }
    return 0;
}

void merge_Sort(unsigned long long p , unsigned long long r , unsigned long long A[])
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

void merge_arrays(unsigned long long p , unsigned long long q,unsigned long long r , unsigned long long A[])
{
    unsigned long long strt1 = p;
    unsigned long long end1 = q;
    unsigned long long strt2 = q+1;
    unsigned long long end2 = r;
    unsigned long long temp[r-p + 1];
    unsigned long long i = 0;
    while(strt1 <= end1 && strt2 <= end2 && i <= (r-p))
    {
        if(A[strt1] <= A[strt2])
        {
            temp[i] = A[strt1];
            //cout<<"...not Swapping.."<<"..A[str1]..."<<A[strt1]<<"..A[str2]..."<<A[strt2]<<endl;
            strt1++;
        }
        else if(A[strt1] > A[strt2])
        {
            temp[i] = A[strt2];
            //cout<< "...swapping..."<<"..A[str1]..."<<A[strt1]<<"..A[str2]..."<<A[strt2]<<endl;
            unsigned long long i = strt1;
            while( i <= end1 )
            {
                if(A[i] > A[strt2])
                    swappings++;
                else
                    break;
                i++;
            }
            strt2++;
        }
        /*else
        {
            temp[i] = A[strt1];
            temp[i+1]= A[strt2];
            cout<< ".. equals..."<<"..A[str1]..."<<A[strt1]<<"..A[str2]..."<<A[strt2]<<endl;
            strt1++;
            strt2++;
            i++;
        }*/
        i++;
    }
    while(strt1 <= end1)
    {
        temp[i] = A[strt1];
        //cout<< ".. str1 remaining..."<<"..A[str1]..."<<endl;
        strt1++;
        i++;
    }
    while(strt2 <= end2)
    {
        temp[i] = A[strt2];
        //cout<< ".. str2 remaining..."<<"..A[str2]..."<<A[strt2]<<endl;
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


