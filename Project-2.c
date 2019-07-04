#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define max 99

void equationdivmul(char arr[],int varr[]);
void equationaddsub(char arr[],int varr[]);
int main()
{
    int n,m;
    //======value input start===
    scanf("%d",&n);
    char var[n],c;
    int val[n];
    int x,i;
    getchar();
    for(i = 0;i < n;i++){
        scanf("%c",&var[i]);
        getchar();
        scanf("%c",&c);
        getchar();
        scanf("%d",&val[i]);
        getchar();
    }
    //======value input finish===

    //======equation input start===
    scanf("%d",&m);
    getchar();
    char eqn[m][50];
    for(i = 0;i < m;i++){
        gets(eqn[i]);
    }
    //======equation input finish===

    //=========Space remove===
    int j,k;
    for(i = 0;i < m;i++){
        for(j =  0;eqn[i][j];j++){
            if(eqn[i][j] == ' '){
                for(k = j;eqn[i][k];k++){
                    eqn[i][k] = eqn[i][k+1];
                }
            }
        }
    }

    //======equation assemble start===

    int veqn[m][50];
    for(i = 0;i < m;i++){
        for(j = 0;eqn[i][j];j++){
            for(k = 0;k < n;k++){
                if(eqn[i][j] == var[k]){
                    veqn[i][j] = val[k];
                }
            }
            if(eqn[i][j] == '+' || eqn[i][j] == '-' ||eqn[i][j] == 'x' ||eqn[i][j] == '/'){
                veqn[i][j] = max;
            }
        }
    }

    for(i = 0;i < m;i++){
        int l = strlen(eqn[i]);
        veqn[i][l] = '\0';
    }


    //======equation assemble finish===

    //======function call start===
    for(i = 0;i < m;i++){
        equationdivmul(eqn[i],veqn[i]);
    }
    return 0;
}

    //======Division + Multiplication function start===
void equationdivmul(char arr[], int varr[]){

    int a,x,i,j,k,l,res = 0;
    l = strlen(arr);
    a = l;
    for(i = 0;i < l;i++){
        if(arr[i] == '/'){
            j = varr[i-1];
            k = varr[i+1];
            res = j / k;
            varr[i-1] = res;
            arr[i-1] = 'c';
            a -= 2;
            for(x = i;x < l-2;x++){
                varr[x] = varr[x+2];
                arr[x] = arr[x+2];

            }
            varr[x] = '\0';
            arr[x] = '\0';
            i--;
        }
        else if(arr[i] == 'x'){
            j = varr[i-1];
            k = varr[i+1];
            res = j * k;
            varr[i-1] = res;
            arr[i-1] = 'c';
            a -= 2;
            for(x = i;x < l-2;x++){
                varr[x] = varr[x+2];
                arr[x] = arr[x+2];

            }
            varr[x] = '\0';
            arr[x] = '\0';
            i--;
        }

    }
    equationaddsub(arr, varr);
}

    //======Addition + Subtraction function start===
void equationaddsub(char arr[], int varr[]){

    int a,x,i,j,k,l,res = 0;

    l = strlen(arr);
    a = l;
    for(i = 0;i < l;i++){
        if(arr[i] == '+'){
            j = varr[i-1];
            k = varr[i+1];
            res = j + k;
            varr[i-1] = res;
            arr[i-1] = 't';
            a -= 2;
            for(x = i;x < l-2;x++){
                varr[x] = varr[x+2];
                arr[x] = arr[x+2];

            }
            varr[x] = '\0';
            arr[x] = '\0';
            i--;
        }
        else if(arr[i] == '-'){
            j = varr[i-1];
            k = varr[i+1];
            res = j - k;
            varr[i-1] = res;
            arr[i-1] = 't';
            a -= 2;
            for(x = i;x < l-2;x++){
                varr[x] = varr[x+2];
                arr[x] = arr[x+2];

            }
            varr[x] = '\0';
            arr[x] = '\0';
            i--;
        }

    }
    if(varr[0] < 1000 && varr[0] > -1000)
        printf("%d\n",varr[0]);
    else
        printf("Compilation Error.!\n");
}

