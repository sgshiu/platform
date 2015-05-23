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

#define list_entity(h, name, type) (type*) ((unsigned long)(h) - ((unsigned long)(&((type*)0)->name)))

#define list_insert_next(h, p) \
	(p)->next = (h)->next;\
	(p)->prev = (h);\
	(h)->next->prev = (p);\
	(h)->next = (p)

#define list_insert_prev(h, p) \
	(p)->prev = (h)->prev;\
	(p)->next = (h);\
	(h)->prev->next = (p);\
	(h)->prev = (p)

#define list_remove(h) \
	(h)->prev->next = (h)->next;\
	(h)->next->prev = (h)->prev

#ifdef __cplusplus
}
#endif

#endif
