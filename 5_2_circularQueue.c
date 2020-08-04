#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// error function
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// initialization
void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
    printf("Queue(front = %d rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d |  ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("Queue is full");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("Queue is empty!");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType* q)
{
    if (is_empty(q))
        error("Queue is empty!");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--Step of adding data--\n");
    while (!is_full(&queue))
    {
        printf("Please enter the integer: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("Queue is full\n\n");

    printf("--Step of deleting data--\n\n");
    while (!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("integer: %d  \n", element);
        queue_print(&queue);
    }
    printf("Queue is empty!\n");
    return 0;
}