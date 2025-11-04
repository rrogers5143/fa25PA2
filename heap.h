//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // Insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // Remove and return smallest index
        // Replace root with last element, then call downheap()
        // Remove and return smallest index
        if (size == 0) return -1;

        int root = data[0];
        size--;
        data[0] = data[size];
        downheap(0, weightArr);

        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // Swap child upward while smaller than parent
        void upheap(int pos, int weightArr[]) {
            // Swap child upward while smaller than parent
            while (pos > 0) {
                int parent = (pos - 1) / 2;

                if (weightArr[data[pos]] < weightArr[data[parent]]) {
                    // Swap indices
                    int temp = data[pos];
                    data[pos] = data[parent];
                    data[parent] = temp;
                    pos = parent;
                } else {
                    break;
                }
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // Swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            // Find smallest among parent and children
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            if (smallest != pos) {
                // Swap indices
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif