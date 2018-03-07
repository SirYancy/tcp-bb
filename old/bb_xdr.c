/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "bb.h"

bool_t
xdr_post_1_argument (XDR *xdrs, post_1_argument *objp)
{
	 if (!xdr_string (xdrs, &objp->user, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->Article, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_reply_1_argument (XDR *xdrs, reply_1_argument *objp)
{
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->user, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->Article, ~0))
		 return FALSE;
	return TRUE;
}