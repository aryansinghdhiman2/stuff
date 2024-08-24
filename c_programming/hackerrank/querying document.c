#include <stdio.h>

char**** get_document(char* text) {
   char**** doc;
   int counter_paragraph=0,g=0;
   for(int i;;i++)
   {
       if((text[i]=='\n') || (text[i]==EOF))
       {
       counter_paragraph++;
       if(text[i]==EOF)
        break;
       }
   }
   doc=calloc(counter_paragraph,sizeof(char***));
   
   int counter_sentence=0;
   for(int i=0;;i++)
   {
       if(text[i]=='.')
       counter_sentence++;
       else if(text[i]==EOF)
       break;
   }
   for(g=0;g<counter_paragraph;g++)
        *(doc+g)=calloc(counter_sentence, sizeof(char**));
   
   int counter_words=0;
   for(int i=0;;i++)
   {
       if((text[i]==' ') || (text[i]=='.'))
       counter_words++;
       else if(text[i]==EOF)
       break;
   }
   for(g=0;g<counter_sentence;g++)
   *(*doc+g)=calloc(counter_words,sizeof(char*));
   
   int counter_characters=0,e=0,temp=0;
   for(g=0,counter_characters=0;;g++)
   {
       if(text[g]==' ' || text[g]='.')
       {
           counter_characters++;
           *(**doc+e)=calloc(counter_characters,sizeof(char));
           for(int u=(temp);u<=counter_characters+temp-1;u++)
           {
               **(**doc+e)=text[u];
           }
           e++;
           temp=temp+counter_characters;
       }
       else if(text[i]==EOF)
        break;
        else
            counter_characters++;
   }

}

int main()
{
    printf("Hello World");

    return 0;
}
