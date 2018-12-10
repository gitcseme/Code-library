#include <iostream>
using namespace std;
#define INF 2000000000

int n, maxIndex;

int LisNlogK(int sequence[], int L[], int I[]) {
    I[0] = - INF;
    for (int i = 1; i <= n; ++i)
        I[i] = INF;

    int low, high, mid, LisLenght = 0;
    maxIndex = 0;

    for (int i = 0; i < n; ++i) {
        low = 0;
        high = LisLenght;

        while (low <= high) {
            mid = (low + high) / 2;
            if (I[mid] < sequence[i])
                low = mid + 1;
            else
                high = mid - 1;
        }

        I[low] = sequence[i];
        L[i] = low;
        if (LisLenght < low) {
            LisLenght = low;  //max LIS length.
            maxIndex = i;     //for path.
        }
    }

    return LisLenght;
}

int main()
{
    scanf("%d", &n);
    int sequence[n];
    int L[n];
    int I[n+1];
    for (int i = 0; i < n; ++i)
        scanf("%d", &sequence[i]);

    int mx_len = LisNlogK(sequence, L, I);
    printf("%d\n", mx_len);

    // Path building.....
    int path[mx_len], idx = 1;
    path[0] = sequence[maxIndex];
    for (int i = maxIndex-1; i >= 0; --i) {
        if (sequence[maxIndex] > sequence[i] && L[maxIndex]-1 == L[i]) {
            //printf("%d\n", arr[i]);
            path[idx++] = sequence[i];
            maxIndex = i;
        }
    }

    //print path......
    for (int i = mx_len - 1; i >= 0; --i)
        printf("%d ", path[i]);

    return 0;
}
