#include "sll.h"
#include "node.h"

#include <stdio.h>
#include <stdint.h>

int main(){
	SLL *sll = sll_create();		// create test

	printf("PRINT TEST: ");
	sll_print(sll);				// print test

	printf("PREPEND TEST: ");
	sll_prepend(10, sll);			// prepend test
	sll_prepend(91, sll);			// prepend test
	sll_print(sll);

	printf("APPEND TEST: ");
	sll_append(-1, sll);				// append test
	sll_append(147, sll);		
	sll_print(sll);

	sll_delete(&sll);			// delete test

	sll_print(sll);
}
