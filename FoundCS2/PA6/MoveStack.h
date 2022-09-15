#ifndef LAB6_PART1_STACK_H
#define LAB6_PART1_STACK_H

struct Move{
    Move(): x(0), y(0){}
    Move(int x, int y): x(x), y(y){}
    int x;
    int y;
};

class MoveStack{
private:

public:
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top(){ return top; }
    void push(Move move);
    void pop();
};

inline Move::MoveStack(){
  top = -1;
  return (top == -1);
}
#endif //LAB6_PART1_STACK_H
