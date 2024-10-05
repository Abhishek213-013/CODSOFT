#include<bits/stdc++.h>
using namespace std;

int main(){
    double num1, num2;
    char operation;
    double answer;
    
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation: ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        answer = num1 + num2;
        cout << "The sum of " << num1 << " + " << num2 << " is " << answer << endl;
        break;
        
    case '-':
        answer = num1 - num2;
        cout << "The difference of " << num1 << " - " << num2 << " is " << answer << endl;
        break;

    case '*':
        answer = num1 * num2;
        cout << "The multiplication of " << num1 << " * " << num2 << " is " << answer << endl;
        break;

    case '/':
        answer = num1 / num2;
        cout << "The division of " << num1 << " / " << num2 << " is " << answer << endl;
        break;

    default:
        cout << "Invalid!!";
        break;
    }
}