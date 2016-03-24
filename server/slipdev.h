/*!
 *
 * @file slipdev.h
 * @author Gokul A.  <gokul@utexas.edu>
 * @brief Serial Line Internet Protocol - SLIP
 * @see RFC: 1055   J. Romkey
 */

#ifndef SLIPDEV_H
#define SLIPDEV_H

#define END 0xc0
#define ESC 0xdb
#define ESC_END 0xdc
#define ESC_ESC 0xdd
#define MAX_LENGTH 1066

int slip(unsigned char *out, int len, unsigned char *in);
int unslip(unsigned char *out, int len, unsigned char *in);
char *strrev(char *in);

#endif //SLIPDEV_H
