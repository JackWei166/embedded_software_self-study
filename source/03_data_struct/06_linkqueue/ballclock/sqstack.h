typedef int data_t;

typedef struct {
	data_t *data;
	int maxlen;
	int top;
} sqstack;

sqstack *stack_create(int len);
int stack_push(sqstack *S, int value);
int stack_empty(sqstack *S);
int stack_full(sqstack *S);
data_t stack_pop(sqstack *S);
data_t stack_top(sqstack *S);
int stack_clear(sqstack *S);
int stack_free(sqstack *S);

