#include<iostream>
using namespace std;
int find_max_subarray(int first , int last , int *A);
int find_cross_sum(int first ,int mid ,int last ,int *A);
int main()
{
    int A[10] = {2 , 16 , -8 , -5 , -12 , -17 , 21 , -9 , -14 , -15};
    int sum = find_max_subarray(0,9,A);
    for(int i=0; i < 10 ; i++)
    {
        cout<<A[i]<<endl;
    }
    cout<< "sum.."<<sum<<endl;
}

int find_max_subarray(int first , int last , int *A)
{
    int cross_sum ;
    int left_sum ;
    int right_sum;
    int mid;
    if(first == last)
    {
        return A[first];
    }
    else
    {
         mid = (first + last)/2;
        left_sum = find_max_subarray(first , mid , A);
        right_sum = find_max_subarray(mid+1, last , A);
        cout<<"...firstArray...";
        for(int i =0;i <= mid; i++)
        {
            cout << A[i] << " ";
        }
        cout<< endl;
        cout<<"...second Array...";
        for(int i = mid + 1;i <= last; i++)
        {
            cout << A[i] << " ";
        }
        cout<< endl;
        cross_sum = find_cross_sum(first , mid , last , A);
        if(left_sum > right_sum && left_sum > cross_sum)
        {
            return left_sum;
        }
        else if(right_sum > left_sum && right_sum > cross_sum)
        {
            return right_sum;
        }
        else
        {
            return cross_sum;
        }
    }
}

int find_cross_sum(int first , int mid , int last , int *A)
{
    int i = mid;
    int left_sum = -100;
    int right_sum = -100;
    int sum = 0;
    while(i>=0)
    {
        sum += A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
        }
        i--;
    }
    sum = 0;
    i= mid + 1;
    while(i <= last)
    {
        sum += A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
        }
        i++;
    }
    return (left_sum + right_sum);
}

