#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Process{
    int id;
    string name;
    int duration;
    int arrival_time;
}Process;

int main()
{
    vector < struct Process > process_scheduled;
    vector < int > time;

    cout << "Input the time quantum:" << endl;
    int tq , n;
    cin >> tq;
    cout << "How many Process?" << endl;
    cin >> n;

    cout << "Input " << n << " process (Seq.No. , ProcessName , Duration , Arrival time)" << endl;
    vector < struct Process > process_arrived(n);
    for(int i = 0 ; i < n ; i++){
        cin >> process_arrived[i].id;
        cin >> process_arrived[i].name;
        cin >> process_arrived[i].duration;
        cin >> process_arrived[i].arrival_time;
    }

    int cur_time = 0;
    vector < string > last_process;
    while(1){
        vector < Process > available_process1;
        vector < Process > available_process2;
        for(int i = 0 ; i < n ; i++){
            if(process_arrived[i].arrival_time <= cur_time && process_arrived[i].duration > 0){
                available_process1.push_back(process_arrived[i]);
            }
        }
        int s1 = available_process1.size();
        if(s1 == 0){
            break;
        }
        for(int i = 0 ; i < s1 ; i++){
            int flag = 1;
            for(int j = 0 ; j < last_process.size() ; j++){
                if(available_process1[i].name == last_process[j]){
                    flag = 0;
                    available_process2.push_back(available_process1[i]);
                    break;
                }
            }
        if(flag){
            process_scheduled.push_back(available_process1[i]);
            last_process.push_back(available_process1[i].name);
            if(available_process1[i].duration < tq){
                time.push_back(available_process1[i].duration);
                cur_time += available_process1[i].duration;
                for(int j = 0 ; j < n ; j++){
                    if(available_process1[i].name == process_arrived[j].name){
                        process_arrived[j].duration = 0;
                    }
                }
            }
            else{
                time.push_back(tq);
                cur_time += tq;
                for(int j = 0 ; j < n ; j++){
                    if(available_process1[i].name == process_arrived[j].name){
                        process_arrived[j].duration = process_arrived[j].duration - tq;
                    }
                }
            }
        }
        }
        int s2 = available_process2.size();
        for(int i = 0 ; i < s2 ; i++){
            process_scheduled.push_back(available_process2[i]);
            last_process.push_back(available_process2[i].name);
            if(available_process2[i].duration < tq){
                time.push_back(available_process2[i].duration);
                cur_time += available_process2[i].duration;
                for(int j = 0 ; j < n ; j++){
                    if(available_process2[i].name == process_arrived[j].name){
                        process_arrived[j].duration = 0;
                    }
                }
            }
            else{
                time.push_back(tq);
                cur_time += tq;
                for(int j = 0 ; j < n ; j++){
                    if(available_process2[i].name == process_arrived[j].name){
                        process_arrived[j].duration = process_arrived[j].duration - tq;
                    }
                }
            }
        }

    }
    cout << "\nSeq.No.    Process Name    Timeline " << endl;
    int gap = 0;
    for(int i = 0 ; i < process_scheduled.size() ; i++){
        cout << i+1  << "           " << process_scheduled[i].name  << "                " << gap  << "-" << gap+time[i] << endl;
        gap += time[i];
    }
}
