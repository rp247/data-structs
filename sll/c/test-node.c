#include "node.h"

int main (){
	Node *n = node_create(0);
	node_print(n);
	node_delete(&n);
}
