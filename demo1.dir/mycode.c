// mycode.c
// AutoMod 12.3.1 Generated File
// Build: 2152.82
// Model name:	Demo1
// Model path:	C:\Users\Seong taek Lim\Desktop\Tuto\Demo1.dir\
// Generated:	Mon Mar 01 17:27:57 2021
// Applied/AutoMod Licensee Confidential
// NO DISTRIBUTION OR REPRODUCTION RIGHTS GRANTED!
// Copyright (c) 1988-2010 Applied Materials All rights reserved.
//
// All Rights Reserved.  Reproduction or transmission in whole or
// in part, in any form or by any means, electronic, mechanical or
// otherwise, is prohibited without the prior written consent of
// copyright owner.
//
// Licensed Material - Property of Applied Materials, Inc.
//
// Applied Materials, Inc.
// 3050 Bowers Drive
// P.O. Box 58039
// Santa Clara, CA 95054-3299
// U.S.A.
//


#include "cdecls.h"


static int32
P_EnterAssembly_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			pushppa(this, P_EnterAssembly_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_Conv1.am_sta1, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; /* go move into territory */
Label2: ; /* Step 2 */
		}
		{
			this->nextproc = am2_P_CompleteAssembly; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_EnterAssembly_arriving */

static int32
P_CompleteAssembly_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			pushppa(this, P_CompleteAssembly_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_Conv1.am_sta2, -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; /* go move to location */
Label2: ; /* Step 2 */
		}
		{
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	return retval;
} /* end of P_CompleteAssembly_arriving */



/* init function for mycode.m */
void
model_mycode_init(struct model_struct* data)
{
	data->am_P_EnterAssembly->aprc = P_EnterAssembly_arriving;
	data->am_P_CompleteAssembly->aprc = P_CompleteAssembly_arriving;
}

