#include "gale/client.h"
#include "gale/misc.h"
#include "gale/globals.h"

/** Add standard identifying fragments to a message.
 *  \param group Group to add fragments to.
 *  \param terminal Terminal (or other "session") identifier for this client. */
void gale_add_id(struct gale_group *group,struct gale_text terminal) {
	struct gale_fragment f;

	f.name = G_("id/class");
	f.type = frag_text;
	f.value.text = gale_text_concat(3,
		gale_text_from(NULL,gale_global->error_prefix,-1),
		G_("/"),
		gale_text_from(NULL,VERSION,-1));
	gale_group_add(group,f);

	f.name = G_("id/instance");
	f.type = frag_text;
	f.value.text = gale_text_concat(9,
		gale_var(G_("GALE_DOMAIN")),G_("/"),
		gale_var(G_("HOST")),G_("/"),
		gale_var(G_("LOGNAME")),G_("/"),
		terminal,G_("/"),
		gale_text_from_number(getpid(),10,0));
	gale_group_add(group,f);

	f.name = G_("id/time");
	f.type = frag_time;
	f.value.time = gale_time_now();
	gale_group_add(group,f);
}
