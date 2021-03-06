/*74:*/
#line 104 "./sp.w"


#include <stdlib.h> 
#include <stdio.h> 
#include "soundpipe.h"
#include "config.h"

int main(){
sp_data*sp;
sp_create(&sp);
sp_srand(sp,12345);
sp->sr= SR;
sp->len= sp->sr*LEN;
uint32_t t,u;
SPFLOAT out= 0;

sp_voc*unit[NUM];

for(u= 0;u<NUM;u++){
sp_voc_create(&unit[u]);
sp_voc_init(sp,unit[u]);
}

for(t= 0;t<sp->len;t++){
for(u= 0;u<NUM;u++)sp_voc_compute(sp,unit[u],&out);
}

for(u= 0;u<NUM;u++)sp_voc_destroy(&unit[u]);

sp_destroy(&sp);
return 0;
}

#line 142 "./voc.w"

/*:74*/
