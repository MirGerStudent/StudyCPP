#include <iostream>
#include "Tree.h"

int main() {
    sequence A(1, new int[1]{0});
    sequence B(1, new int[1]{1});
    sequence C(2, new int[2]{0, 1});
    sequence D(2, new int[2]{0, 0});
    sequence E(3, new int[3]{0, 0, 0});
    sequence F(3, new int[3]{0, 1, 1});
    sequence J(4, new int[4]{0, 0, 0, 0});
    sequence Z(5, new int[5]{0, 0, 0, 0, 0});

    BinaryTree BT(new TreeNode(8));
    BT.add(9, A);
    BT.add(10, B);
    BT.add(11, C);
    BT.add(12, D);
    // BT.add(20, Z);

    std::cout << BT << std::endl;
    std::cout << BT.enumNumbers() << std::endl;
    std::cout << BT.positiveNumbers() << std::endl;
    std::cout << BT.ariphmetikAvarage() << std::endl;
    BT.deleteLeaves();
    std::cout << BT << std::endl;
    
    BT.add(10, B);
    BT.add(11, C);
    BT.add(12, D);
    BT.add(15, E);
    BT.add(20, F);
    BT.add(25, J);
    BT.add(30, Z);

    std::cout << BT << std::endl;
    sequence L = BT.search(25);
    L.print();

    BT.add(35, L);
    std::cout << BT << std::endl;

    return 0;
}