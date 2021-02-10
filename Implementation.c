// File: Implementation.c
// Author: Dmitrii Zmerzlov

#include <stdio.h>
#include "Header.h"


/*
 * \brief: Вставка элемента в дерево
 * \note:  Функция использует рекурсию!
 *
 * \param: *root Узел дерева
 * \param: x Значение, которое надо вставить
 *
 * \return new_node(x): Создание нового узла дерева
 * \return root: Узел дерева
 */
node* insert(node *root, int x) {
	if (root == NULL)
		return new_node(x);
	else if (x >= root->data)
		root->rightSubtree = insert(root->rightSubtree, x);
	else
		root->leftSubtree = insert(root->leftSubtree, x);

	return root;
}

/*
 * \brief: Удаление узла дерева
 * \note:  Функция использует рекурсию!
 *
 * \param: *root Узел дерева
 * \param: x Значение, которое надо удалить
 *
 * \return NULL (1): Если такого узла дерева не существует
 * \return NULL (2): Указатель на NULL (Если нет поддеревьев)
 * \return temp: Замена удаляемого узла на поддерево
 * \return root: Узел дерева
 */
node* deleteNode(node *root, int x) {
	if (root == NULL)
		return NULL; // (1)

	if (x > root->data)
		root->rightSubtree = deleteNode(root->rightSubtree, x);
	else if (x < root->data)
		root->leftSubtree = deleteNode(root->leftSubtree, x);
	else {
		// Нет потомков
		if (root->leftSubtree == NULL && root->rightSubtree == NULL) {
			free(root);

			return NULL; // (2)
		}

		// Один потомок
		else if (root->leftSubtree == NULL || root->rightSubtree == NULL) {
			node *temp;

			if (root->leftSubtree == NULL)
				temp = root->rightSubtree;
			else
				temp = root->leftSubtree;

			free(root);

			return temp;
		}

		// Два потомка
		else {
			node *temp = find_minimum_element(root->rightSubtree);

			root->data = temp->data;
			root->rightSubtree = deleteNode(root->rightSubtree, temp->data);
		}
	}

	return root;
}

/*
 * \brief: Поиск минимального значения после узла root
 * \note:  Функция использует рекурсию!
 *
 * \param: *root Узел дерева
 *
 * \return NULL: Если узла дерева не существует
 * \return find_minimum_element(root->leftSubtree): Ищем минимальные элементы в левом поддереве
 * \return root: Узел дерева
 */
node* find_minimum_element(node *root) {
	if (root == NULL)
		return NULL;
	else if (root->leftSubtree != NULL)
		return find_minimum_element(root->leftSubtree);

	return root;
}

/*
 * \brief: Создание нового узла дерева
 * \param: x Значение, которое нужно вставить в узел
 * \return p: Созданный узел
 */
node* new_node(int x) {
	node *temp;

	temp = malloc(sizeof(node));
	temp->data = x;
	temp->leftSubtree = NULL;
	temp->rightSubtree = NULL;

	return temp;
}

/*
 * \brief: Симметричный вывод дерева
 * \note:  Функция использует рекурсию!
 * \param: *root Корень дерева
 */
void symmetrical_printing(node *root) {
	if (root != NULL) {
		symmetrical_printing(root->leftSubtree);
		printf("%d ", root->data);
		symmetrical_printing(root->rightSubtree);
	}
}

/*
 * \brief: Удаление дерева для экономия памяти
 * \note:  Функция использует рекурсию!
 * \param: *root Корень дерева
 */
void tree_deletion(node *root) {
	if (root != NULL) {
		tree_deletion(root->leftSubtree);   // Рекурсивно удаляем левую ветку
		tree_deletion(root->rightSubtree);  // Рекурсивно удаляем правую ветку
		free(root);                         // Удаляем корень
	}
}