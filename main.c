#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
char name[20];
char sympol;
int score;
}Player;

typedef struct {
int x;
int y;
}Move;

Move computer_history[5];
int computer_move_count=0;

Move bad_moves[5];
int bad_moves_count=0;

Player player1,player2;

char board[3][3];
/*const char player='x';
const char computer='o';
const char second_player='o';*/

void printboard();
void scanboard();
int freespaces();
char checkwiner();
void player_move(Player current);
void computer_move(Player current);
void printwinner(char winner,int choice,Player current);
void second_player_move();
void smart_computer_move();
void smarter_computer_move();
int is_bad_move(int x,int y);
void play_move(int x, int y);
void clear_screen();


int main()
{
 
   char winner=' ';
   char response=' ';
   int choice,Choice;

  
  do{
    do{
     printf("1. Player vs computer\n");
     printf("2. Player vs player\n");
     printf("chose the game mode:");
     scanf("%d",&choice);
      if(choice!=1 && choice!=2)
        {
          printf("Invalid choice\n");
        }
      }while(choice!=1 && choice!=2);
      clear_screen();

    printf("Enter player 1 name:");
    scanf("%s",player1.name);
    player1.sympol='x';
    player1.score=0;
    clear_screen();

    
    if(choice==1)
    { 
      do{
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("chose the difficulty:");
        scanf("%d",&Choice);
      }while(Choice!=1 && Choice!=2 && Choice!=3);

      clear_screen();
      
      strcpy(player2.name,"computer");
      player2.sympol='o';
      player2.score=0;
      
   scanboard();
  computer_move_count=0;
  printboard();
    winner=' ';
    while(winner==' ' && freespaces()!=0)
     {
        player_move(player1);
        winner=checkwiner();
        if(winner!=' ' || freespaces()==0)
          {
            break;
          }
       if(Choice==1)
       {
         computer_move(player2);
       }
       else if(Choice==2)
        {
          smart_computer_move(); 
        }
       else
         {
  smart_computer_move(player2,player1);
         }
        winner=checkwiner();
        if(winner!=' ' || freespaces()==0)
          {
            break;
          }
      
    clear_screen();    
    printboard();
       }
    if(winner==player1.sympol)
      {
        clear_screen();
        printwinner(winner,choice,player1);
      }else
      {
        clear_screen();
        printwinner(winner,choice,player2);
      }
    }
    else if(choice==2)
      {
        printf("Enter player 2 name:");
        scanf("%s",player2.name);
        player2.sympol='o';
        player2.score=0;
        clear_screen();
        scanboard();
        printboard();
        winner=' ';
        while(winner==' ' && freespaces()!=0)
          {
            player_move(player1);
            clear_screen();
            printboard();
            winner=checkwiner();
            if(winner!=' ' || freespaces()==0)
              {
                break;
              }
            //second_player_move();
            player_move(player2);
            clear_screen();
            printboard();
            winner=checkwiner();
            if(winner!=' ' || freespaces()==0)
              {
                break;
              }
          }
        if(winner==player1.sympol)
          {
            clear_screen();
      printwinner(winner,choice,player1);
          }else
          {
            clear_screen();
      printwinner(winner,choice,player2);
          }
        printf("%s's score is %d\n",player1.name,player1.score);
        printf("%s's score is %d\n",player2.name,player2.score);
        }
     do{
    printf("Do you want to play again? (Y/N):");
   scanf(" %c",&response);
   response=toupper(response);
   clear_screen();
    }while(response!='Y' && response!='N');
   }while(response=='Y');
  

  return 0;
}
   
  

// Εμφανιζει το ταμπλο
void printboard()
{
  printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
  
}

// Γεμιζει το ταμπλο με κενα 
void scanboard()
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      board[i][j]=' ';
    }
  }
}

//Επιστρεφει τον αριθμο των κενων θεσεων στο ταμπλο
int freespaces()
{
  int free=9;
  for( int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(board[i][j]!=' ')
      {
        free--;
      }    
    }
  }
  return free;
}

//Ελεγχει αν υπαρχει νικητης
char checkwiner()
{
  for(int i=0;i<3;i++)
  {
    if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' ')
    {
      return board[0][i];
    }
  }

  for(int i=0;i<3;i++)
  {
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ')
    {
      return board[i][0];
    }
  }

  if(board[1][1]==board[0][0] && board[1][1]==board[2][2] && board[1][1]!=' ')
    {
      return board[1][1];
    }
  if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=' ')
    {
      return board[0][2];
    }
  return ' ';
}


//κινηση του 1ου παικτη (χρηστης)
void player_move(Player current)
{
  int x,y,pos;
do{
  /*do{
  printf("Enter the row (for 1-3)\n");
  scanf("%d",&x);
    }while(x<1 || x>3);
  x--;
  do{
  printf("Enter the column (for 1-3)\n");
  scanf("%d",&y);
    }while(y<1 || y>3);
  y--;*/
  printf("%s's turn(%c)\n",current.name,current.sympol);
    do{
      printf("Chose the position (1-9):");
      scanf("%d",&pos);
    }while(pos<1 || pos>9);
    x=(pos-1)/3;
    y=(pos-1)%3;

  if(board[x][y]!=' ')
    {
      printf("Inavalid move\n");
    }
  else
    {
      board[x][y]=current.sympol;;
      break;
    }
 }while(board[x][y]!=' ');
}

//κινηση του υπολογιστη
void computer_move(Player current)
{
 srand(time(NULL));
  int x,y;
     if(freespaces()>0)
       {
        do{
         x=rand()%3;
         y=rand()%3;
          } while(board[x][y]!=' ' || is_bad_move(x,y));
         board[x][y]=player2.sympol;
    computer_history[computer_move_count].x=x;
computer_history[computer_move_count].y=y;
         computer_move_count++;
       }  
     else
       {
         printwinner(' ',1,player1);
       }
}

//Εμφανιζει τον νικητη
void printwinner(char winner,int choice,Player current)
{  
 if(choice==1)
   {
  if(winner==player1.sympol)
    {
      printf("%s WIN!!!\n",player1.name);
      player1.score++;
      for(int i=0;i<computer_move_count;i++)
      {
bad_moves[bad_moves_count++]=computer_history[i];
      }
    }
  else if(winner==player2.sympol)
    {
      printf("YOU LOSE!!!\n");
      player2.score++;
    }
  else
    {
      printf("IT'S A TIE!!!\n");
    }
   }
  else if(choice==2)
    {
      if(winner==player1.sympol)
        {
          printf("%s WINS!!!\n",player1.name);
          player1.score++;
        }
      else if(winner==player2.sympol)
        {
          printf("%s WINS!!!\n",player2.name);
          player2.score++;
        }
      else
        {
          printf("IT'S A TIE!!!\n");
        }
    }
}

//κινηση του 2ου παικτη (χρηστης)
/*void second_player_move()
{
  int x,y,pos;

  if(freespaces()>0)
    {
      do{
        printf("player 2 chose the possition (1-9):");
        scanf("%d",&pos);
        x=(pos-1)/3;
        y=(pos-1)%3;
        if(board[x][y]!=' ')
          {
            printf("Inavalid move\n");
          }
       }while(board[x][y]!=' ');
      
      board[x][y]=second_player;
      }
  else 
     {
       printwinner(' ',2);
     }
    
}*/

void smarter_computer_move()
{
  int x,y,i;
  //srand(time(NULL));
  if(freespaces()>0){
  /*do{
   i=rand()%3;
   y=rand()%3;
    }while(board[i][y]!=' ');
    board[i][y]=player2.sympol;*/
    
  for(int x=0;x<3;x++)
    {
      if(board[x][1]==board[x][2] &&
         (board[x][1]==player2.sympol || board[x][1]==player1.sympol) && board[x][0]==' ')
      {
        play_move(x,0);
        return;
      }
      if(board[x][0]==board[x][2] && (board[x][0]==player2.sympol || board[x][0]==player1.sympol) && board[x][1]==' ')
        {
          play_move(x,1);
          return;
        }
        if(board[x][0]==board[x][1] &&  (board[x][0]==player2.sympol || board[x][0]==player1.sympol) && board[x][2]==' ')
          {
            play_move(x,2);
            return;
          }
      }
    


  for(int i=0;i<3;i++)
    {
      if(board[1][i]==board[2][i] && (board[1][i]==player2.sympol || board[1][i]==player1.sympol) && board[0][i]==' ')
        {
          play_move(0,i);
          return;
        }
      if(board[0][i]==board[2][i] && (board[0][i]==player2.sympol || board[0][i]==player1.sympol) && board[1][i]==' ')
        {
          play_move(1,i);
          return;
        }
      if(board[0][i]==board[1][i] && (board[0][i]==player2.sympol || board[0][i]==player1.sympol) && board[2][i]==' ')
       {
        play_move(2,i);
        return;
       }
    }

    if(board[0][0]==board[1][1] && (board[0][0]==player2.sympol || board[0][0]==player1.sympol) && board[2][2]==' ')
      {
        play_move(2,2);
        return;
      }
     if(board[0][0]==board[2][2] && (board[0][0]==player2.sympol || board[0][0]==player1.sympol) && board[1][1]==' ')
       {
         play_move(1,1);
         return;
       }
      if(board[1][1]==board[2][2] && (board[1][1]==player2.sympol || board[1][1]==player1.sympol) && board[0][0]==' ')
       {
         play_move(0,0);
         return;
       }
     if(board[0][2]==board[1][1] && (board[0][2]==player2.sympol || board[0][2]==player1.sympol) && board[2][0]==' ')
       {
         play_move(2,0);
         return;
       }
     if(board[0][2]==board[2][0] && (board[0][2]==player2.sympol || board[0][2]) && board[1][1]==' ')
       {
         play_move(1,1);
         return;
       }
     if(board[1][1]==board[2][0] && (board[1][1]==player2.sympol || board[1][1]==player1.sympol) && board[0][2]==' ')
       {
         play_move(0,2);
         return;
       }
      if(board[1][1]==' ')
        {
          play_move(1,1);
          return;
        }
      else if(board[0][0]==' ')
        {
          play_move(0,0);
          return;
       }
      else if(board[0][2]==' ')
        {
         play_move(0,2); 
          return;
        }
      else if(board[2][0]==' ')
        {
          play_move(2,0);
          return;
        }
      else if(board[2][2]==' ')
        {
          play_move(2,2);
          return;
        }
      else
        for(int i=0;i<3;i++)
          {
            for(int j=0;j<3;j++)
              {
                if(board[i][j]==' ')
                  {
                    play_move(i,j);
                    return;
                  }
              }
          }
     

    
}
}



void smart_computer_move()
{
  int x,y,i;
  //srand(time(NULL));
  if(freespaces()>0){
  /*do{
   i=rand()%3;
   y=rand()%3;
    }while(board[i][y]!=' ');
    board[i][y]=player2.sympol;*/

  for(int x=0;x<3;x++)
    {
      if(board[x][1]==board[x][2] &&
        board[x][1]==player2.sympol && board[x][0]==' ')
      {
        play_move(x,0);
        return;
      }
      if(board[x][0]==board[x][2] && board[x][0]==player2.sympol && board[x][1]==' ')
        {
          play_move(x,1);
          return;
        }
        if(board[x][0]==board[x][1] &&  board[x][0]==player2.sympol && board[x][2]==' ')
          {
            play_move(x,2);
            return;
          }
      }



  for(int i=0;i<3;i++)
    {
      if(board[1][i]==board[2][i] && board[1][i]==player2.sympol && board[0][i]==' ')
        {
          play_move(0,i);
          return;
        }
      if(board[0][i]==board[2][i] && board[0][i]==player2.sympol && board[1][i]==' ')
        {
          play_move(1,i);
          return;
        }
      if(board[0][i]==board[1][i] && board[0][i]==player2.sympol && board[2][i]==' ')
       {
         play_move(2,i);
        return;
       }
    }

    if(board[0][0]==board[1][1] && board[0][0]==player2.sympol && board[2][2]==' ')
      {
        play_move(2,2);
        return;
      }
     if(board[0][0]==board[2][2] && board[0][0]==player2.sympol && board[1][1]==' ')
       {
         play_move(1,1);
         return;
       }
      if(board[1][1]==board[2][2] && board[1][1]==player2.sympol && board[0][0]==' ')
       {
         play_move(0,0);
         return;
       }
     if(board[0][2]==board[1][1] && board[0][2]==player2.sympol && board[2][0]==' ')
       {
         play_move(2,0);
         return;
       }
     if(board[0][2]==board[2][0] && board[0][2]==player2.sympol && board[1][1]==' ')
       {
         play_move(1,1);
         return;
       }
     if(board[1][1]==board[2][0] && board[1][1]==player2.sympol && board[0][2]==' ')
       {
         play_move(0,2);
         return;
       }
      if(board[1][1]==' ')
        {
          play_move(1,1);
          return;
        }
      else if(board[0][0]==' ')
        {
          play_move(0,0);
          return;
       }
      else if(board[0][2]==' ')
        {
         play_move(0,2);
          return;
        }
      else if(board[2][0]==' ')
        {
          play_move(2,0);
          return;
        }
      else if(board[2][2]==' ')
        {
          play_move(2,2);
          return;
        }
      else
        for(int i=0;i<3;i++)
          {
            for(int j=0;j<3;j++)
              {
                if(board[i][j]==' ')
                  {
                    play_move(i,j);
                    return;
                  }
              }
          }



}
}

int is_bad_move(int x,int y){
  for(int i=0;i<bad_moves_count;i++)
  {
    if(bad_moves[i].x==x && bad_moves[i].y==y)
    {
      return 1;
    }
  }
  return 0;
}

void play_move(int x, int y)
{
  board[x][y]='o';
  computer_history[computer_move_count].x=x;
computer_history[computer_move_count].y=y;
  computer_move_count++;
}



void clear_screen()
{
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif    
}




