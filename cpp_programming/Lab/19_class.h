
class outer
{
public:
    int number;
    class inner
    {
    public:
        char c;
        void nested_function(outer o)
        {
            c=o.number;
        }

    };
};