#include <iostream> // Including Input Output Stream Library
using namespace std; // Compiler assumes std:: prefix

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; // Creating MIN & MAX values for cases to generate random numbers

class DoublyLinkedList { // Creating a Class called Doubly Linked List
private: // Private Members
    struct Node { // Creating a struct called Node inside of private section
        int data; // Node holds a data point int
        Node* prev; // Node holds a Node that will point to the previous node in that linked list
        Node* next; // Node holds a Node pointer that will point to the next node in that linked list
        Node(int val, Node* p = nullptr, Node* n = nullptr) { // Here we have a parameter constructor for creating a Node. It has 3 parameters
            data = val; // First parameter is an int that sets data to that int val
            prev = p; // Second parameter is a node pointer p that sets prev to whatever p is pointing to
            next = n; // Third parameter is a node pointer n that sets next to whatever n is pointing to
        } // End Parameter Constructor
    }; // End Node Structure

    Node* head; // Pointers that point to nodes within DoublyLinkedList. Will be used to point at head node
    Node* tail; // Pointers that point to nodes within DoublyLinked List. Will be used to point at tail node

public: // Public members of DoublyLinkedList
    DoublyLinkedList() { head = nullptr; tail = nullptr; } // Constructor that when a doublylinkedlist is created sets head and tail pointers (node*) to nullptr;

    void insert_after(int value, int position) { // Function that will insert a node after a certain position
        if (position < 0) { // Checking to see if position is a negative number. Test casing, otherwise wont be able to traverse DLL
            cout << "Position must be >= 0." << endl; // Error prompting user if pos < 0
            return; // breaking out of the function insert_after if true
        }

        Node* newNode = new Node(value); // Creating a pointer newNode that points to a newly created Node object in heap and uses value for the constructor 
        if (!head) { // Test casing to see whether the list is empty if head isnt pointing to anything
            head = tail = newNode; // Then we set both head and tail to that newNode because if above line is true, then the list is empty so the head and tail are going to be pointing to same
            return; // breaking out of function since the job will be handled already if the list is already empty
        }

        Node* temp = head; // If list is not empty, lets create a temp traversal node* variable called temp and set it to point to first node (head node)
        for (int i = 0; i < position && temp; ++i) // Traversing through the linked list while using position as the number of times we are doing it. The addition && temp checks to see whether temp is still pointing at something, meaning we can still traverse
            temp = temp->next; // Letting temp point to the next node in the DLL if the above conditions in for loop still hold true

        if (!temp) { // Test casing whether or not position exceeds the amount of nodes in our linked list. We do this by saying !temp or if temp is nullptr
            cout << "Position exceeds list size. Node not inserted.\n"; // Let user know that his position exceeds the amount of nodes in DLL
            delete newNode; // Free up memory by deleting our New Node because then theres nothing to add after pos if above if statement is true
            return; // braek out of insert_after()
        }

        newNode->next = temp->next; // If the above cases hold true, that means temp is at the spot we want to the insert node after. so now we gotta connect newNode into that list. This line allows newNode to point to tempNode's next, as we will be inserting in the middle of temp and temp-next
        newNode->prev = temp; // We will now allow temp to be the Node* prev pointing in our new node, as our newNode is now in front of temp
        if (temp->next) //
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}
