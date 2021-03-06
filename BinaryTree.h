#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTree
{
private:
	struct Node
	{
		T data;
		Node *left;
		Node *right;
		Node(T data)
		{
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	Node *root;

public:
	BinaryTree();
	void insert(T);
	void inorder(Node *);
	void preorder(Node *);
	void postorder(Node *);
	void levelorder(Node *);
	void forLevel(Node *);
	void Delete(T data);
	void DeleteOll(Node *);
	Node *getRoot()
	{
		Node *tmp = this->root;
		return tmp;
	}
	~BinaryTree();
};

template <typename T>
BinaryTree<T>::BinaryTree() : root{nullptr}
{
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	DeleteOll(this->root);
}

template <typename T>
void BinaryTree<T>::insert(T dt)
{

	if (!root)
	{
		root = new Node(dt);
		return;
	}

	Node *cur = root;
	Node *tmp = new Node(dt);

	while (cur)
	{

		if (cur->data == dt)
		{
			return;
		}

		if (cur->data < dt)
		{
			if (!cur->right)
			{
				cur->right = tmp;
				return;
			}
			cur = cur->right;
		}
		else
		{

			if (!cur->left)
			{
				cur->left = tmp;
				return;
			}
			cur = cur->left;
		}
	}
}

template <typename T>
void BinaryTree<T>::inorder(Node *root)
{
	if (!root)
	{
		return;
	}

	inorder(root->left);
	std::cout << root->data << std::endl;
	inorder(root->right);
}

template <typename T>
void BinaryTree<T>::preorder(Node *root)
{
	if (!root)
	{
		return;
	}

	std::cout << root->data << std::endl;
	preorder(root->left);
	preorder(root->right);
}

template <typename T>
void BinaryTree<T>::postorder(Node *root)
{
	if (!root)
	{
		return;
	}

	postorder(root->left);
	postorder(root->right);
	std::cout << root->data << std::endl;
}

template <typename T>
void BinaryTree<T>::levelorder(Node *root)
{
	// if (!root)
	// {
	// 	return;
	// }

	// if (this->root == root)
	// {
	// 	std::cout << root->data << std::endl;
	// }
	// if (root->left)
	// {
	// 	std::cout << root->left->data << std::endl;
	// }

	// if (root->right)
	// {

	// 	std::cout << root->right->data << std::endl;
	// }

	// levelorder(root->left);
	// levelorder(root->right);


	if (root == nullptr)
		return;
	std::queue<Node *> base;
	base.push(root);
	while (!base.empty())
	{
		Node *tmp = base.front();
		std::cout << tmp->data << std::endl;
		base.pop();
		if (tmp->left != nullptr)
		{
			base.push(tmp->left);
		}
		if (tmp->right != nullptr)
		{
			base.push(tmp->right);
		}
	}
}

template <typename T>
void BinaryTree<T>::Delete(T data)
{
	if (this->root == nullptr)
		return;
	std::queue<Node *> base;
	std::vector<T> tmp1;
	base.push(this->root);
	while (!base.empty())
	{
		Node *tmp = base.front();
		if (tmp->data != data)
		{
			tmp1.push_back(tmp->data);
		}

		base.pop();
		if (tmp->left != nullptr)
		{
			base.push(tmp->left);
		}
		if (tmp->right != nullptr)
		{
			base.push(tmp->right);
		}
	}
	this->DeleteOll(this->root);
	for (int i = 0; i < tmp1.size(); ++i)
	{
		this->insert(tmp1[i]);
	}
}

template <typename T>
void BinaryTree<T>::DeleteOll(Node *cur)
{
	if (!cur)
	{
		this->root = nullptr;
		return;
	}

	DeleteOll(cur->left);
	DeleteOll(cur->right);
	delete cur;
	cur = nullptr;
}
