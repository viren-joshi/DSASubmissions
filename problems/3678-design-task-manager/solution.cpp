class TaskManager {
public:

    // userId, taskId, priority
    priority_queue<pair<int,int>> userTasks;
    map<int,int> taskPriority;
    map<int,int> taskOwner;
    

    TaskManager(vector<vector<int>>& tasks) {
        for(auto task: tasks) {
            userTasks.push({task[2], task[1]});
            taskPriority[task[1]] = task[2];
            taskOwner[task[1]] = task[0]; 
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userTasks.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        userTasks.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskOwner[taskId] = -1;
        taskPriority[taskId] = -1;
    }
    
    int execTop() {
        if(userTasks.empty()) {
            return -1;
        }

        auto [priority, taskId] = userTasks.top();
        userTasks.pop();
        if(taskPriority[taskId] == -1) {
            return execTop();
        }
        if(taskPriority[taskId] != priority) {
            return execTop();
        } else {
            taskPriority[taskId] = -1;
            return taskOwner[taskId];
        }
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
