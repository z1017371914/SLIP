//
//  main.c
//  server
//
//  Created by apple on 16/3/23.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <stdio.h>
#include "server.h"
#include "slipdev.h"
#define MAXNUM 1000
int main(int argc, const char * argv[]) {
    initServer(4001);
    unsigned char in[MAXNUM];
    unsigned char out[MAXNUM];
       while (1) {
           //printf("start\n");
        memset(out,0,MAXNUM);
        recvServer(in,MAXNUM);
        
        unslip(out,strlen(in), in);
        printf("%s\n",out);
    }
    return 0;
}
