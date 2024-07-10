// https://leetcode.com/problems/reveal-cards-in-increasing-order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        deque<int>q;
        sort(deck.begin(),deck.end());
        for(auto i=deck.rbegin();i!=deck.rend();i++){
            q.push_back(q.front());
            q.pop_front();
            q.push_back(*i);
        }
    vector<int> res;
        while(!q.empty()){
            res.push_back(q.back());
            q.pop_back();
        }
        return res;
    }
};