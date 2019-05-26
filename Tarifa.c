//
// Created by Jakob Kallestad on 2019-05-26.
//
#include "stdio.h"

int main() {
    int x, n, current = 0;
    scanf("%d%d", &x, &n);
    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);
        current += x-m;
    }
    printf("%d\n", current+x);
    return 0;
}