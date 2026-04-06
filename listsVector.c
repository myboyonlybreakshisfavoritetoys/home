#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
} Vector;

void slice(Vector *sliced, Vector *source, int start, int end) {
    int length = end - start;
    
    if (length < 0 || start < 0 || end > source->size) {
        sliced->data = (char *)malloc(1 * sizeof(char));
        sliced->data[0] = '\0';
        sliced->size = 0;
        return;
    }

    sliced->data = (char *)malloc((length + 1) * sizeof(char));
    sliced->size = length;

    for (int i = 0; i < length; i++) {
        sliced->data[i] = source->data[start + i];
    }
    sliced->data[length] = '\0';
}

int main() {
    int choice;
    
    if (scanf("%d", &choice) != 1) return 0;

    if (choice == 1) {
        char A[16], B[16];
        scanf("%s %s", A, B);
        printf("%s%s\n", A, B);

    } else if (choice == 2) {
        char A_str[16];
        int B, C;
        scanf("%s %d %d", A_str, &B, &C);

        Vector source;
        source.size = strlen(A_str);
        source.data = A_str;

        Vector sliced;
        slice(&sliced, &source, B, C);

        printf("%s\n", sliced.data);

        free(sliced.data);
    }

    return 0;
}
