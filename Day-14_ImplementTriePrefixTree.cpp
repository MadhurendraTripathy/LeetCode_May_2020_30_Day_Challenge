using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Trie {
    struct TrieNode{
        char c;
        TrieNode * childernPointers[26];
        bool endsHere;
    };
    TrieNode * root = new TrieNode();
public:
    Trie() {
        root->c = '/';
        root->endsHere=0;
        memset(root->childernPointers, NULL, sizeof(root->childernPointers));
    }
    TrieNode * makeNode(char chr){
        TrieNode * newNode = new TrieNode();
        newNode->c = chr;
        newNode->endsHere=0;
        memset(newNode->childernPointers, NULL, sizeof(newNode->childernPointers));
        return newNode;
    }
    
    void insert(string word) {
        TrieNode * current = root;
        int idx = 0;
        while(word[idx]!='\0'){
            int index = word[idx]-'a';
            if(current->childernPointers[index]==NULL){
                current->childernPointers[index] = makeNode(word[idx]);
            }
            idx++;
            current = current->childernPointers[index];
        }
        current->endsHere=1;
    }
    
    bool search(string word) {
        TrieNode * current = root;
        int idx = 0;
        while(word[idx]!='\0'){
            int index = word[idx]-'a';
            if(current->childernPointers[index]==NULL){
                return false;
            }
            else{
                current = current->childernPointers[index];
            }
            idx++;
        }
        return current->endsHere;
    }
    
    bool startsWith(string prefix) {
        TrieNode * current = root;
        int idx = 0;
        while(prefix[idx]!='\0'){
            int index  = prefix[idx]-'a';
            if(current->childernPointers[index]==NULL){
                return false;
            }
            current = current->childernPointers[index];
            idx++;
        }
        return true;
    }
};

int main(){
    FAST_IO;
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    param_2?cout<<"YES\n":cout<<"NO\n";
    bool param_3 = obj->startsWith("app");
    param_3?cout<<"YES\n":cout<<"NO\n";
    obj->insert("papaya");
    obj->search("papaya")?cout<<"YES\n":cout<<"NO\n";
    obj->startsWith("apa")?cout<<"YES\n":cout<<"NO\n";
    return 0;
}
