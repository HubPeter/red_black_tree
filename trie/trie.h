#define CHARSIZE 26
#include<assert.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
树节点，用于存储当前字符信息
*/
typedef struct NODE {
	char key;//该值可以没有，由于程序的，可以注释掉相关代码
	bool isNode;//当前节点代表的字符串是否是存入的节点
	struct NODE* child[ CHARSIZE ];//26叉树，按照a-z的顺序，如果是NULL表示该字母位置为空
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
	PNODE pRoot;//树指针
 	static char colls[];//代表26个字母，可以设置自定义的映射和长度
};
char Trie::colls[] = "abcdefghijklmnopqrstuvwxyz ";
/*
构造函数，创建根节点
*/
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
/*
插入新节点
*/
void Trie::Insert( char* sData ){
	//如果字符串为空，不允许插入
	if( sData==NULL || *sData == '\0' ){
		return;
	}
	//获取根指针，用于后边的查找正确的插入位置
	PNODE p = this->pRoot;
	char* pData = sData;//当前字符指针
	//循环直到处理完所有字符
	while( *pData!='\0' ){
		//如果对应位置的指针为空,就创建新的节点
		if( p->child[ *pData-'a' ]==NULL ){
			//make new Node
			PNODE node = (PNODE)malloc(sizeof(struct NODE));
			//node->key = *pData;//key是多余的字段
			node->isNode = true;//该新节点表示真正的存储节点而不是前缀
			int i = 0;
			while( i < CHARSIZE ){
				node->child[i] = NULL;
				i++;
			}
			//将新节点链接到树中的合适位置
			p->child[*pData-'a'] = node;
		}
		//go on loop
		p = p->child[ *pData-'a' ];
		//deal with next character
		pData++;
	}
}
/*
Show string stored in Trie tree
:( not look well, but you can draw on paper from this output
or whtn you delete one node, you will see the change
*/
void Trie::Show( ){
	//为了便于递归调用，使用中间函数
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
/*
Delete node from Trie tree
*/
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
/*
Is a node has children
*/
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


