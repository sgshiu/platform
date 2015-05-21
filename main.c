#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct my_list
{
	LIST_EXTENDS();
	int val;
};

int main() 
{
	struct list data, *h;
	struct my_list d1, d2, d3, *p;

	((struct list*)(&data))->prev = (struct list*)(&d1);

	list_init(&data);

	d1.val = 1;
	d2.val = 2;
	d3.val = 3;

	list_insert_prev(&data, &d1);
	list_insert_next(&data, &d2);
	list_insert_next(&d2, &d3);

	for (h = data.next; h != &data; h = h->next) {
		p = list_entity(h, struct my_list);
		printf("val = %d\r\n", p->val);
	}
	

	return 0;
}
