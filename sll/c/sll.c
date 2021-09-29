#include "sll.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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


// prepends a node.
void sll_prepend(uint8_t val, SLL *sll) {
	
	if (sll) {
		Node *n = node_create(val);
		if (n) {
			n->next = sll->head->next; // between head and first node
			sll->head->next = n;
		}
	}

	return;

}


// appends a node
void sll_append(uint8_t val, SLL *sll) {
	
	if (sll) {
		Node *n = node_create(val);
		if (n) {
			Node *temp = sll->head;
			while(temp->next != sll->tail) {	// get to one before tail
				temp = temp->next;
			}
			n->next = temp->next;			// attach in between
			temp->next = n;
		}
	}

	return;
}	


// prints a sll
void sll_print(SLL *sll) {
	if (sll) {
		printf("HEAD->");
		
		Node *temp = sll->head;
		while (temp->next != sll->tail) {
			temp = temp->next;
			printf("%" PRIu8 "->", temp->val);
		}

		
		printf("TAIL.\n");
	}

	return;
}

