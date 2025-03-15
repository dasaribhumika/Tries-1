// https://leetcode.com/problems/longest-word-in-dictionary/
// Time Complexity : O(N*l)  where N is the number of words and l is the length
// Space Complexity : O(N*l)
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
    
    class Solution {
    private: 
        TrieNode* root;
    public:
        Solution(){
            root = new TrieNode();
        }
        void insert(string word){
            TrieNode* curr=root;
            for(auto i:word){
                if(curr->children[i-'a'] == NULL) curr->children[i-'a'] = new TrieNode();
                curr = curr->children[i-'a'];
            }
            curr->isEnd = true;   
        }
        bool prefixExists(string word){
            TrieNode* curr = root;
            for(int i=0; i<word.length(); i++){
                if(curr->children[word[i]-'a'] == NULL || !curr->children[word[i]-'a']->isEnd) return false;
                curr = curr->children[word[i]-'a'];
            }
            return true;
        }
        string longestWord(vector<string>& words) {
            for(auto i: words){
                insert(i);
            }
            string res="";
            for(auto word: words){
                if(prefixExists(word)){
                    if(word.length() > res.length() || (word.length() == res.length() && word < res)){
                        res = word;
                    }
                }
            }
            return res;
        }
    };