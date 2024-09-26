#include <iostream>
#include <list>

using namespace std;

template<typename T>

struct Nodo {
    T valor;
    Nodo* next;

    Nodo(T v):valor(v),next(nullptr){}
};

template<typename T>

struct  Lista {
public:
    Nodo<T>* head;
    Nodo<T>* tail;
    int list_size;

    Lista():head(nullptr),tail(nullptr),list_size(0){}

    Nodo<T>* getHead() {
        return head;
    }

    Nodo<T>* getTail() {
        return tail;
    }

    void push_back(T nuevo) {
        Nodo<T>* nuevoNodo=new Nodo<T>(nuevo);
        if (head==nullptr) {
            head=tail=nuevoNodo;
        }
        else {
            tail->next = nuevoNodo;
            tail = nuevoNodo;
        }
        list_size++;
    }
    T back() {
        if (tail != nullptr) {
            return tail->valor;
        }
        throw runtime_error("La lista está vacía");
    }

    T begin() {
        if (head != nullptr) {
            return head->valor;
        }
        throw runtime_error("La lista está vacía");
    }

    void print() {
        Nodo<T>* temp = head;
        cout<<"[";

        int i = list_size-1;
        while (temp != nullptr) {
            cout << temp->valor;
            if (i>0) {
                cout<<",";
            }
            temp=temp->next;
            i-=1;
        }

        cout<<"]";
        cout << endl;
    }

    void push_font(T nuevo) {
        if(head==nullptr) {
            head=tail=nuevo;
        }
        else {
            Nodo<T> temp=head;
            head=nuevo;
            head->next=temp;
        }
        list_size++;
    }
    bool empty() {
        return head == nullptr;
    }

    int size() {
        return list_size;
    }

    T pop_front() {
        Nodo<T>* temp=head;
        T valor=temp->valor;
        head=head->next;
        delete temp;
        list_size--;
        return valor;
    }

    T pop_back() {
        T valor;
        if(head==tail) {
            valor=head->valor;
            delete head;
            head=tail=nullptr;
        }
        else {
            Nodo<T>* temp=head;
            while (temp.next!=tail) {
                temp=temp.next;
            }
            valor=tail->valor;
            delete temp;
            tail=temp;
            tail->next=nullptr;
        }
        list_size--;
        return valor;
    }

    T operator[](int indice) {
        if (indice < 0 || indice >= list_size) {
            throw out_of_range("Índice fuera de rango");
        }
        Nodo<T>* temp=head;
        for (int i=0;i<indice;i++) {
            temp=temp->next;
        }
        return temp->valor;
    }
    void clear() {
        while (head != nullptr) {
            Nodo<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        list_size = 0;
    }
    void selection_sort() {
        Nodo<T>* temp = head;

        while (temp != nullptr) {
            Nodo<T>* iz = temp;
            Nodo<T>* der = temp->next;

            while (der != nullptr) {
                if (der->valor < iz->valor) {
                    iz = der;
                }
                der = der->next;
            }
            if (iz != temp) {
                T tempVal = temp->valor;
                temp->valor = iz->valor;
                iz->valor = tempVal;
            }

            temp = temp->next;
        }
    }
    void reverse() {
        Nodo<T>* prev = nullptr;
        Nodo<T>* current = head;
        Nodo<T>* next = nullptr;
        tail = head;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

};


void f1(Lista<int> &lista,int val) {
    while (lista.head != nullptr && lista.head->valor == val) {
        Nodo<int>* temp = lista.head;
        lista.head = lista.head->next;
        delete temp;
        lista.list_size-=1;
    }

    Nodo<int>* current = lista.getHead();
    while (current != nullptr && current->next != nullptr) {
        if (current->next->valor == val) {
            Nodo<int>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            lista.list_size-=1;
        } else {
            current = current->next;
        }
    }

    lista.tail = lista.head;
    while (lista.tail!=nullptr && lista.tail->next != nullptr) {
        lista.tail = lista.tail->next;
    }
}

Nodo<int>* f11(Nodo<int>* &node, int val) {
    while (node != nullptr && node->valor == val) {
        Nodo<int>* temp =node;
        node = node->next;
        delete temp;
    }

    Nodo<int>* current = node;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->valor == val) {
            Nodo<int>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
}

int main() {
    Lista<int> mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(6);
    mylist.push_back(3);
    mylist.push_back(4);
    mylist.push_back(5);
    mylist.push_back(6);

    mylist.print();

    f11(mylist.head,6);

    mylist.print();
}