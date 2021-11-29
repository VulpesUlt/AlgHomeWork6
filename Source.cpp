#include <iostream>
#include <time.h>

const int SIZE = 10;


// Task 1
typedef struct
{
	int priority;
	int data;
} Node;

Node* arr[SIZE];
int items{0};

void init()
{
	for(int i = 0; i < SIZE; i++)
	{
		arr[i] = NULL;
	}
}

void insert (int priority, int data)
{
	Node* node = new Node;
	node->data = data;
	node->priority = priority;

	if (items == 0)
	{
		arr[0] = node;
		items++;
	}
	else if (items == SIZE)
		std::cout << "Queue is full" << std::endl;
	else
	{
		int flag{ 0 };
		while (arr[flag] != NULL)
			flag++;
		arr[flag] = node;
		items++;
	}
}

Node* remove ()
{
	if (items == 0)
	{
		std::cout << "Queue is empty" << std::endl;
		return NULL;
	}
	else
	{
		Node* tempPtr{ 0 };
		int pr{ 0 }, flag{0};
		for (int i = 0; i < SIZE; i++)
			if (arr[i] != NULL)
				if (arr[i]->priority > pr)
				{
					pr = arr[i]->priority;
					tempPtr = arr[i];
					flag = i;
				}
		items--;
		arr[flag] = NULL;
		return tempPtr;
	}
}

void printQueue ()
{
	for (int i = 0; i < SIZE; i++)
		if (arr[i] == NULL)
			std::cout << "(*, *) ";
		else
			std::cout << "(" << arr[i]->priority << ", " << arr[i]->data << ") ";
	std::cout << std::endl;
}

int getRand (int max)
{
	return rand() % max;
}

// Task 2
typedef struct
{
	int* stack;
	int length;
	int tail;
} Stack;

Stack initStack (int length)
{
	Stack stack;
	stack.stack = new int[length];
	for (int i = 0; i < length; i++)
		stack.stack[i] = 0;
	stack.length = length;
	stack.tail = 0;
	return stack;
}

void push(Stack* stack, int data)
{
	if (stack->tail == stack->length)
		std::cout << "Stack is full" << std::endl;
	else 
		stack->stack[stack->tail++] = data;
}

int pop(Stack* stack)
{
	if (stack->tail == 0)
	{
		std::cout << "Stack is full" << std::endl;
		return -1;
	}
	else
	{
		int temp;
		temp = stack->stack[--stack->tail];
		stack->stack[stack->tail] = 0;
		return temp;
	}
}

void decToBin (int num)
{
	Stack number = initStack(20);

	while (num > 0)
	{
		push(&number, num % 2);
		num /= 2;
	}
	
	while (number.tail > 0)
	{
		std::cout << pop(&number);
	}
	std::cout << std::endl;
}


void main ()
{		
	// Task 1
	Node* n = NULL;
	init();
	for (int i = 0; i < SIZE; i++)
		insert(getRand(8), getRand(100));

	printQueue();

	for (int i = 0; i < 5; i++)
	{
		n = remove();
		if (n != NULL)
			std::cout << "(" << n->priority << ", " << n->data << ") ";	
	}
	std::cout << std::endl;

	printQueue();
	
	// Task 2
	decToBin(16564);
}