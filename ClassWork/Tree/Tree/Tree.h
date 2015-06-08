#pragma once

#include <exception>

template <class T_key, class T_value>
class tree {
private:
	struct Node {
		Node() : left(nullptr), right(nullptr) {};
		T_key key;
		T_value value;
		Node *left, *right;
	};

	Node *root;
	size_t amount_of_elements;

	void private_show(Node *current);
	void private_clear(Node *current);
public:
	tree() : root(nullptr), amount_of_elements(0) {};
	~tree() { private_clear(root); };

	T_value& operator[](const T_key& key);
	tree& clear();
	void show();
	const size_t& size();
	bool find(const T_key& key);
	tree& remove(const T_key& key);
};

template <class T_key, class T_value>
void tree<T_key, T_value>::private_show(Node *current) {
	if (current) {
		cout << current->key << ' ' << current->value << endl;
		private_show(current->left);
		private_show(current->right);
	}
}

template <class T_key, class T_value>
void tree<T_key, T_value>::private_clear(Node *current) {
	if (current) {
		private_clear(current->left);
		private_clear(current->right);
		delete current;
	}
}

template <class T_key, class T_value>
T_value& tree<T_key, T_value>::operator[](const T_key& key) {
	Node *temp = root;
	Node **pointer = &root;

	while (temp != nullptr) {
		if (key < temp->key) {
			pointer = &(temp->left);
			temp = temp->left;
		}
		else if (temp->key < key) {
			pointer = &(temp->right);
			temp = temp->right;
		}
		else
			return temp->value;
	}

	*pointer = new Node;
	(*pointer)->key = key;
	++amount_of_elements;
	return (*pointer)->value;
}

template <class T_key, class T_value>
tree<T_key, T_value>& tree<T_key, T_value>::clear() {
	private_clear(root);
	root = nullptr;
	amount_of_elements = 0;
	return *this;
}

template <class T_key, class T_value>
void tree<T_key, T_value>::show() {
	private_show(root);
}

template <class T_key, class T_value>
const size_t& tree<T_key, T_value>::size() {
	return amount_of_elements;
}

template <class T_key, class T_value>
bool tree<T_key, T_value>::find(const T_key& key) {
	Node *temp = root;

	while (temp != nullptr) {
		if (key < temp->key)
			temp = temp->left;
		else if (temp->key < key)
			temp = temp->right;
		else
			return true;
	}

	return false;
}

template <class T_key, class T_value>
tree<T_key, T_value>& tree<T_key, T_value>::remove(const T_key& key) {
	Node *temp = root;
	Node **pointer = &root;

	while (temp && temp->key != key) {
		if (key < temp->key) {
			pointer = &(temp->left);
			temp = temp->left;
		}
		else if (temp->key < key) {
			pointer = &(temp->right);
			temp = temp->right;
		}
	}

	//if (temp->key == key) {
	//	Node *temp_left = temp->left, *temp_right = temp->right;
	//	delete temp;
	//	*pointer = temp_left;

	//	temp = temp_left->right;
	//	while (temp)
	//		temp = temp->right;
	//}
}
