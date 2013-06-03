
class MinStack
{
public:
    void push( int val ) {
        numStack.push(val);
        if( val < getMin() ) {
            minNumStack.push(val);
        }
    }
    void pop() {
        int val = numStack.top();
        if( val == getMin() ) {
            minNumStack.pop();
        }
        numStack.pop();
    }
    
    int& top() {
        return numStack.top();
    }
    int size() {
        return numStack.size();
    }
    int getMin() {
        if( minNumStack.empty() ) return INT_MAX;
        else                      return minNumStack.top();
    }
private:
    stack<int> numStack;
    stack<int> minNumStack;
};
