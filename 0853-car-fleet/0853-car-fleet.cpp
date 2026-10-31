class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
       vector<pair<int,int>>st;
       for( int i =0;i<n;i++){
        st.push_back({position[i],speed[i]});
       } 
       sort(st.rbegin(),st.rend());
       int f = 1;
       double p = (double)(target-st[0].first)/st[0].second;
       for(int i =1;i<n;i++){
        double c = (double)(target-st[i].first)/st[i].second;
        if(c>p){
            f++;
            p = c;

        }
       }
       return f;
    }
};