#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char arrmain [10][8] = {"+", "", "abcABC", "defDEF", "ghiGHI", "jklJKL", "mnoMNO", "pqrsPQRS", "tuvTUV", "wxyzWXYZ"};

typedef struct 
{
    char a[3][8];
}
arr_to_string;

arr_to_string god_give_me_string(char* input)
{
    int input_len = strlen(input);
    arr_to_string input_to_string;
    for (int i = 0; i < input_len; i++)
    {
        switch (input[i])
        {
        case '0':
            strcpy(input_to_string.a[i], "+");
            break;
        case '1':
            break;
        case '2':
            strcpy(input_to_string.a[i], "abcABC");
            break;
        case '3':
            strcpy(input_to_string.a[i], "defDEF");
            break;
        case '4':
            strcpy(input_to_string.a[i], "ghiGHI");
            break;
        case '5':
            strcpy(input_to_string.a[i], "jklJKL");
            break;
        case '6':
            strcpy(input_to_string.a[i], "mnoMNO");
            break;
        case '7':
            strcpy(input_to_string.a[i], "pqrsPQRS");
            break;
        case '8':
            strcpy(input_to_string.a[i], "tuvTUV");
            break;
        case '9':
            strcpy(input_to_string.a[i], "wxyzWXYZ");
            break;
        default:
            break;
        }
    }
    return input_to_string;
}

int mystrlen (char arr[])//моя функция strlen
{
    int j=0, lengthofarr=0;
    while(arr[j] != '\0')
    {
         lengthofarr++;
         j++;

    }
        return lengthofarr;
}

int namesearch (char inputnumber[], char listname[], int lenghtinput)//функция, которая ищет совпадения с именем
{ 
    int i= -1, j=0, k, count=0, match=0,difference, index, lenghtlistname=0;
    
    lenghtlistname= mystrlen(listname);
    while (j<lenghtinput)//цикл проходит по символам строки ввода
    { 
        arr_to_string input_to_string = god_give_me_string(inputnumber);

        for(i=i +1; i<lenghtlistname; i++)//цикл проходит по символам строки из списка
        {
            for (index = 0; index < 8; index++) // цикл проходит по символам массива букв, соответствующих цифре из ввода
            {
                difference=listname[i] - input_to_string.a[j][index];//сравнивает символ из массива с символом строки из списка
                if(0 == difference) //если есть совпадение выходит из цикла
                {
                match=1;//индикатор совпадения
                break;
                }
            }

            if(match==1)//если индикатор сработал увеличивается переменнуая флаг
            {
                count++;
                break;
            }

        }
        match=0;//обнуляется индикатор совпадения
        j++;
    }

   if(count==lenghtinput)// если переменная флаг совпадает с длинной чисел ввода, то контакт найден
      return 1;
   else 
      return 0;
   
}

int numbersearch (char inputnumber[], char listnumber[], int lenghtinput)// функция поиска числа
{ 
   int i= -1, j=0, count=0, difference, lenghtlistnum=0;
       
  lenghtlistnum= mystrlen(listnumber);
    
  while (j<lenghtinput)//цикл проходит по символам строки ввода
  {
             
      for(i=i +1; i<lenghtlistnum; i++)//цикл проходит по символам строки из списка
      {
         difference= listnumber[i] - inputnumber[j];//сравнивает символ из массива с символом строки из списка
         if(listnumber[i] == '+' && inputnumber[j] == '0')//поправка на возможный +
               difference=0;
      if(0 == difference)//если есть совпадение увеличивается переменная флаг
         {
            count++;
            break;
         }
      }
      j++;
   }

   if(count==lenghtinput)//если переменная флаг совпадает с длинной чисел ввода, то контакт найден
      return 1;
   else 
      return 0;
   
}

int main(int argc, char* argv[])
{    
    char* inputnumber= argv[1];
    char listnumber[100];
    char listname[100];
    int count=0;
    int i;
    int lenghtinput;
    int notfound=0;//переменная флаг ненайденного контакта
    if(argc<2)//если пользователь не ввел число 
    {
    while(NULL != fgets(listname, 100, stdin))//в строку буфер записываются только имена
     {    
        fgets(listnumber, 100, stdin);//в строку буфер записываются только числа
        listname[strlen(listname)-1]='\0'; //убираем lf
        printf("%s, %s\n", listname, listnumber);// выводим весь список контактов
      }
   }

   if(argc==2)//если пользователь правильно ввел число
   {
      lenghtinput= mystrlen(inputnumber);
      while(NULL != fgets(listname, 100, stdin))//в строку буфер записываются только имена
     {
        
        fgets(listnumber, 100, stdin);//в строку буфер записываются только числа
        if(namesearch(inputnumber,listname,lenghtinput)==1||numbersearch(inputnumber,listnumber,lenghtinput)==1)//проверка на совпадения имени или номера
        {
            notfound++;//если контакт был найден, то переменная ненайденного контакта изменяется
            listname[strlen(listname)-1]='\0';
            printf("%s, %s\n", listname, listnumber);
        }
     }
     if(notfound==0)//если переменная ненайденного контакта не изменилась вывод контакт не найден
     printf("Not found\n");
   }  
   else//если пользователь неправильно ввел аргумент(больше чем 2) вывод сообщения об ошибке
   {
      printf("Too many arguments\n");
      return 1;
   }
   return 0;
   
}