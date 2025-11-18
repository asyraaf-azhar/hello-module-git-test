/******************************************************************************
 *
 *   Copyright (C) 2025 Altera Corporation. All rights reserved.
 *
 *   SPDX-License-Identifier: GPL-2.0-only
 *
 *****************************************************************************/

#include <linux/module.h>

/* Include auto-generated header from config */
#ifdef USE_CONFIG
#include "module_info.h"
#endif

static int __init hello_module_init(void)
{
#ifdef USE_CONFIG
    pr_info("hello_module: %s\n", MODULE_DESC);
    pr_info("hello_module: Author: %s\n", MODULE_AUTH);
    pr_info("hello_module: Version: %s\n", MODULE_VER);
#else
    pr_info("hello_module: Kernel module loaded successfully [PATCHED VERSION].\n");
#endif
    return 0;
}

static void __exit hello_module_exit(void)
{
    pr_info("hello_module: Kernel module unloaded. Goodbye!\n");
}

module_init(hello_module_init);
module_exit(hello_module_exit);
MODULE_LICENSE("GPL");

