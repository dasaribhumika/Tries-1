// https://leetcode.com/problems/implement-trie-prefix-tree/
// Time Complexity : 
// insert() : O(l) where l is the length of the word
// search() : O(l)
// startswith() : O(l) 
// Space Complexity : O(N*l) where n is the number of words and l is the length of the words
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach


class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd;
    
        TrieNode() : isEnd(false){
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        };
    };
    class Trie {
    private:
        TrieNode * root;
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string word) {
            TrieNode* curr = root;
            for(auto i:word){
                if(curr->children[i-'a'] == NULL) curr->children[i-'a'] = new TrieNode();
                curr = curr->children[i-'a'];
            }
            curr->isEnd = true;
        }
        
        bool search(string word) {
            TrieNode* curr = root;
            for(auto i:word){
                if(curr->children[i-'a'] == NULL) return false;
                curr = curr->children[i-'a'];
            }
            return curr->isEnd;
        }
        
        bool startsWith(string prefix) {
            TrieNode* curr = root;
            for(auto i:prefix){
                if(curr->children[i-'a'] == NULL) return false;
                curr = curr->children[i-'a'];
            }
            return true;
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */