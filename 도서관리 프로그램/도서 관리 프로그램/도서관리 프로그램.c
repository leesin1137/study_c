#include <stdio.h>
#include <string.h>
#include <ctype.h>

int i = 0;
struct BOOK
{
    char book_name[25];
    char book_form[25];
    char book_make[25];
    int book_number;
};
struct BOOK books[100];

struct TO_LEND_BOOK
{
    char lend_book_name[25];
    char lend_book_form[25];
    char lend_book_make[25];
    int lend_book_number;
};
struct TO_LEND_BOOK leBook[100];

void save_book()
{
    printf("\n--책 추가기능--\n");
    printf("1. 책 이름: ");
    scanf_s("%24s", books[i].book_name, sizeof(books[i].book_name));
    printf("2. 책 출판사: ");
    scanf_s("%24s", books[i].book_form, sizeof(books[i].book_form));
    printf("3. 책 지은이: ");
    scanf_s("%24s", books[i].book_make, sizeof(books[i].book_make));
    printf("4. 책 갯수: ");
    scanf_s("%d", &books[i].book_number, sizeof(books[i].book_number));
    for (int j = 0; j < i; j++)
    {
    if(strcmp(books[i].book_name, books[j].book_name) == 0&&
        strcmp(books[i].book_form,books[j].book_form) == 0 &&
        strcmp(books[i].book_make,books[j].book_make) == 0)
        {
        books[j].book_number +=books[i].book_number; 
        printf("중복된 책이 있어 수량이 합쳐졌습니다.\n");
        return;
        }
    }
    i++;
}

void search_book()
{
    char search[25];
    int number;

    printf("\n--책 검색기능--\n");
    printf("1. 책 이름으로 검색\n");
    printf("2. 책 출판사로 검색\n");
    printf("3. 책 지은이로 검색\n");
    scanf_s("%d", &number, sizeof(number));

    switch (number)
    {
    case 1:
        scanf_s("%24s", search, sizeof(search));
        for (int j = 0; j < i; j++)
        {
            if (strcmp(search, books[j].book_name) == 0)
            {
                printf("--%d--\n", j + 1);
                printf("책이름: %s\n", books[j].book_name);
                printf("출판사: %s\n", books[j].book_form);
                printf("지은이: %s\n", books[j].book_make);
                printf("잔여갯수: %d\n", books[j].book_number);
            }
             if (strcmp(search, books[i-1].book_name) > 0)
            {
                printf("잘못된 선택\n");
               
            }
        }
        break;
    case 2:
        scanf_s("%24s", search, sizeof(search));
        for (int j = 0; j < i; j++)
        {
            if (strcmp(search, books[j].book_form) == 0)
            {
                printf("--%d--\n", j + 1);
                printf("책이름: %s\n", books[j].book_name);
                printf("출판사: %s\n", books[j].book_form);
                printf("지은이: %s\n", books[j].book_make);
                printf("잔여갯수: %d\n", books[j].book_number);
            }
            if (strcmp(search, books[i-1].book_form) > 0)
            {
                printf("잘못된 선택\n");
      
            }
        }
        break;
    case 3:
        scanf_s("%24s", search, sizeof(search));
        for (int j = 0; j < i; j++)
        {
            if (strcmp(search, books[j].book_make) == 0)
            {
                printf("--%d--\n", j + 1);
                printf("책이름: %s\n", books[j].book_name);
                printf("출판사: %s\n", books[j].book_form);
                printf("지은이: %s\n", books[j].book_make);
                printf("잔여갯수: %d\n", books[j].book_number);
            }
            if (strcmp(search, books[i-1].book_make) > 0)
            {
                printf("잘못된 선택\n");
                
            }
        }
        break;
    default:
        break;
    }
}

void lend_book()
{
    char search[25];
    int number;
    printf("\n--책 대여기능--\n");
    printf("원하는 책이름: ");
    scanf_s("%24s", search, sizeof(search));
    for (int j = 0; j < i; j++)
    {
        if (strcmp(search, books[j].book_name) == 0)
        {
            printf("원하는 수량: ");
            scanf_s("%d", &number, sizeof(number));
            if (books[j].book_number >= number) {
                strcpy_s(leBook[j].lend_book_name, sizeof(leBook[j].lend_book_name), books[j].book_name);
                leBook[j].lend_book_number = books[j].book_number;
                books[j].book_number -= number;
                printf("대여 완료\n");
            }
            else
            {
                printf("대여 가능한 수량이 부족합니다.\n");
            }
            return;
        }
    }
    printf("원하는 책이 없습니다.\n");
}

void to_return()
{
    char to_re[25];
    int lend_book_count;
    printf("\n--책 반납기능--\n");
    printf("반납할 책: ");
    scanf_s("%24s", to_re, sizeof(to_re));
    for (int j = 0; j < i; j++)
    {
        printf("반납할 수량: ");
        scanf_s("%d", &lend_book_count, sizeof(lend_book_count));
        if (leBook[j].lend_book_number > 0)
        {
            if (strcmp(to_re, leBook[j].lend_book_name) == 0)
            {
                books[j].book_number += lend_book_count;
                leBook[j].lend_book_number -= lend_book_count;
                printf("책 반납완료\n");
                return;
            }
        }
        else
        {
            printf("잘못된 선택\n");
        }
    }
    printf("반납할 책을 찾지 못했습니다.\n");
}

int main()
{
    int user_choice;
    while (1)
    {
        printf("--도서 관리 프로그램--\n");
        printf("1. 책 추가하기\n");
        printf("2. 책 검색하기\n");
        printf("3. 책 빌리기\n");
        printf("4. 책 반납하기\n");
        printf("5. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &user_choice, sizeof(user_choice));

        switch (user_choice)
        {
        case 1:
            save_book();
            break;
        case 2:
            search_book();
            break;
        case 3:
            lend_book();
            break;
        case 4:
            to_return();
            break;
        case 5:
            return 0;
        default:
            printf("잘못된 선택\n");
        }
    }

    return 0;
}
