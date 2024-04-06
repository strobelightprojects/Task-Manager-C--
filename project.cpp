#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void add(vector<Task>& tasks);
void remove(vector<Task>& tasks);
void view(const vector<Task>& tasks);
void save(const vector<Task>& tasks);
void load(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    load(tasks); // Load tasks from file

    char choice;
    do {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                add(tasks);
                break;
            case '2':
                remove(tasks);
                break;
            case '3':
                view(tasks);
                break;
            case '4':
                save(tasks); // Save tasks to file
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while(choice!= '4');

    return 0;
}

void add(vector<Task>& tasks) {
    Task new_task;
    cout << "Enter task description: ";
    getline(cin, new_task.description);
    new_task.completed = false;
    tasks.push_back(new_task);
    cout << "Task added." << endl;
}

void remove(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int index;
    cout << "Enter task index to remove (1-" << tasks.size() << "): ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task index." << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed." << endl;
}

void view(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (Completed)";
        }
        cout << endl;
    }
}

void save(const vector<Task>& tasks) {
    ofstream out_file("tasks.txt");
    if (!out_file) {
        cout << "Error: Unable to save tasks to file." << endl;
        return;
    }

    for (const Task& t : tasks) {
        out_file << t.description << "," << t.completed << endl;
    }

    out_file.close();
    cout << "Tasks saved to file." << endl;
}

void load(vector<Task>& tasks) {
    ifstream in_file("tasks.txt");
    if (!in_file) {
        cout << "No saved tasks found." << endl;
        return;
    }

    tasks.clear(); // Clear existing tasks

    string line;
    while (getline(in_file, line)) {
        size_t pos = line.find(',');
        if (pos!= string::npos) {
            Task t;
            t.description = line.substr(0, pos);
            t.completed = line.substr(pos + 1) == "1";
            tasks.push_back(t);
        }
    }

    in_file.close();
    cout << "Tasks loaded from file." << endl;
}