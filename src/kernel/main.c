#include <stdint.h>
#include <memory.h>
#include <hal/hal.h>
#include <arch/i686/irq.h>
#include <debug.h>
#include <boot/bootparams.h>
#include <stdio.h>

uint8_t* ShellLoadAddress = (uint8_t*)((void*)0x50000);
uint8_t* Shell = (uint8_t*)0x00200000;

extern void _init();

void crash_me();


void timer(Registers* regs)
{

    printf(".");
}

void start(BootParams* bootParams)
{   
    // call global constructors
    _init();

    HAL_Initialize();



    log_debug("Main", "Boot device: %x", bootParams->BootDevice);
    log_debug("Main", "Memory region count: %d", bootParams->Memory.RegionCount);
    for (int i = 0; i < bootParams->Memory.RegionCount; i++) 
    {
        log_debug("Main", "MEM: start=0x%llx length=0x%llx type=%x", 
            bootParams->Memory.Regions[i].Begin,
            bootParams->Memory.Regions[i].Length,
            bootParams->Memory.Regions[i].Type);
    }



    printf("TuxerOS Ver. A 0.1.2\n");
    printf("This operating system is under construction.\n");
    //i686_IRQ_RegisterHandler(0, timer);
    printf("Sup\n");
    //test();

    //crash_me();

end:
    for (;;);
}
