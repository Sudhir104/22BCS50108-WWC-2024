#include <iostream>
#include <cstring>
using namespace std;

const int MAX_PATIENTS = 10000;

struct Patient {
    char name[50];
    int triagePriority;
    int severity;
    long long arrivalTime;
};

bool comparePatients(const Patient& a, const Patient& b) {
    if (a.triagePriority != b.triagePriority) return a.triagePriority > b.triagePriority;
    if (a.severity != b.severity) return a.severity > b.severity;
    return a.arrivalTime < b.arrivalTime;
}

void sortPatients(Patient patients[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!comparePatients(patients[j], patients[j + 1])) {
                swap(patients[j], patients[j + 1]);
            }
        }
    }
}

int main() {
    Patient patients[MAX_PATIENTS];
    int n;

    cout << "Enter number of patients (max  " << MAX_PATIENTS << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_PATIENTS) {
        cout << "Invalid number of patients." << endl;
        return 1;
    }

    cout << "Enter patient details (name triagePriority severity arrivalTime):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> patients[i].name >> patients[i].triagePriority >> patients[i].severity >> patients[i].arrivalTime;
    }

    sortPatients(patients, n);

    cout << "Sorted Patients:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << patients[i].name << " " << patients[i].triagePriority << " " << patients[i].severity << " " << patients[i].arrivalTime << endl;
    }

    return 0;
}