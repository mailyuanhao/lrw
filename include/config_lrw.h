#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __BEOS__
#define DEFAULT_MEM_DEV "/dev/misc/mem"
#else
#define DEFAULT_MEM_DEV "/dev/mem"
#endif

#if USE_MMAP_C == 1
#define USE_MMAP
#else
#undef USE_MMAP
#endif
