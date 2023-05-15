#include <bits/stdc++.h>
using namespace std;
int allocation[30];
float ext_frag = 0;
int ExtFrag(float blocks[30], int num_blocks)
{
    for (int i = 0; i < num_blocks; i++)
        ext_frag += blocks[i];
    return ext_frag;
}
int FF(float blocks[30], float process[30], int num_blocks, int num_process)
{
    for (int i = 0; i < num_process; i++)
    {
        for (int j = 0; j < num_blocks; j++)
        {
            if (blocks[j] >= process[i])
            {
                allocation[i] = j;
                blocks[j] -= process[i];
                break;
            }
            else
                allocation[i] = -1;
        }
    }
    // print(num_process, process);
    return (ExtFrag(blocks, num_blocks));
}
int BF(float blocks[30], float process[30], int num_blocks, int num_process)
{
    for (int i = 0; i < num_process; i++)
        allocation[i] = -1;
    for (int i = 0; i < num_process; i++)
    {
        int index = -1;
        for (int j = 0; j < num_blocks; j++)
        {
            if (blocks[j] >= process[i])
            {
                if (index == -1)
                    index = j;
                else if (blocks[index] > blocks[j])
                    index = j;
            }
        }
        if (index != -1)
        {
            allocation[i] = index;
            blocks[index] -= process[i];
        }
        else
            allocation[i] = -1;
    }
    return (ExtFrag(blocks, num_blocks));
}
int WF(float blocks[30], float process[30], int num_blocks, int num_process)
{
    for (int i = 0; i < num_process; i++)
        allocation[i] = -1;
    for (int i = 0; i < num_process; i++)
    {
        int index = -1;
        for (int j = 0; j < num_blocks; j++)
        {
            if (blocks[j] >= process[i])
                {
                    if (index == -1)
                        index = j;
                    else if (blocks[index] < blocks[j])
                        index = j;
                }
        }
        if (index != -1)
        {
            allocation[i] = index;
            blocks[index] -= process[i];
        }
        else
            allocation[i] = -1;
    }
    return (ExtFrag(blocks, num_blocks));
}
void print(int num_process, float process[30])
{
    int i;
    cout << endl
         << "Process No. \t Process Size \t Block No." << endl;
    for (i = 0; i < num_process; i++)
    {
        cout << i + 1 << "\t \t" << process[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
            cout << endl;
        }
        else
        {
            cout << "Not Allocated";
            cout << endl;
        }
    }
}
int main()
{
    int num_blocks, num_process;
    float blocks[30], process[30];
    cout << endl
         << "Enter number of blocks: ";
    cin >> num_blocks;
    cout << endl
         << "Enter the size of " << num_blocks << " blocks: ";
    for (int i = 0; i < num_blocks; i++)
        cin >> blocks[i];
    int choice1;
    char op;
    do
    {
        cout << endl
             << "Choose an option: ";
        cout << endl
             << "1. Add a process";
        cout << endl
             << "2. Remove a process";
        cout << endl
             << "3. Exit";
        cout << endl
             << "Enter your choice: ";
        cin >> choice1;
        switch (choice1)
        {
        // Add process
        case 1:
        {
            cout << endl
                 << "Enter number of processes: ";
            cin >> num_process;
            cout << endl
                 << "Enter the size of " << num_process << " process: ";
            for (int i = 0; i < num_process; i++)
                cin >> process[i];
            int choice;
            cout << endl
                 << "Choose an option:";
            cout << endl
                 << "1. First Fit ";
            cout << endl
                 << "2. Best Fit";
            cout << endl
                 << "3. Worst Fit";
            cout << endl
                 << "Enter the choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                ext_frag = FF(blocks, process, num_blocks, num_process);
            case 2:
                ext_frag = BF(blocks, process, num_blocks, num_process);
                break;
            case 3:
                ext_frag = WF(blocks, process, num_blocks, num_process);
                break;
            default:
                cout << endl
                     << "Invalid choice !!!!";
            }
            print(num_process, process);
            cout << endl
                 << "External Fragmentation: " << ext_frag;
        }
        break;
        // Remove Process
        case 2:
        {
            int block_no;
            int p;
            cout << endl
                 << "Enter the process to be removed: ";
            cin >> p;
            if (allocation[p - 1] == -1)
                cout << endl
                     << "Process already unallocated !!!!";
            else
            {
                block_no = allocation[p - 1];
                blocks[block_no] += process[p - 1];
                ext_frag += process[p - 1];
                allocation[p - 1] = -1;
                cout << endl
                     << "Process Removed from block " << block_no + 1;
                for (int i = 0; i < num_process; i++)
                {
                    if (i != p - 1)
                    {
                        if (allocation[i] == -1)
                        {
                            if (blocks[block_no] >= process[i])
                            {
                                allocation[i] = block_no;
                                blocks[block_no] -= process[i];
                            }
                        }
                    }
                }
                print(num_process, process);
                cout << endl
                     << "External Fragmentation: " << ext_frag;
            }
        }
        break;
        case 3:
            exit(1);
        default:
            cout << endl
                 << "Invalid Choice !!!!";
        }
        cout << endl
             << "Do you want to perform any other function? (y/n): ";
        cin >> op;
    } while (op == 'y');
    return 0;
}
