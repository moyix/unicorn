/* vim:set shiftwidth=4 ts=4 et: */
/*
 * PXA255 Sharp Zaurus SL-6000 PDA platform
 *
 * Copyright (c) 2008 Dmitry Baryshkov
 *
 * Code based on spitz platform by Andrzej Zaborowski <balrog@zabor.org>
 * This code is licensed under the GNU GPL v2.
 *
 * Contributions after 2012-01-13 are licensed under the terms of the
 * GNU GPL, version 2 or (at your option) any later version.
 */

#include "hw/hw.h"
#include "hw/arm/arm.h"
#include "hw/boards.h"
#include "exec/address-spaces.h"


static void tosa_init(struct uc_struct *uc, MachineState *machine)
{
    //cpu_arm_init(uc, "pxa255");
    cpu_arm_init(uc, "cortex-a15"); // FIXME
}

void tosa_machine_init(struct uc_struct *uc)
{
    static QEMUMachine tosapda_machine = {
        .name = "tosa",
        .init = tosa_init,
        .is_default = 1,
        .arch = UC_ARCH_ARM,
    };

    qemu_register_machine(uc, &tosapda_machine, TYPE_MACHINE, NULL);
}
