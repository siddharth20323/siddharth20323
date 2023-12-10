 #include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) : top(-1), capacity(size)
    {
        arr = new int[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int data)
    {
        if (top < capacity - 1)
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int performOperation(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

int evaluatePostfix(const string &expression)
{
    Stack stack(expression.length());

    for (char c : expression)
    {
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            stack.push(performOperation(operand1, operand2, c));
        }
    }

    return stack.peek();
}

int evaluatePrefix(const string &expression)
{
    Stack stack(expression.length());

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            int operand1 = stack.pop();
            int operand2 = stack.pop();
            stack.push(performOperation(operand1, operand2, c));
        }
    }

    return stack.peek();
}

int main()
{
    string postfixExpression = "23*5+";
    int postfixResult = evaluatePostfix(postfixExpression);
    cout << "Postfix Evaluation Result: " << postfixResult << endl;

    string prefixExpression = "+*235";
    int prefixResult = evaluatePrefix(prefixExpression);
    cout << "Prefix Evaluation Result: " << prefixResult << endl;

    return 0;
}

 