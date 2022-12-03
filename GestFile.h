#include <iostream>

using namespace std;

//structures _____________________________
typedef struct Liste
{
    int val;
    Liste *suiv;
}Liste;

typedef struct File
{
    Liste *l;
    Liste *quee;
}File;

//Prototype ______________________________
File Enfiler (File fa,int v);
File Defiler(File fa,int *v);
bool FileVide(File fa);
void AfficheFile(File fa);

//functions ______________________________
File Enfiler (File fa,int v)
{
    Liste *ptr=new Liste;
    ptr->val=v;
    ptr->suiv=NULL;
    if(FileVide(fa))
    {
        fa.l=ptr;
    }
    else
    {
        fa.quee->suiv=ptr;
    }
    fa.quee=ptr;
    return(fa);
}

File Defiler(File fa,int *v)
{
    Liste *ptr = fa.l;
    fa.l = fa.l->suiv;
    *v = ptr->val;
    delete ptr;
    return(fa);
}

bool FileVide(File fa)
{
    return(fa.l==NULL);
}

void AfficheFile(File fa)
{
    int v;
    while(!(FileVide(fa)))
    {
            fa = Defiler(fa,&v);
            cout << v << endl ;
    }
}
