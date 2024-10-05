#include <bits/stdc++.h>
using namespace std;

void viewTasks(const vector<string>& tasks, const vector<bool>& completed) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "To-Do List:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i];
        if (completed[i]) {
            cout << " [Completed]";
        } else {
            cout << " [Pending]";
        }
        cout << endl;
    }
}

void addTask(vector<string>& tasks, vector<bool>& completed) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, taskDescription);
    tasks.push_back(taskDescription);
    completed.push_back(false); 
    cout << "Task added successfully!" << endl;
}

void markTaskAsCompleted(vector<bool>& completed, const vector<string>& tasks) {
    viewTasks(tasks, completed);
    if (tasks.empty()) return;

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        completed[taskNumber - 1] = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<string>& tasks, vector<bool>& completed) {
    viewTasks(tasks, completed);
    if (tasks.empty()) return;

    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        completed.erase(completed.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<string> tasks;
    vector<bool> completed; 
    int choice = 0;

    while (choice != 5) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, completed);
                break;
            case 2:
                viewTasks(tasks, completed);
                break;
            case 3:
                markTaskAsCompleted(completed, tasks);
                break;
            case 4:
                removeTask(tasks, completed);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
