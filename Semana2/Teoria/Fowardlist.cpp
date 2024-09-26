#include <iostream>

using namespace std;

template<typename T>

struct Nodo {
    T valor;
    Nodo* next;

    Nodo(T v):valor(v),next(nullptr){}
};


template<typename T>

class Lista {
private:
    Nodo<T>* head;
    Nodo<T>* tail;
    int list_size;
public:
    Lista():head(nullptr),tail(nullptr),list_size(0){}

    Nodo<T>* getHead() {
        return head;
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
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->next;
        }
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

    Nodo<int>* x=mylist.getHead();
    x->valor=5;

    mylist.print();

    return 0;
}



