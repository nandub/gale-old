#ifndef SUBSCR_H
#define SUBSCR_H

#include "oop.h"
#include "gale/core.h"

struct connect;

void add_subscr(oop_source *,struct gale_text,struct connect *);
void remove_subscr(oop_source *,struct gale_text,struct connect *);
void subscr_transmit(oop_source *,struct gale_packet *,struct connect *avoid);

int category_flag(struct gale_text cat,struct gale_text *base);
struct gale_text category_escape(struct gale_text cat,int flag);

#endif
