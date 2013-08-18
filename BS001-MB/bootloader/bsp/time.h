﻿//     Copyright (c) 2013 js200300953@qq.com All rights reserved.
//         ==================================================
//         ========圆点博士微型四轴飞行器配套软件声明========
//         ==================================================
//     圆点博士微型四轴飞行器配套软件包括上位机程序、下位机Bootloader
// 和下位机App，及它们的源代码，以下总称“软件”。
//     软件仅提供参考，js200300953不对软件作任何担保，不对因使用该软件
// 而出现的损失负责。
//     软件可以以学习为目的修改和使用，但不允许以商业的目的使用该软件。
//     修改该软件时，必须保留原版权声明。
// 
//     更多资料见：
// http://blog.sina.com.cn/js200300953
// http://www.etootle.com/
// http://www.eeboard.com/bbs/forum-98-1.html#separatorline
// 圆点博士微型四轴飞行器QQ群：276721324

// bsp/time.h
// 2013-1-7 13:49:49
// js200300953

#ifndef __FILE_BSP_TIME_H__
#define __FILE_BSP_TIME_H__

#include <stdint.h>

void     time_init(void);
uint64_t time_nowUs(void);
uint32_t time_nowMs(void);
void     time_waitUs(uint32_t delay);
void     time_waitMs(uint32_t delay);

#define TIME_EXECUTE_PERIODICALLY_BEGIN(time_ms) \
{\
    static uint32_t target = 0;\
    if(target <= time_nowMs())\
    {\
        target = time_nowMs() + time_ms;
#define TIME_EXECUTE_PERIODICALLY_END() \
    }\
}

#endif // __FILE_BSP_TIME_H__
