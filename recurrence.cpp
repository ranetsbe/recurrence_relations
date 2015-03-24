#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

// recurrence token
class rtoken{
public:
	rtoken();
	rtoken(const rtoken &rt);
	char op;
	int val;
};

static std::vector<rtoken> tokens;
static int n_steps = 0;

rtoken::rtoken() : op('x'), val(0) {}
rtoken::rtoken(const rtoken &rt) : op(rt.op), val(rt.val) {}

void parse_reccurence(){
	printf("Enter a recurrence: ");
	char recurrence[100];
	char *tok;
	gets(recurrence);
	tok = strtok(recurrence, " \n");
	for (int i = 0; tok != NULL; i++){
		rtoken step;
		step.op = tok[0];
		step.val = std::atoi(tok+1);
		tokens.push_back(step);
		tok = strtok(NULL, " \n");
		n_steps++;
	}
}

void stepRecurrence(int *u, int current, int n){
	int val = u[current-1];
	for (int i = 0; i < n_steps; i++) {
			switch (tokens[i].op) {
				case '*':	val = val * tokens[i].val; break;
				case '+':	val = val + tokens[i].val; break;
				case '-':	val = val - tokens[i].val; break;
				case '/':	val = val / tokens[i].val; break;
			}
	}

	u[current] = val;
	printf("u[%d] = %d\n", current, u[current]);

	if (current == n) {
		return;
	}
	stepRecurrence(u, current + 1, n);
}

void printRecurrence(int initial, int n) {
	int u[n + 1];
	u[0] = initial;
	printf("u[0] = %d\n", u[0]);
	stepRecurrence(u, 1, n);
}


int main() {
	int initial = 0;
	int n = 0;
	parse_reccurence();
	printf("Input u[0]: ");
	scanf("%d", &initial);
	printf("Input n: ");
	scanf("%d", &n);

	printRecurrence(initial, n);

	return 0;
}
