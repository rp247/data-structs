#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// Each Nodes of the SLL have this form
struct Node {
	Node *next;
	uint8_t val;
};

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
