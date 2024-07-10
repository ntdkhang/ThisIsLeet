#include <condition_variable>
#include <cstdlib>
#include <queue>
#include <thread>
#include <vector>


struct Node {
    std::vector<Node*> children;
    int id;

    Node(int _id) : id(_id){}
    Node() {
        id = rand();
    }
};

Node* TreeGenerator(int height) {
    Node *root = new Node();
    if (height == 1) {
        return root;
    }
    int child_count = rand() % 4 + 1;
    for (int i = 0; i < child_count; i++) {
        root->children.push_back(TreeGenerator(height-1));
    }
    return root;
}

void findNode(Node* root, int id) {
    std::queue<Node*> q;
    bool found = false;
    std::mutex mut;
    std::condition_variable cond;
    int working = 0;

    q.push(root);

    auto worker = [&] {
        while (true) {
            Node* current;
            {
                std::unique_lock<std::mutex> lock(mut);
                cond.wait(lock, [&] { return !q.empty() || working == 0 || found == true; });
                if (found == true || working == 0) {
                    return;
                }
                current = q.front();
                q.pop();
                working++;
            }

            if (current->id == id) {
                found = true;
                return;
            }

            for (Node* node : current->children) {
                std::lock_guard lock(mut);
                q.push(node);
                cond.notify_all();
            }
            working--;
        }
    };

    int num_thread = std::thread::hardware_concurrency();
    if (num_thread == 0)
        num_thread = 3;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_thread; i++) {
        threads.push_back(std::thread(worker));
        threads.back().join();
    }

}

int main() {
    Node* root = TreeGenerator(6);
}
