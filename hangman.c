# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>

const char *word[]={"malaka","ball","bike","telephone","book", "school", "kichen", "window", "summer"};
const char *Medium_word[]={"syllable","psychology","astronaut","knowledge","parallel","pharaoh","awkward","pneumonia","rhythm","mnemonic","zephyr","xylophone","silhouette", "questionnaire",
    "bureaucracy",
    "hemorrhage",
    "exaggerate",
    "unanimous",
    "archaeology",
    "miscellaneous"};
int word_count=sizeof(word)/sizeof(word[0]); // το πληθος των λεξεων του δεικτη 
int Medium_word_count=sizeof(Medium_word)/sizeof(Medium_word[0]);
int max_guesses=6;
char wrong_letter[50];
int wrong=0;
char guess[100];
const char *secret;
int len;

bool check_letter(char let,const char *secret);
bool check_wrong_letter(char let,int wrong,char wrong_letter[50]);
void clear_screen();





bool check(char let,int len,char guess[20])
{
    for(int i=0; i<len; i++)
    {
        if(guess[i]==let)
           return true;
    }
    return false;
}



    


void print_human(int max_guesses)
{
    if(max_guesses==6)
    {
       printf("_______\n");
        printf("|     |\n|\n|\n|\n");
    }
    else if(max_guesses==5)
    {
        printf("_______\n");
        printf("|     |\n|     o\n|\n|\n");

    }
    else if(max_guesses==4)
    {
         printf("_______\n");
         printf("|     |\n|     o\n|     |\n|\n");

    }
    else if (max_guesses==3)
    {
        printf("_______\n");
        printf("|     |\n|     o\n|    /|\n|\n");

    }
    else if(max_guesses==2)
    {
        printf("_______\n");
        printf("|     |\n|     o\n|    /|\\\n|\n");

    }
    else if(max_guesses==1)
    {
        printf("_______\n");
        printf("|     |\n|     o\n|    /|\\\n|    /\n");

    }
    else
    {
        printf("_______\n");
        printf("|     |\n|     o\n|    /|\\\n|    / \\\n");
        printf("YOU LOSEE!!!!\n");
        printf("The word is:%s",secret);
    }
}


void guess_letter(const char *secret,char guess[20])
{
     char let;
    /*do
    {
        printf("Enter possition (1-5):");
        scanf("%d",&pos);    
    }while(pos<1 || pos>5);
    p=pos-1;*/
    do
    {
        printf("\nEnter a letter:");
        scanf(" %c",&let);
        if(check_wrong_letter(let,wrong,wrong_letter))
          {printf("\nYou already enter it!!!\n");}
        else if(check(let,len,guess))
        printf("\nYou already enter it!!!\n");  
    } while (check_wrong_letter(let,wrong,wrong_letter)==true || check(let,len,guess)==true);  
    
    
    if(check_letter(let,secret)==false)
    {
        clear_screen();
        printf("Wrong letter\n");
        wrong_letter[wrong]=let;
        wrong++;
        max_guesses--;
        printf("%d more guesses\n",max_guesses);
    }
    else
    {
        clear_screen();
        printf("Right letter!!!\n");
        for(int i=0; secret[i] != '\0';i++)
        {
            if(secret[i]==let)
                {
                    guess[i]=let;
                }
        }
    }
    printf("All wrong letters are:");
    for(int i=0;i<wrong;i++)
    {
        if(i>0)printf(",");
        printf("%c",wrong_letter[i]);
    }

    printf("\n");



}


bool check_word(const char *secret,char guess[20])
{
    for(int i=0;secret[i] != '\0';i++)
    {
        if(secret[i]!=guess[i])
        {
            return false;
        }
    }

    return true;
}

bool check_letter(char let,const char *secret)
{
    for(int i=0;secret[i] != '\0';i++)
    {
        if(secret[i]==let)
        {
            return true;
        }
    }
    return false;
}


bool check_wrong_letter(char let,int wrong,char wrong_letter[50])
{
    for(int i=0;i<wrong;i++)
    {
        if(let==wrong_letter[i])
        {
            return true;
        }
    }
    
    return false;
}


void clear_screen()
{
    #ifdef _WIN32
       system("cls");
    #else
       system("clear");
    #endif
}




int main()
{
    char answer;
    int ans;
    srand(time(NULL));
    do 
    {
        clear_screen();
        do
        {
            printf("1.easy\n2.hard\nChose game mode:");
            scanf("%d",&ans);
            if(ans!=1 && ans!=2)
            printf("Wrong choice!!!\nChoise again\n");
            
        } while (ans!=1 && ans!=2);

        if(ans==1)
        {
        secret=word[rand()%word_count]; // Η λεξη καθε γυρου
        len = strlen(secret); // Το πληθος γραμματων καθε λεξης
        }
        else 
        {
            secret=Medium_word[rand() % Medium_word_count];
            len = strlen(secret);
        }
        memset(guess,'_',len);
       /*/ for(int i=0; i<len; i++)
        {
            guess[i]='_'; // λεξη με τα καινα
        }*/
        guess[len]='\0';
        memset(wrong_letter,0,sizeof(wrong_letter));
        max_guesses=6;
        wrong=0;
        while(max_guesses>0 && !check_word(secret,guess))
        {
            
            if(max_guesses>0)
            {
                printf("The word is :%s\n",guess);
                print_human(max_guesses);
                guess_letter(secret,guess);
                check_word(secret,guess);
                if(check_word(secret,guess)==true)
                {
                    //printf("%s",guess);
                    clear_screen();
                    printf("\nYOU WINN!!!!");
                }
            }
           /*else
            {
                
                max_guesses--;
            }    */ 
            
        }
        printf("The word is : %s\n",secret);
        print_human(max_guesses);
        do
        {
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c",&answer);
        } while (answer!='y' && answer!='n' );
        
        
    } while (answer=='y');
    
    
    
    return 0;
}
