#include "sll.h"
#include "node.h"

#include <stdio.h>
#include <stdint.h>

int main(){
	SLL *sll = sll_create();
	sll_delete(&sll);
}
