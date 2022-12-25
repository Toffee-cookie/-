//串的存储结构
//1.定长顺序串存储结构
#define MAXSIZE 50
typedef struct{
	char ch[MAXSIZE+1];
	int len;
}SString; 
//2.堆串（通过动态分配函数从中分配一块实际串所需的存储空间） 
typedef struct{
	char* ch;//若是非空串，则指向串的起始地址 
	int len;
}HString;
//3.块链串
#define BLOCK_SIZE 4//每个结点存放字符个数为4
typedef struct block{
	char ch[BLOCK_SIZE];
	struct block *next;
}Block;
typedef struct{
	Block *head;
	Block *tail;
	int len;
}LString;
//模式匹配算法
//1.BF匹配
int Index(String S,String T,int pos){
	int i=pos;
	int j=1;
	while(i<=S[0]&&j<=T[0]){
		if(S[i]==T[j]){
			++i;
			++j;
		}
		else{
			i=i-j+2;
			j=1;
		}
	}
	if(j>T[0]){
		return i-T[0];
	}
	else{
		return 0;
	}
} 
//2.KMP匹配
//返回子串T的next数组
void get_next(String T,int *next){
	int i=1,k=0;
	int next[1]=0;
	while(i<T[0]){
		if(k==0||T[i]==T[k]){//为0或者前缀和后缀相同的话便可以获得++i的next值，为匹配重叠个数加1 ,T[k]是前缀 
			++i;
			++k;
			next[i]=k; 
		}
		else{
			k=next[k];//不相等则取拿着门牌号去找需要的k 
		}
	}
} 

//返回子串T在主串S中第pos个字符之后的位置
int Index_KMP(String S,String T,int pos){
	int i=pos;
	int j=1;
	int next[255];
	get_next(T,next);
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			++i;
			++j;
		}
		else{
			j=next[j];//j找到合适的位置，i不变 
		}
	}
	if(j>T[0]){
		return i-T[0];
	} 
	else{
		return 0;
	}
} 

//优化算法nextval
void get_nextval(String T,int *nextval){
	int i=1,k=0;
	int nextval[1]=0;
	while(i<T[0]){
		if(k==0||T[i]==T[k]){
			++i;
			++k;
			if(T[i]!=T[k]){//有所变化，若当前字符和前缀不相同则k为当前在i位置的值 
				nextval[i]=k;
			}
			else{
				nextval[i]=nextval[k];//否则，则是和他相同的前缀的i位置的值 
			}
		}
		else{
			k=nextval[k];
		}
	}
} 
