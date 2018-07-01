#include <bits/stdc++.h>

using namespace std;
int check_anagram(string s1 ,string s2);

//From HackerRank
// Link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
// The below solution is a brute force way of solving it but it satisfies all the test cases.

int sherlockAndAnagrams(string s){
    // Complete this function
    int len = s.length();
    //cout<<"length of string = "<< len<<endl;
    int counter = 0;
    for(int i = 0; i < len ; i++)
    {
        for(unsigned int j = 1; j < len; j++)
        {
            char sub1[j+1];
            strncpy(sub1,&s[i],j);
            sub1[j] = '\0';
            for(int k=i+1; k<len-(j-1);k++)
            {
                char sub2[j+1];
                strncpy(sub2,&s[k],j);
                sub2[j] = '\0';
                //cout<<"sub1 = "<< sub1 << " sub2 = " << sub2 << endl;
                counter += check_anagram(sub1,sub2);
            }
        }
    }
    return counter;
}

int check_anagram(string s1 ,string s2)
{
    //cout<<" checking if anagram for "<<s1<<" and "<<s2<<endl;
    int l = s1.length();
    int i = 0;
    int a[26] = {0};
    while(i<l)
    {
        a[s1[i]-'a']++;
        a[s2[i]-'a']--;
        i++;
    }
    i = 0;
    while(i<26)
    {
        if(a[i] != 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}
