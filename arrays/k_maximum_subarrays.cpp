#include<iostream>
using namespace std;
#include<vector>
#include<limits>

// Function to compute prefix-sum of the input array
vector<int> prefix_sum(vector<int> arr, int n)
{
    vector<int> pre_sum;
    pre_sum.push_back(arr[0]);
    for (int i = 1; i < n; i++)
        pre_sum.push_back(pre_sum[i - 1] + arr[i]);
    return pre_sum;
}

void print_array(const vector<int> &arr)
{
    for(int i=0; i< arr.size(); i++)
    {
        cout<<".."<<arr[i];
    }
    cout<<endl;
}

void maximize(const vector<int> &temp, vector<int> &maxi, int k)
{
    int j = maxi.size()-1;
    for( int i=temp.size()-1 ; i >= 0 ; i-- )
    {
        while( j >= 0 && temp[i] >= maxi[j] )
            j--;

        if(j >= 0)
        {
            maxi.insert( maxi.begin()+j+1, temp[i] );
        }

        while ( j == -1 && i >= 0 )
        {
            maxi.insert( maxi.begin(), temp[i] );
            i--;
        }
    }
    while( maxi.size() > k )
        maxi.erase( maxi.end()-1, maxi.end() );
}

void minimize( vector<int> &mini, int prefix_sum, int k )
{
    // mini size can be max of k
    int i = 0;
    for( i=0; i<mini.size(); i++ )
    {
        if( prefix_sum < mini[i] )
        {
            mini.insert( mini.begin()+i, prefix_sum );
            break;
        }
    }
    if( i == mini.size() )
        mini.push_back( prefix_sum );

    //cout<<"mini size = "<< mini.size()<<endl;
    if( mini.size() > k )
        mini.erase( mini.end()-1, mini.end() );
}

int main()
{
    vector<int> arr = {2,-3,7,4,-4,6,-3,2,9};

    // enter the number of prefix sums required
    int k;
    cin >> k;

    vector<int> temp;
    vector<int> maxi;
    vector<int> mini;

    vector<int> pref_sum = prefix_sum( arr, arr.size() );

    cout << "prefix sum is "<<endl;
    print_array(pref_sum);
    // pushing the first element as 0
    mini.push_back(0);
    for(int i=0; i<arr.size(); i++)
    {
        int j = 0;
        temp.clear();
        while(j < mini.size())
        {
            temp.push_back( pref_sum[i] - mini[j] );
            j++;
        }

        //cout<< " temp array is "<<endl;
        //print_array(temp);
        //cout<< " maxi array is "<<endl;
        //print_array(maxi);
        maximize(temp, maxi, k);
        minimize(mini, pref_sum[i], k);
        //cout<< " mini array is "<<endl;
        //print_array(mini);
        //cout<< " maxi array is "<<endl;
        //print_array(maxi);

    }
    //cout<< " mini array is "<<endl;
    //print_array(mini);
    cout<< " maxi array is "<<endl;
    print_array(maxi);
}
