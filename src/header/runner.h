#ifndef _RUNNER_
#define _RUNNER_

class Runner {
    public:
        virtual bool run(bool) = 0;
        virtual void print(){};
        virtual ~Runner(){};
};

#endif
