// https://leetcode.com/problems/implement-trie-prefix-tree

class TrieNode{
public:
    bool isEnd=false;
    vector<TrieNode*>child;
    TrieNode(){
        isEnd=false;
        child.resize(26,NULL);
    }
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
    
    bool search(string word,bool prefix=false) {
        TrieNode* node=root;
        for(char c:word){
            if(!node->child[c-'a'])return false;
            node=node->child[c-'a'];
        }
        return node->isEnd||prefix;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */