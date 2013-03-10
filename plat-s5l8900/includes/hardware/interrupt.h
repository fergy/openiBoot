#ifndef HW_INTERRUPT_H
#define HW_INTERRUPT_H

/* VIC PL192 IRQ Controllers
Using the VIC and the new instructions, there is no longer any requirement for
everything to go through the single IRQ vector, and the changeover to a different stack
occurs much more smoothly. The code is similar to the example shown below:
	IRQ1handler
	... Include code to actually process the interrupt ...
	STR
	R0, [R8,#AckFinished]
	SUBS
	PC, R14, #4
	...
	IRQ2handler
	SUB
	R14, R14, #4 ;(1 cycle)
	SRSFD
	R13_svc!
	;(1 cycle)
	CPSIE
	f, #0x13
	; = Supervisor mode(1 cycle)
	STMFD
	R13!, {R2,R3} ;(2 cycles)
	... IRQs are now re-enabled, with original R2, R3, R14, SPSR on stack
	... Include code to stack any more registers required, process the interrupt
	... and unstack extra registers
	LDMFD
	R13!, {R2,R3}
	ADR
	R14, #VICADDRESS
	CPSID
	f
	STR
	R0, [R14,#AckFinished]
	RFEFD
 */

#define VIC_MaxInterrupt 0x40
#define VIC_InterruptSeparator 0x20

// Devices

#define VIC0 0x38E00000 //VIC PL192
#define VIC1 0x38E01000

// REGISTERS
#define VICIRQSTATUS	0x000	//IRQ Status Register
#define VICFIQSTATUS	0x004	//FIQ Status Register
#define VICRAWINTR	0x008	//Raw Interrupt Status Register
#define VICINTSELECT	0x00C	//Interrupt Select Register
#define VICINTENABLE	0x010	//Interrupt Enable Register
#define VICINTENCLEAR	0x014	//Interrupt Clear Register
#define VICSOFTINT	0x018	//Software Interrupt Register
#define VICSOFTCLEAR	0x01C	//Software Interrupt Clear Register
#define VICPROTECTION	0x020	//Protection Enable Register
#define VICSWPRIORITYMASK	0x024	//Software Priority Mask Register
#define VICPRIORITYDAISY	0x028	//Vector Priority Register for Daisy Chain
#define VICVECTADDR0	0x100	//Vector Address 0 Register
#define VICVECTADDR1	0x104
#define VICVECTADDR2	0x108
#define VICVECTADDR3	0x10C
#define VICVECTADDR4	0x110
#define VICVECTADDR5	0x114
#define VICVECTADDR6	0x118
#define VICVECTADDR7	0x11C
#define VICVECTADDR8	0x120
#define VICVECTADDR9	0x124
#define VICVECTADDR10	0x128
#define VICVECTADDR11	0x12C
#define VICVECTADDR12	0x130
#define VICVECTADDR13	0x134
#define VICVECTADDR14	0x138
#define VICVECTADDR15	0x13C
#define VICVECTADDR16	0x140
#define VICVECTADDR17	0x144
#define VICVECTADDR18	0x148
#define VICVECTADDR19	0x14C
#define VICVECTADDR20	0x150
#define VICVECTADDR21	0x154
#define VICVECTADDR22	0x158
#define VICVECTADDR23	0x15C
#define VICVECTADDR24	0x160
#define VICVECTADDR25	0x164
#define VICVECTADDR26	0x168
#define VICVECTADDR27	0x16C
#define VICVECTADDR28	0x170
#define VICVECTADDR29	0x174
#define VICVECTADDR30	0x178
#define VICVECTADDR31	0x17C	//Vector Address 31 Register
#define VICVECTPRIORITY0	0x200	//Vector Priority 0 Register
#define VICVECTPRIORITY1	0x204
#define VICVECTPRIORITY2	0x208
#define VICVECTPRIORITY3	0x20C
#define VICVECTPRIORITY4	0x210
#define VICVECTPRIORITY5	0x214
#define VICVECTPRIORITY6	0x218
#define VICVECTPRIORITY7	0x21C
#define VICVECTPRIORITY8	0x220
#define VICVECTPRIORITY9	0x224
#define VICVECTPRIORITY10	0x228
#define VICVECTPRIORITY11	0x22C
#define VICVECTPRIORITY12	0x230
#define VICVECTPRIORITY13	0x234
#define VICVECTPRIORITY14	0x238
#define VICVECTPRIORITY15	0x23C
#define VICVECTPRIORITY16	0x240
#define VICVECTPRIORITY17	0x244
#define VICVECTPRIORITY18	0x248
#define VICVECTPRIORITY19	0x24C
#define VICVECTPRIORITY20	0x250
#define VICVECTPRIORITY21	0x254
#define VICVECTPRIORITY22	0x258
#define VICVECTPRIORITY23	0x25C
#define VICVECTPRIORITY24	0x260
#define VICVECTPRIORITY25	0x264
#define VICVECTPRIORITY26	0x268
#define VICVECTPRIORITY27	0x26C
#define VICVECTPRIORITY28	0x270
#define VICVECTPRIORITY29	0x274
#define VICVECTPRIORITY30	0x278
#define VICVECTPRIORITY31	0x27C	//Vector Priority 31 Register
#define VICADDRESS	0xF00	//Vector Address Register
#define VICPERIPHID0	0xFE0	//Peripheral Identification Register bits 7:0
#define VICPERIPHID1	0xFE4	//Peripheral Identification Register bits 15:8
#define VICPERIPHID2	0xFE8	//Peripheral Identification Register bits 23:16
#define VICPERIPHID3	0xFEC	//Peripheral Identification Register bits 31:24
#define VICPCELLID0	0xFF0	//PrimeCell Identification Register  bits 7:0
#define VICPCELLID1	0xFF4	//PrimeCell Identification Register  bits 15:8
#define VICPCELLID2	0xFF8	//PrimeCell Identification Register  bits 23:16
#define VICPCELLID3	0xFFC	//PrimeCell Identification Register  bits 31:24

// TEST REGISTERS
#define VICITCR		0x300	//Test Control Register
#define VICITIP1	0x304	//Test Input Register 1
#define VICITIP2	0x308	//Test Input Register 2
#define VICITOP1	0x30C	//Test Output Register 1
#define VICITOP2	0x310	//Test Output Register 2
#define VICINTSSTATUS	0x314	//Sampled Interrupt Source Status Register
#define VICINTSSTATUSCLEAR	0x318	//Sampled Interrupt Source Status Clear Register

#endif

