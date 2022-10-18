#include <iostream>
#include<vector>
vector<int> vec;
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

void helper(Node* head){
     if(head==NULL) 
         return;  
    vec.push_back(head->data);
    helper(head->next);
}

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL)
        return true;
    helper(head);
    int length=vec.size();
    int i=0;
    int j=length-1;
    while(i<=j)
    {
        if (vec[i]!=vec[j])
            return false; 
        i++;
        j--;
    }
    return true;
}

int main()
{
	int t;
    cout<<"Enter the number of test cases to run : ";
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