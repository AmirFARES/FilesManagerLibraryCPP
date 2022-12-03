#include <iostream>
#include "GestFile.h"

using namespace std;

// Prototype ______________________________
File Fusion(File f,File f1,File f2);

int main()
{
    int n,v;
    File f1;f1.l=NULL;
    File f2;f2.l=NULL;
    File f;f.l=NULL;
    //
    cout << "Donner le nomre de la 1 er file : " ;
    cin >> n;
    cout << "Enfiler la 1 er file : " << endl ;
    for(int i=0;i<n;i++)
    {
        cin >> v;
        f1 = Enfiler(f1,v);
    }
    //
    cout << "Donner le nomre de la 2 eme file : " ;
    cin >> n;
    cout << "Enfiler la 2 eme file : " << endl ;
    for(int i=0;i<n;i++)
    {
        cin >> v;
        f2 = Enfiler(f2,v);
    }
    //
    f=Fusion(f,f1,f2);
    //
    cout << "Apres la fusion : " << endl ;
    AfficheFile(f);
    return 0;
}

File Fusion(File f,File f1,File f2)
{
    int v1,v2;
        f1 = Defiler(f1,&v1);
        f2 = Defiler(f2,&v2);
    while((!(FileVide(f1)))&&(!(FileVide(f2))))
    {
        if(v1<v2)
        {
            f = Enfiler(f,v1);
            f1 = Defiler(f1,&v1);
        }
        else
        {
            f = Enfiler(f,v2);
            f2 = Defiler(f2,&v2);
        }
    }
    if((FileVide(f1))&&(FileVide(f2)))
    {
        if(v1<v2)
        {
            f = Enfiler(f,v1);
            f = Enfiler(f,v2);
        }
        else
        {
            f = Enfiler(f,v2);
            f = Enfiler(f,v1);
        }
    }
    int k=0;
    while(!(FileVide(f1)))
    {
        if((v2<=v1)&&(k==0))
        {
            f = Enfiler(f,v2);
            k++;
        }
        f = Enfiler(f,v1);
        f1 = Defiler(f1,&v1);
        if(FileVide(f1))
        {
            if((v2<=v1)&&(k==0))
            {
                f = Enfiler(f,v2);
                k++;
            }
            if(k==0)
            {
                f = Enfiler(f,v1);
                f = Enfiler(f,v2);
            }
            f = Enfiler(f,v1);
        }
    }
    while(!(FileVide(f2)))
    {
        if((v1<=v2)&&(k==0))
        {
            f = Enfiler(f,v1);
            k++;
        }
        f = Enfiler(f,v2);
        f2 = Defiler(f2,&v2);
        if(FileVide(f2))
        {
            if((v1<=v2)&&(k==0))
            {
                f = Enfiler(f,v1);
                f = Enfiler(f,v2);
                k++;
            }
            if(k==0)
            {
                f = Enfiler(f,v2);
                f = Enfiler(f,v1);
            }
        }
    }
    return f;
}
