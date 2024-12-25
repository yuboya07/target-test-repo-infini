#include "../exercise.h"
#include <vector>

int main(){
    // int* p = new int[5] {0,1,4,10,11};
    // std::cout << sizeof(p) << std::endl;

    /*
    当一个函数返回的是引用（& 或 &&），并且你使用 auto ref 接收返回值时，是否能改变内部值取决于你如何声明 ref。具体来说：

    - auto：这会进行类型推导，并且不会保留引用的性质。也就是说，auto 会将返回的引用解引用为一个副本，因此对 ref 的修改不会影响原始对象。
    - auto&：这会保留返回值的左值引用性质，使得 ref 成为原始对象的一个引用，因此对 ref 的修改会直接影响原始对象。
    - auto&&：这会保留返回值的右值引用性质（如果适用），通常用于处理临时对象或移动语义。
    */

    std::vector<int> vec{1, 2, 3, 4, 5};
    auto ref = vec[0];
    ref = 100;
    std::cout << "vec[0]=" << vec[0] << std::endl ;
    auto& ref_ = vec[0];
    ref_ = 100;
    std::cout << "vec[0]=" << vec[0] << std::endl ;

    return 0;
}