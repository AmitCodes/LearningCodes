#include<iostream>
using namespace std;
#include<vector>

void getSum(const vector<int> &l1, const vector<int> &l2, vector<int> &oSum, int k)
{
    if(k != 0)
        oSum.push_back(l1[0] + l2[0]);
    int l1r = 0;
    int l2r = 0;

    int n_larg = l2[1] + l1[0];
    int i=1, j=1;
    while(oSum.size() < k)
    {
        while( i < l1.size() && l2r < l2.size() && oSum.size() < k)
        {
            if(l1[i] + l2[l2r] <= n_larg)
            {
                oSum.push_back(l1[i] + l2[l2r]);
            }
            else
            {
                n_larg = l1[i] + l2[l2r];
                break;
            }
            i++;
            if(i == l1.size())
            {
                i = 0;
                l2r += 1;
            }
        }
        while( j < l2.size() && l1r < l1.size() && oSum.size() < k)
        {
            if(l2[j] + l1[l1r] <= n_larg)
            {
                oSum.push_back(l2[j] + l1[l1r]);
            }
            else
            {
                n_larg = l2[j] + l1[l1r];
                break;
            }
            j++;
            if(j == l2.size())
            {
                j = 0;
                l1r += 1;
            }
        }
    }
}

int main()
{
    // Enter the two sorted arrays
    vector<int> arr1 = {-1,3,5,7,9};
    vector<int> arr2 = {2,3,5,7,10};

    // enter the number of pair sum required
    int k;
    cin>>k;

    vector<int> sum;
    getSum( arr1, arr2, sum, k );

    for(int i=0; i< sum.size(); i++)
    {
        cout<<".."<<sum[i];
    }
}

