#include <iostream>
#include "matchString.h"

using namespace std;

void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", "; // Para separar los elementos
        }
    }
    cout << endl; // Salto de línea al final
}

int main() {
    string text="hola como estas como";
    string pattern="como";
    printVector(stringMatch_RabinKarp(text,pattern));
}