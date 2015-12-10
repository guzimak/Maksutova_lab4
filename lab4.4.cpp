#include "sdt.h"
bool err=true;
//функция для пункта 4.2
void NameChecking(char* name)
{
    //проверка на символы *,",<,>,?,|
    for(int i=0; i<strlen(name); ++i)
    {
        if (name[i]=='*' || name[i]=='"' || name[i]=='<' || name[i]=='>' || name[i]=='?' || name[i]=='|')
        {
            cout <<"Error: symbol " <<name[i] <<endl;
            err=true;
        }
    }
    //проверка на двоеточие
    if (strchr(name,':')==&name[0])
    {
        cout<<"Error: the symbol \":\" on the first position"<<endl;
        err=true;
    }
    else
        for (int i=1; i<strlen(name)-1; ++i)
    {
        if(name[i]==':')
        {
            if(!isalpha(name[i-1]))
            {
                cout <<"before : not a letter"<<endl;
                err=true;
            }
            if(name[i+1]!='\\')
            {
                cout <<"after : not \\"<<endl;
                err=true;
            }
        }
    }
    //проверка на расширение
    char name1[4];
    for(int i=0; i<4;++i)
        name1[i]=name[strlen(name)-4+i];

    if ( strncmp( name1, ".txt", 4 ) != 0 && strncmp( name1, ".TXT", 4 ) != 0)
    {
        cout<<"The extension does not .txt' (.TXT)"<<endl;
        err=true;
    }
}

int main()
{
    char NameFile[22];
    //ввод имени файла, пока оно не будет корректное
    while (err)
    {
        err=false;
        cout <<"Enter the name of the file (.txt)\n";
        cin >>NameFile;
        NameChecking(NameFile);
        cout <<endl;
    }
    //пункт 4.3: загрузить сожержимое файла
    FILE * ptrFile = fopen(NameFile, "a+");
    fseek(ptrFile,0,SEEK_END);  //положение в конец файла
    int size = ftell(ptrFile);  //размер в байтах
    cout <<"Size file: "<<size<<endl;
    fseek(ptrFile,0,SEEK_SET);
    char *mass = new char[ size +1 ];
    memset(mass, 0, size +1);
    size_t result = fread(mass, sizeof(char), size, ptrFile);
    if (result != ftell(ptrFile))
    {
        fputs("Error reading", ptrFile);
        exit (1);
    }
    cout <<endl<<"The contents of the file:"<<endl;
    puts(mass);
    //пункт 4.4: ввести искомую строку в тексте
    cout <<endl <<"Enter a search string:  ";
    char stroca[20];
    cin >>stroca;

    //пункт 4.5: найти введенную строку
    char *cp = (char *) mass;
    char *s1, *s2;
    while(*cp)
    {
        s1 = cp;
        s2 = (char *) stroca;
        while ( *s1 && *s2 && !(*s1-*s2) )
                s1++, s2++;
            if (!*s2)
                cout<<"Position of the string: "<<(cp-mass+1)<<"\n";
        cp++;
    }
    //пункт 4.6: разбить файл на предложения, поместив их в char**
    int * pos=new int [20];
    int number=0;
    pos[0]=-1;
    for(int i=0; i<size; ++i)
            if(mass[i] == '.' || mass[i] == '?' || mass[i] == '!')
            {
                ++number;
                pos[number]=i;
            }
    cout <<"\nThe number of proposals: "<<number<<endl;
    char ** proparray=new char*[number];
        for(int i=0; i<number; ++i)
        {
            fseek(ptrFile, pos[i]+1,SEEK_SET);
            char * mass1 = new char[pos[i+1]];
            fread(mass1,sizeof(char),pos[i+1],ptrFile);
            char * mass2 = new char[pos[i+1]];
            proparray[i]= strncpy(mass2, mass1, (pos[i+1]-pos[i])*sizeof(char));
            delete [] mass1;
        }
        fclose (ptrFile);
        cout<<endl;
        for(int i=0; i<number; ++i)
           cout<<i+1<<" proposal ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    //пункт 4.7: упорядочить предложения по возрастанию
    char * c;
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (strlen(proparray[j]) > strlen(proparray[j+1]))
            {
                c=proparray[j];
                proparray[j]=proparray[j+1];
                proparray[j+1]=c;
            }
        }
    }
    cout<<"\n\nAfter sorting:\n";
    for(int i=0; i<number; ++i)
           cout<<i+1<<" proposal ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    //пункт 4.8: записать предложения в новый файл

    char NameFile2[20];
    err=true;
    while (err)
    {
        err=false;
        cout <<"Enter the name of the file (.txt)\n";
        cin >>NameFile2;
        NameChecking(NameFile2);
        cout <<endl;
    }
    FILE * ptrFile2 = fopen(NameFile2, "a+");
    fseek(ptrFile2,0,SEEK_SET);  //положение в начало файла
    for(int i=0; i<number; ++i)
        fputs(proparray[i], ptrFile2);
        fclose (ptrFile2);

    //пункт 4.9: освободить все выделенные блоки памяти
    for(int i=0; i<number; ++i)
    {
       delete[] proparray[i];
    }
    delete [] mass, pos, cp, proparray;
    delete s1, s2, c;
}
