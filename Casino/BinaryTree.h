#pragma once
#include <iostream>
#include <algorithm>
class BinaryTree
{
private:
	struct Node // стркутура узела дерева
	{
		int data; // значение внутри листа
		int counter; // счетчик, нужен чтобы считать повторения (сейчас он не нужен, занимает память но с большими структурами очень сильно поможет)
		Node* left, * right; // указатели на потомков
	};

	void AddToSubTree(Node*& node, Node* newnode) // создаем узел
	{
		if (node == NULL)
		{
			node = newnode; // если корня нет то новый узел становится корнем
			return;
		}
		if (newnode->data < node->data) // если данные нового узла меньше чем старого
			AddToSubTree(node->left, newnode); // то добавляем в левого потомка
		else
			AddToSubTree(node->right, newnode); // иначе в правого
	}
	Node* root = NULL; // корень дерева
public:

	void AddToTree(int data) // создаем корень
	{
		Node* node = new Node;
		node->data = data;
		node->left = node->right = NULL; // создаем потомков которые пока что пустые
		node->counter = 1;
		AddToSubTree(root, node); // запускаем создание узла
	}

	int SearchInSubTree(int data)
	{
		Node* current = root;
		while (current != nullptr) {
			if (current->data == data) {
				return current->data;
			}
			else if (data < current->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}

		return -1;
	}
};

