#include<stdio.h>
#include<stdlib.h>


struct nodemain
{
	struct nodemain *next;
	int data;
	struct node *adjmain;
	int visited;
	int visitedcoloring;
	int color;
	struct nodecolor *adjcolorlist;


	
};
struct node
{
	
	int data;
	struct nodemain *mainaddr;
	struct node *adj;


	
};
struct nodecolor
{
	
	int data;
	
	
	struct nodecolor *nodecolornext;


	
};
struct dftsequence
{
	
	int data;
	
	struct dftsequence *dftnext;
	struct nodemain *nodeaddr;


	
};
struct nodemain *makenode(struct nodemain *root,int x){
if(root==NULL)
	return root;
struct nodemain *s=(struct nodemain*)malloc(sizeof(struct nodemain));
struct nodemain *p=root;
while(root->next!=NULL){
	root=root->next;


}
root->next=s;
s->next=NULL;
s->data=x;
s->adjmain=NULL;
s->visited=0;
s->visitedcoloring=0;
s->adjcolorlist=NULL;
printf("%d:%d:%u:%u:",s->data,s->visited,s,s->next);
return p;


}

struct nodemain *findnode(struct nodemain *root,int x){
	if(root==NULL)
		return root;
	while(root->next!=NULL&& root->data!=x){
		root=root->next;
	}
	if(root->data==x){
		return root;
	}else{
		printf("wrong vertex inserted!! No such vertex as %d exists",x);
		exit(1);
	}


}
void createandlink(int x,struct nodemain *p,struct nodemain *c){
	struct node *aux,*aux1;
	aux=(struct node*)malloc(sizeof(struct node));
				
				aux->data=x;
				aux->mainaddr=findnode(p,x);
				aux->adj=NULL;

	if(c->adjmain==NULL){
		c->adjmain=aux;
	}else{
		aux1=c->adjmain;
		while(aux1->adj!=NULL){
			aux1=aux1->adj;

		}
		aux1->adj=aux;


	}

		
	
	}
	void makedft(struct dftsequence *aux,int x,struct nodemain *root){
		while(aux->dftnext!=NULL){
			aux=aux->dftnext;

		}
		
		struct dftsequence *aux1;
		aux1=(struct dftsequence*)malloc(sizeof(struct dftsequence));
		aux->dftnext=aux1;
		aux1->nodeaddr=root;
	aux1->data=x;
	aux1->dftnext=NULL;

	}


void dft(struct nodemain *root,struct nodemain *root1,struct dftsequence *aux){
	struct node *first;
	root->visited=1;
	if(root==root1){
		aux->data=root->data;
		aux->dftnext=NULL;
		aux->nodeaddr=root;
		printf("%u\n",root );

	}else{

		makedft(aux,root->data,root);

	}
	
	
	
	

	printf("%d\n",root->data);
	if(root->adjmain!=NULL){
		first=root->adjmain;
	

	while(first!=NULL){
		if(first->mainaddr->visited!=1){
			dft(first->mainaddr,root1,aux);
		}
		first=first->adj;

	}
	return;

	}else{
		return;
	}
	
}
int valuenotpresent(struct nodecolor *p,int x){


	while(p->nodecolornext!=NULL&&p->data!=x){
		
		printf("%u\n",p);

			
			p=p->nodecolornext;

		}
		if(p->data==x){
			
			return 0;
		}else{
			
			return 1;
		}

}
int findminimum(struct nodemain *s,int n){
	struct nodecolor *p;
	int x;
	if(s->adjcolorlist==NULL){
		return 0;

	}

	p=s->adjcolorlist;

	for(int i=0;i<n;i++){
		x=valuenotpresent(p,i);
		

		if(x==1){
			

			return i;
		}

	}


}

void addcolornode(struct nodemain *p,int x){
	struct nodecolor *p1,*p2;
	p1=(struct nodecolor*)malloc(sizeof(struct nodecolor));
	p1->data=x;
	p1->nodecolornext=NULL;

	if(p->adjcolorlist==NULL){
		p->adjcolorlist=p1;
		return;

	}
	p2=p->adjcolorlist;
	while(p2->nodecolornext!=NULL){
		p2=p2->nodecolornext;

	}
	
	p2->nodecolornext=p1;
		



}
void graphcoloring(struct dftsequence *d,int n){
     struct nodemain *s;
     struct node *s1;
     int x;
     

     s=d->nodeaddr;
   
     s1=s->adjmain;
     s->visitedcoloring=1;
     


     if(s->adjcolorlist==NULL){
     	
     	s->color=0;
     	
     	
     }else{
     	
     	x=findminimum(s,n);

     	s->color=x;
     	


     }

     
     while(s1!=NULL){
     	
     		if(s1->mainaddr->visitedcoloring!=1){
     			
     			addcolornode(s1->mainaddr,s->color);
     			


     		}

     		s1=s1->adj;
     		printf("%u\n",s1);

     	}



}


int main(){
	int n,n1,a;

	struct nodemain *head,*s;
	struct node *aux,*aux1;
	printf("hello world");
	printf("\nhow many nodes you have?");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i==1){
			head=(struct nodemain*)malloc(sizeof(struct nodemain));
			printf("%u\n",head );
			head->next=NULL;
			head->data=i;
			head->visited=0;
			head->visitedcoloring=0;
			head->adjcolorlist=NULL;
			head->adjmain=NULL;

		}else{
			head=makenode(head,i);

		}
		



	}
	s=head;
	for(int i=1;i<=n;i++){
		printf("\n%d:%d:%u:%u:%u\n",s->data,s->visited,s,s->next,s->adjmain);

	s=s->next;

		
		



	}
	s=head;
	for(int i=1;i<=n;i++){
		printf("\nenter number of adjacent nodes  for node %d",i);
		scanf("%d",&n1);
		printf("\n enter adjacency list for node %d",i);
		for(int j=1;j<=n1;j++){
			printf("\n enter node %d:",j);


			scanf("%d",&a);
			printf("%d is ajacent",a);
			printf("\n");
			createandlink(a,head,s);
			/*if(j==1){
				s=head;
				
				aux=(struct node*)malloc(sizeof(struct node));
				s->adjmain=aux;
				aux->data=a;
				aux->mainaddr=findnode(head,a);
				aux->adj=NULL;



			}else{

				aux1=(struct node*)malloc(sizeof(struct node));
				s->adjmain=aux1;
				aux->adj=aux1;
				aux1->data=a;
				aux1->mainaddr=findnode(head,a);
				aux1->adj=NULL;
				aux=aux1;



			}*/

			}
		s=s->next;
		printf("hello world");




	}
	s=head;
	for(int i=1;i<=n;i++){
		printf("\n%d node list\n",i);
		printf("\n%d:%d:%u:%u:%u\n",s->data,s->visited,s,s->next,s->adjmain);
		aux=s->adjmain;
		
		while(aux!=NULL){
			
				printf("\n%d:%u:%u:%u\n",aux->data,aux,aux->mainaddr,aux->adj);
			aux=aux->adj;

		}
		
		
		s=s->next;




	}
	printf("%u calling dfs\n",head );
	
	
	struct dftsequence *auxi,*auxihead;
		auxi=(struct dftsequence*)malloc(sizeof(struct dftsequence));
		auxihead=auxi;
	
	dft(head,head,auxi);
	printf(" calling  auxihead\n");
	
	while(auxihead!=NULL){
		
		printf("%d:%u:%u:%u\n",auxihead->data,auxihead ,auxihead->dftnext,auxihead->nodeaddr);

		auxihead=auxihead->dftnext;


	}

	auxihead=auxi;
	printf("%u is auxihead value\n",auxihead );
	while(auxihead!=NULL){


		graphcoloring(auxihead,n);
		
		
		auxihead=auxihead->dftnext;
		

	}
	s=head;

	struct nodecolor *ptr;
	while(s!=NULL){
		ptr=s->adjcolorlist;
		printf("\n %d colorlist is:",s->data);
		while(ptr!=NULL){
			printf("%d",ptr->data);
			ptr=ptr->nodecolornext;
		}
		
		s=s->next;

	}
	s=head;
	printf("\n");
	while(s!=NULL){
		printf("%d color is:%d\n",s->data,s->color );
		s=s->next;

	}
	



	return 0;
}


