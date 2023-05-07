pair<vector<int>,int> getInput(){
    cout<<"Enter Last Cylinder Number: ";
    int lastCylinderNumber;
    cin>>lastCylinderNumber;

    cout<<"Enter Number of disk requests: ";
    int n;
    cin>>n;
    vector<int> diskQueue;
    while(n>0){
        int temp;
        cout<<"Enter Request: ";
        cin>>temp;
        if(temp<0 or temp>lastCylinderNumber){
            cout<<"Invalid, enter again\n";
            continue;
        }
        diskQueue.push_back(temp);
        n--;
    }
    bool correctInput = false;
    int seekHeadPos=0;
    while(not correctInput){
        cout<<"Enter Head Starting Position: ";
        cin>>seekHeadPos;
        if(seekHeadPos<0 or seekHeadPos>lastCylinderNumber) continue;
        else correctInput=true;
    }
    return pair(diskQueue,seekHeadPos);
}