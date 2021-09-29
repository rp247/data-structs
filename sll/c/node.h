#ifndef NODE_H__
#define NODE_H__

typedef struct Node Node;

// Each Nodes of the SLL have this form. Defined here so n->next and n->val can be directly accessed.
struct Node {
	Node *next;
	uint8_t val;
};

Node *node_create(uint8_t val);		// constructor

void node_delete(Node **n);		// destructor

void node_print(Node *n);		// prints a node

#endif /* NODE_H__ */
