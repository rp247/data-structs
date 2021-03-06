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
	sll_prepend(0, sll);			// prepend test
	sll_prepend(91, sll);			// prepend test
	sll_print(sll);

	printf("APPEND TEST: ");
	sll_append(-1, sll);			// append test
	sll_append(147, sll);		
	sll_print(sll);

	printf("DELETE TEST: ");		// delete test
	sll_node_delete(10, sll);
	sll_node_delete(55, sll);
	//sll_node_delete(0, sll);
	sll_node_delete(147, sll);
	//sll_node_delete(91, sll);
	//sll_node_delete(255, sll);
	//sll_node_delete(0, sll);
	//sll_node_delete(84, sll);
	sll_print(sll);

	printf("SEARCH TEST: ");
	printf("%s. ", sll_search_node(91, sll) ? "(91) FOUND" : "(91) NOT FOUND");
	printf("%s. ", sll_search_node(10, sll) ? "(10) FOUND" : "(10) NOT FOUND");
	printf("%s.\n", sll_search_node(0, sll) ? "(0) FOUND" : "(0) NOT FOUND");

	printf("ADD AFTER TEST: ");
	sll_add_after(0, 252, sll);
	sll_add_after(147, 241, sll);
	sll_add_after(91, 232, sll);
	sll_add_after(255, 1, sll);
	sll_print(sll);

	printf("REVERSE TEST: ");
	sll_reverse(sll);
	sll_print(sll);

	sll_delete(&sll);			// delete test
	sll_delete(&sll);			

	sll_print(sll);
}
