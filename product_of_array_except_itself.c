/* Product of all elements of an array excluding given element */

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *result = calloc(sizeof(int), numsSize);

    /* Excluding i while using j to iterate through array */
    int i = 0, j = 0, temp = 1;

    // while (i < numsSize) {
    //     if (i != 0 && nums[i] == nums[i-1]) {
    //         *(result+i) = *(result+i-1);
    //         i++;

    //     } else if (j < numsSize) {
    //         if (j != i)
    //             temp *= nums[j];
           
    //         j++;
    //         // printf("temp: %d = %d\n", i, temp);

    //     } else {
    //         /* Need to make sure that pointer to int array stays at the beginning--cannot use explicit index */
    //         *(result+i) = temp;
    //         // printf("pointer to result %d\n", *result);
    //         // printf("setting result[%d] = %d\n\n", i, temp);
    //         temp = 1, 
    //         j = 0;
    //         i++;
    //     }
    // }


    /* Now attempting with prefix and suffix products */

    // Using our result array to store suffix products
    *(result+numsSize-1) = 1;
    for (int i = numsSize - 2; i >= 0 ; i--) {
        *(result+i) = *(result+i+1) * nums[i+1];
        // printf("result[%d]: %d\n", i, *(result+i));
    }

    // Now multiplying each suffix product in result by the corresponding prefix product stored in temp
    for (int i = 0; i < numsSize; i++) {
        *(result + i) = temp * *(result + i);
        // Starting with temp = 1, we multiply temp by the next value in nums for each i.
        temp *= nums[i];
    }

    return result;
}

void print_array(int* arr, int arr_size) {
    printf("[");
    for (int i = 0; i < arr_size; i++) {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}

int main() {
    int nums[4] = {1,2,3,4};
    int returnSize;

    int *res1 = productExceptSelf(&nums[0], 4, &returnSize);
    print_array(res1, 4);
    
    free(res1);
}