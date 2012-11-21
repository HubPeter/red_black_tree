#include<iostream>
#include"trie.h"
using namespace std;


int main( int argc, char* argv[] ){
	Trie myTrie = Trie();
	myTrie.Insert( "a" );
	myTrie.Insert( "ab" );
	myTrie.Insert( "ac" );
	myTrie.Insert( "ad" );
	myTrie.Insert( "ae" );
	myTrie.Insert( "af" );
	myTrie.Insert( "abc" );
	myTrie.Insert( "abe" );
	myTrie.Insert( "abf" );
	myTrie.Insert( "add" );
	myTrie.Insert( "bb" );
	myTrie.Insert( "bh" );
	myTrie.Show();
	cout<<endl;
	myTrie.Delete("bb");
	myTrie.Show();
	cout<<endl;
	myTrie.DeleteTrie();
	return 0;
}
