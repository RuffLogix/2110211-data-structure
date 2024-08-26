#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
    stack<int> num;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first==1) {
            num.push(v[i].second);
        } else {
            int second = num.top(); num.pop();
            int first = num.top(); num.pop();

            if (v[i].second==0) num.push(first + second);
            else if (v[i].second==1) num.push(first - second);
            else if (v[i].second==2) num.push(first * second);
            else if (v[i].second==3) num.push(first / second);
        }
    }
    return num.top();
}

#endif
