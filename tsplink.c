/*
 *	tsplink.c
 *
 *	Transtech SCSI Processor
 *
 *	Link interface
 *
 *	Copyright (c) 1993 Transtech Parallel Systems Limited
 */

static char *ident = "@(#)tsplink.c	1.11";

#include <stdio.h>
#include <errno.h>
#include <tsplib.h>
#include <string.h>

#include "link-driver.h"
#include "linkio.h"
#include "inmos.h"
#include "iserver.h"

#include <tsplib.h>

/*
 *   Open Link
 */
PUBLIC LINK OpenLink ( Name )
	char *Name;
{
    return tsp_open (Name);
}

/* CloseLink --- close down the link connection */
int CloseLink(LinkId)
LINK            LinkId;
{
	return tsp_close( LinkId );
}


/* ReadLink --- */

int ReadLink(LinkId, Buffer, Count, Timeout)
	LINK            LinkId;
	char           *Buffer;
	unsigned int    Count;
	int             Timeout;
{
    return tsp_read (LinkId, Buffer, Count, Timeout);
}


/* WriteLink --- */

int WriteLink(LinkId, Buffer, Count, Timeout)
	LINK            LinkId;
	char           *Buffer;
	unsigned int    Count;
	int             Timeout;
{
    return tsp_write (LinkId, Buffer, Count, Timeout);
}

/* ResetLink --- */

int ResetLink(LinkId)
	LINK            LinkId;
{
	/* Perform reset */
	if (tsp_reset( LinkId ))
		return -1;
	return 1;
}


/* AnalyseLink --- */

int AnalyseLink(LinkId)
	LINK            LinkId;
{
	/* Perform analyse */
	if (tsp_analyse( LinkId ))
		return -1;
	return 1;
}


/* TestError --- */

int TestError(LinkId)
	LINK            LinkId;
{
    return tsp_error( LinkId );
}


/* TestRead --- */

int TestRead(LinkId)
	LINK            LinkId;
{
	/* Not implemented */
	return (ER_LINK_CANT);
}


/* TestWrite --- */

int TestWrite(LinkId)
	LINK            LinkId;
{
	/* Not implemented */
	return (ER_LINK_CANT);
}



