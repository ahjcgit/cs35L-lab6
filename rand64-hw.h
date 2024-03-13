#ifndef RAND64_HW_H
#define RAND64_HW_H

static _Bool rdrand_supported (void);
static void hardware_rand64_init (void);
static unsigned long long hardware_rand64 (void);
static void hardware_rand64_fini (void);

#endif 