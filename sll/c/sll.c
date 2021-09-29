#include "sll.h"
#include "node.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Singly Linked List definition
struct SLL {
	Node *head;
	Node *tail;
};

// constructor
SLL *sll_create() {

	SLL *sll = (SLL *) malloc(sizeof(SLL));

	if (sll) {
		
		// sentinental nodes
		sll->head = node_create(0);
		sll->tail = node_create(0);

		sll->head->next = sll->tail;
	}

	return sll;

}


// destructor
void sll_delete(SLL **sll) {

	if (sll && *sll) {

		Node *prev = (*sll)->head;
		Node *curr = (*sll)->head->next;

		while (curr != NULL) {
			node_delete(&prev);
			prev = curr;
			curr = curr->next;
		}

		node_delete(&((*sll)->tail));

		free(*sll);
		*sll = NULL;
	}

	return;
}

