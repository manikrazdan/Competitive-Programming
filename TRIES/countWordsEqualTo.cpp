struct Node{
    Node* links[26];
    int cntEndwith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }
    
    Node* get(char c){
        return links[c-'a'];
    }
    
    void put(char c, Node* node){
        links[c-'a'] = node;
        
    }
    
    void increaseEnd(){
        cntEndwith++;
    }
    
    void increasePrefix(){
        cntPrefix++;
    }
    
    void decreaseEnd(){
        cntEndwith--;
    }
    
    void decreasePrefix(){
        cntPrefix--;
    }
    
    int getEnd(){
        return cntEndwith;
    }
    
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
    private:Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
    }
};
