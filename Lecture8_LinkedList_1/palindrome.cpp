#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

bool isPalindrome(Node *head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* prevTail = head;
    while((prevTail->next)->next != NULL){
        prevTail = prevTail->next;
    }

    /* if(head == prevTail){
        if(head->next == NULL){
            return true;
        }
        else if(head->data == (prevTail->next)->data){
            return true;
        }
        else{
            return false;
        }
    } */

    if(head->data == (prevTail->next)->data){
        prevTail -> next = NULL;
        return isPalindrome(head->next);
    }

    return false;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}