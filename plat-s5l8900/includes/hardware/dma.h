#ifndef HW_DMA_H
#define HW_DMA_H

#include "hardware/s5l8900.h"

// VIC PL080 DMA Controller

// Device
#define DMAC0 0x38200000
#define DMAC1 0x39900000

// Registers
#define DMACIntStatus		0x000
#define DMACIntTCStatus		0x004
#define DMACIntTCClear		0x008
#define DMACIntErrorStatus	0x00C
#define DMACIntErrClr		0x010
#define DMACRawIntTCStatus	0x014
#define DMACRawIntErrorStatus	0x018
#define DMACEnbldChns		0x01C
#define DMACSoftBReq		0x020
#define DMACSoftSReq		0x024
#define DMACSoftLBReq		0x028
#define DMACSiftLSReq		0x02C
#define DMACConfiguration	0x030
#define DMACSync		0x34
#define DMAC0SrcAddress		0x100
#define DMAC0DestAddress	0x104
#define DMAC0LLI		0x108
#define DMACC0Control		0x10C
#define DMACC0Configuration	0x110
#define DMACC1SrcAddr		0x120
#define DMACC1DestAddr		0x124
#define DMACC1LLI		0x128
#define DMACC1Control		0x12C
#define DMACC1Configuration	0x130
#define DMACC2SrcAddr		0x140
#define DMACC2DestAddr		0x144
#define DMACC2LLI		0x148
#define DMACC2Control		0x14C
#define DMACC2Configuration	0x150
#define DMACC3SrcAddr		0x160
#define DMACC3DestAddr		0x164
#define DMACC3LLI		0x168
#define DMACC3Control		0x16C
#define DMACC3Configuration	0x170
#define DMACC4SrcAddr		0x180
#define DMACC4DestAddr		0x184
#define DMACC4LLI		0x188
#define DMACC4Control		0x18C
#define DMACC4Configuration	0x190
#define DMACC5SrcAddr		0x1A0
#define DMACC5DestAddr		0x1A4
#define DMACC5LLI		0x1A8
#define DMACC5Control		0x1AC
#define DMACC5Configuration	0x1B0
#define DMACC6SrcAddr		0x1C0
#define DMACC6DestAddr		0x1C4
#define DMACC6LLI		0x1C8
#define DMACC6Control		0x1CC
#define DMACC6Configuration	0x1D0
#define DMACC7SrcAddr		0x1E0
#define DMACC7DestAddr		0x1E4
#define DMACC7LLI		0x1E8
#define DMACC7Control		0x1EC
#define DMACC7Configuration	0x1F0
#define DMACPeriphID0		0xFE0
#define DMACPeriphID1		0xFE4
#define DMACPeriphID2		0xFE8
#define DMACPeriphID3		0xFEC
#define DMACPCellID0		0xFF0
#define DMACPCellID1		0xFF4
#define DMACPCellID2		0xFF8
#define DMACPCellID3		0xFFC

// TEST REGISTERS
#define DMACITCR		0x500
#define DMACITOP1		0x504
#define DMACITOP2		0x508
#define DMACITOP3		0x50C

// Values
#define DMAC0_INTERRUPT 0x10
#define DMAC1_INTERRUPT 0x11
#define DMAC0_CLOCKGATE 0x19
#define DMAC1_CLOCKGATE 0x1A

#define DMA_NUMCHANNELS 8
#define DMA_NUMCONTROLLERS 2

#define DMAChannelRegSize 32
#define DMACConfiguration_ENABLE 1
#define DMACC0Control_SWIDTHSHIFT 18
#define DMACC0Control_DWIDTHSHIFT 21
#define DMACC0Control_DWIDTH(x) GET_BITS(x, 21, 3)
#define DMACC0Control_WIDTHBYTE 0
#define DMACC0Control_WIDTHHALFWORD 1
#define DMACC0Control_WIDTHWORD 2
#define DMACC0Control_SBSIZESHIFT 12
#define DMACC0Control_DBSIZESHIFT 15
#define DMACC0Control_TERMINALCOUNTINTERRUPTENABLE 31
#define DMACC0Control_SOURCEAHBMASTERSELECT 24
#define DMACC0Control_SOURCEAHBMASTERSELECT 24
#define DMACC0Control_SOURCEINCREMENT 26
#define DMACC0Control_DESTINATIONINCREMENT 27
#define DMACC0Control_SIZEMASK 0xFFF

#define DMACC0Configuration_SRCPERIPHERALSHIFT 1
#define DMACC0Configuration_DESTPERIPHERALSHIFT 6
#define DMACC0Configuration_FLOWCNTRLSHIFT 11
#define DMACC0Configuration_FLOWCNTRLMASK 0x7
#define DMACC0Configuration_FLOWCNTRL_M2M 0x0
#define DMACC0Configuration_FLOWCNTRL_M2P 0x1
#define DMACC0Configuration_FLOWCNTRL_P2M 0x2
#define DMACC0Configuration_FLOWCNTRL_P2P 0x3
#define DMACC0Configuration_CHANNELENABLED (1 << 0)
#define DMACC0Configuration_TERMINALCOUNTINTERRUPTMASK (1 << 15)

#endif

