#include<iostream>
#include<string>
#include<cstring> // For strncpy

using namespace std;


struct Node {
    Node* next = nullptr;
    char* valueString = nullptr;
};


class Queue {
    Node* botPtr;
    Node* topPtr;
    int size;

    public:
        Queue () {
            botPtr = nullptr;
            topPtr = nullptr;
            size = 0;
        };

        int getSize() {
            return this->size;
        };

        void addNode(char* data) {
            Node* toAdd = new Node();
            
            toAdd->valueString = data;

            toAdd->next = head;
            head = toAdd;
            this->printLL();
        };

        void addToHead(string data) {
            Node* toAdd = new Node();
            
            toAdd->valueString = new char[data.length() + 1];
            strncpy(toAdd->valueString, data.c_str(), data.length());
            toAdd->valueString[data.length()] = '\0';
            
            toAdd->next = head;
            head = toAdd;
            this->printLL();
        };

        Node getNodeById (int id) {
            Node* now = head;
            int cur_id = 1;
            while (cur_id <= id) {
                if (now == NULL) {
                    cout << "The id you requested is greater than the length of this linked list\n";
                    return *now;
                }
                
                cout << "Current node id: " << cur_id << "\n";
                cout << "Current node value: " << now->valueString << endl;

                now = now->next;
                cur_id++;
            }

            cout << now->valueString << "\n";

            return *now;
        };

        void printLL () {
            Node* now = head;
            int cur_id = 1;
            while (now != NULL) {
                
                cout << "Current node id: " << cur_id << "\n";
                cout << "Current node value: " << now->valueString << endl;

                now = now->next;
                cur_id++;
            }
        }
};

int main() {
    int n;
    string inputString;
    cin >> n;

    LinkedList lk;

    for (int i = 0; i < n; i++) {
        cin >> inputString;

        lk.addToHead(inputString);
    }
    
    lk.getNodeById(n+1);

    return 0;
}