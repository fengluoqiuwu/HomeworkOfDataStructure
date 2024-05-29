//
// Created by 86133 on 2024/5/23.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "work.h"

void work::doHomework() {
    std::cout<<"emmmmm"<<std::endl;
    homework7_1();
    homework7_2();
    homework7_3();
    homework7_4();
    homework7_5();
    homework7_8();
    homework7_9();
    homework7_10();
}

void work::homework7_1() {
    std::cout<<"### Homework 7.1 ###"<<std::endl<<std::endl;
    std::cout<<"(1)"<<std::endl;
    std::cout<<"0 0 0 0 0 0"<<std::endl;
    std::cout<<"1 0 0 1 0 0"<<std::endl;
    std::cout<<"0 1 0 0 0 1"<<std::endl;
    std::cout<<"0 0 1 0 1 1"<<std::endl;
    std::cout<<"1 0 0 0 0 0"<<std::endl;
    std::cout<<"1 1 0 0 1 0"<<std::endl;
    std::cout<<"(2)"<<std::endl;
    std::cout<<"1: []\n"
               "2: [1, 4]\n"
               "3: [2, 6]\n"
               "4: [3, 5, 6]\n"
               "5: [1]\n"
               "6: [1, 2, 5]"<<std::endl;
    std::cout<<"(3)"<<std::endl;
    std::cout<<"1: [2, 5, 6]\n"
               "2: [3, 6]\n"
               "3: [4]\n"
               "4: [2]\n"
               "5: [4, 6]\n"
               "6: [3, 4]"<<std::endl;
    std::cout<<"(4)"<<std::endl;
    std::cout<<"[1]\n"
               "[2,3,4,6]\n"
               "[5]"<<std::endl;
    std::cout<<std::endl;
}

void work::homework7_2() {
    std::cout<<"### Homework 7.2 ###"<<std::endl<<std::endl;
    std::cout<<"(1)DFS"<<std::endl;
    std::cout<<"1 - 7 - 3 - 4 - 5 - 6 - 2 - 8 - 9 - 10"<<std::endl;
    std::cout<<"1 - 7 - 3 - 4 - 5 - 6 - 2\n"
               "3 - 8 - 9 - 10"<<std::endl;
    std::cout<<"(2)BFS"<<std::endl;
    std::cout<<"1 - 7 - 9 - 3 - 8 - 4 - 5 - 6 - 10 - 2"<<std::endl;
    std::cout<<"1 - 7 - 3 - 4\n"
               "3 - 8\n"
               "7 - 10 - 9\n"
               "9 - 5 - 6"<<std::endl;
    std::cout<<std::endl;
}

void work::homework7_3() {
    std::cout<<"### Homework 7.3 ###"<<std::endl<<std::endl;
    std::cout<<"(1)"<<std::endl;
    std::cout<<"  A B C D E F G H\n"
               "A 0 4 3 0 0 0 0 0\n"
               "B 4 0 5 5 9 0 0 0\n"
               "C 3 5 0 5 0 0 0 5\n"
               "D 0 5 5 0 7 6 5 4\n"
               "E 0 9 0 7 0 3 0 0\n"
               "F 0 0 0 6 3 0 2 0\n"
               "G 0 0 0 5 0 2 0 6\n"
               "H 0 0 5 4 0 0 6 0\n"
               "0 is infinite"<<std::endl;
    std::cout<<"A - B\n"
               "A - C - D - H\n"
               "D - G - F - E"<<std::endl;
    std::cout<<"(2)"<<std::endl;
    std::cout<<"A:[B4,C3]\n"
               "B:[A4,C5,D5,E9]\n"
               "C:[A3,B5,D5,H5]\n"
               "D:[B5,C5,E7,F6,G5,H4]\n"
               "E:[B9,D7,F3]\n"
               "F:[D6,E3,G2]\n"
               "G:[D5,F2,H6]\n"
               "H:[C5,D4,G6]"<<std::endl;
    std::cout<<"A - B\n"
               "A - C - D - H\n"
               "D - G - F - E"<<std::endl;
    std::cout<<std::endl;
}

void work::homework7_4() {
    std::cout<<"### Homework 7.4 ###"<<std::endl<<std::endl;
    std::cout<<"1 - 5 - 6 - 2 - 3 - 4\n"
               "5 - 1 - 6 - 2 - 3 - 4\n"
               "5 - 6 - 1 - 2 - 3 - 4"<<std::endl;
    std::cout<<std::endl;
}

void work::homework7_5() {
    std::cout<<"### Homework 7.5 ###"<<std::endl<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 0 2  [A,C]\n"
               "D 0 12 [A,D]\n"
               "E 0 -  []\n"
               "F 0 -  []\n"
               "G 0 -  []\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 0 12 [A,D]\n"
               "E 0 10 [A,C,E]\n"
               "F 0 6  [A,C,F]\n"
               "G 0 -  []\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 0 11 [A,C,F,D]\n"
               "E 0 10 [A,C,E]\n"
               "F 1 6  [A,C,F]\n"
               "G 0 16 [A,C,F,G]\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 0 11 [A,C,F,D]\n"
               "E 1 10 [A,C,E]\n"
               "F 1 6  [A,C,F]\n"
               "G 0 16 [A,C,F,G]\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 1 11 [A,C,F,D]\n"
               "E 1 10 [A,C,E]\n"
               "F 1 6  [A,C,F]\n"
               "G 0 13 [A,C,F,D,G]\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 0 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 1 11 [A,C,F,D]\n"
               "E 1 10 [A,C,E]\n"
               "F 1 6  [A,C,F]\n"
               "G 1 13 [A,C,F,D,G]\n"<<std::endl;
    std::cout<<"  S D  P\n"
               "A 1 0  [A]\n"
               "B 1 15 [A,B]\n"
               "C 1 2  [A,C]\n"
               "D 1 11 [A,C,F,D]\n"
               "E 1 10 [A,C,E]\n"
               "F 1 6  [A,C,F]\n"
               "G 1 13 [A,C,F,D,G]\n"<<std::endl;
    std::cout<<std::endl;
}

// 计算有向图中每个顶点的入度
void computeInDegrees(const std::vector<std::vector<int>>& adj, std::vector<int>& inDegrees) {
    int n = adj.size();
    inDegrees.assign(n, 0); // 初始化入度数组，大小为n，值全为0

    // 遍历邻接表
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            int target = adj[i][j];
            inDegrees[target]++; // 增加目标顶点的入度
        }
    }
}

void work::homework7_8() {
    std::cout<<"### Homework 7.8 ###"<<std::endl<<std::endl;
// 示例有向图，使用邻接表表示
    std::vector<std::vector<int>> adj = {
            {1, 2},    // 顶点 0 指向 顶点 1 和 顶点 2
            {2},       // 顶点 1 指向 顶点 2
            {0, 3},    // 顶点 2 指向 顶点 0 和 顶点 3
            {}         // 顶点 3 没有指向其他顶点
    };

    int n = adj.size();
    std::vector<int> inDegrees(n); // 存储每个顶点的入度

    computeInDegrees(adj, inDegrees);

    // 输出每个顶点的入度
    for (int i = 0; i < n; ++i) {
        std::cout << "vertex " << i << " in degrees: " << inDegrees[i] << std::endl;
    }
    std::cout<<std::endl;
}


// 深度优先搜索算法
bool DFS(const std::vector<std::vector<int>>& adj, int start, int target) {
    int n = adj.size();
    std::vector<bool> visited(n, false); // 标记顶点是否被访问过
    std::stack<int> stack; // 使用栈来实现深度优先搜索

    // 将起始顶点入栈，并标记为已访问
    stack.push(start);
    visited[start] = true;

    // 开始深度优先搜索
    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        // 检查当前顶点是否为目标顶点
        if (vertex == target) {
            return true; // 找到了从 start 到 target 的路径
        }

        // 遍历当前顶点的邻接顶点
        for (int i = 0; i < adj[vertex].size(); ++i) {
            int nextVertex = adj[vertex][i];
            if (!visited[nextVertex]) {
                stack.push(nextVertex); // 将未访问的邻接顶点入栈
                visited[nextVertex] = true; // 标记为已访问
            }
        }
    }

    return false; // 未找到从 start 到 target 的路径
}

// 判断有向图是否存在由顶点Vi至顶点Vj的路径
bool hasPath_DFS(const std::vector<std::vector<int>>& adj, int start, int target) {
    return DFS(adj, start, target);
}

void work::homework7_9() {
    std::cout<<"### Homework 7.9 ###"<<std::endl<<std::endl;

    // 示例有向图，使用邻接表表示
    std::vector<std::vector<int>> adj = {
            {1, 2},    // 顶点 0 指向 顶点 1 和 顶点 2
            {2},       // 顶点 1 指向 顶点 2
            {0, 3},    // 顶点 2 指向 顶点 0 和 顶点 3
            {}         // 顶点 3 没有指向其他顶点
    };

    int startVertex = 0; // 起始顶点
    int targetVertex = 3; // 目标顶点

    // 判断是否存在由 startVertex 至 targetVertex 的路径
    if (hasPath_DFS(adj, startVertex, targetVertex)) {
        std::cout << "There exists a path from vertex " << startVertex << " to vertex " << targetVertex << "." << std::endl;
    } else {
        std::cout << "There does not exist a path from vertex " << startVertex << " to vertex " << targetVertex << "." << std::endl;
    }
    
    std::cout<<std::endl;
}

// 广度优先搜索算法
bool BFS(const std::vector<std::vector<int>>& adj, int start, int target) {
    int n = adj.size();
    std::vector<bool> visited(n, false); // 标记顶点是否被访问过
    std::queue<int> queue; // 使用队列来实现广度优先搜索

    // 将起始顶点入队，并标记为已访问
    queue.push(start);
    visited[start] = true;

    // 开始广度优先搜索
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        // 检查当前顶点是否为目标顶点
        if (vertex == target) {
            return true; // 找到了从 start 到 target 的路径
        }

        // 遍历当前顶点的邻接顶点
        for (int i = 0; i < adj[vertex].size(); ++i) {
            int nextVertex = adj[vertex][i];
            if (!visited[nextVertex]) {
                queue.push(nextVertex); // 将未访问的邻接顶点入队
                visited[nextVertex] = true; // 标记为已访问
            }
        }
    }

    return false; // 未找到从 start 到 target 的路径
}

// 判断有向图是否存在由顶点Vi至顶点Vj的路径
bool hasPath_BFS(const std::vector<std::vector<int>>& adj, int start, int target) {
    return BFS(adj, start, target);
}

void work::homework7_10() {
    std::cout<<"### Homework 7.10 ###"<<std::endl<<std::endl;
    // 示例有向图，使用邻接表表示
    std::vector<std::vector<int>> adj = {
            {1, 2},    // 顶点 0 指向 顶点 1 和 顶点 2
            {2},       // 顶点 1 指向 顶点 2
            {0, 3},    // 顶点 2 指向 顶点 0 和 顶点 3
            {}         // 顶点 3 没有指向其他顶点
    };

    int startVertex = 0; // 起始顶点
    int targetVertex = 3; // 目标顶点

    // 判断是否存在由 startVertex 至 targetVertex 的路径
    if (hasPath_BFS(adj, startVertex, targetVertex)) {
        std::cout << "There exists a path from vertex " << startVertex << " to vertex " << targetVertex << "." << std::endl;
    } else {
        std::cout << "There does not exist a path from vertex " << startVertex << " to vertex " << targetVertex << "." << std::endl;
    }
    std::cout<<std::endl;
}
