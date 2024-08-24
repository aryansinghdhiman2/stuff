class Solution {
public:
    int myAtoi(string s) {
        int converted=0;
        int pow_10=0;
        bool positive = true;
        auto start_itr = s.begin();
        bool start_found = false;
        bool sign_char_found = false;
        auto end_itr = s.begin();
        for(auto itr = s.begin();itr!=s.end();itr++)
        {
            if(*itr == ' ' && !start_found && !sign_char_found) continue;
            else if(*itr == '+' && !sign_char_found) 
            {
                positive = true;
                sign_char_found = true;
            }
            else if(*itr == '-' && !sign_char_found) 
            {
                positive = false;
                sign_char_found = true;
            }
            else if(isdigit(*itr))
            {
                if(!start_found)
                {
                    start_itr = itr;
                    start_found = true;
                    sign_char_found = true; //Implicit positive 
                }
                end_itr=itr;
            }
            else break;
        }

        double increment = 0;
        bool converted_to_int_min = false;
        while(end_itr - start_itr >= 0 && start_found)
        {

            increment = int(*end_itr - '0') * pow(10,pow_10);
            if(positive && (INT_MAX - converted) <=  increment)
            {
                converted = INT_MAX;
                break;
            }
            else if(!positive && (converted + INT_MIN) >= -increment )
            {
                converted = INT_MIN;
                converted_to_int_min = true;
                break;
            }
            converted += increment;
            pow_10++;
            end_itr--;
        }

        if(!positive && !converted_to_int_min) converted = -converted;
        return converted;
    }
};