/*WAP a menu driven program to perform following operations
Infix to Postfix
Infix to Prefix
Evaluate Postfix
Evaluate Prefix
Exit*/

#include <iostream>
#include <string>
using namespace std;

class Expression {
    char stack[100];
    int top;
public:
    Expression() { top = -1; }

    void push(char c) {
	 stack[++top] = c; 
	 }
    char pop() {
	 return stack[top--];
	  }
    char peek() { 
	return stack[top]; 
	}
    bool isEmpty() { 
	return top == -1; 
	}

    int precedence(char op) {
        if(op=='+'||op=='-') return 1;
        if(op=='*'||op=='/') return 2;
        if(op=='$'||op=='^') return 3;
        return 0;
    }

    bool isOperator(char c) {
        return c=='+'||c=='-'||c=='*'||c=='/'||c=='$'||c=='^';
    }

    bool isOperand(char c) {
        return (c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z');
    }

    string infixToPostfix(string infix) {
        string postfix = "";
        top = -1;
        for(int i=0;i<infix.length();i++) {
            char c = infix[i];
            if(isOperand(c)) postfix += c;
            else if(c=='(') push(c);
            else if(c==')') {
                while(!isEmpty() && peek()!='(') postfix += pop();
                pop();
            }
            else if(isOperator(c)) {
                while(!isEmpty() && precedence(peek()) >= precedence(c)) postfix += pop();
                push(c);
            }
        }
        while(!isEmpty()) postfix += pop();
        return postfix;
    }

    string infixToPrefix(string infix) {
        int n = infix.length();
        for(int i=0;i<n/2;i++) {
            char temp = infix[i];
            infix[i] = infix[n-i-1];
            infix[n-i-1] = temp;
        }
        for(int i=0;i<n;i++) {
            if(infix[i]=='(') infix[i]=')';
            else if(infix[i]==')') infix[i]='(';
        }
        string prefix = infixToPostfix(infix);
        for(int i=0;i<prefix.length()/2;i++) {
            char temp = prefix[i];
            prefix[i] = prefix[prefix.length()-i-1];
            prefix[prefix.length()-i-1] = temp;
        }
        return prefix;
    }

    int evaluatePostfix(string exp) {
        int valStack[100], topVal = -1;
        for(int i=0;i<exp.length();i++) {
            char c = exp[i];
            if(c>='0' && c<='9') valStack[++topVal] = c-'0';
            else {
                int b = valStack[topVal--];
                int a = valStack[topVal--];
                int res = 0;
                if(c=='+') res=a+b;
                else if(c=='-') res=a-b;
                else if(c=='*') res=a*b;
                else if(c=='/') res=a/b;
                else if(c=='^') {
                    res = 1;
                    for(int j=0;j<b;j++) res *= a;
                }
                valStack[++topVal] = res;
            }
        }
        return valStack[topVal];
    }

    int evaluatePrefix(string exp) {
        int valStack[100], topVal = -1;
        int n = exp.length();
        for(int i=n-1;i>=0;i--) {
            char c = exp[i];
            if(c>='0' && c<='9') valStack[++topVal] = c-'0';
            else {
                int a = valStack[topVal--];
                int b = valStack[topVal--];
                int res = 0;
                if(c=='+') res=a+b;
                else if(c=='-') res=a-b;
                else if(c=='*') res=a*b;
                else if(c=='/') res=a/b;
                else if(c=='^') {
                    res = 1;
                    for(int j=0;j<b;j++) res *= a;
                }
                valStack[++topVal] = res;
            }
        }
        return valStack[topVal];
    }
};

int main() {
    Expression e;
    int choice;
    string infix, prefix, postfix;

    do {
        cout << "\n1. Infix to Postfix";
		cout << "\n2. Infix to Prefix";
		cout << "\n3. Evaluate Postfix";
		cout << "\n4. Evaluate Prefix";
		cout << "\n5. Exit";
		cout << "\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "Postfix: " << e.infixToPostfix(infix) << endl;
                break;
            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "Prefix: " << e.infixToPrefix(infix) << endl;
                break;
            case 3:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                cout << "Result: " << e.evaluatePostfix(postfix) << endl;
                break;
            case 4:
                cout << "Enter prefix expression: ";
                cin >> prefix;
                cout << "Result: " << e.evaluatePrefix(prefix) << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 6);

    return 0;
}