/*
http://cise.sdust.edu.cn/OJ/
201901071223
zzxlovezfy1314
*/

#include <stdio.h>

int main()
{
    int k;
    int i, m, n, sum;

    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        int col, row;
        int matrix[100][100];
        scanf("%d %d", &m, &n);
        for (row = 0; row < m; row++) {
            for (col = 0; col < n; col++) {
                scanf("%d", &matrix[row][col]);
            }
        }

        printf("case %d:", i);
        for (col = 0; col < n; col++) {
            sum = 0;
            for (row = 0; row < m; row++) {
                sum += matrix[row][col];
            }
            printf("%lg%s", (double)sum / row, col + 1 < n ? " " : "\n");
        }
    }
    
    return 0;
}