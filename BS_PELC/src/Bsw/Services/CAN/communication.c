#include "communication.h"

uint32_t rx_msg_data[2];
uint32_t tx_msg_data[2];

void test() {

  if ((CAN0->IFLAG1 >> 4) & 1)
  {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
    FLEXCAN0_receive_msg (4,rx_msg_data);      /* Read message */
    PTD->PTOR |= 1<<16;         /*   toggle output port D16 (Green LED) */
    tx_msg_data[0]=rx_msg_data[0];
    tx_msg_data[1]=rx_msg_data[1];
    FLEXCAN0_transmit_msg (0,0x15540000,tx_msg_data);     /* MB0 word 1: Tx msg with STD ID 0x555 */
  }

}
