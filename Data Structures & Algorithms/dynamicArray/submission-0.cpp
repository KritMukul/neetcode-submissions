class DynamicArray {
public:
    int *a, cap, ind;
    DynamicArray(int capacity) {
        cap = capacity;
        a = new int[cap];
        ind = 0;
    }

    int get(int i) {
        return a[i];
    }

    void set(int i, int n) {
        a[i] = n;
    }

    void pushback(int n) {
        if(ind >= cap) resize();

        a[ind++] = n;
    }

    int popback() {
        return a[--ind];
    }

    void resize() {
        cap *= 2;
        int *temp = new int[cap];
        for(int i= 0; i < ind; i++) temp[i] = a[i];
        delete[] a;
        a = temp;
    }

    int getSize() {
        return ind;
    }

    int getCapacity() {
        return cap;
    }
};
