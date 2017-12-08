/* FlexCAN.h              (c) 2015 Freescale Semiconductor, Inc.
 * Descriptions: FTM example code.
 * 16 Sep 2016 SM: Initial version
 */


#ifndef FLEXCAN_H_
#define FLEXCAN_H_

uint32_t rx_msg_data[2];
uint32_t tx_msg_data[2];

void FLEXCAN0_init (void);
void FLEXCAN0_transmit_msg (const uint8_t can_mb,const uint32_t CAN_Id, uint32_t *TxDATA);
void FLEXCAN0_receive_msg (const uint8_t can_mb, uint32_t  *RxDATA );

#endif /* FLEXCAN_H_ */
