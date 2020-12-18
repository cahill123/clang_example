#include <stdio.h>
#include <stdlib.h>

void show_qpl(int *missing, int missing_len){
    for(int i=0; i<missing_len; i++){
        printf("%d ,", *(missing+i));
    }
    printf("\n");
}
#define SIGN (-1)
static long int queues=0;
//全排列
void qpl(int *src, int src_len, int *missing, int missing_len){
    int src_tmp[20], src_len_tmp, missing_tmp[20], missing_len_tmp;
    int tmp=0;
    if(src_len!=0){//分而治之，如果被排列序列中有元素，则从src中挑出一个元素放入missing里面
        for(int i=0; i<src_len; i++){
            *(missing+missing_len) = *(src+i);

            for(int j=0,k=0; j<(src_len-1); k++,j++){
                if(j==i){
                    src_tmp[j] = *(src+(++k));
                }else{
                    src_tmp[j] = *(src+k);
                }
                
            }
            qpl(src_tmp, src_len-1, missing, missing_len+1);
            
        }
    }else{
        
        queues++;
        show_qpl(missing, missing_len);
    }
    
    
}

#define MAX_LEN (11)
int data[MAX_LEN] ;

int main(void){
    int missing_data[MAX_LEN];
    
    printf("process ->\n");
    for(int i=0; i<MAX_LEN;i++){
        data[i] = i+1;
    }

    qpl(data, MAX_LEN, missing_data,0);
    printf("\n\n all=%ld \n\n",queues);
    return 0;
}

