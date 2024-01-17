#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/alt_irq.h"


//Global Vars
volatile __uint16_t chaser_on    =0;
volatile __uint16_t chaser_speed =0;

static void irq_handler_bp(void* context, alt_u32 id) {
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0b01);

    chaser_on= chaser_on ^ 1;

    alt_printf("interrupt BP %x\n", chaser_on);
}

static void irq_handler_sw(void* context, alt_u32 id) {
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_0_BASE, 0x00f);

    chaser_speed= IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE);
    chaser_speed= chaser_speed & 0x00f;

    alt_printf("interrupt SW %x\n", chaser_speed);
}


int main() {
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_2_BASE, 0b01);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0b01);
    alt_irq_register(PIO_2_IRQ, NULL, (void*)irq_handler_bp);

    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_0_BASE, 0x00f);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_0_BASE, 0x00f);
    alt_irq_register(PIO_0_IRQ, NULL, (void*)irq_handler_sw);

    int data =0x01;
    IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, data);
    usleep(60000);

    while(1) {
	if(chaser_on == 1) {
    	    while(data != 0x200) {
                data= data<<1;
            	IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, data);
            	usleep(chaser_speed*10000 +10000);
            }

            while(data != 0x001) {
            	data= data>>1;
            	IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, data);
            	usleep(chaser_speed*10000 +10000);  
            }
	}
        else {
	    IOWR_ALTERA_AVALON_PIO_DATA(PIO_1_BASE, 0x000);
	    usleep(chaser_speed*10000 +10000); 
	}
    }
    return 0;
}