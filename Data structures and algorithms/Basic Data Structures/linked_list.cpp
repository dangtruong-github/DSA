#include<iostream>
#include<string>
#include<cstring> // For strncpy

using namespace std;


struct Node {
    Node* next;
    char* valueString;
};

Node getNodeById (int id, Node first) {
    int cur_id = 1;
    while (cur_id < id) {
        if (first.next == NULL) {
            cout << "The id you requested is greater than the length of this linked list\n";
            return *first.next;
        }
        
        cout << "Current node id: " << cur_id << "\n";
        cout << "Current node value: " << first.valueString << endl;

        first = *first.next;
        cur_id++;
    }

    cout << first.valueString << "\n";

    return first;
}

int main() {
    int n;
    string inputString;
    cin >> n;

    Node firstNode;
    firstNode.next = nullptr; // Initialize next pointer
    Node currentNode;

    for (int i = 0; i < n; i++) {
        cin >> inputString;

        currentNode.valueString = new char[inputString.length() + 1];
        strncpy(currentNode.valueString, inputString.c_str(), inputString.length());
        currentNode.valueString[inputString.length()] = '\0';

        cout << "Input string: " << inputString << endl;
        cout << "Node string: " << currentNode.valueString << endl;

        if (i < n - 1) {
            currentNode.next = new Node();
            
            if (i == 0) {
                firstNode = currentNode;
            } else {
                cout << "First node's string:" << firstNode.valueString << "\n";
                cout << "First node's next node's string: " << (*firstNode.next).valueString << "\n";
            }

            currentNode = *currentNode.next;
        }
    }  

    cout << "Create success\n";

    getNodeById(n + 1, firstNode);

    return 0;
}