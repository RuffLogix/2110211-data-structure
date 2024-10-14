#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        ensureCapacity(size() + s.size());
        for (int i=size()-1; i>=0; i--) mData[i + s.size()] = mData[i];
        for (int i=0; i<s.size(); i++) mData[i] = s.mData[i];
        mSize = size() + s.size();
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        int q_size = q.size();
        ensureCapacity(size() + q_size);
        for (int i=size()-1; i>=0; i--) mData[i + q_size] = mData[i];
        while (!q.empty()) {
            mData[q.size() - 1] = q.front();
            q.pop();
        }
        mSize = size() + q_size;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while (!s.empty()) {
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while (!q.empty()) {
            push(q.front());
            q.pop();
        }
    }
}
