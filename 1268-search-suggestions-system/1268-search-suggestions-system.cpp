// https://leetcode.com/problems/search-suggestions-system

class TrieNode{
public:
    bool isEnd=false;
    TrieNode* child[26];
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(char c:word){
            if(!node->child[c-'a'])node->child[c-'a']=new TrieNode();
            node=node->child[c-'a'];
        }
        node->isEnd=true;
    }
    
    vector<string>get3PrefixWords(string prefix){
        vector<string>result;
        TrieNode* node=root;
        for(char c:prefix) {
            if(!node->child[c-'a'])return result;
            node=node->child[c-'a'];
        }
        dfs(node,prefix,result);
        return result;
    }

private:
    void dfs(TrieNode* node, string currentWord, vector<string>& result) {
        if(result.size()==3)return;
        if(node->isEnd)result.push_back(currentWord);
        for(char c='a';c<='z';c++){
            if (node->child[c-'a'])dfs(node->child[c-'a'],currentWord+c,result);
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* t=new Trie();
        for(string product:products)
            t->insert(product);
        vector<vector<string>>res;
        string prefix;
        for(char c:searchWord){
            prefix+=c;
            res.push_back(t->get3PrefixWords(prefix));
        }
        return res;
    }
};