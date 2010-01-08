#include <unistd.h>
int setgroups(int a, const gid_t *b) { return 0; }
int initgroups(const char *a, gid_t b) { return 0; }

#include <stdlib.h>
#include <pwd.h>
#undef getpwuid
struct passwd *getpwuid_(uid_t uid)
{
	struct passwd *ret = getpwuid(uid);
	if (uid == getuid()) ret->pw_dir = getenv("HOME");
	return ret;
}
