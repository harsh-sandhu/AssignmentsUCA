/*
 * Min Stack Implementation
 * Reference: Leet Code
 *
 * @Harsh Sandhu, 1911981371, 18/08/2021
 */


typedef struct{
    int *st;
    int top;
    int *min;
    int mt;
}MinStack;

// initialize your data structure here.

MinStack* minStackCreate() {
    MinStack s = (MinStack)malloc(sizeof(MinStack));
    s -> top = -1;
    s -> mt = -1;
    s -> st = (int*) malloc(sizeof(int) * 100000);
    s -> min = (int*) malloc(sizeof(int) * 100000);
    return s;
}

void minStackPush(MinStack* obj, int val) {
    obj -> top += 1;
    obj -> st[obj -> top] = val;
    
    if(obj -> mt == -1 || obj -> min[obj -> mt] >= val){
        obj -> mt += 1;
        obj -> min[obj -> mt] = val;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top==-1)
        return ;
  if (obj -> min[obj -> mt] == obj -> st[obj -> top])
      obj -> mt -= 1;
    obj -> top -= 1;
}

int minStackTop(MinStack* obj) {
  return (obj -> st[obj -> top]);
}

int minStackGetMin(MinStack* obj) {
  return obj -> min[obj -> mt];
}

void minStackFree(MinStack* obj) {
    // if(obj)
    //     free(obj -> st);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
