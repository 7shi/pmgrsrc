#include <unistd.h>
int setgroups(int a, const gid_t *b) { return 0; }
int initgroups(const char *a, gid_t b) { return 0; }
