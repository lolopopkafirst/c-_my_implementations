#include <cstddef>
#include <stdexcept>
template <typename T>
class Vector{
    private:
        size_t size_;
        size_t capacity_;
        T* data_;
    public: 
        Vector();
        Vector(const Vector& other);
        ~Vector();
        Vector& operator=(const Vector& other);

        void push_back(const T& value);
        void pop_back();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        Vector<T>& operator=(Vector<T>&& other);

        size_t size() const;
        size_t capacity() const;

        T* begin();
        T* end();
};

template <typename T>
Vector<T>::Vector()
    : size_(0), capacity_(0), data_(nullptr) {};

template <typename T>
Vector<T>::Vector(const Vector& other)
:size_(other.size_), capacity_(other.capacity_), data_(nullptr) {
    if(other.capacity_ > 0){
        data_ = new T[capacity_];
        for(size_t i = 0 ; i < size_ ; i++){
            data_[i] = other.data_[i];
        }
    }
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data_;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this == &other) return *this;
    T* new_data = nullptr;
    if(other.capacity_ > 0){
    new_data = new T[other.capacity_];
        for(size_t i = 0 ; i < other.size_ ; i++){
            new_data[i] = other.data_[i];
        }
    }
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new_data;
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index){
    if(index < size_){
        return data_[index];
    }
    else throw std::out_of_range("out of range");
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const{
    if(index < size_){
        return data_[index];
    }
    else throw std::out_of_range("out of range");
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept{
    if(this == &other) return *this;
    delete[] data_;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T& value){
    if(size_ == capacity_){
        size_t capacity_new = capacity_ == 0 ? 1 : capacity_ * 2;
        T* new_data = new T[capacity_new];
        for(size_t i = 0 ; i < size_ ; i++){
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = capacity_new;
    }
    
    data_[size_] = value;
    size_++;
}

template <typename T>
void Vector<T>::pop_back(){
    if(size_ == 0){
        return;
    }
    size_--; 
}

template <typename T>
size_t Vector<T>::size()const{
    return size_;
}

template <typename T>
size_t Vector<T>::capacity()const{
    return capacity_;
}

template <typename T>
T* Vector<T>::begin(){
    return data_;
}

template <typename T>        
T* Vector<T>::end(){
    return data_ + size_;
}