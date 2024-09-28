class MyCircularDeque {
    vector<int> v;
    int k, size = 0;
    int start = 0, end;

public:
    MyCircularDeque(int k) {
        v.resize(k);
        this->k = k;
        this->end = k - 1;
    }

    bool insertFront(int value) {
        if (size == k) {
            return false;
        }
        ++size;
        start = (start + k - 1) % k;
        v[start] = value;
        return true;
    }

    bool insertLast(int value) {
        if (size == k) {
            return false;
        }
        ++size;
        end = (end + 1) % k;
        v[end] = value;
        return true;
    }

    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        --size;
        v[start] = 0;
        start = (start + 1) % k;
        return true;
    }

    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        --size;
        v[end] = 0;
        end = (end + k - 1) % k;
        return true;
    }

    int getFront() { return size ? v[start] : -1; }

    int getRear() { return size ? v[end] : -1; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == k; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 