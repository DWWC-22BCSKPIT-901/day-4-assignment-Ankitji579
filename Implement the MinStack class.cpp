#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;   // Stack to hold all elements
    stack<int> minStack;    // Stack to keep track of minimum elements

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!mainStack.empty() && mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    vector<string> operations = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> inputs = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    vector<string> output;

    MinStack* minStack = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "MinStack") {
            minStack = new MinStack();
            output.push_back("null");
        } else if (operations[i] == "push") {
            minStack->push(inputs[i][0]);
            output.push_back("null");
        } else if (operations[i] == "pop") {
            minStack->pop();
            output.push_back("null");
        } else if (operations[i] == "top") {
            output.push_back(to_string(minStack->top()));
        } else if (operations[i] == "getMin") {
            output.push_back(to_string(minStack->getMin()));
        }
    }

    // Print the output
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
