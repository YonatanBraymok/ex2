/******************
Name: Yonatan Braymok
ID: 
Assignment: ex2
*******************/

#include <stdio.h>
#include <strings.h>

int main() {
  int option;
  do {
    printf("Choose an option:\n"); //Options:
    printf("	1. Happy Face\n");
    printf("	2. Balanced Number\n");
    printf("	3. Generous Number\n");
    printf("	4. Circle Of Joy\n");
    printf("	5. Happy Numbers\n");
    printf("	6. Festival Of Laughter\n");
    printf("	7. Exit\n");
    scanf("%d", &option); //User's choice.

    switch (option) {
      case 1: {
          //Happy Face
          char eyes, nose, mouth; //Char variables for the incoming task.
          int faceSize = 2; //Temporary value;
          printf("Enter symbols for the eyes, nose, and mouth:\n");
          scanf(" %c %c %c", &eyes, &nose, &mouth); //User input.
          printf("Enter face size:\n");
          while(faceSize % 2 == 0 || faceSize < 1) { //This loop will work until the user's value is valid.
              scanf("%d", &faceSize);
              if(faceSize % 2 == 0 || faceSize < 1) //conditions for invalid input.
                  printf("The face's size must be an odd and positive number, please try again:\n");
          }
          printf("%c%*c\n", eyes, faceSize + 1, eyes); //Prints the eyes with spaces.
          printf("%*c\n", faceSize / 2 + 2, nose);
          printf("\\"); //Left border of the mouth.
          for(int i = 0; i < faceSize; i++) { //faceSize amount of mouth chars printed.
              printf("%c", mouth);
          }
          printf("/\n"); //Right border of the mouth.
          break;
      }
      case 2: {
          //Balanced Number
          int balancedNum, leftSum = 0, rightSum = 0, digitCounter = 0; //User's input, leftSum counter, rightSum counter, how many digits.
          printf("Enter a number:\n");
          do {
              scanf("%d", &balancedNum);
              if(balancedNum <1)
                  printf("Only positive number is allowed, please try again: \n");
          } while(balancedNum < 1);
          int temp = balancedNum; //Temporary value in order to not change the original value.
          while(temp > 0) { //Count the number of digits.
              digitCounter++;
              temp /= 10; //Each division clears the rightest digit.
          }
          temp = balancedNum; //Resetting temp's value.
          int digits[digitCounter]; //Array with the right amount of space for each digit in balancedNum.
          for(int i = digitCounter - 1; i>= 0; i--) { //A loop that works digitCounter amount of times.
              digits[i] = temp % 10; //insert the rightest digit to the array.
              temp /= 10; //remove the rightest digit from the temporary number.
          }
          if(digitCounter % 2 == 0) { //Even digit number case
              int midDigit = digitCounter/2; //Middle digit
              for(int i = midDigit - 1; i >= 0; i--) { //Runs half the amount of digits and adding each digit to the sum.(Left)
                  leftSum += digits[i];
              }
              for(int i = midDigit; i <= digitCounter - 1; i++) {//Same as the Left sum but for right.
                  rightSum += digits[i];
              }
          } else { //else statement will work if the number of digits is odd.
              int midDigit = digitCounter/2 + 1; //Indicating the middle digit for odd numbers.
              for(int i = midDigit; i <= digitCounter - 1; i++) { //Right sum for odd numbers.
                  rightSum += digits[i];
              }
              for(int i = midDigit - 2; i >= 0; i--) { //Left sum for odd numbers, SKIPPING the middle digit (-2).
                  leftSum += digits[i];
              }
          }
          if(leftSum == rightSum) //Check if the sums are equal.
              printf("This number is balanced and brings harmony!\n");
          else
              printf("This number isn't balanced and destroys harmony.\n");
          break;
      }
      case 3: {
          //Generous number
          int generousNum, divSum = 0; //user's input, sum of all proper divisiors.
          printf("Enter a number:\n");
          do { //Indicates if the input is positive
              scanf("%d", &generousNum);
              if(generousNum < 1)
                  printf("Only positive number is allowed, please try again: \n");
          } while(generousNum < 1);
          for(int i = 1; i < generousNum; i++) { //Runs for all number smaller than input and checks if they are divisors
              if(generousNum % i == 0)
                  divSum += i; //if they are divisors, add them to the sum
          }
          if(divSum > generousNum) //if sum is bigger then the number is generous.
              printf("This number is generous!\n");
          else
              printf("This number does not share.\n");
          break;
      }
      case 4: {
          //Circle of choice
          int num, reversedNum = 0, circleChecker = 1; //input and reversed
          printf("Enter a number:\n");
          do { //checks if num is positive
              scanf("%d", &num);
              if(num < 1)
                  printf("Only positive number is allowed, please try again: \n");
          } while(num < 1);
          int temp = num;
          while(temp > 0) { //reversing the number
              int digit = temp % 10; //gets the rightest digit
              reversedNum = reversedNum * 10 + digit; //pushing all numbers to the left and adding the digit.
              temp /= 10; //removes digit.
          }
          if(num < 2) { //1 is not a prime number
              printf("The circle remains incomplete.\n");
              break;
          }
          for(int i = 2;i <= num / 2;i++) { //checks if num is prime, a number cant have a divisor bigger than its half.
              if(num % i == 0) { //if the statement is true i is a diviosor
                  circleChecker = 0;
                  break; //no need to check more numbers because num isnt prime
              }
          }
          if(circleChecker == 0) {
              //if num is not prime there is no need to check the reversed num.
              printf("The circle remains incomplete.\n");
              break;
          }
          for(int i = 2;i <= reversedNum / 2;i++) { //same for reversed number.
              if(reversedNum % i == 0) {
                  circleChecker = 0;
              }
          }
          if(circleChecker) {
              printf("This number completes the circle of joy!\n");
              break;
          }
          printf("The circle remains incomplete.\n");
          break;
      }
      case 5: {
          //Happy Numbers
          int num, indexNum = 1; //indexNum will be the current number we are checking if is happy or not
          printf("Enter a number:\n");
          do { //checks if num is positive
              scanf("%d", &num);
              if(num < 1)
                  printf("Only positive number is allowed, please try again: \n");
          } while(num < 1);
          printf("Between 1 and %d only these numbers bring happiness: ", num); //we print the line now without new line in order to print only the numbers in the loop.
          while(indexNum <= num) { //while loop runs all the way from 1 to the number
              int digit, sumDigits;
              int temp = indexNum;
              while(temp != 1 && temp != 4) { //eventually every happy number reaches to 1 and every unhappy number reaches to 4.
                  sumDigits = 0; //value to store the sum
                  /*in this loop we store the sum of the digits squared, and then repeat the same thing
                   * for the new value, until temp eventually reaches a value equal to 1 or 4, which mean it has
                   * done 1 circle, if it reached 4 and we continued the loop it would just go on forever repeating the same
                   calculations*/
                  while(temp > 0) {
                      digit = temp % 10;
                      sumDigits += digit * digit;
                      temp /= 10;
                  }
                  temp = sumDigits;
              }
              if(temp == 1) //the while loop stopped so temp is either 1 or 4 and indexNum should be happy if 1 or not if 4
                  printf("%d ", indexNum);
              indexNum++;
          }
          printf("\n");
          break;
      }
      case 6: {
          //Festival Of Laughter
          int smileNum,cheerNum;
          printf("Enter a smile and cheer number:\n");
          scanf("%*[^\n]"); //clears out buffer
          scanf("%*c");
          while(1) { //this loop works if the user didnt match our instructions.
              if((scanf("smile : %d, cheer : %d", &smileNum, &cheerNum) == 2) && smileNum > 0 && cheerNum > 0 && smileNum != cheerNum) {
                  /*we check for all the instructions for correct input: we want to ensure they are positive and different
                   * also, we check that he inserted the input in the correct format which is "smile: x, cheer: y. */
                  break; //the user matched all the instructions so we break the loop.
              }
              printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
              scanf("%*[^\n]"); //clears out buffer
              scanf("%*c"); //we clear the buffer to make sure the scanf will work properly
          }
          int max;
          printf("Enter maximum number for the festival:\n");
          do {
              scanf("%d", &max);
              if(max < 1)
                  printf("Only positive maximum number is allowed, please try again:\n");
          } while(max < 1); //if max is not a positive number then the scan would repeat itself.
          for(int i =1;i <= max;i++) {
              if(i % smileNum == 0) {
                  if(i % cheerNum == 0) {
                      printf("Festival!\n");
                      continue; //if we got here it means both smilenum and cheernum are dividers of i.
                  }
                  printf("Smile!\n");
                  continue; //if we got here it means smilenum is a divider of i.
              }
              if(i % cheerNum == 0) {
                  printf("Cheer!\n");
                  continue; //if we got here it means cheernum is a divider of i.
              }
              printf("%d\n", i); //neither of them are dividers of i.
          }
          break;
      }
      case 7: {
          //Exit
          printf("Thank you for your journey through Numeria!\n");
          break;
      }
      default: { //Invalid input
          printf("This option is not available, please try again.\n");
          break;
      }
    }
  } while(option != 7);
  return 0;
}

