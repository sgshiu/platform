#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct my_list
{
	int val;
	struct list super;
};

int main() 
{
	struct list data, *h;
	struct my_list d1, d2, d3;

	list_init(&data);

	d1.val = 1;
	d2.val = 2;
	d3.val = 3;

	list_insert_prev(&data, &d1.super);
	list_insert_next(&data, &d2.super);
	list_insert_next(&d2.super, &d3.super);

	for (h = data.next; h != &data; h = h->next) {
		struct my_list *p = list_entity(h, super, struct my_list);
		printf("val = %d\r\n", p->val);
	}
	

	return 0;
}
