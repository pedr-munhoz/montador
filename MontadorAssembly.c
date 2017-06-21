#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char nomeDoArquivo[17];
char stringDeArmazenamento[1000000];
char linhasDeInstrucao[1000][60];
char linhasDeCodigo[1000][60];
char rotulos[1000][20];
char rotulos1[100][20];
int i, j, k ,m, aux, l[60], numeroDeLinhas, contadorDeRotulos=0, marcadorDePosicao=0, contadorDeRotulos1=0, marcadorDePosicao1=0;
FILE *ponteiroArquivo;

int puxaLinha(int qualLinha, int quantasLinhas)
{
    for (aux=0; aux<quantasLinhas;aux++)
    {
        for (k=qualLinha+(2-quantasLinhas);k<numeroDeLinhas;k++)
        {
            for (m=0;m<strlen(linhasDeInstrucao[k]);m++)
                linhasDeInstrucao[k][m]=NULL;
            strcpy(linhasDeInstrucao[k],linhasDeInstrucao[k+1]);
            l[k]=l[k+1];
        }
    }
}

int preparaLinhas()
{
    for (j=0;j<numeroDeLinhas;j++)
    {
        for(i=0;i<l[j]-1;i++)
        {
            if ((linhasDeInstrucao[j][i]=='H') && (linhasDeInstrucao[j][i+1]=='L') && (linhasDeInstrucao[j][i+2]=='T'))
            {
                puxaLinha(j,1);
                break;
            }
            else if ((linhasDeInstrucao[j][i]=='R') && (linhasDeInstrucao[j][i+1]=='E') && (linhasDeInstrucao[j][i+2]=='T'))
            {
                puxaLinha(j,1);
                break;
            }
        }
    }
}

int encontraPar(lin)
{
    for (k=0;k<=numeroDeLinhas || k<100;k++)
    {
        //printf("\n[%d] %s[%d]x %s= %d", k, rotulos1[lin], lin, rotulos[k], strcmp(rotulos1[lin],rotulos[k]));
        if((strcmp(rotulos1[lin],rotulos[k]))==0)
        {
            return k;
        }
    }
}

int encontraRotulos(linha1)
{
    marcadorDePosicao=0;
    for(i=0;i<l[linha1]-1;i++)
    {
        if ((linhasDeInstrucao[linha1][i]=='C') && (linhasDeInstrucao[linha1][i+1]=='A') && (linhasDeInstrucao[linha1][i+2]=='L') && (linhasDeInstrucao[linha1][i+3]=='L'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='M') && (linhasDeInstrucao[linha1][i+1]=='O') && (linhasDeInstrucao[linha1][i+2]=='V'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='S') && (linhasDeInstrucao[linha1][i+1]=='U') && (linhasDeInstrucao[linha1][i+2]=='B'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='A') && (linhasDeInstrucao[linha1][i+1]=='D') && (linhasDeInstrucao[linha1][i+2]=='D'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='C') && (linhasDeInstrucao[linha1][i+1]=='M') && (linhasDeInstrucao[linha1][i+2]=='P'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='M') && (linhasDeInstrucao[linha1][i+2]=='P'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='N') && (linhasDeInstrucao[linha1][i+2]=='C'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='N') && (linhasDeInstrucao[linha1][i+2]=='Z'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='B') && (linhasDeInstrucao[linha1][i+2]=='E'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='R') && (linhasDeInstrucao[linha1][i+1]=='E') && (linhasDeInstrucao[linha1][i+2]=='T'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='H') && (linhasDeInstrucao[linha1][i+1]=='L') && (linhasDeInstrucao[linha1][i+2]=='T'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='C'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='Z'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='J') && (linhasDeInstrucao[linha1][i+1]=='A'))
            break;
        else if ((linhasDeInstrucao[linha1][i]=='E') && (linhasDeInstrucao[linha1][i+1]=='Q')&& (linhasDeInstrucao[linha1][i+2]=='U'))
        {
            k=10*(linhasDeInstrucao[linha1][i+3]-48)+(linhasDeInstrucao[linha1][i+4]-48);
            strcpy(rotulos[k],rotulos[linha1]);
            for (k=0; k<marcadorDePosicao;k++)
                rotulos[linha1][k]=0;
            puxaLinha(linha1,2);
            j=-1;
            break;
        }
        else if (linhasDeInstrucao[linha1][i]>=33 && linhasDeInstrucao[linha1][i]<=125)
        {
            rotulos[linha1][marcadorDePosicao]=linhasDeInstrucao[linha1][i];
            marcadorDePosicao++;
        }
    //printf("\nrotulo[%d]:%s", linha1, rotulos[linha1]);
    }
}

int leitura ()
{
    for (j=0; stringDeArmazenamento[j-1] != EOF; j++)
    {
        stringDeArmazenamento[j] = getc(ponteiroArquivo);
    }

    k=j;
    for(i=0;i<60;i++)
        l[i]=0;
    printf("\n", l[0]);
    i=0;
    for(j=0; j<=k; j++)
    {
        if (stringDeArmazenamento[j]=='\n')
        {
            i+=2;
        }
        else if(stringDeArmazenamento[j]!=' ')
        {
            linhasDeInstrucao[i][l[i]]=stringDeArmazenamento[j];
            l[i]++;
        }
        numeroDeLinhas=i+1;
    }
    strcpy(stringDeArmazenamento, "\n");
}
int determina (int linha)
{
    marcadorDePosicao1=0;
    for (i=0; i<l[linha]-3;i++)
    {
        if ((linhasDeInstrucao[linha][i]=='C') && (linhasDeInstrucao[linha][i+1]=='A') && (linhasDeInstrucao[linha][i+2]=='L') && (linhasDeInstrucao[linha][i+3]=='L'))
        {
            k=i+4;
            while (k<strlen(linhasDeInstrucao[linha])-1&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "e8h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='M') && (linhasDeInstrucao[linha][i+1]=='O') && (linhasDeInstrucao[linha][i+2]=='V'))
        {
            if (linhasDeInstrucao[linha][i+3]=='[')
            {
                k=i+4;
                while (linhasDeInstrucao[linha][k]!=']')
                {
                    rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                    k++;
                    marcadorDePosicao1++;
                }
                aux=encontraPar(linha);
                if(aux<10)
                {
                    rotulos1[linha][0]='0';
                    rotulos1[linha][1]=aux+48;
                }
                else
                {
                    rotulos1[linha][0]=(int)(aux/10)+48;
                    rotulos1[linha][1]=(aux%10)+48;
                }
                for (k=2;k<marcadorDePosicao1;k++)
                    rotulos1[linha][k]=0;
                strcat(linhasDeCodigo[linha], "a2h");
                strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                break;
            }
            else if (linhasDeInstrucao[linha][i+3]=='A')
            {
                if ((linhasDeInstrucao[linha][i+4]==',')&& (linhasDeInstrucao[linha][i+5]=='['))
                {
                    k=i+6;
                    while (linhasDeInstrucao[linha][k]!=']')
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    aux=encontraPar(linha);
                    if(aux<10)
                    {
                        rotulos1[linha][0]='0';
                        rotulos1[linha][1]=aux+48;
                    }
                    else
                    {
                        rotulos1[linha][0]=(int)(aux/10)+48;
                        rotulos1[linha][1]=(aux%10)+48;
                    }
                    for (k=2;k<marcadorDePosicao1;k++)
                        rotulos1[linha][k]=0;
                    strcat(linhasDeCodigo[linha], "a0h");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
                else if ((linhasDeInstrucao[linha][i+4]==',') && (linhasDeInstrucao[linha][i+5]>=48) && (linhasDeInstrucao[linha][i+5]<=59))
                {
                    k=i+5;
                    while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    strcat(linhasDeCodigo[linha], "b0h");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
            }
        }
        else if ((linhasDeInstrucao[linha][i]=='S') && (linhasDeInstrucao[linha][i+1]=='U') && (linhasDeInstrucao[linha][i+2]=='B'))
        {
            if (linhasDeInstrucao[linha][i+3]=='A')
            {
                if ((linhasDeInstrucao[linha][i+4]==',')&& (linhasDeInstrucao[linha][i+5]=='['))
                {
                    k=i+6;
                    while (linhasDeInstrucao[linha][k]!=']')
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    aux=encontraPar(linha);
                    if(aux<10)
                    {
                        rotulos1[linha][0]='0';
                        rotulos1[linha][1]=aux+48;
                    }
                    else
                    {
                        rotulos1[linha][0]=(int)(aux/10)+48;
                        rotulos1[linha][1]=(aux%10)+48;
                    }
                    for (k=2;k<marcadorDePosicao1;k++)
                        rotulos1[linha][k]=0;
                    strcat(linhasDeCodigo[linha], "2ah");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
                else if ((linhasDeInstrucao[linha][i+4]==',')&& ((linhasDeInstrucao[linha][i+5]>=48) && (linhasDeInstrucao[linha][i+5]<=59)))
                {
                    k=i+5;
                    while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    strcat(linhasDeCodigo[linha], "2ch");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
            }
        }
        else if ((linhasDeInstrucao[linha][i]=='A') && (linhasDeInstrucao[linha][i+1]=='D') && (linhasDeInstrucao[linha][i+2]=='D'))
        {
            if (linhasDeInstrucao[linha][i+3]=='A')
            {
                if ((linhasDeInstrucao[linha][i+4]==',')&& (linhasDeInstrucao[linha][i+5]=='['))
                {
                    k=i+6;
                    while (linhasDeInstrucao[linha][k]!=']')
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    aux=encontraPar(linha);
                    if(aux<10)
                    {
                        rotulos1[linha][0]='0';
                        rotulos1[linha][1]=aux+48;
                    }
                    else
                    {
                        rotulos1[linha][0]=(int)(aux/10)+48;
                        rotulos1[linha][1]=(aux%10)+48;
                    }
                    for (k=2;k<marcadorDePosicao1;k++)
                        rotulos1[linha][k]=0;
                    strcat(linhasDeCodigo[linha], "02h");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
                else if ((linhasDeInstrucao[linha][i+4]==',')&& ((linhasDeInstrucao[linha][i+5]>=48) && (linhasDeInstrucao[linha][i+5]<=59)))
                {
                    k=i+5;
                    while (k<strlen(linhasDeInstrucao[linha]))
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    strcat(linhasDeCodigo[linha], "04h");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
            }
        }
        else if ((linhasDeInstrucao[linha][i]=='C') && (linhasDeInstrucao[linha][i+1]=='M') && (linhasDeInstrucao[linha][i+2]=='P'))
        {
            if (linhasDeInstrucao[linha][i+3]=='A')
            {
                if ((linhasDeInstrucao[linha][i+4]==',')&& (linhasDeInstrucao[linha][i+5]=='['))
                {
                    k=i+6;
                    while (linhasDeInstrucao[linha][k]!=']')
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    aux=encontraPar(linha);
                    if(aux<10)
                    {
                        rotulos1[linha][0]='0';
                        rotulos1[linha][1]=aux+48;
                    }
                    else
                    {
                        rotulos1[linha][0]=(int)(aux/10)+48;
                        rotulos1[linha][1]=(aux%10)+48;
                    }
                    for (k=2;k<marcadorDePosicao1;k++)
                        rotulos1[linha][k]=0;
                    strcat(linhasDeCodigo[linha], "3ah");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
                else if ((linhasDeInstrucao[linha][i+4]==',')&& ((linhasDeInstrucao[linha][i+5]>=48) && (linhasDeInstrucao[linha][i+5]<=59)))
                {
                    k=i+5;
                    while (k<=strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
                    {
                        rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                        k++;
                        marcadorDePosicao1++;
                    }
                    strcat(linhasDeCodigo[linha], "3ch");
                    strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
                    break;
                }
            }
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='M') && (linhasDeInstrucao[linha][i+2]=='P'))
        {
            k=i+3;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "ebh");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='N') && (linhasDeInstrucao[linha][i+2]=='C'))
        {
            k=i+3;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "73h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='N') && (linhasDeInstrucao[linha][i+2]=='Z'))
        {
            k=i+3;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "75h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='B') && (linhasDeInstrucao[linha][i+2]=='E'))
        {
            k=i+3;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "76h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='R') && (linhasDeInstrucao[linha][i+1]=='E') && (linhasDeInstrucao[linha][i+2]=='T'))
        {
            strcat(linhasDeCodigo[linha], "c3h ");
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='H') && (linhasDeInstrucao[linha][i+1]=='L') && (linhasDeInstrucao[linha][i+2]=='T'))
        {
            strcat(linhasDeCodigo[linha], "f4h ");
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='C'))
        {
            k=i+2;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "72h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='Z'))
        {
            k=i+2;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "74h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
        else if ((linhasDeInstrucao[linha][i]=='J') && (linhasDeInstrucao[linha][i+1]=='A'))
        {

            k=i+2;
            while (k<strlen(linhasDeInstrucao[linha])&& linhasDeInstrucao[linha][k]>=33 && linhasDeInstrucao[linha][k]<=125)
            {
                rotulos1[linha][marcadorDePosicao1]=linhasDeInstrucao[linha][k];
                k++;
                marcadorDePosicao1++;
            }
            aux=encontraPar(linha);
            if(aux<10)
            {
                rotulos1[linha][0]='0';
                rotulos1[linha][1]=aux+48;
            }
            else
            {
                rotulos1[linha][0]=(int)(aux/10)+48;
                rotulos1[linha][1]=(aux%10)+48;
            }
            for (k=2;k<marcadorDePosicao1;k++)
                rotulos1[linha][k]=0;
            strcat(linhasDeCodigo[linha], "77h");
            strcat(linhasDeCodigo[linha+1], rotulos1[linha]);
            break;
        }
    }


}
int mandaPraTela(int linhaFinal)
{
    printf("\n\n\n");
    for (j=0; j<linhaFinal;j++)
    {
        /*printf("\n%d  %s       ",j,linhasDeInstrucao[j]);
        printf("\t");*/
        printf("\n");
        printf("%s", linhasDeCodigo[j]);
        strcat(stringDeArmazenamento, linhasDeCodigo[j]);
        strcat(stringDeArmazenamento, "\n");
        //printf("\t\t");
    }
    printf("\n\n\n\n");
    for (j=0; j<linhaFinal|| j<100;j++)
    {
        if(rotulos[j][0]!=0)
            printf("\n[%d]%s",j,rotulos[j]);
    }
    //printf("%s",stringDeArmazenamento);
}
int main (int argc, char*argv[])
{
    strcpy(nomeDoArquivo,argv[1]);
    //strcpy(nomeDoArquivo,"trabalhoMontador1.dat");
    ponteiroArquivo = fopen(nomeDoArquivo, "rt");
    if (!ponteiroArquivo)
    {
        system("cls");
        printf("\nERRO NA ABERTURA DO ARQUIVO");
        exit(1);
    }
    else
    {
        printf("Abriu bonitinho\n\n");
        leitura();
        preparaLinhas();
        for (j=0; j<=numeroDeLinhas; j++)
            encontraRotulos(j);
        for (j=0; j<=numeroDeLinhas; j++)
            determina(j);
        mandaPraTela(numeroDeLinhas);
        printf("\n\n\n\n");
    }

    fclose(nomeDoArquivo);
}
