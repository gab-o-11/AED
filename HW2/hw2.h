
#ifndef HW2_H
#define HW2_H

#include <vector>

using namespace std;

template <typename T>
struct Heap {
    bool minHeap;

    vector<int> data;

    int left(int n);

    int right(int n);

    int parent(int n);

    void heapify(bool isMinHeap, int start);

    Heap(bool isMinHeap = true);

    void insert(T const& element);

    T extractTop();

    T peek() const;

    size_t size() const;

    bool isEmpty() const;

    void clear();
};




#endif //HW2_H
