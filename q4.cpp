#include <iostream>
using namespace std;

const int MAX = 5;

int queueData[MAX];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int value) {
    if (count == MAX) {
        cout << "Queue Overflow!" << endl;
    } else {
        if (count == 0) {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queueData[rear] = value;
        count++;

        cout << value << " inserted successfully." << endl;
    }
}

void dequeue() {
    if (count == 0) {
        cout << "Queue Underflow!" << endl;
    } else {
        cout << queueData[front] << " removed successfully." << endl;

        front = (front + 1) % MAX;
        count--;

        if (count == 0) {
            front = -1;
            rear = -1;
        }
    }
}

void getFront() {
    if (count == 0) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << queueData[front] << endl;
    }
}

void display() {
    if (count == 0) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue: ";

        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX;
            cout << queueData[index] << " ";
        }

        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                getFront();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}
