// https://leetcode.com/problems/replace-words/
// Time Complexity : O(N*l + s)  where N is the number of words and l is the length, s is the length of the sentence
// Space Complexity : O(N*l + s)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach

class TrieNode{
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
    
        string replaceWords(vector<string>& dictionary, string sentence) {
            string res;
            vector<string> dict;
            for(auto i:dictionary){
                insert(i);
            }
            string ans="";
            for(int i=0; i<sentence.length(); i++){
                if(sentence[i] == ' '){
                    dict.push_back(ans);
                    ans = "";
                } 
                else{
                    ans += sentence[i];
                }
            }
            dict.push_back(ans);
    
            for(auto i:dict){
                string temp = i;
                TrieNode* curr = root;
                string prefix = "";
                for(auto c: temp){
                    if(curr->children[c-'a'] == NULL || curr->isEnd) break;
                    prefix += c;
                    curr = curr->children[c-'a'];
                }
                if(curr->isEnd){
                    if(!res.empty()) res += ' ';
                    res += prefix;
                }
                else{
                    if(!res.empty()) res += ' ';
                    res += temp;
                }
            }
            return res;
        }
    };