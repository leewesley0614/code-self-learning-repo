#define MaxLEN 255
#define CHUNKSIZE 80

typedef struct
{
    char ch[MaxLEN + 1];
    int length; // current string length
}SString;

typedef struct Chunk
{
    char ch[CHUNKSIZE]; //结点可以不止放一个字符，允许放多个字符提高存储密度
    Chunk *next;
}Chunk;

typedef struct
{
    Chunk *head, *tail;
    int curlen;
}LSting;

int index_BF(SString S, SString T)
{
    
}