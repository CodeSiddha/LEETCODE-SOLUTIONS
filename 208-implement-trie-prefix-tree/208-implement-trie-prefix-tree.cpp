struct Node {
	Node* links[26];
	bool flag = false;
	bool isContainKey(char ch) {
		if (links[ch - 'a'] != NULL) return true;
		return false;
	}
	void TheEnd() {
		flag = true;
	}
	void put(char ch , Node* node) {
		links[ch - 'a'] = node;
	}
	bool isEnd() {
		return flag;
	}
};
class Trie {
    private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
    Node *node = root;
	for (int i = 0 ; i < word.size() ; i++) {
		if (!node->isContainKey(word[i])) {
			node->put(word[i] , new Node());
		}
		node = node->links[word[i] - 'a'];
	    }
	    node->TheEnd();
    }
    
    bool search(string word) {
    Node *node = root;
	for (int i = 0 ; i < word.size(); i++) {
		if (!node->isContainKey(word[i])) {
			return false;
		}
		node = node->links[word[i] - 'a'];
	}
	return (node->isEnd());
    }
    bool startsWith(string word) {
    Node *node = root;
	for (int i = 0 ; i < word.size() ; i++) {
		if (!node->isContainKey(word[i])) {
			return false;
		}
		node = node->links[word[i] - 'a'];
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