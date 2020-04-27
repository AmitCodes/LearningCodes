#include<vector>
#include <iostream>
using namespace std;

int findPivot(vector<int>& nums)
    {
        // cout<< "findPivot"<<nums.size()<<endl;
        int left  = 0 ;
        int right = nums.size()-1;
        int mid = (left + right)/2;
        while( left <= right )
        {
            mid = (left + right)/2;
            // cout<< "mid" << mid << ".."<<nums[mid]<<".."<<nums[right] <<".."<< nums[left];
            if(nums[mid] >= nums[right])
            {
                left = mid +1;
                // cout<< " changing left to "<<left;
            }
            else if(nums[mid] <= nums[0])
            {
                right = mid -1;
                // cout<< " changing right to "<<right;
            }
            else
            {
                return 0;
            }
            // case if there is no rotation in the array
            //if(mid - 1 < 0)
              //  return mid;
            if(mid - 1 >= 0 && nums[mid] < nums[mid-1])
                return mid;
        }
        return 0;
    }


    int binarySearch(vector<int>& nums, int left, int right, int target)
    {
        // cout<< "binarySearch"<<endl;
        int mid = (left+right)/2;
        if(left <= right)
        {
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid] && target <= nums[nums.size()-1])
                return binarySearch(nums, mid + 1, right, target);
            else
                return binarySearch(nums, left, mid-1, target);
        }
        return -1;
    }

int search_ele(vector<int>& nums, int target) {

        // priting array
        // cout<< "printing array ";
        // for(int i=0; i<nums.size(); i++)
        // {
        //     cout<<".."<<nums[i];
        // }
        int pivot = 0;
        pivot = findPivot(nums);
        cout<<"pivot is " << pivot;
        // serach now
        if(target == nums[pivot])
            return pivot;
        else if(target > nums[pivot])
        {
            return binarySearch(nums, pivot+1, nums.size()-1, target);
        }
        else if (pivot != 0)
        {
            return binarySearch(nums, 0, pivot-1, target);
        }
        else
        {
            return -1;
        }

    }
int main()
{
    vector<int> vect{1,3,5};
    cout<< search_ele(vect,0);
}

