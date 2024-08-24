#include <iostream>
#include <thread>
#include <memory>
#include <string>
using namespace std;

struct semaphore{
    int s;
    public:
    semaphore(int a):s(a){}
    void signal(){
        s++;
    }
    void wait(int waitTime){
        while(s<=0){
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
        s--;
    }
    void wait(int waitTime,string waiter){
        string line = waiter+" is waiting\n";
        while(s<=0){
            cout<<line;
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
        s--;
    }
};


unique_ptr<semaphore> mutex;
unique_ptr<semaphore> rw_mutex;
unique_ptr<int> read_count;
unique_ptr<int> numberOfItems;

void reader(int waitTime,int readTime,int i){
    int numberOfItemsToRead = *numberOfItems;
    string line = "Reader "+to_string(i)+" is reading\n";
    while(numberOfItemsToRead>0){
        mutex->wait(waitTime);
        (*read_count)++;
        if((*read_count)==1){
            rw_mutex->wait(waitTime);
        }
        mutex->signal();
        cout<<line;
        numberOfItemsToRead--;
        mutex->wait(waitTime);
        (*read_count)--;
        if(*(read_count)==0){
            rw_mutex->signal();
        }
        mutex->signal();
        this_thread::sleep_for(chrono::milliseconds(readTime));
    }
}

void writer(int waitTime,int writeTime){
    int numberOfItemsToWrite = *numberOfItems;
    while(numberOfItemsToWrite>0){
        rw_mutex->wait(waitTime);
        cout<<"Writer is writing"<<endl;
        numberOfItemsToWrite--;
        rw_mutex->signal();
        this_thread::sleep_for(chrono::milliseconds(writeTime));
    }
}

int main(){
    mutex = make_unique<semaphore>(1);
    rw_mutex = make_unique<semaphore>(1);
    read_count = make_unique<int>(0);

    cout<<"Enter Number of Items: ";
    int n;
    cin>>n;
    numberOfItems = make_unique<int>(n);

    cout<<"Enter Number of Readers: ";
    int numOfRead;
    cin>>numOfRead;
       
    int wTime=500;
    int rTime=500;
    int waitTime=100;
    thread writerThread(writer,waitTime,wTime);
    writerThread.detach();
    for(int i=0;i<numOfRead;i++){
        thread readerThread=thread(reader,waitTime,rTime,i);
        readerThread.detach();
    }

    for(;;){}
}