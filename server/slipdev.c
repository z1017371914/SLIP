/*!
 *
 * @file slipdev.c
 * @author Gokul A.  <gokul@utexas.edu>
 * @brief Serial Line Internet Protocol - SLIP
 * @see RFC: 1055   J. Romkey
 */

#include "slipdev.h"

#ifdef DEBUG
    #include <stdio.h>
#endif

/*!
 * \brief slip
 * \param[out] out - slipped output buffer
 * \param[in] len - strlen of input buffer
 * \param[in] in - input buffer
 * \return
 */
int slip(unsigned char *out, int len, unsigned char *in)
{
    if(len > MAX_LENGTH)
        return -1;
    int j = 0;  //track out
    int i = 0;  //trac in
    out[j++] = END;
    while(j<=len)
    {
        switch((unsigned char)in[i])
        {
        case END:
            out[j++] = ESC;
            out[j++] = ESC_END;
            i+=1;
            break;
        case ESC:
            out[j++] = ESC;
            out[j++] = ESC_ESC;
            i+=1;
            break;
        default:
            out[j++] = in[i];
            i+=1;
        }
    }
    out[j] = END;
    return j;
}

/*!
 * \brief unslip
 * \param[out] out - unslipped buffer
 * \param[in] len - strlen of input buffer
 * \param[in] in - slipped input buffer
 * \return
 */
int unslip(unsigned char *out, int len, unsigned char *in)
{
#ifdef DEBUG
   // printf("in unslip\n");
#endif
    int i = 0;
    len -= 1;   //for 0
    while (i < MAX_LENGTH)
    {
#ifdef DEBUG
        //printf("SW %X\n", in[len]);
#endif
        switch((unsigned char)in[len])
        {
        case END:
                if(len==0){
                strrev(out);
                return i;
                }
            else
                len -=1;
                break;
        case ESC:
            switch((unsigned char)in[len])
            {
            case ESC_END:
                len -=1;
                out[i++] = END;
                break;
            case ESC_ESC:
                len-=1;
                out[i++] = ESC;
                break;

            }
        default:
            if(len > 0)
                out[i++] = in[len];
            len-=1;
        }
    }
    strrev(out);
    return i;
}

/*!
 * \brief strrev
 * \param[in] input string
 * \return reversed string
 */
char *strrev(char *in)
{
    char *t1, *t2;
    if(!in || !*in)
        return in;
    for(t1=in,t2= in+strlen(in)-1 ;t2>t1; ++t1,--t2)
    {
        *t1 ^= *t2;
        *t2 ^= *t1;
        *t1 ^= *t2;
    }
    return in;

}
