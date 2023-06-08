#include <iostream>
#include <ostream>
#include <vector>
#include "TreeException.h"

struct TreeNode {
    int num_;
    TreeNode *left_;
    TreeNode *right_;

    TreeNode() : 
                num_{0},
                left_{nullptr},
                right_{nullptr}
                {}
    TreeNode(TreeNode &list) :
                                num_{list.num_},
                                left_{list.left_},
                                right_{list.right_}
                                {}
    TreeNode(int num, TreeNode *left, TreeNode *right) :
                                                        num_{num},
                                                        left_{left},
                                                        right_{right}
                                                        {}
    TreeNode(int num) :
                        num_{num},
                        left_{nullptr},
                        right_{nullptr}
                        {}
};

struct sequence {
    int length_;
    int *path_;

    sequence(int length, int *path) {
        if (length == 0 || path == nullptr) {
            throw TreeException("Пустой путь!");
        }

        try {
            length_ = length;
            path_ = path;
        } catch (const TreeException &err) {
            std::cerr << err.what() << "\n";
        }
    }
    
    ~sequence() {
        length_ = 0;
        delete[] path_;
    }

    void print() {
        for (int i = 0; i < length_; i++) {
            std::cout << path_[i] << " ";
        }
        std::cout << std::endl;
    }
};

struct map {
    int n_;
    long sum_;

    map() : n_(0), sum_(0) {}

    void plus(int n) {
        sum_ += n;
        n_++;
    }
};

class BinaryTree {
    private:
        TreeNode *root_;

        bool deleteLeaves(TreeNode *leave);
        bool search(TreeNode *root, int x, std::vector<int> &res);
        int enumNumbers(TreeNode *root);
        bool positiveNumbers(TreeNode *root);
        void ariphmetikAvarage(TreeNode *root, map &res);
        std::ostream& getOS(TreeNode *root, std::ostream &os);
    public:
        BinaryTree(TreeNode *Root);
        BinaryTree();
        ~BinaryTree();
        void add(int number, const sequence &path);
        int enumNumbers();
        bool positiveNumbers();
        void deleteLeaves();
        double ariphmetikAvarage();
        sequence search(int x);
        friend std::ostream& operator <<(std::ostream &os, BinaryTree &table);
};
