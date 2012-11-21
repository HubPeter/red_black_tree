#define CHARSIZE 26
#include<assert.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct NODE {
	char key;
	bool isNode;
	struct NODE* child[ CHARSIZE ];
}* PNODE,*TRIE;

class Trie{
public:
	Trie();
	void Insert( char* sData );
	void Show( );
	void ShowTrie( PNODE root );
	bool Delete( char* sData );
	bool NoChild(PNODE pNode);
	struct NODE* Search( char* sData );
	void DeleteTrie();
	~Trie();
private:
	PNODE pRoot;
 	static char colls[];
};
char Trie::colls[] = "abcdefghijklmnopqrstuvwxyz ";
Trie::Trie(){
	//root create
	this->pRoot = NULL;
	this->pRoot = (PNODE)malloc(sizeof(struct NODE));
	this->pRoot->key = ' ';
	this->pRoot->isNode = false;
	for( int i=0; i<CHARSIZE; i++ ){
		this->pRoot->child[ i ] = NULL;
	}
}
void Trie::Insert( char* sData ){
	//stick
	if( sData==NULL || *sData == '\0' ){
		return;
	}
	PNODE p = this->pRoot;
	char* pData = sData;
	//same error sigabrt ginal
	//still error
	//PNODE node = (PNODE)malloc(sizeof(struct NODE)); 
	while( *pData!='\0' ){
		//如果对应位置的指针为空
		if( p->child[ *pData-'a' ]==NULL ){
			//make new Node
			PNODE node = (PNODE)malloc(sizeof(struct NODE));
			
			node->key = *pData;
			node->isNode = true;
			int i = 0;
			while( i < CHARSIZE ){
				node->child[i] = NULL;
				i++;
			}
			p->child[*pData-'a'] = node;
		}
		
		p = p->child[ *pData-'a' ];
		pData++;
	}
}
void Trie::Show( ){
	ShowTrie( this->pRoot );
}
void Trie::ShowTrie( PNODE root ){
	if( root==NULL ){
		return;
	}
	if( root->isNode == true )
		cout<<root->key<<"	";
	for( int i=0; i<CHARSIZE; i++ ){
		ShowTrie( root->child[i] );
	}
}
bool Trie::Delete( char * sData ){
	if( sData==NULL || *sData=='\0' )
		return false;
	PNODE p = this->pRoot;
	PNODE pre = NULL;
	char *pData = sData;

	while(pData!=NULL && *pData!='\0'){
		if( p==NULL || p->child[*pData-'a']==NULL ){
			cout<<"No:"<<*sData<<endl;
		}else if( p->child[*pData-'a']->isNode==true ){
			//delete this
			if( NoChild(p->child[*pData-'a']) ){
				p->child[*pData-'a'] = NULL;//delete this node directly
			}else{//has children
				p->child[*pData-'a']->isNode = false;
			}
			return true;
		}else{
			pre = p;
			p = p->child[*pData-'a'];
			pData++;
		}
	}
	return false;
}
bool Trie::NoChild(PNODE pNode){
	if(pNode == NULL)
		return true;
	for( int i=0; i<CHARSIZE; i++ ){
		if( pNode->child[i]!=NULL ){
			return false;
		}
	}
	return true;
}
void Trie::DeleteTrie(){
	
}
Trie::~Trie(  ){}


