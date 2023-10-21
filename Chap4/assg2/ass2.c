#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int line_number = 0;  // 줄 번호
    int use_line_numbers = 0;  // -n 옵션 사용 여부
    FILE *fp;
    int c;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            use_line_numbers = 1;  // -n 옵션이 주어진 경우 플래그 설정
        } else {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "File %s Open Error\n", argv[i]);
                continue;  // 파일 열기에 실패하면 다음 파일을 시도
            }

            if (argc > 2 && use_line_numbers) {
                printf("== File: %s ==\n", argv[i]);
            }

            line_number = 0;
            while ((c = getc(fp) != EOF)) {
                if (use_line_numbers && c == '\n') {
                    line_number++;
                    printf("\n");
                }
                putc(c, stdout);
            }

            fclose(fp);

            if (use_line_numbers) {
                printf("\n== End of File: %s ==\n", argv[i]);
            }
        }
    }

    return 0;
}

