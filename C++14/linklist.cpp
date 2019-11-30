#include<iostream>
using namespace std;


class Node {

    public:
        Node(int d) {
            this->data = d;
            this->next = nullptr;
        }
        int data;
        Node*  next;
};


class list {
    public:
        list():head(nullptr) { }
        void insertAtStart(int d) {
            Node *temp = new Node(d);
            if (head == nullptr) {
                head = temp;
            } else {
                temp->next = head;
                head = temp;
            }

        }

        void insertAtLast(int d) {
            Node *temp = new Node(d);

            Node *it = head;
            while(it->next != nullptr) {
                it = it->next;
            }
            it->next = temp;
        }

        void printList() {
            cout << "printing list" <<endl;
            Node *it = head;
            while(it != nullptr) {
                cout << it->data << endl;
                it = it->next;
            }
        }

        void deleteFromLast() {
            Node *it = head;
            while(it->next->next != nullptr) {
                it = it->next;
            }
            delete it->next;
            it->next = nullptr;
        }
        void deleteData(int d) {
            Node *it = head;
            while(it->next !== nullptr) {
                it = it->next;
                if(it->data == d) {
                }
            }
        }
// Assignement ==> break the loop in linklist, where it starts where it ends
    private:
        Node *head;
};

int main () {
    list *l = new list();
    l->insertAtStart(10);
    l->insertAtStart(20);
    l->insertAtStart(30);
    l->insertAtLast(40);
    l->insertAtLast(50);
    l->insertAtLast(60);
    l->printList();
    l->deleteFromLast();
    l->printList();
    delete l;
    return 0;
}
