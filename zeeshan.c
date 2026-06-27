#include <stdio.h>

int main() {
    int n, m; 
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int Allocation[n][m], Max[n][m], Need[n][m], Available[m];
    int Finish[n], SafeSeq[n];

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Maximum Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &Available[j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) Finish[i] = 0;

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (Finish[i] == 0) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Available[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (int j = 0; j < m; j++) {
                        Available[j] += Allocation[i][j];
                    }
                    SafeSeq[count++] = i;
                    Finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in UNSAFE STATE.\n");
            return 0;
        }
    }

    printf("System is in SAFE STATE.\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", SafeSeq[i]);
        if (i != n - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
