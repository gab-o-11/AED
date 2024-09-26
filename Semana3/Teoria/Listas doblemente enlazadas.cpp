#include <iostream>

using namespace std;


template <typename T>
class Nodo {
private:
    T data;
    T* next;
    T* prev;

    Nodo(T data):data(data),next(nullptr),prev(nullptr){}
};

template <typename T>
class Lista {
    Nodo<T>* head;
    Nodo<T>* tail;
public:
    Lista():head(nullptr),tail(nullptr){}
    void push_back(T nuevo) {
        Nodo<T>* nuevo_nodo= new Nodo<T>(nuevo);
        if (head==nullptr) {
            head=tail=nuevo_nodo;
        }
        else {
            tail->next=nuevo_nodo;
            nuevo_nodo->prev=tail;
            tail=nuevo_nodo;
        }
    }
    void push_front(T nuevo) {
        Nodo<T>* nuevo_nodo=new Nodo<T>(nuevo);
        if (head==nullptr) {
            head=tail=nuevo_nodo;
        }
        else {
            head->prev=nuevo_nodo;
            nuevo_nodo->next=head;
            head=nuevo_nodo;
        }
    }
    void pop_back() {
        if (tail==nullptr) {
            cout<<"La lista esta vacia"<<endl;
        }
        else if(head==tail) {
            delete tail;
            head=tail=nullptr;
        }
        else {
            Nodo<T>* temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
        }
    }
    void pop_front() {
        if (tail==nullptr) {
            cout<<"La lista esta vacia"<<endl;
        }

    }
};

int main() {

}