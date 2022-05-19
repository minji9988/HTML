#include <stdio.h>
#include <stdlib.h>



	
	
typedef char TElement;  //         Ã¼  
	
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
}TNode;
	
TNode* root; 
	
void init_tree() {root = NULL;}
int is_empty_tree() {return root == NULL;}
TNode* get_root() {return root;}
	
	//     Æ®    Ê± È­   root   null     È®   Ï´     Ì´ . 
	//  Æ®   null     È®   Ï¸  is_empty( 
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
	
	typedef TNode* Element; //    Æ®          rootnode pointer 
	
	
void preorder(TNode *n) //      È¸ 
{ 
	if( n != NULL) { 
		printf("[%c]", n->data);
		preorder(n->left); //         Æ®    æ¹®  
		preorder(n->right); // 
	}
}
	
void inorder(TNode *n) //      È¸ 
{ 
	if( n != NULL) { 
		inorder(n->left); //         Æ®    æ¹® 
		printf("[%c]", n->data); //  Æ®(x)     Ã³   
		inorder(n->right); // 
	}
}
	
void postorder(TNode *n) //      È¸ 
{ 
	if( n != NULL) { 
		postorder(n->left); //         Æ®    æ¹®  
		postorder(n->right); // 
		printf("[%c]", n->data); //  Æ®(x)     Ã³  
	}
}
	

#define MAX_QUEUE_SIZE	100

typedef TNode* Element;

// ÇÁ·Î±×·¥ 4.1ÀÇ 6~37Çà Ãß°¡
Element data[MAX_QUEUE_SIZE];	// ¿ä¼ÒÀÇ ¹è¿­
int	front;			// Àü´Ü
int	rear;			// ÈÄ´Ü

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
								// Å¥ÀÇ ÁÖ¿ä ¿¬»ê: °øÅë
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
	if (is_full())
		error("  Å¥ Æ÷È­ ¿¡·¯");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue()
{
	if (is_empty())
		error("  Å¥ °ø¹é ¿¡·¯");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  Å¥ °ø¹é ¿¡·¯");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}
void levelorder(TNode *root)
{
	TNode* n;

	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty()) {
		n = dequeue();
		if (n != NULL) {
			printf("[%c] ", n->data);
			//print_elem(n);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int count_node(TNode *n)
{
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n)
{
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n)
{
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
}

TNode* search( TNode *n, int key )
{
if (n == NULL ) return NULL;
else if (key== n->data) return n;
else if (key < n->data) return search( n->left, key );
else return search( n->right, key );
}


void serch_BST(int key)
{
	TNode* n = search(root, key);
	
	if (n != NULL)
		printf("[Å½»ö¿¬»ê]: Success [%d] = 0x%x\n", n->data, n);
	else
		printf("[Å½»ö¿¬»ê]: Failed : NO = %d!\n", key);
}



int insert( TNode* r, TNode* n ) //»ðÀÔ¿¬»ê ¾Ë°í¸®Áò 
{
	if( n->data == r->data ) return;
	else if( n->data < r->data ) {
		if( r->left == NULL ) r->left = n;
		else insert( r->left, n );
	}
	else {
		if( r->right== NULL ) r->right = n;
		else insert( r->right, n );
	}
}



void insert_BST(int key)
{
	TNode* n = create_tree(key, NULL, NULL);
	if (is_empty_ ())
		root = n;
	else if (insert(root, n) == 0)
		free(n);
}


void delete(TNode *parent, TNode *node)
{
	TNode *chile, *succ, *succp;
}


void delete_BST(int key)
{
	TNode *parent = NULL;
	TNode *node  = root;
	
	if (node == NULL) return;
	while (node != NULL && node->data != key) {
		parent = node;
		node = (key < node->datadata) ? node->left : node->right;
	}
	if (node == NULL)
		printf("Errot: key is not in the tree! \n");
	else delete (parent, node);

 } 


int maxVal(TNode* n){
	TNode* max = n;
	
	while(max->right != NULL){
		max = max -> right;
	}
	return max->data;
}

//case 1 ´Ü¸»³ëµå »èÁ¦ 
 
if ((node->left == NULL && node->right == NULL)) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->left == node)
				parent->left = NULL;
			else parent->right = NULL;
		}
}


// case 2 ÀÚ½ÄÀÌ ÇÏ³ªÀÎ ³ëµå »èÁ¦
 
if (node->left == NULL || node->right == NULL) {
	child = (node->left != NULL) ? node->left : node->right;
		if (node == root) root = child;
			else {
				if (parent->left == node)
					parent->left = child;
				else parent->right = child;
			}
}



// case 3 µÎ °³ÀÇ ÀÚ½ÄÀ» °¡Áø ³ëµå »èÁ¦

if ((node->left == NULL && node->right == NULL)) {
	case 1
}
else if ((node->left == NULL && node->right == NULL)) {
	case 2
}
else {
		succp = node;
		succ = node->right;
		while (succ->left != NULL) {
				succp = succ;
				succ = succ->left;
}
		if (succp->left == succ) {
			succp->left = succ->right;
		else succp->right = succ->right;

		node->data = succ->data;
		node = succ;

	}
}
	
void main(){

	
	printf("[»ðÀÔ ¿¬»ê] : 35 18 7 26 12 3 68 22 30 99")
	
	init_tree();
	 
	insert_BST(35); insert_BST(18);
	insert_BST(7); insert_BST(26);
	insert_BST(12); insert_BST(3);
	insert_BST(68); insert_BST(22);
	insert_BST(30); insert_BST(99); 
	
	
	printf("\n In-Order: "); inorder(root);
	printf("\n Pre-Order: "); preorder(root);
	printf("\n Post-Order: "); postorder(root);
	printf("\n Level-Order: "); levelorder(root);
	
	
	printf("\n ³ëµåÀÇ °³¼ö= %d\n"), count_node(root));
	printf("\n ´Ü¸»ÀÇ °³¼ö= %d\n"), count_leaf(root));	
	printf("\n ³ëµåÀÇ ³ôÀÌ = %d\n"), count_height(root));
	
	printf("max value"), max_Val


}





