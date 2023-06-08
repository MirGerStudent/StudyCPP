#include "Tree.h"
#include "TreeException.h"
#include <vector>

BinaryTree::BinaryTree(TreeNode *Root) :
                                        root_{Root}
                                        {}

BinaryTree::BinaryTree() : 
                            root_{nullptr}
                            {}

BinaryTree::~BinaryTree() {}

void BinaryTree::add(int number, const sequence &path) {
    TreeNode *it = root_;
    
    //Можно сократить, надо доделать
    if (!root_) {
        root_ = new TreeNode(number);
    } else {
        for (int i = 0; i < path.length_; i++) {
            if (path.path_[i] == 0) {
                if (it->left_ != nullptr && i < path.length_-1) {
                    it = it->left_;
                } else
                if (it->left_ != nullptr && i == path.length_-1) {
                    it->left_->num_ = number;
                } else
                if (it->left_ == nullptr && i == path.length_-1) {
                    it->left_ = new TreeNode(number);
                } else {
                    throw TreeException("Путь ведёт в никуда!");
                }
            }
            if (path.path_[i] == 1) {
                if (it->right_ != nullptr && i < path.length_-1) {
                    it = it->right_;
                } else
                if (it->right_ != nullptr && i == path.length_-1) {
                    it->right_->num_ = number;
                } else
                if (it->right_ == nullptr && i == path.length_-1) {
                    it->right_ = new TreeNode(number);
                } else {
                    throw TreeException("Путь ведёт в никуда!");
                }
            }
        }
    }

    try {
        return;
    } catch(const TreeException& err) {
        std::cerr << err.what() << '\n';
    }
}

std::ostream& BinaryTree::getOS(TreeNode *root, std::ostream &os) {
    if (!root) {
        return os;
    }

    getOS(root -> left_, os);
    os << root->num_ << " ";
    getOS(root -> right_, os);

    return os;
}

std::ostream& operator <<(std::ostream &os, BinaryTree &table) {
    return table.getOS(table.root_, os);
}

int BinaryTree::enumNumbers(TreeNode *root) {
    return (root == nullptr) ? 0 : (root->num_ % 2 == 0) + enumNumbers(root->right_) + enumNumbers(root->left_);
}

int BinaryTree::enumNumbers() {
    return enumNumbers(root_);
}

bool BinaryTree::positiveNumbers(TreeNode *root) {
    return (root == nullptr) ? true : (root->num_ > 0) && positiveNumbers(root->right_) && positiveNumbers(root->left_);
}

bool BinaryTree::positiveNumbers() {
    return positiveNumbers(root_);
}

bool BinaryTree::deleteLeaves(TreeNode* leave) {
    if(leave == nullptr){
        return false;
    }
    else {
        if(leave->right_ == nullptr && leave->left_ == nullptr) {
            delete leave;
            return true;
        } 
        if(deleteLeaves(leave->left_)) {
            leave->left_ = nullptr;
        }
        if(deleteLeaves(leave->right_)) {
            leave->right_ = nullptr;
        }
        return false;
    }
}

void BinaryTree::deleteLeaves() {
    deleteLeaves(root_);
}

void BinaryTree::ariphmetikAvarage(TreeNode *root, map &res) {
    if (root) {
        res.plus(root->num_);
        ariphmetikAvarage(root->right_, res);
        ariphmetikAvarage(root->left_, res);
    }
}

double BinaryTree::ariphmetikAvarage() {
    map res = map();
    ariphmetikAvarage(root_, res);
    return ((double) res.sum_) / res.n_;
}

bool BinaryTree::search(TreeNode *root, int x, std::vector<int> &res) {
    if (root != nullptr) {
        if (root->num_ == x) {
            return true;
        }
        res.push_back(0);
        if (search(root->left_, x, res)) {
            return true;
        }
        res.pop_back();
        res.push_back(1);
        if (search(root->right_, x, res)) {
            return true;
        }
        res.pop_back();
    } else {
        return false;
    }
}

sequence BinaryTree::search(int x) {
    std::vector<int> res;
    search(root_, x, res);

    int *arr = new int[res.size()];

    for (int i = 0; i < res.size(); i++) {
        arr[i] = res.at(i);
    }
    sequence RES(res.size(), arr);

    return RES;
}