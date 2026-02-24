#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len);
void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int left, int right);

int main() 
{
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
    int N = sizeof(input_array) / sizeof(input_array[0]);
    
    printf("Orijinal dizi: \n");
    print_array(input_array, N);
    
    merge_sort(input_array, 0, N - 1);
    
    printf("Sıralanmış dizi: \n");
    print_array(input_array, N);
    
    return 0;
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int left_len = mid - left + 1;
    int right_len = right - mid;
    
    // Geçici diziler oluştur
    int *left_arr  = (int*)malloc(left_len * sizeof(int));
    int *right_arr = (int*)malloc(right_len * sizeof(int));
    
    // Verileri kopyala
    for (i = 0; i < left_len; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < right_len; j++)
        right_arr[j] = arr[mid + 1 + j];
    
    // Merge işlemi
    i = 0; j = 0; k = left;
    while (i < left_len && j < right_len) {
        if (left_arr[i] <= right_arr[j])
            arr[k++] = left_arr[i++];
        else
            arr[k++] = right_arr[j++];
    }
    // Merge işleminden sonra kalan elemanlar sıralanmış olacaktır ve dizinin geri kalanına kopyalanır
    while (i < left_len)
        // Eğer left_arr'de hala eleman varsa, bunları arr'ye kopyala
        arr[k++] = left_arr[i++];
    while (j < right_len)
        // Eğer right_arr'de hala eleman varsa, bunları arr'ye kopyala
        arr[k++] = right_arr[j++];
    
    // Geçici dizileri temizle (memory leak'i önlemek için)
    free(left_arr);
    free(right_arr);
}

void merge_sort(int *arr, int left, int right) {
    // recursive olarak diziyi böl ve sırala
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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