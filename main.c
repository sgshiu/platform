#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct my_list
{
	int val;
	struct list h;
};

int main(int argc, char *argv[])
{
	struct my_list h, h1, h2, h3;
	struct my_list *p = NULL;

	h.val = 0;
	h1.val = 1;
	h2.val = 2;
	h3.val = 3;
	
	list_init(&h.h);
	list_insert_prev(&h.h, &h1.h);
	list_insert_next(&h.h, &h2.h);
	list_insert_next(&h.h, &h3.h);
	p = list_entity(list_next(&h.h));
	assert(p->val == 2);
	p = list_entity(list_next(&p->h));
	assert(p->val == 3);
	p = list_entity(list_next(&p->h));
	assert(p->val == 1);
	
	return 0;
}
