#ifndef RAND64_SW_H
#define RAND64_SW_H

void software_rand64_init (const char* file_dir, int use_lrand);
unsigned long long software_rand64 (void);
void software_rand64_fini (void);
_Bool writebytes(long long x, int nbytes);

#endif