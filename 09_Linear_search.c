#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int i, key;

    printf("Enter number: ");
    scanf("%d", &key);

    for(i = 0; i < 5; i++) {
        if(a[i] == key) {
            printf("Found at position %d", i + 1);
            return 0;
        }
    }

    printf("Not found");
}