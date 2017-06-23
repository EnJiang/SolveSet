
#include <stdio.h>
#include <algorithm>
#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE *input, FILE *user_output);

void close_file(FILE *f){
    if(f != NULL){
        fclose(f);
    }
}

int main(int argc, char *args[]){
    FILE *input = NULL, *user_output = NULL;
    int result;
    if(argc != 3){
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if(input == NULL || user_output == NULL){
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("result: %d\n", result);

    close_file(input);
    close_file(user_output);
    return result;
}

int spj(FILE *input, FILE *user_output){
    /*
      parameter:
        - input�����������ļ�ָ��
        - user_output���û�����ļ���ָ��
      return:
        - ����û�����ȷ������AC
        - ����û��𰸴��󷵻�WA
        - ������������Լ��Ĵ������ڴ����ʧ�ܣ�����ERROR
      ���û���ɴ˺���.
      demo:
      int a, b;
      while(fscanf(f, "%d %d", &a, &b) != EOF){
          if(a -b != 3){
              return WA;
          }
      }
      return AC;
     */
     int ans[9];
     while(true)
     {
         if (fscanf(input, "%d", ans + 1) != EOF)
         {
             for (int i = 2; i < 9; i++)
             {
                 if (fscanf(input, "%d", ans + i) == EOF) return WA;
             }
             ans[0] = 0;
             int a, b;
             while(fscanf(user_output, "%d", &a) != EOF && a != -1)
             {
                 if (fscanf(user_output, "%d", &b) == EOF) return WA;
                 if (a < 0 || a > 8 || b < 0 || b > 8) return WA;
                 if (ans[b] != 0 || ans[a] == 0)
                 {
                     return WA;
                 }
                 std::swap(ans[b], ans[a]);
             }
             for (int i = 0; i < 9; i++)
             {
                 if (ans[i] != i)
                 {
                     return WA;
                 }
             }
         }
         else
         {
             return AC;
         }
     }
}
