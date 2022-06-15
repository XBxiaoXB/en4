/***********************************************************************/
/*                                                                     */
/*  FILE        :sbrk.c                                                */
/*  DATE        :Sat, Jun 11, 2022                                     */
/*  DESCRIPTION :Program of sbrk                                       */
/*  CPU TYPE    :H8/3694F                                              */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.16).    */
/*                                                                     */
/***********************************************************************/
                  


#include <stdio.h>
#include "typedefine.h"
#include "sbrk.h"
_SBYTE *sbrk(size_t);

//const size_t _sbrk_size=          /* Specifies the minimum unit of */
                                    /* the defined heap area         */

#pragma pack 2
static union {
    _SWORD  dummy;                  /* Dummy for 2-byte boundary */
    _SBYTE  heap[HEAPSIZE];         /* Declaration of the area managed by sbrk */
} heap_area;
#pragma unpack

static _SBYTE *brk=(_SBYTE *)&heap_area;  /* End address of area assigned by sbrk */

/*****************************************************************************/
/*    sbrk: Data write                                                       */
/*           Return value: Start address of the assigned area (Pass)         */
/*                         -1                                 (Failure)      */
/*****************************************************************************/
extern _SBYTE *sbrk(size_t size)                /* Assigned area size */
{
    _SBYTE  *p;
    if(brk+size > heap_area.heap+HEAPSIZE){     /* Empty area size */
        p = (_SBYTE *)-1;
    }
    else {
        p = brk;                                /* Area assignment */
        brk += size;                            /* End address update */
    }

    return p;
}
