#include <iostream>
using namespace std;

const int MAX = 5;

class Array {
private:
    int arr[MAX];

public:
    Array() { // constructor to initialize array with 0
        for (int i = 0; i < MAX; i++)
            arr[i] = 0;
    }

    void insert(int pos, int num);
    void del(int pos);
    void reverse();
    void display();
    void search(int num);
};

void Array::insert(int pos, int num) {
    if (pos < 0 || pos >= MAX) {
        cout << "Invalid position!" << endl;
        return;
    }
    arr[pos] = num;
}

void Array::del(int pos) {
    if (pos < 0 || pos >= MAX) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < MAX - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[MAX - 1] = 0;
}

void Array::reverse() {
    for (int i = 0; i < MAX / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[MAX - 1 - i];
        arr[MAX - 1 - i] = temp;
    }
}

void Array::search(int num) {
    for (int i = 0; i < MAX; i++) {
        if (arr[i] == num) {
            cout << "Element found at position: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

void Array::display() {
    for (int i = 0; i < MAX; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Array a;
    a.insert(2, 10);
    a.display();

    a.del(3);
    a.display();

    a.reverse();
    a.display();

    a.search(10);
    return 0;
}
