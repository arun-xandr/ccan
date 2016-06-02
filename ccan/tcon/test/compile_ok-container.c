#include <stdlib.h>

#include <ccan/tcon/tcon.h>
#include <ccan/build_assert/build_assert.h>
#include <ccan/tap/tap.h>

struct inner {
	int inner_val;
};

struct outer {
	int outer_val;
	struct inner inner;
};

struct info_base {
	char *infop;
};

struct info_tcon {
	struct info_base base;
	TCON(TCON_CONTAINER(concan, struct outer, inner));
};

int main(int argc, char *argv[])
{
	/* Const should work! */
	const struct outer *ovar;
	struct outer *o;
	struct info_tcon info;

	o = tcon_container_of(&info, fi, &ovar->inner);
	return (o == ovar);
}

