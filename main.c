#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define L 21
#define C 120

int main()
{
    //const int L=21, C=120;
    int i, j, x, y, bola, mov0, mov1, mov2, mov3, mov4, mov5, mov6, mov7, mov8, mov9, esqoudir, sobedesce, pontos1, pontos2, angulo, vel;
    char a, b, campo[L][C], start;

    srand(time(NULL));
    printf("\t\t\t\tAUTISM PONG\n ");
    printf("\t\t\t   Cedeteg Version 2016\n\n\n");
    printf("\t\t\tPressione Qualquer Tecla...");
    start = getch();
    Beep(1000,400);
    system("cls");
    for(j=0; j<C; j++)
    {
        campo[0][j] = 219;
        campo[20][j] = 219;
        if(start == 'm')
        {
            campo[0][j] = '?';
            campo[20][j] = '?';
        }
    }
    for(i=1; i<L-1; i++)
    {
        for(j=0; j<C; j++)
        {
            campo[i][j] = 176;
        }
    }
    x = 10;
    y = 40;
    vel = 10000;
    campo[x][y] = 'o';
    bola = rand()%4;
    pontos1 = 0;
    pontos2 = 0;
    mov0 = mov5 = 8;//player1
    mov1 = mov6 = 9;
    mov2 = mov7 = 10;
    mov3 = mov8 = 11;
    mov4 = mov9 = 12;//player1
    //player 1
    campo[mov0][C-(C-1)] = campo[mov1][C-(C-1)] = campo[mov2][C-(C-1)] = campo[mov3][C-(C-1)] = campo[mov4][C-(C-1)] = 219;
    //player 2
    campo[mov5][C-2] = campo[mov6][C-2] = campo[mov7][C-2] = campo[mov8][C-2] = campo[mov9][C-2] = 219;
    angulo = 1;

    while((pontos1<5) && (pontos2<5))
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tPlayer 1     %d X %d     Player 2\n", pontos1, pontos2);
        for(i=0; i<L; i++)
        {
            for(j=0; j<C; j++)
            {
                printf("%c", campo[i][j]);
            }
        }

        if(bola == 0 && campo[1][y] != 'o' && campo[L-2][y] != 'o') //saida 0 x=desce y=direita
        {
            y++;
            x++;
            campo[x-1][y-1] = 176;
            campo[x][y] = 'o';
            esqoudir = 1; //direitea = 1
            sobedesce = 0; //desce = 0
        }
        else if(bola == 1 && campo[1][y] != 'o' && campo[L-2][y] != 'o') //saida 1 x=desce y=esquerda
        {
            x++;
            y--;
            campo[x-1][y+1] = 176;
            campo[x][y] = 'o';
            esqoudir = 0;
            sobedesce = 0;
        }
        else if(bola == 2 && campo[1][y] != 'o' && campo[L-2][y] != 'o') //saida 2 x=sobe y=direita
        {
            x--;
            y++;
            campo[x+1][y-1] = 176;
            campo[x][y] = 'o';
            esqoudir = 1;
            sobedesce = 1;
        }
        else if(bola == 3 && campo[1][y] != 'o' && campo[L-2][y] != 'o') //saida 0 x=sobe y=esquerda
        {
            x--;
            y--;
            campo[x+1][y+1] = 176;
            campo[x][y] = 'o';
            esqoudir = 0;
            sobedesce = 1;
        }
        else if((campo[L-2][y]=='o' && esqoudir == 1) || ((bola==4 && esqoudir == 1) && (bola==4 && sobedesce == 0))) //inv 0
        {
            if (angulo == 1)
            {
                x--;
                y++;
                campo[x+1][y-1] = 176;
            }
            else if ((angulo == 2 && x <= 16) && (angulo == 2 && x >= 4) && (angulo == 2 && y >= 4) && (angulo == 2 && y <= C-5))
            {
                x -= 2;
                y += 2;
                campo[x+2][y-2] = 176;
            }
            else if ((angulo==2 && x > 16) || (angulo==2 && x < 4) || (angulo==2 && y < 4) || (angulo==2 && y > C-5))
            {
                x--;
                y++;
                campo[x+1][y-1] = 176;
            }
            campo[x][y] = 'o';
            bola = 4;
        }
        else if((campo[L-2][y] == 'o' && esqoudir == 0) || ((bola == 4 && esqoudir == 0) && (bola == 4 && sobedesce == 0))) //inv 1
        {
            if (angulo == 1)
            {
                x--;
                y--;
                campo[x+1][y+1] = 176;
            }
            else if ((angulo == 2 && x <= 16) && (angulo == 2 && x >= 4) && (angulo == 2 && y >= 4) && (angulo == 2 && y <= C-5))
            {
                x -= 2;
                y -= 2;
                campo[x+2][y+2] = 176;
            }
            else if ((angulo==2 && x > 16) || (angulo==2 && x < 4) || (angulo==2 && y < 4) || (angulo == 2 && y > C-5))
            {
                x--;
                y--;
                campo[x+1][y+1] = 176;
            }
            campo[x][y] = 'o';
            bola = 4;
        }
        else if((campo[1][y] == 'o' && esqoudir == 1) || ((bola == 4 && esqoudir == 1) && (bola == 4 && sobedesce == 1))) //inv 2
        {
            if (angulo == 1)
            {
                x++;
                y++;
                campo[x-1][y-1] = 176;
            }
            else if ((angulo == 2 && x <= 16) && (angulo == 2 && x >= 4) && (angulo == 2 && y >= 4) && (angulo == 2 && y <= C-5))
            {
                x += 2;
                y += 2;
                campo[x-2][y-2] = 176;
            }
            else if ((angulo == 2 && x > 16) || (angulo == 2 && x < 4) || (angulo == 2 && y < 4) || (angulo == 2 && y > C-5))
            {
                x++;
                y++;
                campo[x-1][y-1] = 176;
            }
            campo[x][y] = 'o';
            bola = 4;
        }
        else if((campo[1][y]=='o' && esqoudir == 0) || ((bola==4 && esqoudir == 0) && (bola==4 && sobedesce == 1))) //inv 3
        {
            if (angulo==1)
            {
                x++;
                y--;
                campo[x-1][y+1] = 176;
            }
            else if ((angulo == 2 && x <= 16) && (angulo == 2 && x >= 4) && (angulo == 2 && y >= 4) && (angulo == 2 && y <= C-5))
            {
                x += 2;
                y -= 2;
                campo[x-2][y+2] = 176;
            }
            else if ((angulo == 2 && x > 16) || (angulo == 2 && x < 4) || (angulo == 2 && y < 4) || (angulo == 2 && y > C-5))
            {
                x++;
                y--;
                campo[x-1][y+1] = 176;
            }
            campo[x][y] = 'o';
            bola=4;
        }
        if((x == mov0 && y == 2) || (x == mov1 && y == 2) || (x == mov2 && y == 2) || (x == mov3 && y == 2) || (x == mov4 && y == 2) || (x == mov5 && y == C-3) || (x == mov6 && y == C-3) || (x == mov7 && y == C-3) || (x == mov8 && y == C-3) || (x == mov9 && y == C-3))
        {
            if ((x == mov0) || (x == mov5) || (x == mov4) || (x == mov9))
            {
                angulo=2;
            }
            else if ((x == mov1) || (x == mov6) || (x == mov3) || (x == mov8) || (x == mov2) || (x == mov7))
            {
                angulo=1;
            }
            vel-=1000;
            if(esqoudir==1)
            {
                esqoudir=0;
            }
            else if(esqoudir==0)
            {
                esqoudir=1;
            }
        }
        if(y == C-(C-1))
        {
            pontos2++;
            campo[x][y] = 176;
            x = L/2;
            y = C/2;
            angulo = 1;
            bola = rand() % 4;
            vel -=1000;
        }
        else if (y == C-1)
        {
            pontos1++;
            campo[x][y] = 176;
            x = L/2;
            y = C/2;
            angulo = 1;
            bola = rand() % 4;
            vel -= 1000;
        }
        //player1
        if(kbhit() == 1)
        {
            a = getch();
            if(a == 'w' && mov0 != L-(L-2))
            {
                mov0--;
                mov1--;
                mov2--;
                mov3--;
                mov4--;
                campo[mov0][C-(C-1)] = 219;
                campo[mov1][C-(C-1)] = 219;
                campo[mov2][C-(C-1)] = 219;
                campo[mov3][C-(C-1)] = 219;
                campo[mov4][C-(C-1)] = 219;
                campo[mov4+1][C-(C-1)] = 176;

            }
            if(a == 's' && mov4 != L-3)
            {
                mov0++;
                mov1++;
                mov2++;
                mov3++;
                mov4++;
                campo[mov0][C-(C-1)] = 219;
                campo[mov1][C-(C-1)] = 219;
                campo[mov2][C-(C-1)] = 219;
                campo[mov3][C-(C-1)] = 219;
                campo[mov4][C-(C-1)] = 219;
                campo[mov0-1][C-(C-1)] = 176;

            }


            //player2
            if(a == '8' && mov5 != L-(L-2))
            {
                mov5--;
                mov6--;
                mov7--;
                mov8--;
                mov9--;
                campo[mov5][C-2] = 219;
                campo[mov6][C-2] = 219;
                campo[mov7][C-2] = 219;
                campo[mov8][C-2] = 219;
                campo[mov9][C-2] = 219;
                campo[mov9+1][C-2] = 176;

            }
            if(a == '5' && mov9 != L-3)
            {
                mov5++;
                mov6++;
                mov7++;
                mov8++;
                mov9++;
                campo[mov5][C-2] = 219;
                campo[mov6][C-2] = 219;
                campo[mov7][C-2] = 219;
                campo[mov8][C-2] = 219;
                campo[mov9][C-2] = 219;
                campo[mov5-1][C-2] = 176;
            }
        }
        usleep(vel);
        if(x == L-2)
        {
            sobedesce = 0;
        }
        if(x == L-(L-1))
        {
            sobedesce = 1;
        }
    }
    system("cls");
    (pontos1>pontos2)?printf("\n\n\t\tPlayer 1 Venceu!! de %d a %d\n",pontos1,pontos2):printf("\n\n\t\tPlayer 2 Venceu!! de %d a %d\n",pontos2,pontos1);
    getchar();
}
