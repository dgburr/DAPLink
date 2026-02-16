/**
 * @file    target.c
 * @brief   Target information for the STM32H743ZI
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2017-2019, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "target_config.h"

// The file flash_blob.c must only be included in target.c
#include "flash_blob.c"

// target information
target_cfg_t target_device = {
    .version                        = kTargetConfigVersion,
    .sectors_info                   = sectors_info,
    .sector_info_length             = (sizeof(sectors_info))/(sizeof(sector_info_t)),
    .flash_regions[0].start         = 0x08000000,
    .flash_regions[0].end           = 0x08200000,
    .flash_regions[0].flags         = kRegionIsDefault,
    .flash_regions[0].flash_algo    = (program_target_t *) &flash,
    .ram_regions[0].start           = 0x20000000, // DTCMRAM (128KB): will be used by flash algo
    .ram_regions[0].end             = 0x20020000,
    .ram_regions[1].start           = 0x24000000, // RAM_D1 (512KB)
    .ram_regions[1].end             = 0x24080000,
    .ram_regions[2].start           = 0x30000000, // RAM_D2 (288KB)
    .ram_regions[2].end             = 0x30048000,
    .ram_regions[3].start           = 0x38000000, // RAM_D3 (64KB)
    .ram_regions[3].end             = 0x38010000,
    .target_vendor                  = "STMicroelectronics",
    .target_part_number             = "STM32H743ZI",
};
