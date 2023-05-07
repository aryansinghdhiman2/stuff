#include <iostream>
#include <thread>
#include <memory>
#include <vector>
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

vector<unique_ptr<semaphore>> chopsticks;
unique_ptr<int> numberOfSpoonfuls;

void philospher(int waitTime,int sleepTime,int i){
    int spoonful = *numberOfSpoonfuls;
    string line1 = "Philospher "+to_string(i)+" is eating\n";
    string line2 = "Philospher "+to_string(i)+" is thinking\n";
    while(spoonful>0){
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
        chopsticks.at(i)->wait(waitTime);
        chopsticks.at((i+1)%5)->wait(waitTime);
        string line = "Philospher "+to_string(i)+" is eating\n";
        cout<<line1;
        spoonful--;
        chopsticks.at(i)->signal();
        chopsticks.at((i+1)%5)->signal();
        cout<<line2;
    }
}

int main(){
    cout<<"Enter Number of Philosphers: ";
    int numberOfPhil;
    cin>>numberOfPhil;
    
    cout<<"Enter number of spoonfuls needed to finish meal: ";
    int spoon;
    cin>>spoon;
    numberOfSpoonfuls=make_unique<int>(spoon);
    int sleeptime = 500;
    int waitTime = 200;
    for(int i=0;i<numberOfPhil;i++){
        chopsticks.push_back(make_unique<semaphore>(1));
    }
    for(int i=0;i<numberOfPhil;i++){
        thread phil(philospher,waitTime,sleeptime,i);
        // sleeptime-=10;
        phil.detach();
    }
    for(;;){}
}