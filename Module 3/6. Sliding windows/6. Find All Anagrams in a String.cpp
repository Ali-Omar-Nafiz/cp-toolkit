// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s="abaacab";
    string p="baac";
    vector<int>s_cnt(26),p_cnt(26);
    int k=p.size();
    for(int i=0;i<k;i++){
        p_cnt[p[i]-'a']++;
    }
    for(int i=0;i<k;i++){
        s_cnt[s[i]-'a']++;
    }
    if(s_cnt==p_cnt){
        cout<<0<<" ";
    }
    int n=s.size();
    for(int i=0;i<n-k;i++){
        s_cnt[s[i]-'a']--;
        s_cnt[s[i+k]-'a']++;
        if(s_cnt==p_cnt)cout<<i+1<<" ";
    }
}
