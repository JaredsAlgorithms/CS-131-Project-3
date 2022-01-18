template <typename T>
size_t minideque<T>::fronthalfsize() const {
    return fronthalf_.size();
}
template <typename T>
size_t minideque<T>::backhalfsize() const {
    return backhalf_.size();
}
template <typename T>
size_t minideque<T>::size() const {
    return (fronthalfsize() + backhalfsize());
}
template <typename T>
bool minideque<T>::empty() const {
    return this->fronthalf_.empty() && this->backhalf_.empty();
}

template <typename T>
T& minideque<T>::front() {
    // this function is correct
    if (!fronthalf_.empty()) {
        return fronthalf_.back();
    } else if (!backhalf_.empty()) {
        return backhalf_.at(0);
    }
    throw new std::logic_error("out of bounds");
}

template <typename T>
T& minideque<T>::back() {
    return *(backhalf_.rbegin());
}

template <typename T>
const T& minideque<T>::back() const {
    return *(backhalf_.rbegin());
}

template <typename T>
const T& minideque<T>::front() const {
    if (!fronthalf_.empty()) {
        return fronthalf_.back();
    } else if (!backhalf_.empty()) {
        return backhalf_[0];
    }
    throw new std::logic_error("out of bounds");
}

template <typename T>
void minideque<T>::push_front(T v) {
    fronthalf_.push_back(v);
}

template <typename T>
// this only deals with the the backhalf_ vector, the function name is
// misleading should read out push_backhalf_
void minideque<T>::push_back(T v) {
    backhalf_.push_back(v);
}

template <typename T>
void minideque<T>::pop_front() {
    // pop the front element in the fronthalf_ vectors
    if (fronthalfsize() == backhalfsize()) {
        fronthalf_.pop_back();
        backhalf_.pop_back();
        return;
    }
    if (fronthalf_.empty()) {
        for (size_t i = 0; i < backhalfsize(); ++i) {
            if ((backhalfsize() + 1) / 2 && i != 0) {
                fronthalf_.push_back(backhalf_[backhalfsize() - i]);
            }
            backhalf_.pop_back();
        }
    } else if (backhalf_.empty()) {
        for (size_t i = 0; i < fronthalfsize(); ++i) {
            if ((backhalfsize() + 1) / 2 && i != 0) {
                backhalf_.push_back(fronthalf_[fronthalfsize() - i]);
            }
            fronthalf_.pop_back();
        }
    } else {
        fronthalf_.pop_back();
    }
}

template <typename T>
void minideque<T>::pop_back() {
    if (fronthalfsize() == backhalfsize()) {
        fronthalf_.pop_back();
        backhalf_.pop_back();
    }
    if (backhalf_.empty()) {
        for (int i = 0; i < fronthalfsize(); ++i) {
            if ((fronthalfsize() + 1) / 2 && i != 0) {
                backhalf_.push_back(fronthalf_[fronthalfsize() - i]);
            }
            fronthalf_.push_back();
        }
    } else if (fronthalf_.empty()) {
        for (int i = 0; i < backhalfsize(); ++i) {
            if ((backhalfsize() + 1) / 2 && i != 0) {
                fronthalf_.push_back(fronthalf_[backhalfsize() - i]);
            }
            backhalf_.pop_back();
        }
    }
}

template <typename T>
T& minideque<T>::operator[](size_t index) {
    if (index >= fronthalfsize()) {
        auto begin = backhalf_.begin();
        begin + index;
        return *(begin);
    }
    return fronthalf_[index];
}
template <typename T>
const T& minideque<T>::operator[](size_t index) const {
    if (index >= fronthalfsize()) {
        auto begin = backhalf_.begin();
        begin + index;
        return *(begin);
    }
    return fronthalf_[index];
}


