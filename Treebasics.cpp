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

struct DataNode* searchInTree(int keyToFind){
	struct DataNode * currentNode=rootNode;
	while(currentNode!=NULL){
		if(currentNode->key==keyToFind) return currentNode;
		else{
			if(currentNode->key > keyToFind) currentNode=currentNode->leftNode;
			else currentNode=currentNode->rightNode;
		}
	}
	return NULL;	
}

int main(){
	//int array[7]={ 27, 14, 35, 10, 19, 31, 42 };
	// need to sort it and put inside balanced tree
	
	//for(int i=0;i<7;i++)
	//insertIntoTree(array[i]);
	
	insertIntoTree(55);
	insertIntoTree(20);
	insertIntoTree(90);
	insertIntoTree(50);
	insertIntoTree(35);
	insertIntoTree(15);
	insertIntoTree(65);
	traverseTree(rootNode);
	
	struct DataNode *resultNode=NULL;
	resultNode=searchInTree(36);
	resultNode==NULL?printf("not found"):printf("found key=%d",resultNode->key);
	
	return 1;
}
