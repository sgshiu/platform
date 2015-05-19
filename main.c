#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct my_list
{
	int val;
	struct list context;
};

int main(int argc, char *argv[])
{
	struct list h, *hp;
	struct my_list h1, h2, h3;
	struct my_list *p = NULL;

	h1.val = 1;
	h2.val = 2;
	h3.val = 3;

	list_init(&h);
	list_insert_prev(&h, &h1.context);
	list_insert_next(&h, &h2.context);
	list_insert_next(&h, &h3.context);

	p = list_entity(list_next(&h), context, struct my_list);
	assert(p->val == 3);
	p = list_entity(list_next(&p->context), context, struct my_list);
	assert(p->val == 2);
	p = list_entity(list_next(&p->context), context, struct my_list);
	assert(p->val == 1);

	for (hp = h.next; hp != &h; hp = hp->next) {
		p = list_entity(hp, context, struct my_list);
		printf("val = %d\r\n", p->val);
	}

	printf("done\r\n");
	
	return 0;
}
