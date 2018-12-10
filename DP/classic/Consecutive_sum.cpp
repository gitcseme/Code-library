#include <iostream>

using namespace std;

int main() {

    int arr[] = {1, 2, 5, 8, 7, 3};
    int sum[6];

    int current = 0;
    for (int i = 0; i < 6; ++i) {
        current += arr[i];
        sum[i] = current;
    }

    // calculate Queries.
    int i, j;
    while (scanf("%d %d", &i, &j) == 2) {
        printf("sum %d to %d = %d\n", i, j, i>0 ? sum[j] - sum[i-1] : sum[j]);
    }


    return 0;
}
