class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elemFreq;
        for(int i=0; i < nums.size(); i++)
        {
            if(elemFreq.find(nums[i]) == elemFreq.end())
            {
                elemFreq[nums[i]] = 1;
            }
            else
            {
                elemFreq[nums[i]] += 1;
            }
        }

        // push the elements inside the min heap as per their frequency
        // Creating heap here
        vector<int> heap;
        map<int, int>::iterator elemFreqIter = elemFreq.begin();
        while(elemFreqIter != elemFreq.end())
        {
            InsertIntoHeap(nums, heap, elemFreq, elemFreqIter, k);
            elemFreqIter ++;
        }

        return heap;

    }

    void InsertIntoHeap(vector<int> &nums, vector<int> &heap, map<int, int> &elemFreq, map<int,
                         int>::iterator &elemFreqIter, int k)
    {
        int element = elemFreqIter->first;
        cout<<"element is "<<element<<endl;
        if( heap.size() == 0 )
        {
            heap.push_back(element);
            cout<<"entered into 0 heap size use case "<<endl;
        }
        else
        {
            cout<<"elemFreq[heap[0]] .."<<elemFreq[heap[0]]<<endl;
            if(heap.size() < k)
            {
                cout<<"entered into less than k heap size use case "<<endl;
                heap.push_back(element);
                int i = heap.size() - 1;
                while( parent(i) != -1 && elemFreq[heap[i]] < elemFreq[heap[parent(i)]] )
                {
                    cout<<"swapped here 11"<<endl;
                    swap( heap, i, parent(i) );
                    i = parent(i);
                }
            }
            else if( elemFreq[heap[0]] < elemFreq[element] )
            {
                cout<<"entered into equal to k heap size use case "<<endl;
                int i = 0;
                int j = i;
                heap[0] = element;
                while( rightChild(heap, j) != -1 || leftChild(heap, j) != -1)
                {
                    i = j;
                    if( leftChild(heap, i) != -1 && elemFreq[heap[leftChild(heap, i)]] < elemFreq[heap[j]])
                        j = leftChild(heap, i);
                    if( rightChild(heap, i) != -1 && elemFreq[heap[rightChild(heap, i)]] < elemFreq[heap[j]])
                        j = rightChild(heap, i);

                    if( j != i )
                        swap(heap, j, i);
                    else
                        break;
                }
            }
        }
    }

    int parent(int i)
    {
        if( (i-1)/2 >= 0 )
            return (i-1)/2;
        return -1;
    }
    int rightChild( const vector<int> &heap, int i )
    {
        if( i*2+2 <  heap.size() )
            return i*2+2;
        return -1;
    }
    int leftChild(const vector<int> &heap, int i)
    {
        if( i*2+1 <  heap.size() )
            return i*2+1;
        return -1;
    }

    void swap(vector<int> &arr, int first, int second)
    {
        int c = arr[first];
        arr[first] = arr[second];
        arr[second] = c;
    }
};
