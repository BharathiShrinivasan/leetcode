#include<stdio.h>
#include<cstdlib>

struct DataNode{
	int key;
	struct DataNode * leftNode;
	struct DataNode * rightNode;
};

struct DataNode * rootNode=NULL;

void insertIntoTree(int newData){
	// creat a node and init NULL left right
	struct DataNode * newNode=(struct DataNode *) malloc(sizeof(struct DataNode));
	newNode->key=newData;
	newNode->leftNode=NULL;
	newNode->rightNode=NULL; 
	
	if(rootNode==NULL){
		rootNode=newNode;
	}
	else{
		struct DataNode *currentNode=rootNode;
		while(currentNode!=NULL){
			if(newData<currentNode->key){ // need to traverse left;
				if(currentNode->leftNode == NULL){ // if left is empty insert it here
					currentNode->leftNode=newNode;
					currentNode=NULL;
				}
				else currentNode=currentNode->leftNode;
			}
			else{
				if(newData>currentNode->key){ // need to traverse rigth;
					if(currentNode->rightNode==NULL){
						currentNode->rightNode=newNode;
						currentNode=NULL;
					}
					else currentNode=currentNode->rightNode;
				}
			}
		}
	}	
}

void traverseTree(struct DataNode * rootNode){
	if(rootNode->leftNode != NULL) traverseTree(rootNode->leftNode);
	printf("%d ",rootNode->key);
	if(rootNode->rightNode != NULL) traverseTree(rootNode->rightNode);
}

int maxDia=0;
int GetMaxDepth(struct DataNode* root)
{
    if(root==NULL) return 0;
    int leftDepth=GetMaxDepth(root->leftNode);
    int rightDepth=GetMaxDepth(root->rightNode);
    maxDia=(maxDia<(leftDepth+rightDepth))?(leftDepth+rightDepth):maxDia;
    return (leftDepth>rightDepth?leftDepth+1:rightDepth+1);
}

int diameterOfBinaryTree(struct DataNode* root){
    int maxDiameter=0;
    GetMaxDepth(root);
    maxDiameter=maxDia;
    return maxDiameter;
}


int main(){
	int array[7]={ 15,10,9,8,11,12,14 };//{ 27, 14, 35, 10, 19, 31, 42 };
		// need to sort it and put inside balanced tree
		
	for(int i=0;i<7;i++)
	insertIntoTree(array[i]);
	traverseTree(rootNode);
	printf("\n\nresult- %d",diameterOfBinaryTree(rootNode));
	
	return 1;
}
