#ifndef _RTL871X_BYTEORDER_H_
#define _RTL871X_BYTEORDER_H_

#include <asm/byteorder.h>

/* Use kernel-provided swapping */
#define rtw_le16_to_cpu le16_to_cpu
#define rtw_le32_to_cpu le32_to_cpu
#define rtw_cpu_to_le16 cpu_to_le16
#define rtw_cpu_to_le32 cpu_to_le32

/* Guard to prevent driver's internal swab.h from loading */
#define _RTL871X_SWAB_H_

#endif

