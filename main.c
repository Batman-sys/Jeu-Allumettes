#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

int left=75,
  right=77,
  enter=13,
  escape=27;








int aleatoire(int max)
{
  int nbr;
  srand(time(NULL));
  nbr=rand() % max;
  nbr++;
  return nbr;
}







void main()
{








  int  i,tour,take,difficulte,allu;
  char left,right,bouton,enter,escape;








  start:
  tour=1,take=0,difficulte=1,allu=6;







  textcolor(12);
  cprintf("------------------------------------------- JEU DES ALLUMETTES -------------------------------------------\n\n");
  gotoxy(1,4);
  cprintf("Voici un petit jeu ou vous devez prendre 1 2 ou 3 allumettes, et le joueur qui prend la derniere allumette a perdu");
  do
  {
    gotoxy(1,8);
    textcolor(14);
    cprintf("nombre d'allumettes : ");
    textcolor(10);
    cprintf("%d ",allu);
    bouton=getch();
    if (bouton==right)
    {
      allu++;
      if (allu==31)
        allu=6;
    }



    if (bouton==left)
    {
      allu--;
      if (allu==5)
        allu=30;
    }



  } while (bouton!=enter);
  do
  {
    gotoxy(1,9);
    textcolor(14);
    cprintf("Difficulte : ");
    textcolor(10);
    switch (difficulte)
    {
      case 1: cprintf("facile   ");
              break;
      case 2: cprintf("normal   ");
              break;
      case 3: cprintf("difficile");
              break;
    }
    bouton=getch();
    if (bouton==left)
    {
      difficulte--;
      if (difficulte==0) difficulte=3;
    }
    if (bouton==right)
    {
      difficulte++;
      if (difficulte==4) difficulte=1;
    }
  } while (bouton!=enter);
  clrscr();
  do
  {
    textcolor(10);
    for (i=1 ; i<=allu ; i++)
    {
      gotoxy(i*2,2);
      cprintf("\xDB");
      gotoxy(i*2,3);
      cprintf("\xDB");
      gotoxy(i*2,4);
      cprintf("\xDB");
    }
    if (tour==2)
    {
      textcolor(12);
      if (difficulte==1)
      {
        if (allu>3) take=aleatoire(3);
        else
        {
          if (allu==3) take=aleatoire(2);
          else take=1;
        }
      }
      if (difficulte==2)
      {
        if(allu==4)
            take=3;
        else if(allu==3)
                take=2;
                else if(allu==2 || allu==1)
                      take=1;
                        else take=aleatoire(3);



      }
      if (difficulte==3)
      {
        take=0;
        i=2;
        if (allu==1)
            take=1;
        while (take==0)
        {
          if (allu==i) take=1;
          if (allu==i+1) take=2;
          if (allu==i+2) take=3;
          if (allu==i+3) take=aleatoire(3);
          i=i+4;
        }
      }
      allu=allu-take;
      gotoxy(1,6);
      cprintf("L'ordinateur prend %d allumettes",take);
      tour=1;
    }
    else while (tour==1)
    {
      reprise:
      textcolor(14);
      gotoxy(1,7);
      cprintf("Combien d'allu voulez-vous prendre?");
      bouton=getch();
      take=0;



      switch (bouton)
      {
        case '1':  take=1;
                   tour=2;
                   break;
        case '2':  take=2;
                   tour=2;
                   break;
        case '3':  take=3;
                   tour=2;
                   break;
      }
      if (((take>=allu)&&(allu>1))||((take>1)&&(allu==1)))
      {
        gotoxy(1,7);
        if (allu==3)
        {cprintf(" Vous pouvez taker maximum 2 allumettes!");Sleep(1500); goto reprise;}
        else {cprintf(" Vous pouvez taker maximum 1 allumette!");Sleep(1500); goto reprise;}
        sleep(2000);
        tour=1;
      }
      else allu=allu-take;
      if (tour==2) cprintf("%d",take);
      if (bouton==escape) tour=2;
    }
    if (tour==1) textcolor(12);
    else textcolor(14);
    for (i=1 ; i<=take ; i++)
    {
      gotoxy((i*2)+(allu*2),2);
      cprintf("\xDB");
      gotoxy((i*2)+(allu*2),3);
      cprintf("\xDB");
      gotoxy((i*2)+(allu*2),4);
      cprintf("\xDB");
    }
    if (allu==0)
    {
      if (tour==2)
      {
        for (i=10 ; i<=14 ; i++)
        {
          gotoxy(1,9);
          textcolor(i);





          printf("                 \xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB \xDB   \xDB \xDB\xDB\xDB\xDB\xDB       \xDB\xDB\xDB\xDB\xDB \xDB   \xDB \xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB\n");
          printf("                 \xDB     \xDB   \xDB \xDB\xDB \xDB\xDB \xDB           \xDB   \xDB \xDB   \xDB \xDB     \xDB   \xDB\n");
          printf("                 \xDB   \xDB \xDB\xDB\xDB\xDB\xDB \xDB \xDB \xDB \xDB\xDB\xDB\xDB\xDB       \xDB   \xDB \xDB   \xDB \xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB\n");
          printf("                 \xDB   \xDB \xDB   \xDB \xDB   \xDB \xDB           \xDB   \xDB  \xDB \xDB  \xDB     \xDB \xDB  \n");
          printf("                 \xDB\xDB\xDB\xDB\xDB \xDB   \xDB \xDB   \xDB \xDB\xDB\xDB\xDB\xDB       \xDB\xDB\xDB\xDB\xDB   \xDB   \xDB\xDB\xDB\xDB\xDB \xDB  \xDB \n");
        }
        cprintf("\nBaby steps");
        gotoxy(40,25);
        cprintf("\nAppuyez sur ECHAP pour rejouer");
        bouton=getch();
        if(bouton==escape)
            {
                clrscr();
                goto start;
            }
        getch();
      }
      else
      {
        for (i=10 ; i<=14 ; i++)
        {
          gotoxy(1,9);
          printf("                       \xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB \xDB   \xDB \xDB\xDB\xDB\xDB\xDB\n");
          printf("                       \xDB   \xDB \xDB   \xDB \xDB   \xDB \xDB   \xDB \xDB   \xDB\n");
          printf("                       \xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xDB \xDB   \xDB \xDB   \xDB\n");
          printf("                       \xDB   \xDB \xDB \xDB   \xDB   \xDB  \xDB \xDB  \xDB   \xDB\n");
          printf("                       \xDB\xDB\xDB\xDB  \xDB  \xDB  \xDB   \xDB   \xDB   \xDB\xDB\xDB\xDB\xDB\n");



        }
        if (difficulte==1)
        {

printf("\n                                      _");
printf("\n                                    .' '.");
printf("\n                               __  /     %c    _",92);
printf("\n                              /.-;|   /'._|_.' `\ ");
printf("\n                             ||    |  |  _     |");
printf("\n                             \\ __/|  \.' ;'-.__/");
printf("\n                               '--'%c     /",92);
printf("\n                                     '._.'");
        }
        if (difficulte==2) cprintf("\n\nNot bad, I bet you can't do that against 'difficile'");
        if (difficulte==3) cprintf("\nBOOOOOOOM! You're awesome!!!!");
        getch();
        cprintf("\nAppuyez sur Echap pour rejouer");
            bouton=getch();
          if(bouton==escape)
            {
                clrscr();
                goto start;
            }
        getch();
      }
    }
  } while ((bouton!=escape)&&(allu!=0));
}

