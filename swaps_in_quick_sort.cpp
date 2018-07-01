#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void quick_sort_ascending(long long A[] , long long p , long long r);
void quick_sort_descending(long long A[] , long long p , long long r);
void swap_address_values(long long *a , long long *b);
long long partition(long long A[] , long long p , long long r);
long long descending_partition(long long A[] , long long p , long long r);
map<long long, long long> mp ;
typedef struct data
{
    long long data;
    bool visited;
}my_data;

int count_swap(my_data A[], map<long long, long long> mp, long long length);

long long swap_cnt = 0;
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */
    long long inp;
    cin >> inp;
    long long A[inp] , C[inp];
    my_data B[inp];
    for(long long i = 0;i< inp; i++)
    {
        cin>>A[i];
        C[i] = A[i];
        B[i].data = A[i] ;
        B[i].visited = false;
    }
    quick_sort_ascending(A , 0 , inp-1);
    quick_sort_descending(C , 0 , inp-1);
    for(long long i = 0;i< inp; i++)
    {
        mp[A[i]] = i;
    }
    int swap_cnt1 = count_swap(B,mp,inp);
    mp.clear();
    for(long long i = 0;i< inp; i++)
    {
        mp[C[i]] = i;
        B[i].visited = false;
    }
    int swap_cnt2 = count_swap(B , mp , inp);
    cout << (swap_cnt1 < swap_cnt2 ? swap_cnt1 : swap_cnt2);
}
void quick_sort_ascending(long long A[] , long long p , long long r)
{
    long long q;
    if(p<r)
    {
        q = partition(A , p , r);
        quick_sort_ascending(A , p , q-1);
        quick_sort_ascending(A , q+1 , r);
    }
}

void quick_sort_descending(long long A[] , long long p , long long r)
{
    long long q;
    if(p<r)
    {
        q = descending_partition(A , p , r);
        quick_sort_descending(A , p , q-1);
        quick_sort_descending(A , q+1 , r);
    }
}

long long partition(long long A[] , long long p , long long r)
{
    long long i = p-1;
    long long j = p;
    long long x = A[r];
   // cout << "...x = "<<x <<endl;
    while(j < r)
    {
        if(A[j] < x)
        {
            i++;
            /*if(i != j)
            {
                swap_cnt++;
                cout << "i = "<<i+1 << " swapped with j = "<<j << endl;
            }*/
            swap_address_values(&A[i] , &A[j]);
        }
        j++;
    }
    /*if(i+1 != r)
    {
        swap_cnt++;
        cout << "i = "<<i+1 << " swapped with r = "<<r << endl;
    }*/
    swap_address_values(&A[i+1] , &A[r]);
    return (i+1);
}

long long descending_partition(long long A[] , long long p , long long r)
{
    long long i = p-1;
    long long j = p;
    long long x = A[r];
   // cout << "...x = "<<x <<endl;
    while(j < r)
    {
        if(A[j] > x)
        {
            i++;
            /*if(i != j)
            {
                swap_cnt++;
                cout << "i = "<<i+1 << " swapped with j = "<<j << endl;
            }*/
            swap_address_values(&A[i] , &A[j]);
        }
        j++;
    }
    /*if(i+1 != r)
    {
        swap_cnt++;
        cout << "i = "<<i+1 << " swapped with r = "<<r << endl;
    }*/
    swap_address_values(&A[i+1] , &A[r]);
    return (i+1);
}

void swap_address_values(long long *a , long long *b)
{
    if(*a != *b)
    {
        swap_cnt++;
    }
    long long temp = *a;
    *a = *b;
    *b =temp;
}

int count_swap(my_data A[],map<long long, long long> mp , long long length)
{
    long long j = 0 , i = 0;
    long long cnt = 0;
    while(j < length)
    {
        i = j;
        if(false == A[j].visited)
        {
            while(mp[A[i].data] != j)
            {
                //cout<< "...A[i].data..."<<A[i].data<<endl;
                A[i].visited = true;
                i = mp[A[i].data];
                cnt++;
            }
            A[i].visited = true;
        }
        j++;
    }
    return cnt;
}
