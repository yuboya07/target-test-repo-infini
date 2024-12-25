﻿#include "../exercise.h"
#include <cstring>

// READ: 模板非类型实参 <https://zh.cppreference.com/w/cpp/language/template_parameters#%E6%A8%A1%E6%9D%BF%E9%9D%9E%E7%B1%BB%E5%9E%8B%E5%AE%9E%E5%8F%82>

// unsigned int N 是一个非类型模板参数，表示模板可以接受一个 unsigned int 类型的常量值作为参数。
// class T 是一个类型模板参数，表示模板可以接受一个类型作为参数。

template<unsigned int N, class T>
struct Tensor {
    unsigned int shape[N];
    T *data;

    Tensor(unsigned int const shape_[N]) {
        unsigned int size = 1;
        // TODO: 填入正确的 shape 并计算 size
        // copy shape_
        memcpy(shape, shape_, N*sizeof(unsigned int));

        // calculate size
        for (unsigned int i = 0; i < N; ++i) {
            size *= shape[i];
        }        

        data = new T[size];
        std::memset(data, 0, size * sizeof(T));
    }
    ~Tensor() {
        delete[] data;
    }

    // 为了保持简单，禁止复制和移动
    Tensor(Tensor const &) = delete;
    Tensor(Tensor &&) noexcept = delete;

    T &operator[](unsigned int const indices[N]) {
        return data[data_index(indices)];
    }
    T const &operator[](unsigned int const indices[N]) const {
        return data[data_index(indices)];
    }

private:
    unsigned int data_index(unsigned int const indices[N]) const {
        unsigned int index = 0;
        unsigned int stride = 1;
        for (int i = N - 1; i >= 0; --i) {
            ASSERT(indices[i] < shape[i], "Invalid index");
            // TODO: 计算 index
            index += indices[i] * stride;
            stride *= shape[i];
        }
        return index;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{2, 3, 4, 5}; // 120 num :indices 0-119 {0,0,0,0} -> {1,2,3,4}
        auto tensor = Tensor<4, int>(shape);

        unsigned int i0[]{0, 0, 0, 0};
        tensor[i0] = 1;
        ASSERT(tensor[i0] == 1, "tensor[i0] should be 1");
        ASSERT(tensor.data[0] == 1, "tensor[i0] should be 1");

        unsigned int i1[]{1, 2, 3, 4};
        tensor[i1] = 2;
        ASSERT(tensor[i1] == 2, "tensor[i1] should be 2");
        ASSERT(tensor.data[119] == 2, "tensor[i1] should be 2");
    }
    {
        unsigned int shape[]{7, 8, 128};
        auto tensor = Tensor<3, float>(shape);

        unsigned int i0[]{0, 0, 0};
        tensor[i0] = 1.f;
        ASSERT(tensor[i0] == 1.f, "tensor[i0] should be 1");
        ASSERT(tensor.data[0] == 1.f, "tensor[i0] should be 1");

        unsigned int i1[]{3, 4, 99};
        tensor[i1] = 2.f;
        ASSERT(tensor[i1] == 2.f, "tensor[i1] should be 2");
        ASSERT(tensor.data[3683] == 2.f, "tensor[i1] should be 2");
        // 3683 = 3*8*128 + 4*128 + 99
    }
    return 0;
}