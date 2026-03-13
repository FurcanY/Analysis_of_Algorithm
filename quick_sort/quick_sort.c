#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len);
void swap (int *a , int *b);
int lomuto_partition (int *arr, int left, int right);
void quick_sort(int *arr, int left, int right);


int main (void){

    int input_array[] = {
        674,32,590,704,
        456,811,79,564,481,270,728,795,464,
        295,124,604,885,739,746,926,19,498,745,846,430,
        832,293,322,663,794,108,946,21,404,298,738,658,
        546,813,952,759,680,70,920,958,570,306,611,55,
        236,9,407,209,444,990,238,242,792,
        99,120,208,812,369,440,897,247,584,144,
        430,175,337,42,863,8,77,996,
        963,323,546,262,532,333,53,850,409,
        798,397,107,747,973,631,176,
        535,766,377,464,738,520,977,200,1
    };

    int N = sizeof (input_array) / sizeof (input_array [0]);

    printf("Orijinal dizi: \n");
    print_array(input_array, N);

    quick_sort (input_array, 0 ,N-1);

    printf("Sıralanmış dizi: \n");
    print_array(input_array, N);

    return 0;
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

void swap (int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition (int *arr, int left, int right) {
    // pivot son eleman olarak seçilir ve swap işlemi yapılır.
    int i = left-1;
    for ( int j = left; j < right; j++)
    {   
        // pivot daha büyükse değiştir
        if (arr[j] < arr[right] ) {
            i++;
            swap (&arr[j], &arr[i]);
        }
    }
    // en sonda pivotun yerini yerleştiririz
    swap (&arr[++i], &arr[right]);
    return i;
}

void quick_sort(int *arr, int left, int right){

    if (left < right ) {
        // ilk olarak diziyi bir pivota göre sıralayıp pivotun indisinden ikiye böleriz.
        int pivot = lomuto_partition (arr, left, right);
        quick_sort ( arr, left ,pivot-1 );
        quick_sort ( arr, pivot + 1, right);
        
    }
}