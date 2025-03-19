class Node {
public:
    Node* link[26];
    bool flag = false;

    // O(1) operation (since there are at most 26 possible links).
    bool containsKey (char ch) {
        return link[ch - 'a'] != NULL;
    }

    //O(1) operation.
    void put (char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    //O(1)
    Node* get (char ch) {
        return link[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

//The reason we use the -> operator instead of the . operator is because root is a pointer to a Node object, not a direct instance of a Node.

class Trie {
private:
//root can hold the address (pointer) of a Node object.
    Node* root;
public:
    Trie() {
        //// Creates a new Node object on the heap and assigns the pointer to root
        root = new Node();
    }
    
    //O(n),
    void insert(string word) {
        Node* node = root;
        for (int i=0;i<word.size();i++)
        {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            // making refernce's node for each node
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
    
    //time complexity is O(n),
    bool search(string word) {
        Node* node = root;
        for (int i=0;i<word.size();i++)
        {
            if (!node -> containsKey(word[i]))   return false;
            node = node -> get(word[i]);
        }
        return node -> isEnd();
    }
    
    // O(m), where m is the length of the prefix.
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i=0;i<prefix.size();i++)
        {
            if (!node -> containsKey(prefix[i]))   return false;
            node = node -> get(prefix[i]);
        }

        return true;
    }
};