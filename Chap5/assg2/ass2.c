#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    char lines[100][MAX_LINE_LENGTH];
    int line_count = 0;

    // 파일 읽기
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
        line_count++;
    }
    fclose(file);

    // 거꾸로 출력
    for (int i = line_count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
    }

    return 0;
}

