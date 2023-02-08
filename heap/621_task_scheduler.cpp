//
// Created by yunfei on 06/11/2022.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m) {
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

template<typename V>
void print_queue(priority_queue<V> const &q) {
    priority_queue<pair<int, char>> nq = q;
    while (!nq.empty()) {
        cout << "(" << nq.top().second <<", "<<nq.top().first<<")"<<endl;
        nq.pop();
    }
    cout << '\n';
}

template<typename V>
void print_vector(vector<V> const &v) {
    cout << "[";
    for (auto i: v) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

int leastInterval(vector<char>& tasks, int n) {
    int time = 0;
    unordered_map<char, int> count;
    priority_queue<pair<int, char>> heap;
    queue<pair<pair<int, char>, int>> cooldown_queue;
    vector<string> order;
    pair<int, char> run_task;

    // count task frequences
    for(auto &task:tasks) {
        if(count.find(task) == count.end()) {
            count[task] = 1;
        } else {
            count[task]++;
        }
    }
    
    // add (key, frequence) in heap
    for (auto const &p: count) {
        heap.push(pair<int, char>(p.second, p.first));
    }

    run_task = heap.top();

    // print_queue(heap);
    while(!heap.empty() || !cooldown_queue.empty()) {
        time++;
        // select task and push it to the waiting queue
        if(heap.empty()) {
            order.push_back("idle");
        }else {
            run_task = heap.top();
            heap.pop();
            run_task.first--;
            if(run_task.first > 0) {
                cooldown_queue.push(pair<pair<int, char>, int   >(run_task, time+n));
            }
            string task_name(1, run_task.second);
            order.push_back(task_name);
        }

        // get available task from waiting queue and push it back to the heap
        if(!cooldown_queue.empty() && cooldown_queue.front().second == time) {
            heap.push(cooldown_queue.front().first);
            cooldown_queue.pop();
        }
    }
    print_vector(order);
    return time;
}

int main() {
    //vector<char> tasks{'A', 'A', 'B', 'B', 'C'};
    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    leastInterval(tasks, 2);
    return 0;
}