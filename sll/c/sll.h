#ifndef SLL_H__
#define SLL_H__

#include <inttypes.h>

typedef struct SLL SLL;

SLL *sll_create();				// constructor
void sll_delete(SLL **sll);			// destructor 
void sll_prepend(uint8_t val, SLL *sll);	// prepends between head sentinetal and first node
void sll_append(uint8_t val, SLL *sll);		// appends between tail sentinental and last node
void sll_print(SLL *sll);			// prints sll

#endif /* SLL_H__ */
