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

void traverseInorder(struct DataNode* root,int* result, int* i){
    if(root->leftNode!=NULL) traverseInorder(root->leftNode,result,i);
    if(root!=NULL){
        int index=*i;
        result[index]=root->key;
        *i=index+1;
    }
    if(root->rightNode !=NULL) traverseInorder(root->rightNode,result,i);
}

int* inorderTraversal(struct DataNode* root, int* returnSize){
    if(root==NULL) return NULL;
    else{
        int *result=(int*)malloc(sizeof(int)*100);
        *returnSize=0;
        traverseInorder(root,result,returnSize);
        return result;
    }

}

int main(){
	int array[7]={ 27, 14, 35, 10, 19, 31, 42 };
		// need to sort it and put inside balanced tree
		
	for(int i=0;i<7;i++)
	insertIntoTree(array[i]);
	
	int returnSize=0;
	int *ptr=inorderTraversal(rootNode,&returnSize);
	
	for(int i=0;i<returnSize;i++)
	printf("%d ",ptr[i]);
	
	return 1;
}
