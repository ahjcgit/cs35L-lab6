#ifndef RAND64_HW_H
#define RAND64_HW_H

struct cpuid {unsigned int leaf, subleaf};
_Bool rdrand_supported (void);
void hardware_rand64_init (void);
unsigned long long longhardware_rand64 (void);
void hardware_rand64_fini (void);

#endif