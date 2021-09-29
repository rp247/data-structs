#ifndef SLL_H__
#define SLL_H__

#include "node.h"

#include <inttypes.h>

typedef struct SLL SLL;

SLL *sll_create();				// constructor
void sll_delete(SLL **sll);			// destructor 
void sll_prepend(uint8_t val, SLL *sll);	// prepends between head sentinetal and first node
void sll_append(uint8_t val, SLL *sll);		// appends between tail sentinental and last node
void sll_node_delete(uint8_t val, SLL *sll);	// deletes a node with val. no sentinentals deleted.
void sll_print(SLL *sll);			// prints sll
Node *sll_search_node(uint8_t val, SLL *sll);	// searches first node with the val *val*
void sll_add_after(uint8_t search, uint8_t val, SLL *sll);   // appends a node after a certain value
void sll_reverse(SLL *sll);

#endif /* SLL_H__ */
