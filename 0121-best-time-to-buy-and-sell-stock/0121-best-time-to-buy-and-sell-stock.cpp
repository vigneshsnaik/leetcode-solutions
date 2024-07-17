class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int max_profit=0;
        for(int i=1;i<prices.size();++i){
            if(prices[i]<min)min=prices[i];
            int profit=prices[i]-min;
            if(profit>max_profit)max_profit=profit;
        }
        return max_profit;
 
    }
};