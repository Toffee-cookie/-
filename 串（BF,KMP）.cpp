//���Ĵ洢�ṹ
//1.����˳�򴮴洢�ṹ
#define MAXSIZE 50
typedef struct{
	char ch[MAXSIZE+1];
	int len;
}SString; 
//2.�Ѵ���ͨ����̬���亯�����з���һ��ʵ�ʴ�����Ĵ洢�ռ䣩 
typedef struct{
	char* ch;//���Ƿǿմ�����ָ�򴮵���ʼ��ַ 
	int len;
}HString;
//3.������
#define BLOCK_SIZE 4//ÿ��������ַ�����Ϊ4
typedef struct block{
	char ch[BLOCK_SIZE];
	struct block *next;
}Block;
typedef struct{
	Block *head;
	Block *tail;
	int len;
}LString;
//ģʽƥ���㷨
//1.BFƥ��
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
//2.KMPƥ��
//�����Ӵ�T��next����
void get_next(String T,int *next){
	int i=1,k=0;
	int next[1]=0;
	while(i<T[0]){
		if(k==0||T[i]==T[k]){//Ϊ0����ǰ׺�ͺ�׺��ͬ�Ļ�����Ի��++i��nextֵ��Ϊƥ���ص�������1 ,T[k]��ǰ׺ 
			++i;
			++k;
			next[i]=k; 
		}
		else{
			k=next[k];//�������ȡ�������ƺ�ȥ����Ҫ��k 
		}
	}
} 

//�����Ӵ�T������S�е�pos���ַ�֮���λ��
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
			j=next[j];//j�ҵ����ʵ�λ�ã�i���� 
		}
	}
	if(j>T[0]){
		return i-T[0];
	} 
	else{
		return 0;
	}
} 

//�Ż��㷨nextval
void get_nextval(String T,int *nextval){
	int i=1,k=0;
	int nextval[1]=0;
	while(i<T[0]){
		if(k==0||T[i]==T[k]){
			++i;
			++k;
			if(T[i]!=T[k]){//�����仯������ǰ�ַ���ǰ׺����ͬ��kΪ��ǰ��iλ�õ�ֵ 
				nextval[i]=k;
			}
			else{
				nextval[i]=nextval[k];//�������Ǻ�����ͬ��ǰ׺��iλ�õ�ֵ 
			}
		}
		else{
			k=nextval[k];
		}
	}
} 
