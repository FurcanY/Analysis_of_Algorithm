#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len);

void insertion_sort(int *arr, int len){

    for (int i = 1; i < len ;++i)
    {
        int key = arr[i];
        int j  = i-1;
        
        while ( j >= 0 && arr[j] > key){
            // kaydırma işlemi yapılır
            arr[j+1] = arr[j]; // veri kopyalama yapılır (kaydırma mantığı)
            j = j-1; // bir alt indise geçilir
        }
        arr[j+1] = key; 
    }
    
}

int main (){

    int input_array[] = {
        674,32,590,704,
        456,811,79,564,481,270,728,795,464,
        295,124,604,885,739,746,926,19,498,745,846,430,
        832,293,322,663,794,108,946,21,404,298,738,658,
        546,813,952,759,680,70,920,958,570,306,611,55,
        236,9,407,209,444,990,238,242,792,1024,
        99,120,208,812,369,440,897,247,584,144,
        430,175,337,42,863,8,77,996,
        963,323,546,262,532,333,53,850,409,
        798,397,107,747,973,631,176,
        535,766,377,464,738,520,977,200,1,2000,0
    };

    int N = sizeof(input_array) / sizeof(input_array[0]);
    printf ("Siralanmamis dizi: \n");
    print_array (input_array, N);

    insertion_sort (input_array, N);

    printf ("Siralanmis dizi: \n");
    print_array (input_array, N);

}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; ++i){
        printf("[%3d]", arr[i]);
        if(i % (len/4) == 0 && i > 0)
            printf("\n");
    }
    printf("\n");
    printf("------------------------------\n");
}