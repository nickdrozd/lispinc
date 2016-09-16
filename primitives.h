/*
	PRIMITIVES

	Primitive functions operate on actual C objects 
	(like numbers and lists). primitives.c creates 
	a list of the functions and list of the names of 
	these functions and then passes them to env.c, 
	where they are zipped together to create the frame 
	of the base_env.
*/

#ifndef PRIMITIVES_GUARD
#define PRIMITIVES_GUARD

#include <stdlib.h>

#include "objects.h"

extern List* primitive_vars(void);
extern List* primitive_vals(void);

/* primtive functions declarations */

twoArgFunc add_;
twoArgFunc sub_;
twoArgFunc mul_;
twoArgFunc div_;
twoArgFunc eq_;

oneArgFunc null_;

oneArgFunc car_;
oneArgFunc cdr_;
twoArgFunc cons_;

#endif