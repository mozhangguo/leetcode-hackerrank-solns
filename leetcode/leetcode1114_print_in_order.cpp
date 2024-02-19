class Foo {

private: 
    mutex mu;
    condition_variable cond;
    int controlCnt = 0;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lkg(mu);
        cond.wait(lkg, [&](){
            return controlCnt==0;
        });
        controlCnt=1;
        printFirst();
        cond.notify_all();
        
    }

    void second(function<void()> printSecond) { 
    
        unique_lock<mutex> lkg(mu);
        cond.wait(lkg, [&](){
            return controlCnt==1;
        });
        controlCnt=2;
        printSecond();
        cond.notify_all();
    }

    void third(function<void()> printThird) {
        
        unique_lock<mutex> lkg(mu);
        cond.wait(lkg, [&](){
            return controlCnt==2;
        });
        controlCnt=0;
        printThird();
        cond.notify_all();
    }
};
