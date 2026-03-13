#include <stdio.h>
#include <stdlib.h>



int find_max (int low_index, int high_index, int arr[]){
    // temel kararları ilk yazarız

    // tek eleman varsa döndür
    if (low_index == high_index){
        return arr[low_index];
    }
    // iki eleman varsa büyük olan döndürülür.
    if (low_index +1 == high_index) {
        return (arr[low_index] > arr[high_index]) ? arr[low_index]  : arr[high_index];
    }

    // dizinin orta indisini buluruz.
    int mid = (low_index + high_index ) / 2;

    int left_max  = find_max (low_index, mid ,arr);
    int right_max = find_max (mid + 1, high_index, arr);

    // son karar işlemleri yapılır
    return (left_max < right_max) ? right_max : left_max;

}

int find_min(int low_index, int high_index, int arr[]){
    // temel kararları ilk yazarız

    // tek eleman varsa döndür
    if (low_index == high_index){
        return arr[low_index];
    }
    // iki eleman varsa küçük olan döndürülür.
    if (low_index +1 == high_index) {
        return (arr[low_index] < arr[high_index]) ? arr[low_index]  : arr[high_index];
    }

    // dizinin orta indisini buluruz.
    int mid = (low_index + high_index ) / 2;

    int left_min  = find_min (low_index, mid ,arr);
    int right_min = find_min (mid + 1, high_index, arr);

    // son karar işlemleri yapılır
    return (left_min > right_min) ? right_min : left_min;

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
        535,766,377,464,738,520,977,200,1
    };

    int N = sizeof(input_array) / sizeof(input_array[0]);

    int max = find_max (0,N-1,input_array);
    int min = find_min (0,N-1,input_array);

    printf ("Dizideki max eleman: %d\n",max);
    printf ("Dizideki min eleman: %d\n",min);



    return 0;
}