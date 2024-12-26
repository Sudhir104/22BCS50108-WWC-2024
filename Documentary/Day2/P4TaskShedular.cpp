#include <iostream>
using namespace std;

struct Task {
    int taskID;
    int priority;
    int executionTime;
    Task* next;

    Task(int id, int prio, int execTime) : taskID(id), priority(prio), executionTime(execTime), next(nullptr) {}
};

class TaskScheduler {
private:
    Task* head;

public:
    TaskScheduler() : head(nullptr) {}

    void insertTask(int id, int prio, int execTime) {
        Task* newTask = new Task(id, prio, execTime);
        if (!head || head->priority < prio) {
            newTask->next = head;
            head = newTask;
        } else {
            Task* current = head;
            while (current->next && current->next->priority >= prio) {
                current = current->next;
            }
            newTask->next = current->next;
            current->next = newTask;
        }
    }

    void completeTask() {
        if (!head) return;
        Task* temp = head;
        head = head->next;
        delete temp;
    }

    void preemptTask(int id, int prio, int execTime) {
        completeTask();
        insertTask(id, prio, execTime);
    }

    void displayTasks() {
        Task* current = head;
        while (current) {
            cout << "Task ID: " << current->taskID << ", Priority: " << current->priority << ", Execution Time: " << current->executionTime << endl;
            current = current->next;
        }
    }

    ~TaskScheduler() {
        while (head) {
            completeTask();
        }
    }
};

int main() {
    TaskScheduler scheduler;
    scheduler.insertTask(1, 3, 10);
    scheduler.insertTask(2, 1, 5);
    scheduler.insertTask(3, 2, 8);
    scheduler.displayTasks();

    scheduler.preemptTask(4, 4, 6);
    cout << "After preemption:" << endl;
    scheduler.displayTasks();

    scheduler.completeTask();
    cout << "After completing a task:" << endl;
    scheduler.displayTasks();

    return 0;
}