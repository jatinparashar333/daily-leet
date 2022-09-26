class Solution {
public:
    
    bool find_path(char a,char b,vector<bool> &vis,vector<vector<char>> &adj){
        if(a==b){
            return true;
        }
        bool ans=false;
        int k=a-'a';
        int n=adj[k].size();
        for(int i=0;i<n;i++){
            if(vis[adj[k][i]-'a']==false){
                vis[adj[k][i]-'a']=true;
                ans = ans || find_path(adj[k][i],b,vis,adj);
            }
        }
        return ans;
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<vector<char>> adj(26);
        for(int i=0;i<n;i++){
            string s=equations[i];
            if(s[1]=='='){
                adj[s[0]-'a'].push_back(s[3]);
                adj[s[3]-'a'].push_back(s[0]);
            }
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(26,false);
            string s=equations[i];
            if(s[1]=='!'){
                if(find_path(s[0],s[3],vis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};