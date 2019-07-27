#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process{
    int id;
    string name;
    int duration;
    int arrival_time;
};

bool compareByArrivalTime(const Process &a, const Process &b)
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

        sort(process_arrived.begin() , process_arrived.end() , compareByArrivalTime);

        int ATT = 0;
        for(int i = 0 ; i < process_arrived.size() ; i++){
            process_scheduled.push_back(process_arrived[i]);
        }

        int timeline = 0;
        cout <<"Seq.No.    ProcessName    Timeline    Turnaround" << endl;
        for(int i = 0 ; i < process_scheduled.size() ; i++){
            int current_time = process_scheduled[i].arrival_time;
            string s = "";
            for(int j = i-1 ; j >= 0 ; j--){
                if(process_scheduled[j].arrival_time == current_time){
                    s += " or " + process_scheduled[j].name;
                }
                else{
                    break;
                }
            }
            for(int j = i+1 ; j <= process_scheduled.size() ; j++){
                if(process_scheduled[j].arrival_time == current_time){
                    s += " or " + process_scheduled[j].name;
                }
                else{
                    break;
                }
            }
            cout << i+1 << "    " << process_scheduled[i].name + s << "    " << timeline << "-" << process_scheduled[i].duration+timeline << "    " << process_scheduled[i].duration+timeline-process_scheduled[i].arrival_time << endl;
            ATT += process_scheduled[i].duration+timeline-process_scheduled[i].arrival_time;
            timeline = process_scheduled[i].duration+timeline;
        }
        cout << "A.T.T = "  << ATT/process_scheduled.size() << endl;


    }
}
