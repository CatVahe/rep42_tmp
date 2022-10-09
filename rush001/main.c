#include <unistd.h>
#include <stdio.h>

int get_visibil(int one, int two, int three, int four);

int main(){
    int allVar [24][3];
    int one = 1;
    int two = 1;
    int three = 1;
    int four = 1;
    int i = 0;
    int k = 0;
   while(one <= 4){
    two = 1;
    while(two <= 4){
        three = 1;
        while (three <= 4){
            four = 1;
            while (four <= 4)
            {
              /*  printf("%d, %d , %d, %d", one, two, three, four);*/
              if (one != two && one != three && one != four && two != three && two != four && three != four)
              {
                allVar [i][0] = one * 1000 +two*100 + three * 10 +four;
                
                allVar [i][1] = get_visibil(one, two, three, four);
                allVar [i][2] = get_visibil(four, three, two, one);

             /* printf("%d - %d, %d, %d", i, allVar [i][0], allVar [i][1], allVar [i][2]);
              printf("\n");*/
              ++i;
              }
              ++four;
            }
            ++three;
        }
        ++two;  
    }
    ++one;
   }

    int up[] = {4, 3, 2, 1};
    int down[] = {1, 2, 2, 2};
    int left[] = {4, 3, 2, 1};
    int right[] = {1, 2, 2, 2};
    
    int board[4][4];

    
    int forcheck[12][4] = {-1, -1, -1, -1};

    int boardit = 0;
    while(boardit < 12){
        int it = 0;
        while(it < 4){
            int itforVal = 0;
            while(itforVal < 24){
                if((left[it] == allVar[itforVal][1] && right[it] == allVar[itforVal][2]) && (itforVal != forcheck[boardit][it])){

                    board[it][0] = allVar[itforVal][0]/1000;
                    board[it][1] = (allVar[itforVal][0]/100)%10;
                    board[it][2] = (allVar[itforVal][0]/10)%10;
                    board[it][3] = (allVar[itforVal][0]%10);
           
                    forcheck[boardit][it] = itforVal;
                    printf("%d \n",  forcheck[boardit][it]);
                    break;
                }
                ++itforVal;
            }
          printf("%d, %d, %d, %d", board[it][0], board[it][1], board[it][2], board[it][3]);
                    printf("\n");    
            ++it;
        }
        int k = 0;
        while(k < 4){
            int check = get_visibil(board[0][k], board[1][k], board[2][k], board[3][k]);
            int checkR = get_visibil(board[3][k], board[2][k], board[1][k], board[0][k]);

            if(check == -1 || checkR == -1){
                printf("breaking\n");
                break;
            }
            else if(check != -1 && checkR != -1)
            {
                printf("true\n");
            }
            ++k;
        }

    
    ++boardit;
    }
}

int get_visibil(int one, int two, int three, int four)
{
    int arr[4] = {one, two, three, four};
    int k = 0;
    int count = 1;

        if(arr[0] == 4)
            return 1;
        else if(arr[1] == 4)
            return 2;
        else if(arr[2] == 4)
        {
            if(arr[0] > arr[1])
                return 2;
            else 
                return 3;
        }
        else if(arr[3] == 4){
            if(arr[0] > arr[1] && arr[0] > arr[2])
                return 2;
            else if(arr[0] < arr[1] && arr[1] > arr[2])
               return 3;
            else if(arr[0] > arr[1] && arr[1] < arr[2])
                return 3;
            else if(arr[0] < arr[1] && arr[1] < arr[2])
                return 4;
        }
        return -1;

}

        