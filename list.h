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

#define LIST_EXTENDS() struct list super

#define list_init(h) (h)->prev = h; (h)->next = h;

#define list_entity(h, type) (type*)(h)

#define list_insert_next(h, p) \
	((struct list*)(p))->next = ((struct list*)(h))->next;\
	((struct list*)(p))->prev = (struct list*)(h);\
	((struct list*)(h))->next->prev = (struct list*)(p);\
	((struct list*)(h))->next = (struct list*)(p)

#define list_insert_prev(h, p) \
	((struct list*)(p))->prev = ((struct list*)(h))->prev;\
	((struct list*)(p))->next = (struct list*)(h);\
	((struct list*)(h))->prev->next = (struct list*)(p);\
	((struct list*)(h))->prev = (struct list*)(p)

#define list_remove(h) \
	((struct list*)(h))->prev->next = ((struct list*)(h))->next;\
	((struct list*)(h))->next->prev = ((struct list*)(h))->prev

#ifdef __cplusplus
}
#endif

#endif
