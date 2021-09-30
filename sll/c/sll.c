#include "sll.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

/* 
 * to do:
 * add time complexities
 * more algorithms for sll
 */

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


// deletes first node with val *val*. sentinental nodes do no count.
void sll_node_delete(uint8_t val, SLL *sll) {
	if (sll) {
		Node *temp = sll->head, *temp2;

		while (temp->next != sll->tail) {
			if (temp->next->val == val) {
				temp2 = temp->next;	// for freeing mem
				temp->next = temp->next->next;
				node_delete(&temp2);
				break;
			}
			temp = temp->next;
		}
	}
	
	return;
}


// searches for the first node with val *val*
Node *sll_search_node(uint8_t val, SLL *sll) {
	if (!sll) return NULL;

	Node *temp = sll->head;
	bool found = false;

	while (temp->next != sll->tail) {
		temp = temp->next;	
		if (temp->val == val) {
			found = true;
			break;
		}
	}

	return found ? temp : NULL;
}


// adds a node with val *val* after the first node with val *search*. otherwise doesnt add.
void sll_add_after(uint8_t search, uint8_t val, SLL *sll) {
	Node *n = sll_search_node(search, sll);

	if (n) {
		Node *temp = node_create(val);
		temp->next = n->next;
		n->next = temp;
	}

	return;
}


// reverses a sll
void sll_reverse(SLL *sll) {

	Node *prev = sll->head, *nn = sll->head, *nexxt = sll->head, *temp;


		while (nexxt->next != NULL && prev->next->next != NULL) {
			prev->next = nexxt;
			temp = prev->next->next; nexxt = prev->next->next; nn = prev->next;
			nn->next = prev;
			prev = nexxt->next;
			nexxt->next = nn;
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

