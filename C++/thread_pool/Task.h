/**
 * @file Task.h
 * @author angus.li
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 * 任务队列：主要包含两个类：Task和TaskQueue
 *  Task类是任务类，包含CallFunc和void*两个指针成员；
 *  TaskQueue类是任务队列，提供添加任务、取出任务、获取任务个数、线程同步等功能
 */

#ifndef TASK_H_
#define TASK_H_
#include <functional>
#include <mutex>
#include <queue>

using CallFunc = std::function<void(void*)>;
struct Task
{
    Task() {
        function = nullptr;
        args = nullptr;
    }
    Task(CallFunc f, void* arg) : function(f), args(arg) {}
    CallFunc function;
    void* args;
};

class TaskQueue {
public:
    TaskQueue();
    ~TaskQueue();
    // push task
    void pushTask(Task& task);
    void pushTask(CallFunc func, void* arg);

    // pull task
    Task takeTask();

    // 获取当前队列中任务个数
    int taskNumber() { return m_queue.size(); }

private:
    std::mutex mutex;
    std::queue<Task> m_queue;

};



#endif // TASK_H_