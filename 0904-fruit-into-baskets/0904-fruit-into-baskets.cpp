class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n=s.size();
        int low=0;
        int ans=0;
        unordered_map<int,int>freq;
        for(int high=0;high<n;high++){
            freq[s[high]]++;
            while(freq.size()>2){
                freq[s[low]]--;
                if(freq[s[low]]==0){
                    freq.erase(s[low]);
                }
                low++;
            }
            
            ans=max(ans,high-low+1);
            
        }
        
        return ans;
    }
};
