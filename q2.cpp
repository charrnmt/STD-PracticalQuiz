#include <iostream>
using namespace std;

const int MAX = 100;

char charStack[MAX];
int top = -1;

void push(char value) {
    if (top < MAX - 1) {
        top++;
        charStack[top] = value;
    }
}

char pop() {
    char value = charStack[top];
    top--;
    return value;
}

int main() {
    char word[MAX];
    char reversed[MAX];

    cout << "Enter a word: ";
    cin >> word;

    int i = 0;

    while (word[i] != '\0') {
        push(word[i]);
        i++;
    }

    int j = 0;

    while (top != -1) {
        reversed[j] = pop();
        j++;
    }

    reversed[j] = '\0';

    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversed << endl;

    return 0;
}
