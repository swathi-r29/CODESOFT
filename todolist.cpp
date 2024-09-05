#include<iostream>
#include<string>
using namespace std;

const int maxtasks = 200;

class task {
public:
    string description;
    bool isCompleted;
};

void addTask(task tasks[], int &taskCount) {
    if (taskCount < maxtasks) {
        cin.ignore(); 
        cout << "Enter the task description: ";
        getline(cin, tasks[taskCount].description);
        tasks[taskCount].isCompleted = false;
        taskCount++;
    } else {
        cout << "Task list is full!\n";
    }
}

void viewTasks(task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available\n";
    } else {
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                cout << " [Completed]\n";
            } else {
                cout << " [Pending]\n";
            }
        }
    }
}

void markTaskAsCompleted(task tasks[], int taskCount) {
    int taskNo;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNo;
    if (taskNo > 0 && taskNo <= taskCount) {
        tasks[taskNo - 1].isCompleted = true;
        cout << "Task marked as completed\n";
    } else {
        cout << "Invalid task number\n";
    }
}

void removeTask(task tasks[], int &taskCount) {
    int taskNo;
    cout << "Enter the task number to remove: ";
    cin >> taskNo;
    if (taskNo > 0 && taskNo <= taskCount) {
        for (int i = taskNo - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number\n";
    }
}

int main() {
    task tasks[maxtasks];
    int taskCount = 0;
    int ch;

    do {
        cout << "To-Do List Managing\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskAsCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (ch != 5);

    return 0;
}
