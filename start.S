.global _start
.global key_isr

_start:
    @ Set stack pointer to call C functions
    ldr sp, =0x40000000

    @ Enable IRQ interrupts globally
    mrs r0, cpsr
    bic r0, r0, #0x80
    msr cpsr, r0

    @ Branch to C main function
    bl main

halt:
    b halt

key_isr:
    @ Adjust return address (LR) because of IRQ entry
    sub lr, lr, #4
    @ Save context (r0-r12 and the adjusted lr)
    stmfd sp!, {r0-r12, lr}

    @ Branch to the C interrupt handler
    bl key_handle

    @ Restore context and return from interrupt
    ldmfd sp!, {r0-r12, pc}^