#include <stdio.h>

int indexOfSmallestElement(int array[], int len)
{
    int ret = 0;
    int i;

    for (i = 1; i < len; i++) {
        if (array[i] <= array[ret]) {
            ret = i;
        }
    }

    return ret;
}

int main()
{
    int i, n;
    
    scanf("%d", &n);

    int array[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("%d\n", indexOfSmallestElement(array, n));
    return 0;
}
