#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


// constructor
Node *node_create(uint8_t val) {

	Node *n = (Node *) malloc(sizeof(Node));	// mem for Node

	if (n) {
		n->val = val;
		n->next = NULL;
	}

	return n;

}


// destructor
void node_delete(Node **n) {

	// cant access n after free(n). Therefore pass **n.
	if (n && *n) {
		free(*n);
		*n = NULL;
	}

	return;
}


// print node
void node_print(Node *n) {

	if (n) {
		printf("Val: %" PRIu8 ". Next: %p.\n", n->val, n->next);
	}

	return;

}

