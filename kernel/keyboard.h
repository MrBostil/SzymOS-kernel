#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

// Keyboard scan codes
#define KEY_ESCAPE      0x01
#define KEY_BACKSPACE   0x0E
#define KEY_TAB         0x0F
#define KEY_ENTER       0x1C
#define KEY_LCTRL       0x1D
#define KEY_LSHIFT      0x2A
#define KEY_RSHIFT      0x36
#define KEY_LALT        0x38
#define KEY_SPACE       0x39
#define KEY_CAPSLOCK    0x3A
#define KEY_F1          0x3B
#define KEY_F2          0x3C

void keyboard_init(void);
char keyboard_getchar(void);
int keyboard_haskey(void);

#endif