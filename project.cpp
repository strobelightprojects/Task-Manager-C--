#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure
struct Task
{
    string description;
    bool completed;
};

// Function prototypes
void add(vector<Task> &tasks);
void remove(vector<Task> &tasks);
void view(const vector<Task> &tasks);

int main()
{
    vector<Task> tasks;

    char choice;
    // The menu options
    do
    {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != '4');

    return 0;
}

void add(vector<Task> &tasks)
{
    // adding task
    Task new_task;
    cout << "Enter task description: ";
    cin.ignore(); // ignore the newline character
    getline(cin, new_task.description);
    new_task.completed = false;
    tasks.push_back(new_task);
    cout << "Task added." << endl;
}

void remove(vector<Task> &tasks)
{
    // remove task
    if (tasks.empty())
    {
        cout << "No tasks to remove." << endl;
        return;
    }

    int index;
    // selecting task to remove
    cout << "Enter task index to remove (1-" << tasks.size() << "): ";
    cin >> index;

    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task index." << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed." << endl;
}

void view(const vector<Task> &tasks)
{
    // look at the tasks
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed)
        {
            cout << " (Completed)";
        }
        cout << endl;
    }
}
