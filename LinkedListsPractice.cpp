// Your task is to implement the missing parts of the LinkedList class, including the constructor,
// destructor, and methods for inserting, deleting, and searching for nodes in the list.

#include <iostream>

// Define a structure for the linked list node
struct Node
{
    int data;
    Node* next;
};

// Define a class for the linked list
class LinkedList
{
private:
    Node* head; // Pointer to the head of the list

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor
    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Return the data of the first, or 'head' Node.

    int getHeadData() {
        if (head == nullptr) {
            return -1;
        }
        return head->data;
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete a node with the given data from the list
    void deleteNode(int data)
    {
        // make sure we aren't running this on an empty list.
        if (head == nullptr)
        {
            return;
        }

        if (head->data == data)
        {
            // The node to delete is the head of the list.
            Node* temp = head;
            // sets the head to whatever was second, basically
            head = head->next;
            // works because we are working with pointers.
            delete temp;
        }
        else
        {
            // This means the node we want to delete is further in the list.
            Node* current = head;
            while (current->next != nullptr && current->next->data != data)
            {
                current = current->next;
                // This will mean we have either gotten to the end of the list, or we found the data
            }

            if (current->next != nullptr)
            {
                // it must mean we found the node to delete.
                Node* temp = current->next;
                current->next = temp->next;
                // this part confused me when I learnt it. if the current node is 1, the node we want to delete is 2, and the node after that is 3
                // we set temp to node 2 (the one we want to delete.)
                // and set the pointer for 'next' in node 1 to the address of node 3 using temp->next (node2.next)
                delete temp;
            }
        }
    }

    // Search for a node with the given data in the list
    bool search(int data)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse()
    {
        // Check if the list is empty
        if (head == nullptr)
        {
            return;
        }

        // Initialize pointers to trrack the current and previous nodes.
        Node* current = head;
        Node* previous = nullptr;

        // Iterate over the list
        while (current != nullptr)
        {
            // Store the next node
            Node* next = current->next;

            // Reverse the current node's next pointer
            current->next = previous;

            // Move the previous and current pointers one step forward
            previous = current;
            current = next;
        }

        // Update the head of the list.
        head = previous;
    }
};

int main()
{
    // Create a linked list instance
    LinkedList list;

    // Insert some nodes at the beginning of the list
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    // Insert some nodes at the end of the list
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    // Delete a node from the list
    list.deleteNode(2);

    // Print the head data before we reverse the list
    std::cout << "Head Data Before Reverse: " << list.getHeadData() << std::endl;

    list.reverse();
    std::cout << "List has been reversed. " << std::endl;
    // The list should now be in reverse order.

    // Print the head data after reversing the list
    std::cout << "Head data after reversing the list: " << list.getHeadData() << std::endl;

    // Search for a node in the list
    if (list.search(5))
    {
        std::cout << "Found node with data 5" << std::endl;
    }
    else
    {
        std::cout << "Did not find node with data 5" << std::endl;
    }

    return 0;
}