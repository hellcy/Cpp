// C++ program to illustrate inserting a Node in 
// a Cicular Doubly Linked list in begging, end 
// and middle 
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <iterator> 
#include <map> 
using namespace std; 
  
// Structure of a Node 
struct Node 
{ 
    long long data; 
    struct Node *next; 
    struct Node *prev; 
}; 
  
// Function to insert at the end 
void insertEnd(struct Node** start, long long value) 
{ 
    // If the list is empty, create a single node 
    // circular and doubly list 
    if (*start == NULL) 
    { 
        struct Node* new_node = new Node; 
        new_node->data = value; 
        new_node->next = new_node->prev = new_node; 
        *start = new_node; 
        return; 
    } 
  
    // If list is not empty 
  
    /* Find last node */
    Node *last = (*start)->prev; 
  
    // Create Node dynamically 
    struct Node* new_node = new Node; 
    new_node->data = value; 
  
    // Start is going to be next of new_node 
    new_node->next = *start; 
  
    // Make new node previous of start 
    (*start)->prev = new_node; 
  
    // Make last preivous of new node 
    new_node->prev = last; 
  
    // Make new node next of old last 
    last->next = new_node; 
} 
  
// Function to insert Node at the beginning 
// of the List, 
void insertBegin(struct Node** start, long long value) 
{ 
    // Pointer points to last Node 
    struct Node *last = (*start)->prev; 
  
    struct Node* new_node = new Node; 
    new_node->data = value;   // Inserting the data 
  
    // setting up previous and next of new node 
    new_node->next = *start; 
    new_node->prev = last; 
  
    // Update next and previous pointers of start 
    // and last. 
    last->next = (*start)->prev = new_node; 
  
    // Update start pointer 
    *start = new_node; 
} 
  
// Function to insert node with value as value1. 
// The new node is inserted after the node with 
// with value2 
void insertAfter(struct Node** start, long long value1, 
                                      long long value2) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = value1; // Inserting the data 
  
    // Find node having value2 and next node of it 
    struct Node *temp = *start; 
    while (temp->data != value2) 
        temp = temp->next; 
    struct Node *next = temp->next; 
  
    // insert new_node between temp and next. 
    temp->next = new_node; 
    new_node->prev = temp; 
    new_node->next = next; 
    next->prev = new_node; 
} 
  
  
void display(struct Node* start) 
{ 
    struct Node *temp = start; 
  
    while (temp->next != start) 
    { 
        printf("%lld ", temp->data); 
        temp = temp->next; 
    } 
    printf("%lld ", temp->data); // now temp is the last node in the list.
    printf("\n");
} 

list<string> splitFile(string str) 
{ 
    list<string> input;
    string word = ""; 
    for (auto x : str) 
    { 
        if (x == ' ') 
        { 
            input.push_back(word);
            word = ""; 
        } 
        else
        { 
            word = word + x; 
        } 
    }  
    input.push_back(word);
    return input;
}

void print(std::list<std::string> const &list)
{
    for (auto const& i: list) {
        std::cout << i << "\n";
    }
}
  
/* Driver program to test above functions*/
int main() 
{ 
    ifstream f("input.txt"); //taking file as inputstream
    string str;
    if(f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        str = ss.str();
    }

    string word = ""; 
    int playerNum = 0;
    long ballNum = 0;
    int count = 0;
    for (auto x : str) 
    { 
        if (x == ' ' && count == 0) 
        { 
            playerNum = stoi(word);
            word = ""; 
            count++;
        }
        else if (x == ' ' && count == 6)
        {
            ballNum = stoi(word);
            word = "";
            count++;
        }
        else if (x == ' ')
        {
            word = "";
            count++;
        }
        else
        { 
            word = word + x; 
        } 
    }  

    cout << playerNum << "\n";
    cout << ballNum << "\n";

    //test
    //playerNum = 30;
    //ballNum = 5807;

    struct Node* circle = NULL;
    map<int, long long> scores; // keep track of all the scores for all elves 
    map<int, long long>::iterator it;

    for (int i = 1; i <= playerNum; i++)
    {
        scores.insert(pair<int,long long>(i,0));
    }

    insertEnd(&circle, 0);
    struct Node* current = circle;
    insertAfter(&circle, 1, current->next->data);
    current = current->next;

    for (long i = 2; i <= ballNum; i++)
    {
        if (i % 23 != 0)
        {
            struct Node* new_node = new Node;
            new_node->data = i;
            struct Node* temp1 = current->next;
            struct Node* temp2 = current->next->next;
            temp1->next = new_node;
            new_node->prev = temp1;
            new_node->next = temp2;
            temp2->prev = new_node;
            current = new_node;
            // insertAfter(&circle, i, current->next->data);
            // current = current->next->next;
            //printf("%d\n", current->data);
            //display(circle);
        }
        else
        {
            int match = i%playerNum;
            if (match == 0) match = playerNum;
            it = scores.find(match); 
            if (it != scores.end()) it->second += i;
            current = current->prev->prev->prev->prev->prev->prev;
            printf("%d\n", current->data);
            if (it != scores.end()) it->second += current->prev->data;
            struct Node* temp = current->prev->prev;

            temp->next = current;
            current->prev = temp;
            //display(circle);
            //printf("%lld\n", it->second);
        }
    }

    long long max = 0, tempMax = 0;

    for (it = scores.begin(); it != scores.end(); ++it) { 
        tempMax = it->second;
        if (max < tempMax)
        {
            max = tempMax;
        }
        printf("%d %lld %lld\n", it->first, it->second, max);
    } 

    printf("%lld\n", max);
    return 0; 
} 