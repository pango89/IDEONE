#include<cstdio>
#include<cstring>

#define MAXSIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

int charToIndex(char ch)
{
	return ch-'a';
}

struct trie_node
{
	int value;
	trie_node* children[MAXSIZE];
};

struct trie
{
	trie_node* root;
	int count;
};

trie_node* getNode()
{
	trie_node* temp= new trie_node;
	if(!temp)
		return NULL;
	temp->value=0;
	for(int i=0;i<MAXSIZE;i++)
		temp->children[i]=NULL;
	return temp;
}	

void initialize(trie* t)
{
	t->root=getNode();
	t->count=0;
}

void insert(trie* t,char str[])
{
	trie_node* pCrawl=t->root;
	int len=strlen(str);
	t->count++;
	
	for(int level=0; level< len; level++)
	{
		int index=charToIndex(str[level]);
		if(pCrawl->children[index]==NULL)
		{
			pCrawl->children[index]=getNode();
		}
		pCrawl=pCrawl->children[index];
	}
	//MARK LAST NODE AS LEAF
	pCrawl->value=t->count;
}	

bool search(trie* t,char str[])
{
	trie_node* pCrawl=t->root;
	int len=strlen(str);
	
	for(int level=0; level< len; level++)
	{
		int index=charToIndex(str[level]);
		
		if(pCrawl->children[index]==NULL)
			return false;
		
		pCrawl=pCrawl->children[index];
	}
	//MARK LAST NODE AS LEAF
	return (pCrawl!=NULL && pCrawl->value!=0);
}	
	
// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie t;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    initialize(&t);
 
    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&t, keys[i]);
    }
 
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&t, "the")] );
    printf("%s --- %s\n", "these", output[search(&t, "these")] );
    printf("%s --- %s\n", "their", output[search(&t, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&t, "thaw")] );
 
    return 0;
}		