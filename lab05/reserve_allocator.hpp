#include <vector>
#include <memory>

template<class T, uint64_t MAX_SIZE = 1000>
class Reserve_Allocator {
    std::vector<T> buffer;
    // std::vector<uint64_t> free_points;
    std::vector<uint64_t> free_indexes;
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Reserve_Allocator():
    buffer(MAX_SIZE), /* free_points(MAX_SIZE), */ free_indexes(MAX_SIZE) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            free_indexes[i] = i;
        }
    }

    ~Reserve_Allocator() = default;

    pointer allocate(size_t n) {
        pointer result;
        if (n == 1) {
            if (free_indexes.empty())
                throw std::bad_alloc();
            result = &buffer[free_indexes[free_indexes.size() - 1]];
            free_indexes.pop_back();
        }
        else {
            if (free_indexes.size() < n)
                throw std::bad_alloc();
            result = &buffer[free_indexes[free_indexes.size() - n]];
            free_indexes.resize(free_indexes.size() - n);
        }
        // uint64_t taken = MAX_SIZE;
        // for (uint64_t index : free_indexes) {
        //     if (free_points[index] >= n) {
        //         result = &buffer[index];
        //         taken = index;
        //         break;
        //     }
        // }
        // if (taken == MAX_SIZE)
        //     throw std::bad_alloc("There are no more memory in buffer");
        // for (int i = taken; i < taken + n; ++i) {
        //     free_points[i] = 0;
        // }
        return result;
    }

    void deallocate(pointer p, size_t n) {
        uint64_t index = (p - &buffer[0]) / sizeof(value_type);
        if (n == 1) {
            free_indexes.push_back(index);
        }
        else {
            for (int i = index; i < index + n; ++i) {
                free_indexes.push_back(i);
            }
        }
    }

    template <class U, class... Args>
    void construct(U *p, Args&& ...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

    template <class U>
    struct rebind {
        using other = Reserve_Allocator<U>;
    };
};

template <class T, class U>
constexpr bool operator==(const Reserve_Allocator<T> &lhs, const Reserve_Allocator<U> &rhs) 
{
    return true;
}

template <class T, class U>
constexpr bool operator!=(const Reserve_Allocator<T> &lhs, const Reserve_Allocator<U> &rhs)  
{
    return false;
}