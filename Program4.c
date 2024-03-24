//C program to convert miles
//to kilometres
/*Name    : Anoop R A
  Roll No : 1132
  Division: K
  Date    : 17/10/2023
*/
  #include<stdio.h>

  int main()
  {
      //local declaration section
      float distance_in_miles,distance_in_km;
      //input distance in miles
      printf("Enter the Distance in miles:");
      scanf("%f",&distance_in_miles);
      //compute distance in kilometres
      distance_in_km=distance_in_miles*1.609;
      //display distance in km
      printf("Distance in kiolometres is %f",distance_in_km);
      return 0;
  }//end of main()
