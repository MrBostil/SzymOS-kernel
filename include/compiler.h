#ifndef COMPILER_H
#define COMPILER_H

// GCC inline assembly wrapper
#ifndef __GNUC__
#error "SzymOS requires GCC compiler"
#endif

// Make sure asm is recognized
#ifndef asm
#define asm __asm__
#endif

#ifndef volatile
// volatile is a keyword, just ensure it's available
#endif

#endif