#pragma once
#include <iostream>
#include <algorithm>
class BinaryTree
{
private:
	struct Node // ��������� ����� ������
	{
		int data; // �������� ������ �����
		int counter; // �������, ����� ����� ������� ���������� (������ �� �� �����, �������� ������ �� � �������� ����������� ����� ������ �������)
		Node* left, * right; // ��������� �� ��������
	};

	void AddToSubTree(Node*& node, Node* newnode) // ������� ����
	{
		if (node == NULL)
		{
			node = newnode; // ���� ����� ��� �� ����� ���� ���������� ������
			return;
		}
		if (newnode->data < node->data) // ���� ������ ������ ���� ������ ��� �������
			AddToSubTree(node->left, newnode); // �� ��������� � ������ �������
		else
			AddToSubTree(node->right, newnode); // ����� � �������
	}
	Node* root = NULL; // ������ ������
public:

	void AddToTree(int data) // ������� ������
	{
		Node* node = new Node;
		node->data = data;
		node->left = node->right = NULL; // ������� �������� ������� ���� ��� ������
		node->counter = 1;
		AddToSubTree(root, node); // ��������� �������� ����
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

