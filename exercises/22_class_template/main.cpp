#include "../exercise.h"
#include <cstring> // 包含 memcpy 的头文件

// READ: 类模板 <https://zh.cppreference.com/w/cpp/language/class_template>

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        for (int i = 0; i < 4; ++i) {
            shape[i] = shape_[i];
        }
        unsigned int size = 1;
        for (int i = 0; i < 4; ++i) {
            size *= shape[i];
        }
        data = new T[size];
        memcpy(data, data_, size * sizeof(T));
    }

    ~Tensor4D() {
        delete[] data;
    }

    // 为了保持简单，禁止复制和移动
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = delete;

    // 这个加法需要支持“单向广播”。
    // 具体来说，`others` 可以具有与 `this` 不同的形状，形状不同的维度长度必须为 1。
    // `others` 长度为 1 但 `this` 长度不为 1 的维度将发生广播计算。
    // 例如，`this` 形状为 `[1, 2, 3, 4]`，`others` 形状为 `[1, 2, 1, 4]`，
    // 则 `this` 与 `others` 相加时，3 个形状为 `[1, 2, 1, 4]` 的子张量各自与 `others` 对应项相加。
    Tensor4D &operator+=(Tensor4D const &others) {
        // 检查两个张量的形状是否兼容广播
        for (unsigned int i = 0; i < 4; ++i) {
            if (shape[i] != others.shape[i] && others.shape[i] != 1) {
                throw std::invalid_argument("Incompatible shapes for broadcasting.");
            }
        }

        // 遍历 this 张量的元素，并找到相对应的others元素
        for (unsigned int i0 = 0; i0 < shape[0]; ++i0) {
            for (unsigned int i1 = 0; i1 < shape[1]; ++i1) {
                for (unsigned int i2 = 0; i2 < shape[2]; ++i2) {
                    for (unsigned int i3 = 0; i3 < shape[3]; ++i3) {
                        // this 张量中当前元素的索引
                        int index_this = i0 * shape[1] * shape[2] * shape[3] +
                                         i1 * shape[2] * shape[3] +
                                         i2 * shape[3] +
                                         i3;
                        // 计算 others 张量中对应元素的索引
                        // 如果 others.shape[0] == 1，则使用 i0 % others.shape[0] 得到 0，表示使用 others 第一个元素
                        //否则，使用 i0 % others.shape[0] 得到 i0，表示使用 others 的第 i0 个元素
                        int index_others =  ( i0 %others.shape[0]) * others.shape[1] * others.shape[2] * others.shape[3] +
                                            ( i1 %others.shape[1]) * others.shape[2] * others.shape[3] +
                                            ( i2 %others.shape[2]) * others.shape[3] +
                                            ( i3 %others.shape[3]);
                        data[index_this] += others.data[index_others];
                    }
                }
            }
        }
        // TODO: 实现单向广播的加法
        return *this;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    // 主函数中包含三个大括号内容，每个大括号内部是一段独立的作用域。
    // 这些大括号的主要作用是限定变量的生命周期，确保在离开大括号后自动释放相关的资源。
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D(shape, data);
        auto t1 = Tensor4D(shape, data);
        t0 += t1;
        for (auto i = 0u; i < sizeof(data) / sizeof(*data); ++i) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
            1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3,

            4, 4, 4, 4,
            5, 5, 5, 5,
            6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
            6,
            5,
            4,

            3,
            2,
            1};
        // clang-format on

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == 7.f, "Every element of t0 should be 7 after adding t1 to it.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == d0[i] + 1, "Every element of t0 should be incremented by 1 after adding t1 to it.");
        }
    }
}
