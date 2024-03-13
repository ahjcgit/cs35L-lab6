#include <stdio.h>
#include <limits.h>

/* Software implementation.  */

/* Input stream containing random bytes.  */
static FILE *urandstream = NULL;
static int use_lrand48 = 0;

/* Initialize the software rand64 implementation.  */
static void
software_rand64_init (const char* file_dir, int use_lrand)
{
  use_lrand48 = use_lrand;
  urandstream = fopen (file_dir, "r");

  if (! urandstream)
    abort ();

  if (urandstream == NULL) fopen ("/dev/random", "r");
}

/* Return a random value, using software operations.  */
static unsigned long longsoftware_rand64 (void)
{ //When input option is lrand48_r
  unsigned long long int x;
  if (use_lrand48){
    static long long buffer;
    lrand48_r(&buffer, &x);
  }
  else if (fread (&x, sizeof x, 1, urandstream) != 1)
    abort ();
  return x;
}

/* Finalize the software rand64 implementation.  */
static void
software_rand64_fini (void)
{
  fclose (urandstream);
}

static _Bool writebytes (unsigned long long x, int nbytes){
  do{
    if (putchar (x) < 0) return 0;
      x >>= CHAR_BIT;
      nbytes--;
    }
  while (0 < nbytes); return 1;
}
