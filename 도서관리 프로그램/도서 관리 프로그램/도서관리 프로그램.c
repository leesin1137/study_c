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
    printf("\n--å �߰����--\n");
    printf("1. å �̸�: ");
    scanf_s("%24s", books[i].book_name, sizeof(books[i].book_name));
    printf("2. å ���ǻ�: ");
    scanf_s("%24s", books[i].book_form, sizeof(books[i].book_form));
    printf("3. å ������: ");
    scanf_s("%24s", books[i].book_make, sizeof(books[i].book_make));
    printf("4. å ����: ");
    scanf_s("%d", &books[i].book_number, sizeof(books[i].book_number));
    for (int j = 0; j < i; j++)
    {
    if(strcmp(books[i].book_name, books[j].book_name) == 0&&
        strcmp(books[i].book_form,books[j].book_form) == 0 &&
        strcmp(books[i].book_make,books[j].book_make) == 0)
        {
        books[j].book_number +=books[i].book_number; 
        printf("�ߺ��� å�� �־� ������ ���������ϴ�.\n");
        return;
        }
    }
    i++;
}

void search_book()
{
    char search[25];
    int number;

    printf("\n--å �˻����--\n");
    printf("1. å �̸����� �˻�\n");
    printf("2. å ���ǻ�� �˻�\n");
    printf("3. å �����̷� �˻�\n");
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
                printf("å�̸�: %s\n", books[j].book_name);
                printf("���ǻ�: %s\n", books[j].book_form);
                printf("������: %s\n", books[j].book_make);
                printf("�ܿ�����: %d\n", books[j].book_number);
            }
             if (strcmp(search, books[i-1].book_name) > 0)
            {
                printf("�߸��� ����\n");
               
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
                printf("å�̸�: %s\n", books[j].book_name);
                printf("���ǻ�: %s\n", books[j].book_form);
                printf("������: %s\n", books[j].book_make);
                printf("�ܿ�����: %d\n", books[j].book_number);
            }
            if (strcmp(search, books[i-1].book_form) > 0)
            {
                printf("�߸��� ����\n");
      
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
                printf("å�̸�: %s\n", books[j].book_name);
                printf("���ǻ�: %s\n", books[j].book_form);
                printf("������: %s\n", books[j].book_make);
                printf("�ܿ�����: %d\n", books[j].book_number);
            }
            if (strcmp(search, books[i-1].book_make) > 0)
            {
                printf("�߸��� ����\n");
                
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
    printf("\n--å �뿩���--\n");
    printf("���ϴ� å�̸�: ");
    scanf_s("%24s", search, sizeof(search));
    for (int j = 0; j < i; j++)
    {
        if (strcmp(search, books[j].book_name) == 0)
        {
            printf("���ϴ� ����: ");
            scanf_s("%d", &number, sizeof(number));
            if (books[j].book_number >= number) {
                strcpy_s(leBook[j].lend_book_name, sizeof(leBook[j].lend_book_name), books[j].book_name);
                leBook[j].lend_book_number = books[j].book_number;
                books[j].book_number -= number;
                printf("�뿩 �Ϸ�\n");
            }
            else
            {
                printf("�뿩 ������ ������ �����մϴ�.\n");
            }
            return;
        }
    }
    printf("���ϴ� å�� �����ϴ�.\n");
}

void to_return()
{
    char to_re[25];
    int lend_book_count;
    printf("\n--å �ݳ����--\n");
    printf("�ݳ��� å: ");
    scanf_s("%24s", to_re, sizeof(to_re));
    for (int j = 0; j < i; j++)
    {
        printf("�ݳ��� ����: ");
        scanf_s("%d", &lend_book_count, sizeof(lend_book_count));
        if (leBook[j].lend_book_number > 0)
        {
            if (strcmp(to_re, leBook[j].lend_book_name) == 0)
            {
                books[j].book_number += lend_book_count;
                leBook[j].lend_book_number -= lend_book_count;
                printf("å �ݳ��Ϸ�\n");
                return;
            }
        }
        else
        {
            printf("�߸��� ����\n");
        }
    }
    printf("�ݳ��� å�� ã�� ���߽��ϴ�.\n");
}

int main()
{
    int user_choice;
    while (1)
    {
        printf("--���� ���� ���α׷�--\n");
        printf("1. å �߰��ϱ�\n");
        printf("2. å �˻��ϱ�\n");
        printf("3. å ������\n");
        printf("4. å �ݳ��ϱ�\n");
        printf("5. ���α׷� ����\n");
        printf("����: ");
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
            printf("�߸��� ����\n");
        }
    }

    return 0;
}
