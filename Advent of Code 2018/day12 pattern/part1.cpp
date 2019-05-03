#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <map>
using namespace std;

static enum StringValue {
	rule0, 
	rule1, 
	rule2, 
	rule3,
	rule4,
	rule5,
	rule6,
	rule7,
	rule8,
	rule9,
	rule10, 
	rule11,
	rule12,
	rule13,
	rule14,
	rule15,
	rule16,
	rule17,
    rule18, 
	rule19,
	rule20,
	rule21,
	rule22,
	rule23,
	rule24,
	rule25,
    rule26, 
	rule27,
	rule28,
	rule29,
	rule30,
	rule31,
	rule32
};

map<string, StringValue> notes;

void Initialize()
{
	notes["#...."] = rule1;
	notes["#..##"] = rule2;
	notes["....#"] = rule3;
	notes["...#."] = rule4;
	notes["...##"] = rule5;
	notes["#.#.#"] = rule6;
	notes[".#..."] = rule7;
	notes["##.#."] = rule8;
	notes["..#.#"] = rule9;
	notes[".##.#"] = rule10;
	notes["###.#"] = rule11;
	notes[".#.##"] = rule12;
	notes["....."] = rule13;
	notes["#####"] = rule14;
	notes["###.."] = rule15;
	notes["##..#"] = rule16;
	notes["#.###"] = rule17;
	notes["#.#.."] = rule18;
	notes["..###"] = rule19;
	notes["..#.."] = rule20;
	notes[".#..#"] = rule21;
	notes[".##.."] = rule22;
	notes["##..."] = rule23;
	notes[".#.#."] = rule24;
	notes[".###."] = rule25;
	notes["#..#."] = rule26;
	notes["####."] = rule27;
	notes[".####"] = rule28;
	notes["#.##."] = rule29;
	notes["##.##"] = rule30;
	notes["..##."] = rule31;
	notes["#...#"] = rule32;
}

// Structure of a Node 
// doubly linked list
struct Node 
{ 
    char data; 
    struct Node *next; 
    struct Node *prev; 
}; 


void display(struct Node* start)  
{  
    struct Node *ptr;  
    printf("\n printing values...\n");  
    ptr = start;  
    while(ptr != NULL)  
    {  
        printf("%c",ptr->data);  
        ptr=ptr->next;  
    } 
    printf("\n");
} 

void insert_end(struct Node** pots, char x)
{
	struct Node* new_node = new Node;
	struct Node* temp = new Node;

	new_node->data = x;

	if (*pots == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*pots = new_node;
	}
	else
	{
		temp = *pots;
    	while (temp->next != NULL)
    	{
    		temp = temp->next;
    	}

    	temp->next = new_node;
	    new_node->prev = temp;
	    new_node->next = NULL;
	}
}

void calPlants(struct Node* node)
{
	string rules = "";
	rules.push_back(node->prev->prev->data);
	rules.push_back(node->prev->data);
	rules.push_back(node->data);
	rules.push_back(node->next->data);
	rules.push_back(node->next->next->data);

	switch(notes[rules])
	{
		case 1:
			node->data = '.';
			break;
		case 2:
			node->data = '#';
			break;
		case 3:
			node->data = '.';
			break;
		case 4:
			node->data = '.';
			break;
		case 5:
			node->data = '#';
			break;
		case 6:
			node->data = '.';
			break;
		case 7:
			node->data = '#';
			break;
		case 8:
			node->data = '.';
			break;
		case 9:
			node->data = '.';
			break;
		case 10:
			node->data = '#';
			break;
		case 11:
			node->data = '#';
			break;
		case 12:
			node->data = '.';
			break;
		case 13:
			node->data = '.';
			break;
		case 14:
			node->data = '#';
			break;
		case 15:
			node->data = '.';
			break;
		case 16:
			node->data = '#';
			break;
		case 17:
			node->data = '#';
			break;
		case 18:
			node->data = '.';
			break;
		case 19:
			node->data = '.';
			break;
		case 20:
			node->data = '.';
			break;
		case 21:
			node->data = '#';
			break;
		case 22:
			node->data = '#';
			break;
		case 23:
			node->data = '#';
			break;
		case 24:
			node->data = '#';
			break;
		case 25:
			node->data = '#';
			break;
		case 26:
			node->data = '.';
			break;
		case 27:
			node->data = '.';
			break;
		case 28:
			node->data = '#';
			break;
		case 29:
			node->data = '#';
			break;
		case 30:
			node->data = '.';
			break;
		case 31:
			node->data = '.';
			break;
		case 32:
			node->data = '#';
			break;
		default:
			break;
	}

}


int main()
{
	Initialize();
	ifstream f("input.txt"); //taking file as inputstream
    string str;
    if(f) {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        str = ss.str();
    }

    string input = "";
    string word = ""; 
    int count = 0;
    for (char x : str) 
    { 
        if ((x == ' ' || x == '\n') && count == 2) 
        { 
            input = word;
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

    struct Node* pots = NULL;

    // insert all input to a doubly linked list.
    for (char x : input)
    {
    	insert_end(&pots, x);
    }

    display(pots);

    struct Node* current = NULL;
    current = pots->next->next;

    while(current->next->next != NULL)
    {
	    calPlants(current);
    	current = current->next;
    }

    display(pots);

	return 0;
}
