//https://leetcode.com/problems/design-front-middle-back-queue/description/
//mrzi me, dva deka
class FrontMiddleBackQueue {
public:
    deque<int> d1;
    deque<int> d2;
    FrontMiddleBackQueue() {

    }
    void print(){
        for(int x : d1)cout << x << " ";
        cout << " | ";
        for(int x : d2)cout << x << " ";
        cout << endl;
    }
    void pushFront(int val) {
        d1.push_front(val);
        //print();
    }

    void pushMiddle(int val) {
        while((int)d1.size() - (int)d2.size() >= 1){
            d2.push_front(d1.back());
            d1.pop_back();
        }
        while((int)d2.size() - (int)d1.size() > 1){
            d1.push_back(d2.front());
            d2.pop_front();
        }
        d2.push_front(val);
        //print();
    }

    void pushBack(int val) {
        d2.push_back(val);
        //print();
    }

    int popFront() {
        if(d1.size()==0 && d2.size()==0)return -1;
        int broj;
        if(d1.size() > 0){
            broj = d1.front();
            d1.pop_front();
        }
        else{
            broj = d2.front();
            d2.pop_front();
        }

        return broj;
    }

    int popMiddle() {
        if(d1.empty() && d2.empty()) return -1;
        while((int)d1.size() - (int)d2.size() >= 1){
            d2.push_front(d1.back());
            d1.pop_back();
        }
        while((int)d2.size() - (int)d1.size() > 1){
            d1.push_back(d2.front());
            d2.pop_front();
        }
        int broj;
        if((int)d1.size() >= (int)d2.size()){
            broj = d1.back();
            d1.pop_back();
        }
        else{
            broj = d2.front();
            d2.pop_front();
        }

        return broj;
    }

    int popBack() {
        if(d1.empty() && d2.empty())return -1;
        int broj;
        if(d2.empty()){
            broj = d1.back();
            d1.pop_back();
        }
        else{
            broj = d2.back();
            d2.pop_back();
        }
        return broj;

    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */