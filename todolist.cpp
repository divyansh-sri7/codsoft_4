#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDesc) {
        tasks.emplace_back(Task(taskDesc));
        std::cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " - ";
            if (tasks[i].completed)
                std::cout << "Completed\n";
            else
                std::cout << "Pending\n";
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task number!\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Invalid task number!\n";
        }
    }
};

int main() {
    ToDoList myToDoList;
    int choice;

    do {
        std::cout << "\n==== To-Do List Manager ====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); 
                std::string taskDesc;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDesc);
                myToDoList.addTask(taskDesc);
                break;
            }
            case 2:
                myToDoList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                myToDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                myToDoList.removeTask(taskIndex);
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
