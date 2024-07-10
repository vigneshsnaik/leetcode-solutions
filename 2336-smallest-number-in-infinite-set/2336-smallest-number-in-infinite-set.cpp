// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
    }
    int currSmall=1;
    set<int>s;
    int popSmallest() {
        int res;
        if(!s.empty()){
            res=*s.begin();
            s.erase(s.begin());
        }
        else res=currSmall++;
        return res;
    }
    
    void addBack(int num) {
        if(num>=currSmall||s.find(num)!=s.end())return;
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet*
  obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */