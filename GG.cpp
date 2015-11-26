#include <iostream>
#include <string.h>

using namespace std;

class node
{
public:
	int id;
	node* parent;
	node* left;
	node* right;

public:
	node()
	{
		id = 0;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	void add(node* parent, int dir, int a)
	{
		node* temp = new node;
		temp->id = a;
		temp->parent = parent;
		(dir == 1)? parent->left = temp : parent->right = temp;
	}

	void add_left_recursive(node* curr, int a)
	{
		if (curr == NULL) return;
		if (curr->left == NULL)
		{
			add (curr, 1, a);
		}
		else
		{
			add_left_recursive(curr->left, a);
		}
		add_left_recursive(curr->right, a);
	}

	void add_right_recursive(node* curr, int a)
	{
		if (curr == NULL) return;
		if (curr->right == NULL)
		{
			add (curr, -1, a);
		}
		else
		{
			add_right_recursive(curr->right, a);
		}
		add_right_recursive(curr->left, a);
	}

	void add_all(node* root,int dir, int a)
	{
		node * curr = root;
		if (dir == 1)
		{
			add_left_recursive(root, a);
		}
		if (dir == -1)
		{
			add_right_recursive(root, a);
		}
	}

	void dfp(node *curr)
	{
		if (curr != NULL)
		{
			dfp(curr->left);
			cout << curr->id << " ";
			dfp(curr->right);
		}
	}	

	void execute_on_leaves(node* curr)
	{
		if (curr == NULL) return;
		if (curr->left != NULL)
		{
			execute_on_leaves(curr->left);
		}
		if (curr->right != NULL)
		{
			execute_on_leaves(curr->right);
		}
		if (curr->left == NULL && curr->right == NULL)
		{
			//Execute function
			cout << "This node is: " << curr->id << endl;
		}
	}	

	void find_words(string partial_word, node* curr)
	{
		

	}
};



int main()
{
	int N;
    int M;
    cin >> N >> M;
    string S;
    cin >> S;

    int count = 0;
    node tree;

    node x;

    char c;

    tree.id = 0;

    for (int count =0; count < S.size(); count++)
    {
    	c = S[count];
    	cout << "Processing " << c << endl;
    	if (c == 'L')
    	{
    		cout << "Adding " << count+1 << " to the right\n";
    		x.add_all(&tree, -1, count+1);
    	}
    	else
    	{
    		cout << "Adding " << count+1 << " to the left\n";
    		x.add_all(&tree, 1, count+1);
    	}
    }

    x.dfp(&tree);
    
    x.execute_on_leaves(&tree);

    return 0;
}