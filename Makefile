#******************************************************************************
#
# Makefile - Rules for building the uart_echo example.
#
# Copyright (c) 2013-2014 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 2.1.0.12573 of the EK-TM4C1294XL Firmware Package.
#
#******************************************************************************

#
# The base directory for TivaWare.
#
ROOT=.

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find header files that do not live in the source directory.
#
IPATH=./src/CMSIS/Include
IPATH+=./src/LwIP/src/include/
IPATH+=./src/LwIP/src/include/ipv4
IPATH+=./src/LwIP/src/include/lwip
IPATH+=./src/LwIP/src/include/netif
IPATH+=./src/LwIP/src/include/posix
IPATH+=./src/LwIP/src/include/posix/sys
IPATH+=./src/STM32F4x7_ETH_Driver/inc
IPATH+=./src/STM32F4xx_StdPeriph_Driver/inc
IPATH+=./src/User/inc
IPATH+=./src/LwIP/port/STM32F4x7
IPATH+=./src/STM32_EVAL/STM3240_41_G_EVAL
IPATH+=./src/STM32_EVAL/Common
IPATH+=./src/LwIP/port/STM32F4x7/Standalone
VPATH=./src/LwIP/src/api
VPATH+=./src/LwIP/src/core
VPATH+=./src/LwIP/src/core/ipv4
VPATH+=./src/LwIP/src/core/snmp
VPATH+=./src/LwIP/src/netif
VPATH+=./src/LwIP/src/netif/ppp
VPATH+=./src/LwIP/port/STM32F4x7/Standalone
VPATH+=./src/STM32F4x7_ETH_Driver/src
VPATH+=./src/STM32F4xx_StdPeriph_Driver/src
VPATH+=./src/User/src
VPATH+=./src/STM32_EVAL/STM3240_41_G_EVAL
VPATH+=./src/ARM
#
# The default rule, which causes the uart_echo example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/net.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}
install:
	openocd -f openocd.cfg -c "flash_image"

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir -p ${COMPILER}

#
# Rules for building the uart_echo example.
#
${COMPILER}/net.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/net.axf: ${COMPILER}/system_stm32f4xx.o
${COMPILER}/net.axf: ${COMPILER}/ethernetif.o
${COMPILER}/net.axf: ${COMPILER}/api_lib.o
${COMPILER}/net.axf: ${COMPILER}/api_msg.o
${COMPILER}/net.axf: ${COMPILER}/err.o
${COMPILER}/net.axf: ${COMPILER}/netbuf.o
${COMPILER}/net.axf: ${COMPILER}/netdb.o
${COMPILER}/net.axf: ${COMPILER}/netifapi.o
${COMPILER}/net.axf: ${COMPILER}/sockets.o
${COMPILER}/net.axf: ${COMPILER}/tcpip.o
${COMPILER}/net.axf: ${COMPILER}/dhcp.o
${COMPILER}/net.axf: ${COMPILER}/dns.o
${COMPILER}/net.axf: ${COMPILER}/init.o
${COMPILER}/net.axf: ${COMPILER}/mem.o
${COMPILER}/net.axf: ${COMPILER}/netif.o
${COMPILER}/net.axf: ${COMPILER}/pbuf.o
${COMPILER}/net.axf: ${COMPILER}/raw.o
${COMPILER}/net.axf: ${COMPILER}/sys.o
${COMPILER}/net.axf: ${COMPILER}/tcp.o
${COMPILER}/net.axf: ${COMPILER}/tcp_in.o
${COMPILER}/net.axf: ${COMPILER}/tcp_out.o
${COMPILER}/net.axf: ${COMPILER}/timers.o
${COMPILER}/net.axf: ${COMPILER}/udp.o
${COMPILER}/net.axf: ${COMPILER}/def.o
${COMPILER}/net.axf: ${COMPILER}/memp.o
${COMPILER}/net.axf: ${COMPILER}/stats.o
${COMPILER}/net.axf: ${COMPILER}/autoip.o
${COMPILER}/net.axf: ${COMPILER}/icmp.o
${COMPILER}/net.axf: ${COMPILER}/igmp.o
${COMPILER}/net.axf: ${COMPILER}/inet.o
${COMPILER}/net.axf: ${COMPILER}/inet_chksum.o
${COMPILER}/net.axf: ${COMPILER}/ip.o
${COMPILER}/net.axf: ${COMPILER}/ip_addr.o
${COMPILER}/net.axf: ${COMPILER}/ip_frag.o
${COMPILER}/net.axf: ${COMPILER}/asn1_dec.o
${COMPILER}/net.axf: ${COMPILER}/asn1_enc.o
${COMPILER}/net.axf: ${COMPILER}/mib_structs.o
${COMPILER}/net.axf: ${COMPILER}/mib2.o
${COMPILER}/net.axf: ${COMPILER}/msg_in.o
${COMPILER}/net.axf: ${COMPILER}/msg_out.o
${COMPILER}/net.axf: ${COMPILER}/etharp.o
${COMPILER}/net.axf: ${COMPILER}/ethernetif.o
${COMPILER}/net.axf: ${COMPILER}/slipif.o
${COMPILER}/net.axf: ${COMPILER}/fsm.o
${COMPILER}/net.axf: ${COMPILER}/ipcp.o
${COMPILER}/net.axf: ${COMPILER}/lcp.o
${COMPILER}/net.axf: ${COMPILER}/magic.o
${COMPILER}/net.axf: ${COMPILER}/md5.o
${COMPILER}/net.axf: ${COMPILER}/pap.o
${COMPILER}/net.axf: ${COMPILER}/ppp_oe.o
${COMPILER}/net.axf: ${COMPILER}/vj.o
${COMPILER}/net.axf: ${COMPILER}/auth.o
${COMPILER}/net.axf: ${COMPILER}/chap.o
${COMPILER}/net.axf: ${COMPILER}/chpms.o
${COMPILER}/net.axf: ${COMPILER}/ppp.o
${COMPILER}/net.axf: ${COMPILER}/randm.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4x7_eth.o
${COMPILER}/net.axf: ${COMPILER}/main.o
${COMPILER}/net.axf: ${COMPILER}/netconf.o
${COMPILER}/net.axf: ${COMPILER}/serial_debug.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4x7_eth_bsp.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_it.o
${COMPILER}/net.axf: ${COMPILER}/tcp_echoclient.o
${COMPILER}/net.axf: ${COMPILER}/misc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_adc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_can.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_crc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_cryp.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_cryp_aes.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_cryp_des.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_dac.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_dbgmcu.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_dcmi.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_dma.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_exti.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_fsmc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_hash.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_hash_md5.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_hash_sha1.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_i2c.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_iwdg.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_pwr.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_rcc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_rng.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_rtc.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_spi.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_tim.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_wwdg.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_cryp_tdes.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_flash.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_gpio.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_sdio.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_syscfg.o
${COMPILER}/net.axf: ${COMPILER}/stm32f4xx_usart.o
${COMPILER}/net.axf: stm32f4xx_flash.ld
SCATTERgcc_net=stm32f4xx_flash.ld
ENTRY_net=ResetISR
CFLAGSgcc=-DUSE_STDPERIPH_DRIVER -DSTM32F40XX -DUSE_STM324xG_EVAL

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
