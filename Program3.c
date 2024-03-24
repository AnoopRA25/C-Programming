//C program to compute distance and time
//for Mohan to reach Sohan
/*Name    : Anoop R A
  Roll No : 1132
  Division: K
  Date    : 17/10/2023
*/
  #include<stdio.h>
  #include<math.h>

  int main()
  {
      //local declaration section
      int x1,x2,y1,y2;
      float speed,distance,time;
      //input mohan's coordinate
      printf("Enter Mohan's Coordinate:");
      scanf("%d%d",&x1,&y1);
      //input for Sohan's coordinate
      printf("Enter Sohan's Coordinate:");
      scanf("%d%d",&x2,&y2);
      //input speed
      printf("Enter Speed:");
      scanf("%f",&speed);
      //compute distance
      distance=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
      //compute time
      time=distance/speed;
      //display distance and time
      printf("Distance is %f\n",distance);
      printf("Time to reach Sohan is %f hrs:",time);
      if(time<1)
      {
          //true block
          printf("Yes, Mohan can reach Sohan within one hour\n");
      }
      else
      {
          //false block
          printf("No Mohan cannot reach sohan within one hour\n");
      }
      return 0;
  }//end of main()
