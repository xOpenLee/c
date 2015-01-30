/*************************************************************************
	> File Name: exercise.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Thursday, January 29, 2015 PM07:30:57 HKT
 ************************************************************************/

#include<stdio.h>
#include "../../cbb/includes.h"

#define OUT 1
#define IN 0

static i32 excerise_1_1()
{
    printf("hello world!\r\n");
    return 0;

}

static i32 excerise_1_2()
{
    /* \c unknow escape sequence*/
    printf("hello world!");
    return 0;
}

static i32 excerise_1_3()
{
    float fahr = 0, celsius = 0;
    i32 lower = 0, upper = 300, step = 20;

    fahr = lower;
    printf("\r\nTable Fahr  Celsius\r\n");
    while(fahr <= upper)
    {
        celsius =(5.0/9.0)*(fahr - 32);
        printf("%3.0f, %6.0f\r\n" , fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

static i32 excerise_1_4()
{
    float fahr = 0, celsius = 0;
    i32 lower = 0, upper = 100, step = 10;

    celsius = lower;
    printf("\r\nTable Fahr  Celsius\r\n");
    while(celsius <= upper)
    {
        fahr = (9.0/5.0)*celsius+32;
        printf("%3.0f, %6.0f\r\n" , fahr, celsius);
        celsius = celsius + step;
    }

    return 0;
}

static i32 excerise_1_5()
{
    float fahr = 0, celsius = 0;
    i32 lower = 0, upper = 300, step = 20;

    fahr = upper;
    printf("\r\nTable Fahr  Celsius\r\n");
    while(fahr >= 0)
    {
        celsius =(5.0/9.0)*(fahr - 32);
        printf("%3.0f, %6.0f\r\n" , fahr, celsius);
        fahr = fahr - step;
    }

    return 0;
}

static i32 excerise_1_6()
{
    /*value = 0*/
    printf("getchar() != EOF = %d\r\n", getchar() != EOF);
    return 0;
}

static i32 excerise_1_7()
{
    printf("EOF = %d\r\n", EOF);
    return 0;
}

static i32 excerise_1_8()
{
    i32 blank = 0, tab = 0, newline = 0;
    i32 c = 0;
    while((c = getchar()) != EOF)
    {
        if (' ' == c)
            blank++;
        else if ('\t' == c)
            tab++;
        else if ('\n' == c)
            newline++;
    }
    printf("blank = %d, tab = %d, newline = %d\r\n", blank, tab, newline);
    return 0;
}

static i32 excerise_1_9()
{
    i32 c = 0, buffer = 0;
    while((c = getchar()) != EOF)
    {
        if (' '== c && ' '==buffer)
            continue;

        putchar(c);
        buffer = c;
    }

    return 0;
}

static i32 excerise_1_10()
{
    i32 blank = 0, tab = 0, newline = 0;
    i32 c = 0;
    while((c = getchar()) != EOF)
    {
        if ('\t' == c)
            printf("\t");
        else if ('\b' == c)
            printf("\b");
        else if ('\\' == c)
            printf("\\");
    }
    return 0;
}

/*test mothed : open txtfile, statistic*/
static i32 excerise_1_11()
{
    int c, nl, nw, nc, state;

    state = OUT;
    c = nl = nw = nc = 0;

    while((c = getchar()) != EOF)
    {
        ++nc;
        if ('\n' == c)
            ++nl;
        /* uncover possible punctuation */
        if (' ' == c || '\n' == c || '\t' == c || ',' == c || '.' == c || ':' == c ) /*and so on */
            state = OUT;
        else if (OUT == state)
        {
            state = IN;
            ++nw;
        }
    }
    printf("###INFO: line = %d, word = %d, character = %d \r\n", nl, nw, nc);
}

static i32 excerise_1_12()
{
    int c, nl, nw, nc, state;

    state = OUT;
    c = nl = nw = nc = 0;

    while((c = getchar()) != EOF)
    {
        /* uncover possible punctuation and so on */
        if (' ' == c || '\n' == c || '\t' == c || ',' == c || '.' == c || ':' == c )
            printf("\r\n");
        else
            putchar(c);
    }
    return 0;
}

struct Histogram
{
    u32 count;
    u8 word_len;
};

#define MAX_WORLD_LEN 10

static i32 excerise_1_13()
{
    u8 row = 0 , column = 0;
    i32 c = 0 ;
    u8 word_len = 0;
    u32 max_count = 0;

    struct Histogram histogram[MAX_WORLD_LEN];

    memset(histogram, 0x00, MAX_WORLD_LEN * sizeof(struct Histogram));

    for(row = 0; row < MAX_WORLD_LEN; row++)
        histogram[row].word_len = row;

    /*get input data*/
    while((c = getchar()) != EOF)
    {
        if (word_len >= MAX_WORLD_LEN)
            word_len = 0;/*reset */

        if ((' ' == c || '\n' == c || '\t' == c || ',' == c || '.' == c || ':' == c ))
        {
            histogram[word_len].count += 1;
            /*save max word , use for draw ordinate */
            max_count = histogram[word_len].count  > max_count ? histogram[word_len].count: max_count;
            word_len = 0;/*reset*/
            continue;
        }
        word_len++;
    }

    histogram[0].count = 0;


    /*draw Histogram*/
    printf("word_count\r\n");
    for(row = 0; row < max_count; row++)
    {
        printf("%d |", max_count - row);
        for(column = 1 ; column < MAX_WORLD_LEN; column++)
        {
            if(histogram[column].count >= max_count-row)
                printf("  *");
            else
                printf("   ");
        }
        printf("\r\n");
    }
    /*draw  horizontal axis*/
    printf("   ");
    for(column = 1; column < MAX_WORLD_LEN; column++)
        printf("___");

    printf("  word len\r\n");

    for(column = 0; column < MAX_WORLD_LEN; column++)
        printf("  %d", column);

    return 0;
}


#define MAX_CHARACTERS_LEN 128

static i32 excerise_1_14()
{
    u8 row = 0 , column = 0;
    i32 c = 0 ;
    u8 word_len = 0;
    u32 max_count = 0;

    struct Histogram histogram[MAX_CHARACTERS_LEN];

    memset(histogram, 0x00, MAX_CHARACTERS_LEN * sizeof(struct Histogram));

    for(row = 0; row < MAX_CHARACTERS_LEN; row++)
        histogram[row].word_len = row;

    /*get input data*/
    while((c = getchar()) != EOF)
    {
        histogram[c].count += 1;
        /*save max word , use for draw ordinate */
        max_count = histogram[c].count  > max_count ? histogram[c].count: max_count;
    }

    histogram[0].count = 0;


    /*draw Histogram*/
    printf("character_count\r\n");
    for(row = 0; row < max_count; row++)
    {
        printf("%d |", max_count - row);
        for(column = 1 ; column < MAX_CHARACTERS_LEN; column++)
        {
            if(histogram[column].count >= max_count-row)
                printf("  *");
            else
                printf("   ");
        }
        printf("\r\n");
    }
    /*draw  horizontal axis*/
    printf("   ");
    for(column = 1; column < MAX_CHARACTERS_LEN; column++)
        printf("___");

    printf("  character_len\r\n");

    for(column = 0; column < MAX_CHARACTERS_LEN; column++)
        printf("  %d", column);

    return 0;
}

static i32 excerise_1_15(const i32 nlower, const i32 nupper, const i32 nstep)
{
    float fahr = 0, celsius = 0;
    i32 lower = nlower, upper = nupper, step = nstep;

    fahr = upper;
    printf("\r\nTable Fahr  Celsius\r\n");
    while(fahr >= 0)
    {
        celsius =(5.0/9.0)*(fahr - 32);
        printf("%3.0f, %6.0f\r\n" , fahr, celsius);
        fahr = fahr - step;
    }

    return 0;
}

static int excerise_1_16_getline(char *s, const i32 lim)
{
    i32 c = 0, i = 0;
    if (NULL == s)
        return 0;

    /*for safe: i < lim -1*/
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';/*the null character, whose value is zero*/
    return i;
}

static i32 excerise_1_16()
{
    i32 ret = 0;
    i32 len = 0, max = 0;

#define MAX_LINE 1000
    char line[MAX_LINE] = {0,};
    char longest[MAX_LINE] = {0,};

    while ((len = excerise_1_16_getline(line, MAX_LINE)) > 0)
    {
        printf("%s\r\n", line);
    }

    return 0;
}

static i32 excerise_1_17()
{
    i32 ret = 0;
    i32 len = 0, max = 0;

#define MAX_LINE 1000
    char line[MAX_LINE] = {0,};
    char longest[MAX_LINE] = {0,};

    while ((len = excerise_1_16_getline(line, MAX_LINE)) > 0)
    {
        if(len > 80)
            printf("%s\r\n", line);
        len = 0;
    }

    return 0;
}

static int excerise_1_18_getline(char *s, const i32 lim)
{
    i32 c = 0, i = 0;
    if (NULL == s)
        return 0;

    /*for safe: i < lim -1*/
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if(c == ' ' || c == '\t')
        {
            i--;
            continue;
        }
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';/*the null character, whose value is zero*/
    return i;
}


static i32 excerise_1_18()
{
    i32 ret = 0;
    i32 len = 0, max = 0;

#define MAX_LINE 1000
    char line[MAX_LINE] = {0,};
    char longest[MAX_LINE] = {0,};

    while ((len = excerise_1_18_getline(line, MAX_LINE)) > 0)
    {
        if(len != 0)
            printf("%s\r\n", line);
        len = 0;
    }

    return 0;
}


static int excerise_1_19_getline(char *s, const i32 lim)
{
    i32 c = 0, i = 0;
    if (NULL == s)
        return 0;

    /*for safe: i < lim -1*/
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';/*the null character, whose value is zero*/
    return i;
}

static i32 excerise_1_19()
{
    i32 ret = 0;
    i32 len = 0, index = 0;

#define MAX_LINE 1000
    char line[MAX_LINE] = {0,};
    char longest[MAX_LINE] = {0,};

    while ((len = excerise_1_18_getline(line, MAX_LINE)) > 0)
    {
        /*just print reverse*/
        while(len--)
            putchar(line[len]);
        printf("\r\n");
    }

    return 0;
}

i32 main()
{
    PDEBUG();

#ifdef SHOW_PASS
    excerise_1_1();
    excerise_1_2();
    excerise_1_3();
    excerise_1_4();
    excerise_1_5();
    excerise_1_6();
    excerise_1_7();
    excerise_1_8();
    excerise_1_9();
    excerise_1_10();
    excerise_1_11();
    excerise_1_12();
    excerise_1_13();
    excerise_1_14();
    excerise_1_15(0, 300, 20);
    excerise_1_16();
    excerise_1_17();
    excerise_1_18();

#endif

    excerise_1_19();
    return 0;
}

