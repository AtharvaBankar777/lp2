#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
};

bool compareArrivalTime(const Job& j1, const Job& j2) {
    return j1.arrival_time < j2.arrival_time;
}

void scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareArrivalTime);

    int current_time = 0;
    for (int i = 0; i < jobs.size(); ++i) {
        if (jobs[i].arrival_time > current_time) {
            current_time = jobs[i].arrival_time;
        }

        jobs[i].completion_time = current_time + jobs[i].burst_time;
        current_time = jobs[i].completion_time;
    }
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time and burst time for job " << i + 1 << ": ";
        cin >> jobs[i].arrival_time >> jobs[i].burst_time;
        jobs[i].id = i + 1;
    }

    scheduleJobs(jobs);

    cout << "Job\tArrival Time\tBurst Time\tCompletion Time\n";
    for (int i = 0; i < n; ++i) {
        cout << jobs[i].id << "\t" << jobs[i].arrival_time << "\t\t" << jobs[i].burst_time << "\t\t" << jobs[i].completion_time << "\n";
    }

    return 0;
}
