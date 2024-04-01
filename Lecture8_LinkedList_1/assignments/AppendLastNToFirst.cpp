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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *appendLastNToFirst(Node *head, int n){
    if(head == NULL || head->next == NULL || n == 0){
        return head;
    }

    Node* temp = head;
    Node* tail = NULL;
    int lastIndex = -1;
    while(temp != NULL){
        if(temp->next == NULL){
            tail = temp;
        }
        lastIndex++;
        temp = temp->next;
    }

    int newLastIndex = lastIndex - n;
    Node* newTail = head;
    int count = 0;
    while(count < newLastIndex){
        newTail = newTail->next;
        count++;
    }
    Node* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    
    return newHead;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}