struct Node{
    Node* link[26];
    bool flag = false;
    bool containsKey(char c){
        return (link[c - 'a'] != NULL);
    }
    void put(char c, Node* node){
        link[c - 'a'] = node;
    }
    Node* getNext(char c){
        return link[c - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
}

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return true;
    }
}
