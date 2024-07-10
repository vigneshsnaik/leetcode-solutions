// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int,int>>s;
    int i;
    StockSpanner() {
    }
    
    int next(int price) {
        int result=1;
        while(!s.empty()&&price>=s.top().first)
            result+=s.top().second,s.pop();
        s.push({price,result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */