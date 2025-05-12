#ifndef Database_h
#define Database_h

#include "To_do.h"


void save_to_file(struct task **a, int index);

int load_from_file(struct task **a);

#endif