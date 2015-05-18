#ifndef GAWIN_LIST_H
#define GAWIN_LIST_H

struct list
{
	struct list *prev;
	struct list *next;
};

#ifdef __cplusplus
extern "C" {
#endif

#define list_init(h) (h)->prev = h; (h)->next = h;

#define list_insert_next(h, p) printf("not implement")
#define list_insert_prev(h, p) printf("not implement")
#define list_entity(h) NULL

#ifdef __cplusplus
}
#endif

#endif
