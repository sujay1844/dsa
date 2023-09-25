#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *next;
};

int push(struct Node **head, char data) {
	struct Node *new_plate = malloc(sizeof(struct Node));
	new_plate->data = data;
	new_plate->next = *head;
	*head = new_plate;
	return 0;
}

char pop(struct Node **head) {
	if(*head == NULL) {
		return -1;
	}
	struct Node *oldNode = *head;
	int data = oldNode->data;
	*head = oldNode->next;
	free(oldNode);
	return data;
}

char peek(struct Node *head) {
    return head->data;
}

int precedence(char ch) {
    switch(ch) {
        case '(': return 3;
        case '^': return 2;
        case '*':
        case '/': return 1;
        case '+':
        case '-': return 0;
        default: return -1;

    }
}

int main() {
    struct Node *head = NULL;
    char exp[100];
    scanf("%s", exp);
    int i = 0;
    char ch = exp[i++];
    while(ch != '\0') {
        
        if(ch >= '0' && ch <= '9') {
            printf("%c", ch);
        }
        else if(ch == ' ') continue;
        else if (ch == '(') {
            push(&head, ch);
        }
        else if (ch == ')') {
            char popped;
            while((popped = pop(&head)) != '(') {
                printf("%c", popped);
            }
        }
        else {
            while (head != NULL && precedence(ch) >= precedence(peek(head))) {
                if(pop(&head) == '(') {
                    printf("%c", ch);
                } else {
                    printf("%c", pop(&head));

                }
            }
            push(&head, ch);
        }
        ch = exp[i++];
    }
    while(head != NULL) {
        printf("%c", pop(&head));
    }
}