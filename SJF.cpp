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

bool compareByduration(Process a , Process b)
{
    return a.duration < b.duration;
}

bool compareByarrival(Process a , Process b)
{
    return a.arrival_time < b.arrival_time;
}

int main()
{
    vector < struct Process > process_scheduled;

    while(1){
        cout << "How many process arrived?" << endl;
        int n;
        cin >> n;
        cout << "Input " << n << " process (Seq.No. , ProcessName , Duration , Arrival time)" << endl;
        vector < struct Process > process_arrived(n);
        for(int i = 0 ; i < n ; i++){
            cin >> process_arrived[i].id;
            cin >> process_arrived[i].name;
            cin >> process_arrived[i].duration;
            cin >> process_arrived[i].arrival_time;
        }

        sort(process_arrived.begin() , process_arrived.end() , compareByarrival);

        int ATT = 0;

        for(int i = 0 ; i < process_arrived.size() ;){
            int atime = process_arrived[i].arrival_time;
            vector < struct Process > p;
            p.push_back(process_arrived[i]);
            int j;
            for(j = i+1 ; j < process_arrived.size() ; j++){
                if(atime == process_arrived[j].arrival_time){
                    p.push_back(process_arrived[j]);
                }
                else{
                    break;
                }
            }
            i = j;
            sort(p.begin() , p.end() , compareByduration);
            for(int i = 0 ; i < p.size() ; i++){
                process_scheduled.push_back(p[i]);
            }
        }

        int timeline = 0;
        cout <<"Seq.No.    ProcessName    Timeline    Turnaround" << endl;
        for(int i = 0 ; i < process_scheduled.size() ; i++){
            int current_time = process_scheduled[i].arrival_time;

            cout << i+1 << "    \t\t" << process_scheduled[i].name << "    \t" << timeline << "-" << process_scheduled[i].duration+timeline << "  \t\t" << process_scheduled[i].duration+timeline-process_scheduled[i].arrival_time << endl;
            ATT += process_scheduled[i].duration+timeline-process_scheduled[i].arrival_time;
            timeline = process_scheduled[i].duration+timeline;
        }
        cout << "A.T.T = "  << ATT/process_scheduled.size() << endl;


    }
}

