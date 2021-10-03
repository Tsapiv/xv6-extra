#ifndef XV6_PUBLIC_HTOP_H
#define XV6_PUBLIC_HTOP_H
#include "types.h"
typedef struct iproc {
    uint sz;                     // Size of process memory (bytes)
    uint state;        // Process state
    int pid;                     // Process ID
    uint ofile;  // Open files
    char name[16];               // Process name (debugging)
} iproc;

#endif //XV6_PUBLIC_HTOP_H
