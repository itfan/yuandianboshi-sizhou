﻿//     Copyright (c) 2013 js200300953@qq.com All rights reserved.
//         ========圆点博士微型四轴飞行器配套程序声明========
// 
// 圆点博士微型四轴飞行器配套程序包括上位机程序、下位机Bootloader和
//     下位机App，及它们的源代码，以下总称“程序”。
// 程序由js200300953编写。
// 程序仅为使用者提供参考，js200300953不对程序提供任何明示或暗含的担保，
//     不对在使用该程序中出现的意外或者损失负责，
//     也不对因使用该程序而引起的第三方索赔负责。
// 使用者可以以学习为目的修改和使用该程序，请勿以商业的目的使用该程序。
// 修改该程序时，必须保留原版权声明，并且不能修改原版权声明。
// 
// 更多资料见：
//     http://blog.sina.com.cn/js200300953
//     http://www.etootle.com/
//     http://www.amobbs.com/thread-5504090-1-1.html
//     圆点博士微型四轴飞行器QQ群：276721324

// app/status/status.c
// 2013-1-9 14:10:04
// js200300953

#include "bsp/time.h"
#include "bsp/battery.h"
#include "app/exception/interface.h"
#include "status.h"

static status_t status;

void status_init(void);
void status_checkEvent(void);

void status_init(void)
{
    for(int i=0;i<sizeof(status);i++)
        ((uint8_t *)&status)[i] = 0;
    status.bateryVoltage = 4.2;
}

void status_checkEvent(void)
{
    TIME_EXECUTE_PERIODICALLY_BEGIN(100)
    {
        const static float RATE = 0.05;
        status.bateryVoltage = (1-RATE) * status.bateryVoltage + RATE * battery_getVoltage();
        //
        exception_checkBateryVoltage(status.bateryVoltage);
    }TIME_EXECUTE_PERIODICALLY_END()
}

float status_getBateryVoltage(void)
{
    return status.bateryVoltage;
}
