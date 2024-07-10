#include <vector>

class MinHeap {
    std::vector<int> data;
    int length;

public:

    MinHeap() {
    }

    void insert(int value) {
        data.push_back(value);
        length++;
        if (length == 1) {
            return;
        }
        heapifyUp(length-1);
    }

    int remove() {
        if (length == 0) {
            return -1;
        }
        int out = data[0];
        if (length == 1) {
            length--;
            return out;
        }

        data[0] = data[length - 1];
        length--;
        heapifyDown(0);
        return out;
    }

    void heapifyUp(int idx) {
        if (idx == 0) {
            return;
        }
        int parent_idx = parentIdx(idx);
        int parent_val = data[parent_idx];
        int val = data[idx];

        if (data[parent_idx] > val) {
            data[idx] = parent_val;
            data[parent_idx] = val;
            heapifyUp(parent_idx);
        }
    }

    void heapifyDown(int idx) {
        int left_idx = leftChildIdx(idx);
        int right_idx = rightChildIdx(idx);
        if (idx >= length || left_idx >= length) {
            return;
        }
        int val = data[idx];
        int child_idx = -1, child_val;

        if (data[left_idx] < val) {
            child_idx = left_idx;
            child_val = data[left_idx];
        } else if (right_idx < length && data[right_idx] < val && data[right_idx] < data[left_idx]) {
            child_idx = right_idx;
            child_val = data[right_idx];
        }

        if (child_idx != -1) {
            data[idx] = child_val;
            data[child_idx] = val;
            heapifyDown(child_idx);
        }
    }

    int parentIdx(int idx) {
        return idx / 2;
    }

    int leftChildIdx(int idx) {
        return (2 * idx) + 1;
    }

    int rightChildIdx(int idx) {
        return (2 * idx) + 2;
    }
};
