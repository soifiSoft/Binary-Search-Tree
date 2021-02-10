// File: Source.c
// Author: Dmitrii Zmerzlov
/* Description: Реализация бинарного дерева поиска */
#include <stdio.h>
#include "Header.h"

int main() {
	node *root;                                                  // Корень бинарного дерева
	int valuesForATree[] = { 20, 4, 1, 12, 40, 9, 42, 45, 25};   // Значения узлов для дерева
	int i;                                                       // Счетчик

	// Создание бинарного дерева поиска
	root = new_node(valuesForATree[0]);   // Корень дерева
	for (i = 1; i < ELEMENTS_ARR_NUMBER(valuesForATree); i++)
		insert(root, valuesForATree[i]);  // Узлы дерева

	// Вывод в симметричном порядке
	symmetrical_printing(root);
	printf("\n");

	/*
                    20
	               /    \
				  /      \
				 4        40
				/ \      /  \
			   /   \    /    \
			  1     12 25     42
	               /            \
	              /              \
	             9                45
	*/


	deleteNode(root, 1);   // Удаление узла без потомков
	deleteNode(root, 42);  // Удаление узла с одним потомком
	deleteNode(root, 40);  // Удаление узла с двумя потомками

	/*
					 20
				   /    \
				  /      \
				 4        45
				  \      /
			       \    /
			        12 25
				   /            
				  /              
				 9                
	*/

	// Вывод в симметричном порядке
	symmetrical_printing(root);
	printf("\n");

	// Удаление дерева
	tree_deletion(root);

	return 0;
}