// PriorityQueue.cpp -- class to store edges in minheap priority queue structure

#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

#include <vector>

using namespace std;

template <typename T>
class PriorityQueue {
    vector<T> A;

    void heapify_enqueue (int index) {   // used in enqueue.

    if (A[parent(index)] > A[index])
        {
            swap(A[index], A[parent(index)]);
            heapify_enqueue(parent(index));
        }
    }

    int parent(int child){
        return (child - 1 )/2;
    }

    int RIGHT(int parent)
    {
        return (2*parent + 2);
    }
    int LEFT(int parent)
    {
        return (2*parent + 1);
    }

    void heapify_dequeue (int index) {   // used in dequeue.
    // get left and right child of node at index `i`
        int left = LEFT(index);
        int right = RIGHT(index);
        int largest = index;
        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size() && (A[left] < A[index])) {
            largest = left;
        }

        if (right < size() && (A[right] < A[largest])) {
            largest = right;
        }

        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != index)
        {
            swap(A[index], A[largest]);
            heapify_dequeue(largest);
        }
    }

public:
    void enqueue (T element) {
        A.push_back (element);
        heapify_enqueue (A.size()-1);  // start at last element.
    }

    T dequeue() { // make this function return T if we want to return the dequeud element
        T removed_element = A[0];
        A[0] = A[A.size()-1];          // copy last element to root.
        A.pop_back();                 // remove last element.
        heapify_dequeue(0);           // start at root.
        return removed_element;
      }

    int size() {
        return A.size();
    }

    void print(){
        for (int i = 0; i < A.size(); i++)
          cout << A.at(i);
      }
};

#endif