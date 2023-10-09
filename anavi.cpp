#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

int find_substr(const int length,const string input_str);
bitset<30> concatenate(const bitset<30> first,const int first_length,const bitset<30> second,const int second_length);
void rotate(bitset<30>& b,const int length);


int main()
{
    int length;
    cin>>length;

    string input_str;
    cin>>input_str;

    cout<<find_substr(length,input_str);

}


int find_substr(const int length,const string input_str)
{
    if((int)input_str.length() > length) return 0;
    bitset<30> input(input_str);
    
    if((int)input.to_ulong() > pow(length,2)) return 0;

    int counter = 0;
    const int input_length = (int)input_str.length();
    const int additional_bits_length = length - input_length;
    const int final_bits_length = input_str.length()+additional_bits_length;

    if(additional_bits_length > 0)
    {
        for(int i=0; i < pow(2,additional_bits_length) ;i++)
        {
            bitset<30> additional_bits(i);
            auto final_bits = concatenate(additional_bits,additional_bits_length,input,input_length);
            counter++;
            auto bits = final_bits;
            while(true)
            {
                rotate(bits,final_bits_length);
                if(bits == final_bits) break;
                else counter++;
            }
        }       
    }
    else
    {
        counter++;
        auto bits = input;
        while(true)
        {
            rotate(bits,input_length);
            if(bits == input) break;
            else counter++;
        } 
    }
    return counter;
}

bitset<30> concatenate(const bitset<30> first,const int first_length,const bitset<30> second,const int second_length)
{
    bitset<30> result;
    int result_index;
    for(int i=0;i<second_length;i++)
    {
        if(second.test(i))
        {
            result.set(result_index);
        }
        result_index++;
    }

    for(int i=0;i<first_length;i++)
    {
        if(first.test(i))
        {
            result.set(result_index);
        }
        result_index++;
    }

    return result;
}

void rotate(bitset<30>& b,const int length)
{
    bool temp = b[0];
    for(int i=length-1;i>0;i--)
    {
        bool temp2 = b[i];
        b[i]=temp;
        temp = temp2;
    }
    b[0]=temp;
}