#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

using namespace std;

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
}

template<typename T>
int Heap<T>::left(int n) {
    return 2*n+1;
}

template<typename T>
int Heap<T>::right(int n) {
    return 2*n+2;
}

template<typename T>
int Heap<T>::parent(int n) {
    return (n-1)/2;
}

template<typename T>
void Heap<T>::heapify(bool isMinHeap, int start) {
    int s=this->size();
    int left=this->left(start);
    int right=this->right(start);
    int change=start;
    if (isMinHeap) {
        if(left<s && data[left]<data[change]) {
            change=left;
        }
        if(right<s && data[right]<data[change]) {
            change=right;
        }
    }
    else {
        if(left<s && data[left]>data[start]) {
            change=left;
        }
        if(right<s && data[right]>data[start]) {
            change=right;
        }
    }
    if (change != start) {
        swap(data[start], data[change]);
        heapify(isMinHeap, change);
    }
}


template <typename T>
void Heap<T>::insert(T const& element) {
    this->data.push_back(element);
    heapify(this->minHeap,0);
}

template <typename T>
T Heap<T>::extractTop() {
    if (!this->isEmpty()) {
        T top = data[0];
        if (data.size() == 1) {
            data.pop_back();
            return top;
        }
        T lastValue = data[this->size()-1];
        data.pop_back();

        int i = 0;
        while (true) {
            int left = left(i);
            int right = right(i);
            int change = -1;

            if (minHeap) {
                if (left < data.size() && data[left] < lastValue) {
                    change = left;
                }
                if (right < data.size()) {
                    if (change == -1) {
                        if (data[right] < lastValue) {
                            change = right;
                        }
                    } else {
                        if (data[right] < data[left]) {
                            change = right;
                        }
                    }
                }
            } else {
                if (left < data.size() && data[left] > lastValue) {
                    change = left;
                }
                if (right < data.size()) {
                    if (change == -1) {
                        if (data[right] > lastValue) {
                            change = right;
                        }
                    } else {
                        if (data[right] > data[left]) {
                            change = right;
                        }
                    }
                }
            }
            if (change == -1) {
                data[i] = lastValue;
                break;
            }
            data[i] = data[change];
            i = change;
        }
        return top;
    }
}

template <typename T>
T Heap<T>::peek() const {
    if (!this->isEmpty()) {
        return data[0];
    }
}

template <typename T>
size_t Heap<T>::size() const {
    return data.size();
}

template <typename T>
bool Heap<T>::isEmpty() const {
    if (data.empty()) return true;
    return false;
}


template <typename T>
void Heap<T>::clear() {
    data.clear();
}
