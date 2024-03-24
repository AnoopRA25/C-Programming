#include<stdio.h>
void share_investment(int);
main()
{
   int N;
   printf("enter the number of shares in which Ramesh has invested\n");
   scanf("%d",&N);
   share_investment(N);
}

void share_investment(int N)
{
  float amt_invested,profit_loss,total_amount=0.0,share_sell_amount,total_sell_amount;
  int i;
  for(i=1;i<=N;i++)
  {
    printf("enter the amount invested in the share\n");
    scanf("%f",&amt_invested);
    printf("enter profit or loss percentage\n");//if profit enter percentage in positive otherwise in negative
    scanf("%f",&profit_loss);
    total_amount=total_amount+amt_invested;
    share_sell_amount=amt_invested+(amt_invested*profit_loss)/100;
    total_sell_amount=total_sell_amount+share_sell_amount;
  }
  printf("Total amount invested by Ramesh=%f\n",total_amount);
  if(total_sell_amount>total_amount)
     printf("total profit=%f\n",total_sell_amount-total_amount);
  else
     printf("total loss=%f\n",total_amount-total_sell_amount);
}

