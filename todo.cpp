#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

string toLower(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c){ return tolower(c); });
    return result;
}

struct {
    vector<string> tasks;
    string choice;
} TaskManager;

void addTask(string task) {
    
    if (task.empty()) {
        cout << "Task cannot be empty";
    } else {
        TaskManager.tasks.push_back(task);
        cout << "Task added!\n";
    }
}

void viewTasks() {
    cout << "\n--- Your tasks ---\n";
    if (TaskManager.tasks.empty()) {
        cout << "No tasks yet!\n";
    } else {
        for (string& t: TaskManager.tasks) {
            cout << t << '\n';
        }
    }
}

void deleteTask(int index) {
    
    if (index > 0 && index <= (int)TaskManager.tasks.size()) {
        TaskManager.tasks.erase(TaskManager.tasks.begin() + index - 1);
        cout << "Task removed!\n";
    } else {
        cout << "Invalid number!\n";
    }
}

vector<string> defaultList = {"==== TODO's ====", "1 - Add todo", "2 - View List", "3 - Remove todo", "4 - Exit", "Choice: "};

void performAction(auto choice) {
    if (TaskManager.choice == "1" || lowerChoice.find("add") != std::string::npos) {
        string task;
        cout << "Enter task: ";
        getline(cin, task);

        addTask(task);

    } else if (TaskManager.choice == "2" || lowerChoice.find("view") != std::string::npos) {
        viewTasks();

    } else if (TaskManager.choice == "3" || lowerChoice.find("remove") != std::string::npos || lowerChoice.find("del") != std::string::npos) {
        int index;
        cout << "Enter task number to remove: ";
        cin >> index;

        deleteTask(index);
    }
}

int main() {

    do {

        for (size_t i = 0; i < defaultList.size(); i++) {
            if ( i == 0) {
                cout << "\n" << defaultList[i] << "\n";
            } else if (i == defaultList.size() - 1) {
                cout << defaultList[i];
            } else {
                cout << defaultList[i] << '\n';
            }
        }

        cin >> TaskManager.choice;

        cin.clear(); // clear leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Be sure that cin is totally empty, so even by typing add todo, it will keep the first param as the choice and then will ask the param relative to the task

        string lowerChoice = toLower(TaskManager.choice);

        performAction(lowerChoice);

    } while (TaskManager.choice != "4" && toLower(TaskManager.choice).find("exit") == std::string::npos);

    cout << "Goodbye!\n";
    return 0;
}