#ifndef SMARTPOINT_H
#define SMARTPOINT_H

template <typename T>
class SmartPointer {
private:
    T* ptr;
    unsigned int* count;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p), count(new unsigned int(1)) {}

    SmartPointer(const SmartPointer<T>& other) : ptr(other.ptr), count(other.count) {
        (*count)++;
    }

    ~SmartPointer() {
        release();
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            (*count)++;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    unsigned int use_count() const { return *count; }

private:
    void release() {
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
};

#endif
