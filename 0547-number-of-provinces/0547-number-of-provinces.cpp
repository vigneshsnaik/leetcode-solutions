class Solution {
public:
    vector<bool>cities;
    int n;
    void conquer(vector<vector<int>>& isConnected,int k){
        if(cities[k])return;
        cities[k]=true;
        for(int i=0;i<n;i++)
            if(isConnected[i][k])conquer(isConnected,i);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        int provinces=0;
        cities.resize(n,false);
        for(int i=0;i<n;i++){
            if(!cities[i]){
                provinces++;
                conquer(isConnected,i);
            }
        }
        return provinces;
    }
};