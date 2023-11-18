#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define START_ID 1

struct student {
    char name[24];
    int id;
    int score;
};

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
        fprintf(stderr, "How to use : %s File \n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\nEnter StudentID you want to modify : ");
    while (scanf("%d", &id) == 1) {
        // 파일에 대한 쓰기 잠금 설정
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (id - START_ID) * sizeof(record);
        lock.l_len = sizeof(record);

        // 파일 잠금 설정. 이미 잠겨 있으면 대기.
        if (fcntl(fd, F_SETLKW, &lock) == -1) {
            perror(argv[1]);
            exit(3);
        }

        // 지정된 위치에서 학생 레코드 읽기
        lseek(fd, (long)(id - START_ID) * sizeof(record), SEEK_SET);

        // 읽은 데이터가 있고, 레코드 ID가 0이 아니면 실행
        if ((read(fd, (char *)&record, sizeof(record)) > 0) && (record.id != 0)) {
            printf("Name:%s\t StuID:%d\t Score:%d\n",
                   record.name, record.id, record.score);
            printf("Enter new score: ");
            scanf("%d", &record.score);

            // 현재 위치에서 뒤로 이동한 후 업데이트된 레코드를 쓰기
            lseek(fd, (long)-sizeof(record), SEEK_CUR);
            write(fd, (char *)&record, sizeof(record));

            // 파일 잠금 해제
            lock.l_type = F_UNLCK;
            fcntl(fd, F_SETLK, &lock);
        } else {
            printf("No record %d \n", id);
        }

        printf("\nEnter StudentID you want to modify : ");
    }

    // 파일 닫기
    close(fd);
    exit(0);
}

