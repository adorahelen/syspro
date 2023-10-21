#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 100

int main() {
    char savedText[MAX_LINES][MAX_LINE_LENGTH];
    char buf;
    int line = 0;
    int line_count = 0;
    FILE *file = fopen("test.txt", "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    while ((buf = fgetc(file)) != EOF) {
        if (buf == '\n') {
            savedText[line][line_count] = '\0';
            line++;
            line_count = 0;
        } else {
            savedText[line][line_count++] = buf;
        }

        if (line == MAX_LINES) {
            printf("저장 공간 부족\n");
            break;
        }
    }
    fclose(file);

    printf("라인 번호를 입력하세요: ");
    int option;
    scanf("%d", &option);

    if (option == 0) {
        for (int i = 0; i < line; i++) {
            printf("%s\n", savedText[i]);
        }
    } else if (option > 0 && option <= line) {
        printf("%s\n", savedText[option - 1]);
    } else {
        printf("유효하지 않은 라인 번호\n");
    }

    return 0;
}

