#include <stdio.h>
#include <stdlib.h>


	#define MAX_QUEUE_SIZE 100 
	
	
typedef char TElement;  //         ü  
	
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
}TNode;
	
TNode* root; 
	
void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* get_root() {return root;}
	
	//     Ʈ    ʱ ȭ   root   null     Ȯ   ϴ     ̴ . 
	//  Ʈ   null     Ȯ   ϸ  is_empty( 
	//create_tree(e, left, right)
	//get root()   return root; 
	
	
//	void init_tree() {root
//	}

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
	TNode* n = (TNode*) malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}
	
	typedef TNode* Element; //    Ʈ          rootnode pointer 
	
	
void preorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		printf("[%c]", n->data);
		preorder(n->left); //         Ʈ    湮  
		preorder(n->right); // 
	}
}
	
void inorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		inorder(n->left); //         Ʈ    湮 
		printf("[%c]", n->data); //  Ʈ(x)     ó   
		inorder(n->right); // 
	}
}
	
void postorder(TNode *n) //      ȸ 
{ 
	if( n != NULL) { 
		postorder(n->left); //         Ʈ    湮  
		postorder(n->right); // 
		printf("[%c]", n->data); //  Ʈ(x)     ó  
	}
}
	
	
void levelorder(TNode *root) 
{
	TNode* n;
		
	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty()){
		n = dequeue();
		if (n != NULL) {
			printf("[%c]", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

	
	int front;
	int rear;
	
	
	void int_queue() {front = rear = 0;}
	int is_empty() {return front == rear;}
	int is_full() {return front == (rear + 1) % MAX_QUEUE_SIZE;}
	int size() {return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;}
	Element data[MAX_QUEUE_SIZE]; //       迭

	
	void error(char str[])
	{
		printf("%s\n", str);
		exit(1);
	 } 
	
	
	
	void enqueue(Element val)
	{
		if (is_full())
			error("ť   ȭ");
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
					
	}
	
	Element dequeue()
	{
		if (is_empty())
		error("ť          ");
		front = (front + 1)  % MAX_QUEUE_SIZE;
		return data[front];
	}
	
	Element peek()
	{
		if (is_empty())
		error("ť          ");
		return data[(front+1)% MAX_QUEUE_SIZE];
	}
	
int main(){


	TNode *b, *c, *d, *e, *f;
	
	init_tree();
	 
	d = creat_tree('D', NULL, NULL);
	e = creat_tree('E', NULL, NULL);
	b = creat_tree('B', d, e);
	f = creat_tree('F', NULL, NULL);
	c = creat_tree('C', f, NULL);
	root = create_tree('A', b, c);
	
	printf("\n In-Order: "); inorder(root);
	printf("\n Pre-Order: "); preorder(root);
	printf("\n Post-Order: "); postorder(root);
	printf("\n Level-Order: "); levelorder(root);

	return 0;
}
