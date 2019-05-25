//
//  utilities.h
//  SearchRoutines
//
//  Created by venkata bethamcharla on 5/5/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef utilities_h
#define utilities_h

#define MAX_INT32   2147483647
#define MIN_INT32   -2147483648

#define true    1
#define false   0

#define sprint(expr)    printf(#expr)
#define printINT(d)     printf("%d\n",d)
#define dprint(expr, d) printf(#expr": %d\n", d)
#define dprint2(expr, d1, d2) printf(#expr": %d\t%d\n", d1, d2)


#endif /* utilities_h */
