/******************************************************************************
filename    pi.c
author      Joey Laybourn
DP email    j.laybourn@digipen.edu
course      CS120
assignment  1
due date    11/26/2037

Brief Description:
This file contains the main function for the pi assignment. It is used as
a "driver" to test the circle_pi function and the leibniz_pi function.

******************************************************************************/

#include <math.h> /*sqrt*/

/******************************************************************************
   Function: circle_pi

   Description: Approximates pi with the circle method

   Inputs:      accuracy - The amount of times the program runs.  The higher 
                           the accuracy, the closer the output is to pi.  

   Outputs:     An approximation of pi with the accuracy based on the input. 
******************************************************************************/
double circle_pi(int rectangles)
{
  double radius = 2;                               /*the radius of the circle*/
  double pi_approx = 0;                            /*the approximation of pi */
  double i;                                        /*loop variable           */
 
  /*width is the radius divided by the rectangles*/
  double width = radius / rectangles;
  
  /*the higher the iteration, the closer the output is to pi*/
  for (i = 0; i < rectangles; i++)
  {
    /*calculates the midpoint*/
    double midpoint = (width / 2) + (width * i);

    /*calculates the height using the formula given*/
    double height = sqrt((radius * radius) - (midpoint * midpoint));

    /*approximates pi with the width multiplied by the height*/
    pi_approx = pi_approx + (width * height);
  }
  return pi_approx;                         /*returns the approximation of pi*/
}

/******************************************************************************
   Function: leibniz_pi

   Description: Approximates pi with the leibniz method

   Inputs:      accuracy - The amount of times the program runs.  The higher
                           the accuracy, the closer the output is to pi.

   Outputs:     An approximation of pi with the accuracy based on the input.
******************************************************************************/
double leibniz_pi(int iterations)
{
  double i;                     /*loop variable                              */
  double sign = -1;             /*switches from 1 to -1 every other iteration*/
  double pi = 1;                /*the approximation of pi                    */    

  /*each iteration gets closer to pi*/
  for (i = 3; i <= iterations * 2; i += 2)
  {
    pi = pi + (sign * 1 / i);   /*divides 1 over every odd number            */
    sign = sign * -1;           /*switches sign from negative to positive    */
  }
  return pi * 4;                /*returns the approximation of pi            */
}