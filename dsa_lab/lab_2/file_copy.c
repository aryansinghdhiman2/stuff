#include <stdio.h>

int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        fprintf(stdout,"Not enough Parameters");
    }
    FILE* input_file=fopen(argv[1],"r");
    if(input_file==NULL)
    {
        printf("Could not open input file\n");
        return -1;
    }

    FILE* output_file=fopen(argv[2],"w");
    if(output_file==NULL)
    {
        printf("Could not open output file\n");
        fclose(input_file);
        return 1;
    }

    int num;
    fscanf(input_file,"%d",&num);
    fprintf(output_file,"%d",num);

    fclose(input_file);
    fclose(output_file);
}