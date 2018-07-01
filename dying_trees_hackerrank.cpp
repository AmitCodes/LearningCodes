#include <bits/stdc++.h>
#include <queue>
#include<iostream>
using namespace std;


// Link to question:- https://www.hackerrank.com/challenges/poisonous-plants/problem

using namespace std;

int poisonousPlants(vector <int> p1) {
    int l = p1.size();
    queue<int> *q1 = new queue<int>();
    queue<int> *q2 = new queue<int>();
    while(l >0)
    {
        cout<< "...l..."<<l<<endl;
        q1->push(p1[p1.size()-l]);
        l--;
    }
    int count = 0, p = -1;
    queue<int> *temp;
    bool dead = false;
    while((!q1->empty()) || !(q2->empty()))
    {
        cout<<"..inside while loop..."<<endl;
        if(q1->empty())
        {
            cout<<"..q1 became empty..."<<endl;
            p = -1;
            temp = q1;
            q1 = q2;
            q2 = temp;
            if(!dead)
            {
                cout<<"..no one died so moving out of loop..."<<endl;
                break;
            }
            else
            {
                cout<<"..died some trees..."<<count<<endl;
                dead = false;
                count++;
            }
        }

        if(p == -1)
        {
            p = q1->front();
            q2->push(q1->front());
            q1->pop();
        }
        else
        {
            cout<<"..comparison time to kill someone...q1.front()"<<q1->front() << "..p.."<<p<<endl;
            if(q1->front() > p)
            {
                p = q1->front();
                q1->pop();
                dead = true;
            }
            else
            {
                q2->push(q1->front());
                p = q1->front();
                q1->pop();
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    int in;
    for(int p_i = 0; p_i < n; p_i++){
            cin>>in;
       p.push_back(in);
       cout<<"...taking input..."<<p_i;
    }
    int result = poisonousPlants(p);
    cout << result << endl;
    return 0;
}
