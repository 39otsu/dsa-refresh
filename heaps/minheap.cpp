#include <iostream>
#include <random>
#include <vector>
class MinHeap {
    std::vector<int> v;
    /*
        (i - 1) / 2 = parent
        (2 * i) + 1 = left child
        (2 * i) + 2 = right child
    */
public:
    void insert(int value) {
        v.push_back(value);
        
        int index = v.size() - 1;
        int parent = v[(index - 1)/2];
        int current = v[index];
        while(index > 0 && v[(index - 1)/2] > v[index]) {
            current = v[index];
            parent = v[(index - 1)/2];
            // store parent
            int temp = parent;
            // update parent
            v[(index - 1)/2] = current;
            v[index] = temp;
            // update index
            index = (index - 1) / 2;
        }
    }
    
    int peek() {
        return v[0];
    }
    
    void deletion() {
        int back = v[v.size() - 1];
        v[0] = back;
        v.pop_back();
        
        int index = 0;
        int i = 0; // debugging
        while (index < v.size()) {
            int largest = v[index];
            int leftIndex = (index * 2) + 1;
            int rightIndex = (index * 2) + 2;
            if (leftIndex > v.size() - 1 || rightIndex > v.size() - 1) {
                return;
            }
            int left = v[leftIndex];
            int right = v[rightIndex];
            if (left < right) {
                int temp = left;
                v[leftIndex] = largest;
                v[index] = temp;
                index = leftIndex;
            } else {
                int temp = right;
                v[rightIndex] = largest;
                v[index] = temp;
                index = rightIndex;
            }
            i++;
        }
        
        
    }
    
    void print() {
        if (v.size() == 0) {
            std::cout << "no more items\n";
            return;
        }
        for(int i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    MinHeap mh;
    mh.print();
    std::cout << "Insert 10 random numbers\n";
    for (int i = 0; i < 10; i++) {
        int t = rand() % 100;
        mh.insert(t);
    }
    mh.print();
    for (int i = 0; i < 10; i++) {
        std::cout << "Delete 1\n";
        mh.deletion();
        mh.print();
    }

    return 0;
}