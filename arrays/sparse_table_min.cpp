#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<climits>

void print_array(int arr[], int n)
{
    for(int i=0; i< n; i++)
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

vector<vector<int>> form_ap_table(int arr[], int n)
{
    // row and column of sparse table
    int r_sp = log_c(n);
    int c_sp = n;

    vector<vector<int>> sp_t(r_sp+1);

    // fill the table

    // fill first row with actual array elements
    for(int i=0; i<n; i++)
    {
        sp_t.at(0).push_back(arr[i]);
    }

    // filling the rest rows
    for(int i=1; i<= r_sp; i++)
    {
        for(int j=0; j<n; j++)
        {
            // gets the size of the array to be compared
            int comp_range = pow(2, i-1);

            if( j+comp_range < n && sp_t[i-1][j+comp_range] != INT_MIN)
            {
                sp_t.at(i).push_back( min(sp_t[i-1][j], sp_t[i-1][j+comp_range]) );
            }
            else
            {
                sp_t.at(i).push_back(INT_MIN);
            }
        }
    }

    return sp_t;
}

int get_min_query(int l, int r, auto sp_t)
{
    int r_q = log_c((r-l)+1);
    return min(sp_t[r_q][l], sp_t[r_q][r - pow(2, r_q) + 1]);
}

int main()
{
    int arr[7] = {2,7,3,0,1,4,5};

    print_array(arr, 7);
    // form sparse table and initialize it
    vector<vector<int>> sp_t = form_ap_table(arr, 7);

    // accept query and get the min of the range
    cout<<"query range (2,4) min is " << get_min_query(2, 4, sp_t)<<endl;
    cout<<"query range (3,6) min is " << get_min_query(3, 6, sp_t)<<endl;
    cout<<"query range (0,2) min is " << get_min_query(0, 2, sp_t)<<endl;
    cout<<"query range (4,6) min is " << get_min_query(4, 6, sp_t)<<endl;
    cout<<"query range (1,1) min is " << get_min_query(1,1, sp_t)<<endl;
    cout<<"query range (5,6) min is " << get_min_query(5, 6, sp_t)<<endl;
}


