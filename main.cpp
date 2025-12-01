#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "queue.h"

int main(int argc, char **argv) {

    Queue q;
    int customerNo = 1;

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "x") == 0) {
            q.serve();
        }

        else {

            if (i + 1 >= argc) {
                cout << "Missing quantity\n";
                break;
            }

            int foodID = atoi(argv[i]);
            int qty = atoi(argv[i+1]);

            q.enqueue(customerNo, foodID, qty);
            customerNo++;

            i++;
        }
    }

    cout << "==========================\n";
    cout << "There are " << q.size() << " ppl left in the queue\n";
    return 0;
}
