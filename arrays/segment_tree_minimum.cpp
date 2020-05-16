#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<climits>

// This program is to
void print_array(const vector<int> &arr)
{
    for(int i=0; i< arr.size(); i++)
    {
        cout<<".."<<arr[i];
    }
    cout<<endl;
}

int log_c(int n)
{
    if (n == 1)
        return 0;
    return log_c(n/2) + 1;
}

// function creates segment tree
int segment_tree( vector<int> &arr, vector<int> &seg_arr, int low, int high, int index )
{
    int mid = ( low+high )/2;
    if(low != high)
    {
        int left_min = segment_tree(arr, seg_arr, low, mid, index*2 + 1);
        int right_min = segment_tree(arr, seg_arr, mid+1, high, index*2 + 2);
        int min_val = left_min < right_min ? left_min : right_min;
        seg_arr.at(index) = min_val;
        return min_val;
    }
    else
    {
        seg_arr.at(index) = arr[low];
        return arr[low];
    }
}

// this function gets the minimum value using the segment tree created in the above function
int get_min(auto seg_tree,int low, int high, int q_low, int q_high, int index = 0)
{
    int mid = (low+high)/2;
    if( low>= q_low && high <= q_high)
    {
        return seg_tree[index];
    }
    else if( (low < q_low && high < q_low) ||
             (low > q_high && high > q_high) )
    {
        return INT_MAX;
    }
    else
    {
        int l_min = get_min(seg_tree, low, mid, q_low, q_high, index*2+1);
        int r_min = get_min(seg_tree, mid+1, high, q_low, q_high, index*2+2);
        return (l_min < r_min ? l_min : r_min);
    }
}
int main()
{
    vector<int> arr = {3,1,0,-1,4,-2,3,1};
    print_array(arr);
    int seg_arr_size = pow(2, log_c(arr.size()))*2 - 1;
    vector<int> seg_tree( seg_arr_size, INT_MAX );

    segment_tree(arr, seg_tree, 0, arr.size()-1, 0);
    print_array(seg_tree);

    // here we pass the range to get min of it.
    int q_low = 0, q_high = 2;
    cout << "Min Value is " << get_min(seg_tree, 0, arr.size()-1, q_low, q_high) << endl;
}


