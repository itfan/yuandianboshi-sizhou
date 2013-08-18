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

// app/communication/interface.h
// 2013-1-8 12:55:11
// js200300953

#ifndef __FILE_APP_COMMUNICATION_INTERFACE_H__
#define __FILE_APP_COMMUNICATION_INTERFACE_H__

#include <stdint.h>
#include "protocol.h"

void communication_init(void);
void communication_checkEvent(void);
int32_t cmd_returnMessage(const char * msg);
int32_t engine_transmitBegin(uint8_t packetType);
int32_t engine_transmitContent(const void * part,int32_t length);
int32_t engine_transmitEnd(void);
int32_t engine_maxTransmitContentSize(void);

#define com_transmitBegin(packetType)       engine_transmitBegin(packetType)
#define com_transmitContent(part,length)  engine_transmitContent(part,length)
#define com_transmitEnd()                   engine_transmitEnd()
#define com_maxTransmitContentSize()        engine_maxTransmitContentSize()

#endif // __FILE_APP_COMMUNICATION_INTERFACE_H__
