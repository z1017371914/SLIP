//
//  main.c
//  client
//
//  Created by apple on 16/3/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include "client.h"
#include "slipdev.h"
#define MAXNUM 1000

int main(int argc, const char * argv[]) {
    initSocket("127.0.0.1", 4001);
    unsigned char in[MAXNUM];
    unsigned char out[MAXNUM];
    unsigned char dec[MAXNUM];
    while (1) {
        scanf("%s",in);
        memset(out,0,MAXNUM);
        slip(out, strlen(in), in);
//        printf("%s\n",out);
//        unslip(dec,strlen(out), out);
//        printf("%s\n",dec);
        sendMessage(out, MAXNUM);
        strrev(in);
        printf("%s\n",out);
    }
    return 0;
}
