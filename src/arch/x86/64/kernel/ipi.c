/*
 * Copyright 2016, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(D61_GPL)
 */

#include <config.h>
#include <mode/kernel/ipi.h>
#include <mode/kernel/tlb.h>

#if CONFIG_MAX_NUM_NODES > 1

void Mode_handleRemoteCall(IpiModeRemoteCall_t call, word_t arg0, word_t arg1, word_t arg2)
{
    switch (call) {
    case IpiRemoteCall_InvalidatePCID:
        invalidateLocalPCID(arg0, (void*)arg1, arg2);
        break;

    case IpiRemoteCall_InvalidateASID:
        invalidateLocalASID((vspace_root_t*)arg0, arg1);
        break;

    default:
        fail("Invalid remote call");
    }
}

#endif /* CONFIG_MAX_NUM_NODES */
