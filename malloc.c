#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 3

typedef struct Patterns {
    int pattern;
} Patterns;

void func1(struct Patterns *file_patterns);
void func2(struct Patterns *file_patterns);
struct Patterns *func3(struct Patterns *file_patterns, int buf);


int main() {
    Patterns *file_patterns = malloc(BUFFER * sizeof(file_patterns));
    func1(file_patterns);
    printf("Result %d - %d\n", file_patterns[0].pattern, file_patterns[5].pattern);
    return 0;
}

void func1(struct Patterns *file_patterns) {
    // file_patterns[0].pattern = 999;
    // printf("%d\n", file_patterns[0].pattern);
    func2(file_patterns);
}

void func2(struct Patterns *file_patterns) {
    // file_patterns[1].pattern = 9999;
    // printf("%d\n", file_patterns[1].pattern);
    int i = 0;
    int buf = BUFFER;
    while (i < 6) {
        printf("i = %d\n", i);
        file_patterns[i].pattern = i + 99;
        if (i >= buf - 1) {
            printf("SEGA\n");
            buf *= 2;
            file_patterns = func3(file_patterns, buf);
        }
        i++;
    }
}

struct Patterns *func3(struct Patterns *file_patterns, int buf) {
    struct Patterns *temp;
    temp = realloc(file_patterns, buf * sizeof(file_patterns));
    file_patterns = temp;
    return file_patterns;
}


