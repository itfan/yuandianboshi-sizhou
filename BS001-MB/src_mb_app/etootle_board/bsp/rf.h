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

// bsp/rf.h
// 2013-1-7 14:01:42

#ifndef __FILE_BSP_RF_H__
#define __FILE_BSP_RF_H__

#include <stdint.h>

// 外部实现的函数。回调。
void rf_handleReceivedData(const uint8_t * data,int32_t len);

int32_t     rf_init(void);
int32_t     rf_transmit(const uint8_t * data,uint32_t len);
void        rf_startReceive(void);
void        rf_stopReceive(void);
void        rf_checkEvent(void);

#endif // __FILE_BSP_RF_H__
