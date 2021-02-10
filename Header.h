// File: Header.h
// Author: Dmitrii Zmerzlov

#define ELEMENTS_ARR_NUMBER(arr) sizeof(arr) / sizeof(arr[0])    // Число элементов в массиве arr

/* $
   $ brief: Структура, описывающая узел дерева
   $ param: data Данные, которые хранятся в узле
   $ param: *leftSubtree Указатель на левое поддерево
   $ param: *rightSubtree Указатель на правое поддерево
   $ */
typedef struct nodeOfTree {
	int data;
	struct nodeOfTree *leftSubtree;
	struct nodeOfTree *rightSubtree;
} node;


node* insert(node *root, int x);
node* deleteNode(node *root, int x);
node* find_minimum_element(node *root);
node* new_node(int x);
void symmetrical_printing(node *root);
void tree_deletion(node *root);
