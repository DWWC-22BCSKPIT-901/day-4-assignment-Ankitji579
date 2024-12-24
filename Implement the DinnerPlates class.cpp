#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class DinnerPlates {
private:
    int capacity;
    vector<stack<int>> stacks;
    int leftMostStack;

public:
    // Constructor to initialize the DinnerPlates object
    DinnerPlates(int capacity) {
        this->capacity = capacity;
        this->leftMostStack = 0;
        cout << "null" << endl; // Output null for constructor
    }

    // Pushes the value into the leftmost stack with size less than capacity
    void push(int val) {
        while (leftMostStack < stacks.size() && stacks[leftMostStack].size() == capacity) {
            leftMostStack++;
        }
        
        if (leftMostStack == stacks.size()) {
            stacks.push_back(stack<int>());
        }
        
        stacks[leftMostStack].push(val);
        cout << "null" << endl; // Output null for push
    }

    // Pops the top value from the rightmost non-empty stack and removes it
    int pop() {
        if (stacks.empty()) {
            return -1;
        }
        
        while (!stacks.empty() && stacks.back().empty()) {
            stacks.pop_back();
        }

        if (stacks.empty()) {
            return -1;
        }

        int val = stacks.back().top();
        stacks.back().pop();
        return val;
    }

    // Pops the top value from the stack at the given index and removes it
    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty()) {
            return -1;
        }

        int val = stacks[index].top();
        stacks[index].pop();
        return val;
    }
};

int main() {
    DinnerPlates dp(2);  // Constructor call, should output 'null'
    
    dp.push(1);  // Should output 'null'
    dp.push(2);  // Should output 'null'
    dp.push(3);  // Should output 'null'
    dp.push(4);  // Should output 'null'
    dp.push(5);  // Should output 'null'
    
    cout << dp.popAtStack(0) << endl; // 2
    dp.push(20);  // Should output 'null'
    dp.push(21);  // Should output 'null'
    
    cout << dp.popAtStack(0) << endl; // 20
    cout << dp.popAtStack(2) << endl; // 21
    cout << dp.pop() << endl;         // 5
    cout << dp.pop() << endl;         // 4
    cout << dp.pop() << endl;         // 3
    cout << dp.pop() << endl;         // 1
    cout << dp.pop() << endl;         // -1
    
    return 0;
}
