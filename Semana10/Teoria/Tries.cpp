#include <iostream>

using namespace std;



class Tries {
private:
    Tries* hijos[26];
    char data;
public:
    Tries() {
        for (int i=0;i<26;i++) {
            hijos[i]=nullptr;
        }
        data='';
    }
    Tries(char x) {
        for (int i=0;i<26;i++) {
            hijos[i]=nullptr;
        }
        data=x;
    }
    Tries* insertWord(string word, Tries* root) {
        int wordSize=word.size();
        if (wordSize == 0) {
            return root;
        }
        for (int i=0;i<26;i++) {
            if (root->hijos[i] != nullptr && root->hijos[i]->data == word[0]) {
                string newWord = word.substr(1);
                return insertWord(newWord, root->hijos[i]);
            }
        }

        for (int j = 0; j < 26; j++) {
            if (root->hijos[j] == nullptr) {
                root->hijos[j] = new Tries(word[0]);
                string newWord=word.substr(1);
                return insertWord(newWord,root->hijos[j]);
            }
        }
    }
};