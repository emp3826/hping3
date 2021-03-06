#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <errno.h>

#include "hping2.h"
#include "globals.h"

void inc_destparm(int sid)
{
	static long sec = 0;
	static long usec = 0;
	int *p;
	int errno_save = errno;

	switch (ctrlzbind) {
	case BIND_DPORT:
		p = &dst_port;
		break;
	case BIND_TTL:
		p = &src_ttl;
		break;
	default:
		printf("error binding ctrl+z\n");
		/* errno = errno_save; */
		return;
	}

	if ( (time(NULL) == sec) && ((get_usec() - usec) < 200000) ) {
		if (*p > 0)
			(*p)-=2;
		if (*p < 0)
			*p=0;
	} else
		(*p)++;
	
	printf("\b\b\b\b\b\b\b\b\b");
	printf("%d: ", *p);
	fflush(stdout);

	sec = time(NULL);
	usec = get_usec();
	signal(SIGTSTP, inc_destparm);
	errno = errno_save;
}
