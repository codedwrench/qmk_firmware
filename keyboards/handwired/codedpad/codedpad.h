#ifndef CODEDPAD_H
#define CODEDPAD_H

#include "quantum.h"

#define LAYOUT( \
      k00, k01, k02, k03, \
      k04, k05, k06, k07, \
      k08, k09, k10, k11  \
) \
{ \
    { k00, k01, k02, k03 }, \
    { k04, k05, k06, k07 }, \
    { k08, k09, k10, k11 }  \
}

#endif
