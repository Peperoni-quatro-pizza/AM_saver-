// mycode.c
// AutoMod 12.3.1 Generated File
// Build: 2152.82
// Model name:	demo1
// Model path:	C:\Users\LST\Desktop\IN Lab\AM_saver-\demo1.dir\
// Generated:	Tue Mar 02 18:03:04 2021
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
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			pushppa(this, P_EnterAssembly_arriving, Step 2, am_localargs);
			pushppa(this, inqueue, Step 1, am2_Q_Assemble);
			return Continue; /* go move into territory */
Label2: ; /* Step 2 */
		}
		{
			this->attribute->am2_A_Time = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			if (getrsrc(am2_R_Operator1, 1, this, P_EnterAssembly_arriving, Step 3, am_localargs) == Delayed)
				return Delayed;  /* go wait for resource */
Label3: ; /* Step 3 */
		}
		{
			if (waitfor(ToModelTime(uniform1(am2_stream0, 100, 15), UNITSECONDS), this, P_EnterAssembly_arriving, Step 4, am_localargs) == Delayed)
				return Delayed;
Label4: ; /* Step 4 */
		}
		{
			if (waitfor(ToModelTime(10, UNITSECONDS), this, P_EnterAssembly_arriving, Step 5, am_localargs) == Delayed)
				return Delayed;
Label5: ; /* Step 5 */
		}
		{
			pushppa(this, P_EnterAssembly_arriving, Step 6, am_localargs);
			load_SetDestLoc(this, LocGetQualifier(am_model.am_Conv1.am_sta1, -9999));
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; /* go move into territory */
Label6: ; /* Step 6 */
		}
		{
			freersrc(am2_R_Operator1, 1, this);
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


static process*
Func0(load* this)
{
	return &(am2_P_Out[1]);
}


static process*
Func1(load* this)
{
	return &(am2_P_Out[2]);
}


typedef struct {
	double freq;
	process* (*value)(load*);
} Oneof0;

static Oneof0 List0[] = {
	{ 50, Func0},
	{ 100, Func1}
};

static process*
oneofFunc0(load* this)
{
	int ind = 0;
	Oneof0* list = List0;
	double sample = getdrand(am2_stream0) * 100;

	tprintf(tfp, "In oneof\n");
	while (list->freq < sample) {
		ind++;
		list++;
	}
	return List0[ind].value(this);
}

static int32
P_CompleteAssembly_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	int32 retval = Continue;
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
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
			return usefor(am2_R_Operator2, 1, this, P_CompleteAssembly_arriving, Step 3, am_localargs, ToModelTime(uniform1(am2_stream0, 60, 10), UNITSECONDS));
Label3: ; /* Step 3 */
		}
		{
			this->nextproc = oneofFunc0(this); /* send to ... */
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

static int32
P_Out_arriving(load* this, int32 step, void* args)
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
			pushppa(this, P_Out_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, SysGetQualifier(am_model.am_Conv1.$sys, "staout", CurProcIndex(), -9999));
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; /* go move to location */
Label2: ; /* Step 2 */
		}
		{
			this->attribute->am2_A_Time = ASIclock - this->attribute->am2_A_Time;
			EntityChanged(0x00000040);
		}
		{
			{
				char* pArg1 = rel_actorname(this, am_model.$sys);
				char* pArg2 = " ";
				char* pArg3 = "Time in system = ";
				double pArg4 = FromModelTime(this->attribute->am2_A_Time, UNITSECONDS);

				message("%s%s%s%lf", pArg1, pArg2, pArg3, pArg4);
			}
		}
		{
			am2_V_Numdone += 1;
			EntityChanged(0x01000000);
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
} /* end of P_Out_arriving */



/* init function for mycode.m */
void
model_mycode_init(struct model_struct* data)
{
	data->am_P_EnterAssembly->aprc = P_EnterAssembly_arriving;
	data->am_P_CompleteAssembly->aprc = P_CompleteAssembly_arriving;
	data->am_P_Out->aprc = P_Out_arriving;
}

