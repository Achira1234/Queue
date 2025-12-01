#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Node {
    int orderNo;
    int foodID;
    int qty;
    int price;
    Node* next;

    Node(int on, int f, int q, int p) {
        orderNo = on;
        foodID = f;
        qty = q;
        price = p;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void enqueue(int orderNo, int foodID, int qty) {

        int price = 0;

        if (foodID == 1) price = 100;
        if (foodID == 2) price = 100;
        if (foodID == 3) price = 120;
        if (foodID == 4) price = 150;
        if (foodID == 5) price = 30;

        if (price == 0) {
            cout << "No Food\n";
            return;
        }

        Node* newNode = new Node(orderNo, foodID, qty, price);

        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "My order is " << foodID << endl;
        count++;
    }

    void serve() {

        if (front == NULL) {
            cout << "the queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        cout << "Customer no: " << temp->orderNo << endl;

        if (temp->foodID == 1) cout << "Ramen" << endl;
        if (temp->foodID == 2) cout << "Fried Chicken" << endl;
        if (temp->foodID == 3) cout << "Burger" << endl;
        if (temp->foodID == 4) cout << "Pizza" << endl;
        if (temp->foodID == 5) cout << "Drink" << endl;

        int total = temp->price * temp->qty;

        cout << "You have to pay " << total << endl;

        int cash = 0;

        while (cash < total) {
            cout << "Cash:";
            cin >> cash;
        }

        cout << "Thank you" << endl;

        int change = cash - total;

        if (change > 0)
            cout << "Change is:" << change << endl;

        delete temp;
        count--;
    }

    int size() {
        return count;
    }
};

#endif
