#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    for(int i=0;a[i]!='\0' || b[i]!='\0';i++)
    {
    if(a[i]>b[i])
    {
        return 1;
    }
    else if(a[i]<b[i])
    {
        return 0;
    }
    }
    return 0;

}

int lexicographic_sort_reverse(const char* a, const char* b) {
    for(int i=0;a[i]!='\0' || b[i]!='\0';i++)
    {
        if(a[i]<b[i])
        {
            return 1;
        }
        else if(a[i]>b[i])
        {
            return 0;
        }
    }
    return 0;

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i=0;
    for(i=0;;i++)
    {
        if(a[i]=='\0')
            break;
    }
    _Bool *counter_for_a;
    counter_for_a=(_Bool*)calloc(i,sizeof(int));
    _Bool *checker_for_repeated_elements_of_a;
    checker_for_repeated_elements_of_a=(_Bool*)calloc(i,sizeof(_Bool));
    int j,k;
    for(j=0;a[j]!='\0';j++)
    {
        if(!checker_for_repeated_elements_of_a[j])
            for(k=0;a[k]!='\0';k++)
            {
                if(a[j]==a[k])
                {
                    counter_for_a[j]=1;
                    if(!checker_for_repeated_elements_of_a[k])
                        checker_for_repeated_elements_of_a[k]=1;
                }
            }
    }
    int distinct_elements_in_a=0;
    for(int t=0;t<i;t++)
    {
        distinct_elements_in_a=distinct_elements_in_a+counter_for_a[t];
    }
    /*******************************************************/
    for(i=0;;i++)
    {
        if(b[i]=='\0')
            break;
    }
    _Bool *counter_for_b;
    counter_for_b=(_Bool*)calloc(i,sizeof(int));
    _Bool *checker_for_repeated_elements_of_b;
    checker_for_repeated_elements_of_b=(_Bool*)calloc(i,sizeof(_Bool));
    for(j=0;b[j]!='\0';j++)
    {
        if(!checker_for_repeated_elements_of_b[j])
            for(k=0;b[k]!='\0';k++)
            {
                if(b[j]==b[k])
                {
                    counter_for_b[j]=1;
                    if(!checker_for_repeated_elements_of_b[k])
                        checker_for_repeated_elements_of_b[k]=1;
                }
            }
    }
    int distinct_elements_in_b=0;
    for(int t=0;t<i;t++)
    {
        distinct_elements_in_b=distinct_elements_in_b+counter_for_b[t];
    }
    /************************************************************/
    if(distinct_elements_in_a>distinct_elements_in_b)
    {
        return 1;
    }
    else if(distinct_elements_in_b==distinct_elements_in_a)
    {
        return lexicographic_sort(a,b);
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {

    int length_of_a=0,i;
    for(i=0;;i++)
    {
        if(a[i]=='\0')
            break;
    }
    length_of_a=i;

    int length_of_b=0;
    for(i=0;;i++)
    {
        if(b[i]=='\0')
            break;
    }
    length_of_b=i;
    if(length_of_a>length_of_b)
    {
        return 1;
    }
    else if(length_of_a==length_of_b)
    {
        return lexicographic_sort(a,b);
    }
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i,j;
    char *c=NULL;
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            if(i==j)
                continue;
        else if((*cmp_func)(*(arr+i),*(arr+j)))
                {
                    c=*(arr+i);
                    *(arr+i)=*(arr+j);
                    *(arr+j)=c;
                }
        }
    }

}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
