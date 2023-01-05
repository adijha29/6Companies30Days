class Solution {
public:
    void generateComb(int prev,int k,int n,vector<int>&st,set<vector<int>>&sst,vector<bool>&mp){
        if(n==0){
            if(k==0)sst.insert(st);
            return;
        }
        
        if(k<=0){
            return;
        }
        for(int i=prev+1;i<=9;i++){
            if(mp[i]==false){
                // cout << n << " " << k << " " << i << endl;
                mp[i] = true;
                st.push_back(i);
                generateComb(i,k-i,n-1,st,sst,mp);
                st.pop_back();
                mp[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> sst;
        vector<int> st;
        vector<bool> mp(10,false);
        
        generateComb(0,n,k,st,sst,mp);

        vector<vector<int>> v(sst.size());
        int i = 0;
        for(auto &x:sst){
            v[i] = x;
            i++;
        }
        cout << sst.size() << endl;

        return v;
    }
};