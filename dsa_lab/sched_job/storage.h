enum priority {PRI_0,PRI_1,PRI_2};

struct Job
{
    int id;
    priority pri;
    int at;
    int et;
};

class JobList
{
    Job j;
    JobList *next;
    JobList *head;
    JobList *previous;

    JobList(){head=next=nullptr;}
    JobList(Job k):j{k},next{nullptr},head{nullptr},previous{nullptr}{}
    JobList* get_next() {return this->next;}
    void set_job(Job k){j=k;}
    // void add_node(Job j)
};