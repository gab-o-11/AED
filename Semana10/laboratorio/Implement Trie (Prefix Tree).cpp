#include <iostream>

using namespace std;

class Trie {
private:
    Trie* hijos[26];
    bool isEndOfWord;
    char val;

public:
    Trie(char c) : val(c), isEndOfWord(false) {
        for (int i = 0; i < 26; i++) {
            hijos[i] = nullptr;
        }
    }

    void insert(string word, Trie* root) {
        for (char c : word) {
            Trie* child = nullptr;
            for (int i = 0; i < 26; i++) {
                if (root->hijos[i] != nullptr && root->hijos[i]->val == c) {
                    child=root->hijos[i];
                    break;
                }
            }
            if (child == nullptr) {
                for (int i = 0; i < 26; i++) {
                    if (root->hijos[i] == nullptr) {
                        root->hijos[i] = new Trie(c);
                        child = root->hijos[i];
                        break;
                    }
                }
            }
            root = child;
        }
        root->isEndOfWord = true;
    }
    bool search(string word, Trie* root) {
        for (char c : word) {
            Trie* Child = nullptr;
            for (int i = 0; i < 26; i++) {
                if (root->hijos[i] != nullptr && root->hijos[i]->val == c) {
                    Child = root->hijos[i];
                    break;
                }
            }
            if (Child == nullptr) {
                return false;
            }
            root = Child;
        }
        return root->isEndOfWord;
    }
    bool startsWith(string prefix, Trie* root) {
        for (char c : prefix) {
            Trie* child = nullptr;
            for (int i = 0; i < 26; i++) {
                if (root->hijos[i] != nullptr && root->hijos[i]->val == c) {
                    child = root->hijos[i];
                    break;
                }
            }
            if (child == nullptr) {
                return false;
            }
            root = child;
        }
        return true;
    }
};