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

	SLL *sll = (SLL *) malloc(sizeof(SLLL));

	if (sll) {
		
		// sentinental nodes
		Node *head = node_create(0);
		Node *tail = node_create(0);

		head->next = tail;
	}

	return sll;

}


