#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

template <typename T>
class minideque {
   private:
    std::vector<T> fronthalf_;
    std::vector<T> backhalf_;

   public:
    minideque() = default;  // do not change, C++ defaults are ok
    minideque(const minideque<T>& other) = default;  // rule of three
    minideque& operator=(const minideque<T>& other) = default;
    ~minideque() = default;

    size_t size() const;
    size_t fronthalfsize() const;
    size_t backhalfsize() const;
    bool empty() const;

    void pop_front();
    void pop_back();

    void push_front(T v);
    void push_back(T v);

    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    const T& operator[](size_t index) const;  // TODO
    T& operator[](size_t index);

    void balanceDeque();
    void testDeque();
    void resize();
    friend std::ostream& operator<<(std::ostream& os,
                                    const minideque<T>& dq) {  // do not change
        if (dq.empty()) {
            return os << "minideque is empty";
        }

        dq.printFronthalf(os);
        os << "| ";
        dq.printBackhalf(os);
        os << ", front:" << dq.front() << ", back:" << dq.back()
           << ", size:" << dq.size();
        return os;
    }

    void printFronthalf(std::ostream& os = std::cout) const {  // do not change
        if (empty()) {
            std::cout << "fronthalf vector is empty";
        }

        for (typename std::vector<T>::const_reverse_iterator crit =
                 fronthalf_.crbegin();
             crit != fronthalf_.crend(); ++crit) {
            os << *crit << " ";
        }
    }

    void printBackhalf(std::ostream& os = std::cout) const {  // do not change
        if (empty()) {
            os << "backhalf vector is empty";
        }

        for (typename std::vector<T>::const_iterator cit = backhalf_.cbegin();
             cit != backhalf_.cend(); ++cit) {
            os << *cit << " ";
        }
    }
};
#include "minideque.tcc"
