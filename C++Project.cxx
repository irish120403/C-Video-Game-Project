#include <stdlib.h>
#include <stdio.h>
#include <string.h> //Used AI to figure this out to make my game smoother to make. Only did it towards the end
#include <time.h> //Used AI for getting random numbers
#include <math.h>

//Code written by Chad Isbell and Omar Morsy


//I (Chad Isbell) did use AI for part of this to figure out how to get a random number of wins and losses for each team. Also used it for string operations like "\0". You can find this in
//google doc that I sent 
//I will indicate every single instance where AI was used
//I (Chad Isbell) did the entirety of the tournament game (case 1 in the gameChoice switch statement)

//I (Omar Morsy) did NOT use AI for this game
//I(Omar Morsy) completed the games in case 2 and case 3 of the gameChoice switch Statement. (quiz_soccer_game function and )



//Game 1- Tournament game.  You pick a team and then play against up to 3 different opponents.  To win, you must win on offense and defense.  For further elaboration see the rules in game 1'
//Game 2 - Soccer quiz.  You must answer different soccer trivia questions. (May have to look them up if you are unfamilar with soccer)
//Game 3 - Penalty shootout. In soccer you have to pick which direction to shoot in, and the goalkeeper has to predict what you will do. The concept is the same here.

//Prototype Functions

int header();

//Tournament game (game 1)

void Rules(); //Our single no input no output function.
int differentTeams(char [][30],int [],int[],int);
void Gameplay(char [],char [][30],int [],int [],int);
int Offense();
int Defense();
int Overtime(char []);

//Soccer quiz game (game 2)

int Quiz_soccer_game(int round);

//penalty shooting game (game 3)

int PenaltyGame();





int main(void){
	
	
	
	
	srand(time(NULL));//Used AI to figure out how to do this
	//Outside switch case
	
	int gameChoice,continue1,infinite = 1; //
	while(infinite == 1){ // Will run indefinitely until broken out of using a break
	
	gameChoice = header(); // Calling the header function
	

switch(gameChoice){ // Switiching game choices.  game you play depends on number you enter
	
	case 1:{  // Plays the first game (tournament game)
	
	//Tournament style game
	
	
	//Variables tab for game 1:
	
	int teamChoice=11; //Will store the team that the user chooses.  Pass this into the function
	char teamNames[10][30] = {"Bulls","Eagles","Rhinos","Pigeons","Tigers","Jaguars","Lions","Ponies","GoldFish","Dragons"}; //String names for all 10 teams
	int userChoice1,i; //userChoice1 allows player to see the name and record of every team
	char userTeam[100];
	
	int Wins[10],Losses[10]; // Getting these outside of the funtion so that they can remain the same if the user wants to select the option twice
	
	for (int i = 0; i<10;i++){
		
		
		Wins[i] = (rand()%16)+1; //Used AI to get this notation
		Losses[i] = 16 - Wins[i];
		
		
		
	}
	
	

	
	//Main Function
	
	printf("Welome to the playoff simulator!\nHere you can pick your favorite team and try to win the championship!");
	do{
	
	do{
	
	printf("\n\nPress 1 to read the rules\nPress 2 to see names of every team and their record, and to choose your team\nPress 3 to begin the game only after you have selected a team in option 2\nEnter Choice: "); //Have a couple different options before the games begin (Like see teams and records, etc) Repeat and let user pick multiple options if they so choose
	scanf("%d",&userChoice1);
	
	if(userChoice1 <1 || userChoice1 >3){  //Error checking to make sure user enters 1-3
		
		printf("Please select a number 1-3");
		while (getchar() != '\n');
		
	}
	
	
}while(userChoice1 != 1 && userChoice1 != 2 && userChoice1 !=3);
	
	
	
	
	if (userChoice1 == 1){  //Call rules 
		
		Rules();
		
		
	}
	
	else if (userChoice1 == 2){
		
		teamChoice = differentTeams(teamNames,Wins,Losses,teamChoice);
		switch (teamChoice){
			
			case 0:{
			
			strcpy(userTeam, teamNames[teamChoice]);  //Used strcpy to place the name of a string into a variable, in this case teamNames[teamChoice] into userTeam
			i =0;//using i to be a placeholder number for the corresponding team name, starting at index 0
			
			
			
			break;	
			}
			
			case 1:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i =1;
			
			
			break;	
			}
			
			case 2:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 2;
			
			
			break;	
			}
			
			case 3:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 3;
			
			break;	
			}
			
			case 4:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 4;
			
			break;	
			}
			
			case 5:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 5;
			
			break;	
			}
			
			case 6:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 6;
			
			break;	
			}
			
			case 7:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 7;
			
			break;	
			}
			
			case 8:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 8;
			
			break;	
			}
			
			case 9:{
			
			strcpy(userTeam, teamNames[teamChoice]);
			i = 9;
			
			break;	
			}
			
			
			
			
			}
		
		
	}
	
	else {
		
		
		//Call actual game function if correct conditions are met
		
		
		if (teamChoice == 11){  //Initialized teamChoice to be 11 before to make sure that user picks a team
			
			
			
			printf("Please select 2 and select a team");
			
			
			
		}
		
		else{
			
			Gameplay(userTeam,teamNames,Wins,Losses,i);//Calling game function
			
		}
	}
	}while(userChoice1 == 1 || userChoice1 == 2 || (userChoice1 == 3 && teamChoice == 11));	//Same with here	
		
		
		
		
		break;
	}
	

//End of case 1
	
	case 2:{
		
		//Variables
    char play_again;
    int result;
    
//do - while loop to play again
    do {
        
        //Calling the function
        result = Quiz_soccer_game(1);
        if (result == 1) {
            printf("\nCongratulations! You have won the game!\n");
        } else {
            printf("\nGame Over! Better luck next time!\n");
        }

        printf("\nDo you want to play the soccer quiz game again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThank you for playing! Goodbye!\n");

		
		break;
		
	}//end of case 2
	
	
	case 3:{
		//calling the plenalty game
    int finalPlayerScore = PenaltyGame();
   
    printf("Player's Final Score: %d\n", finalPlayerScore);
		
		break;
	}
	
	case 4:{
		
		printf("We hope you enjoyed the games!");
		break;
	}
	
}
	if(gameChoice == 4){
		
	break;	
	}
	
	do{
	printf("\nWould you like to select another game? (1 to select another game, 2 to stop)\nEnter Choice: ");
	scanf("%d",&continue1);
}while(continue1<1 || continue1>2);
	
	if(continue1 == 2 ){
		
		printf("\nWe hope you enjoyed the games! Have a nice day!");
		break;
		
	}
	
 // end of switch statement to choose different games
	
	
	
}

return 0;

}



//Functions



void Rules(){
	
	
	printf("\nRule 1: You must first select a team to play as.  You may choose any team, and go as an 'underdog' if you please.  Only after you select a team you may start a game up.\n");
	printf("Rule 2: Once in a game, the number 1 or 2 will be randomly generated, and you must select the correct one (similar to heads to tails)\n");
	printf("Rule 3: If you select the correct number, you will begin on offense.  Your opponent will \"choose\" a number from 1-10, and you must pick within 2 of that number to win on offense.\n");
	printf("Example: The opponent chooses the number 6. To win, you must select in the range of 4-8 to win (+-2).\n");
	printf("Rule 4: If you select the wrong number, you will begin on defense.  On defense, you will choose a number, and your opponent will try to pick a number in a +- 2 range to eliminate you.\n");
	printf("Example: You select the number 3. If your opponent choose any number in the range of 1-5, you will lose on defense.\n");
	printf("Rule 5: In the result of a tie, where you and your opponent each win one turn (You win offense and they win defense, or vice versa), the game will enter overtime.\n");
	printf("In overtime, you and your opponent will go back and forth on offense until one team eventually wins both rounds.\n");
	printf("Rule 6: If you win a round, you will move onto the next, facing a new opponent.  There are 3 total rounds, and winning the third will result in a lot of glory!\n");
	printf("Rule 7: The final rule is to have fun.  This game is based purely off luck, so try to have fun.");
	
	
	

	
}





int differentTeams(char teamNames[][30],int Wins[],int Losses[],int teamChoice){
	
	
	//Has a list of every time with a random record (16 totals games played)
	//Need to return the entire list somehow (Pointer?)
	
	
	
	for (int i = 0;i<10;i++){
		
		
		printf("Team Name: %d.) %s\tRecord: %d-%d\n",i+1,teamNames[i],Wins[i],Losses[i]);
		
		
		
	}
	
	//char extra;
	
	do {
		
		printf("\nPlease choose what team you would like (1-10): ");
		scanf("%d",&teamChoice);
		
		if((teamChoice<1 || teamChoice>10)){
			
			
			printf("\nPlease make sure to select a number 1-10");
			while (getchar() != '\n'); // learned this from AI.  Prevents the program from infinitely looping if a string is entered instead of a number.
		}
		
		
		
	}while((teamChoice<1 || teamChoice>10));
	
	teamChoice = teamChoice-1; // subtracting to get index starting at 0
	
	return teamChoice;
	
	
	
}


//Second function will involve the gameplay itself
//Will likely be repeated 4 times in the main, since the game itself will stay the same.
//Everytime it is called there will be a different team that you go against








void Gameplay(char userTeam[],char teamNames[][30],int Wins[],int Losses[],int i){
	
	//int randOffense,userOffense; // variables so that the user can enter them into userOffense and then compare to randoffense
	char opponent[100]; //Establishing so that the player can play a team that they have not chosen
	int resultMatch,k=1,OneOrTwo,userGuess;
	//Round 1 of tournament
	
	
	
		
	do{
	
	
	
	//int resultOffense1,resultMatch1,resultDefense1; // if equal to 1, player won the match, if equal to 2, player lost the match
	
	if(k<3){
		
		
	printf("\n\nWelcome to round %d of the tournament\n",k);
	
}

else{
	printf("\n\nWelcome to the final round of the tournament!");
	
	
}
	
	if(i<(8+k)){//if k = 3, team will not exist so have to go the else where they can pick a valid team. 8 is arbitary number
	
	strcpy(opponent, teamNames[i+k]);
	printf("\n\nOpponent %d will be %s",k,opponent);
	
	
}

	else {
	strcpy(opponent, teamNames[i-k]);
	printf("\n\nOpponent %d will be %s",k,opponent);
	
	
} // If the given i value from switch statement is the last number in the array, then it will not be able to do the first if statement. so it will then go to i-1 which is guaranteed to be good

printf("\n\nGame Start!\n%s v. %s",userTeam,opponent);

OneOrTwo = (rand()%2)+1;//Random number 1-2


do{
printf("\n\nPlease choose 1 or 2 to decide who starts the game: ");
scanf("%d",&userGuess);
}while(userGuess!=1 && userGuess !=2);

//resultTotal = 0;
// will break out since infinite will never change.  Also could break out if result = 2 or 0;





if(userGuess == OneOrTwo){
	
	printf("\n\nYou guessed correctly!");
	printf("\nYou will start the game");
	
	//Game will be:
	//Player will enter a number 1-10.  If it is within 3 of a randomly generated number, the player loses a turn. If it is not, the user will get that number added to their total.
	//Whatever player gets the highest number wins.  
	
	//Call Offense
	//Call Defense
	// If you win, your points go up, if not points don't go up.  if you end the game with 1, that means you won one and lost one so need to do the overtime.
	
	int resultOffense1 = Offense();
	int resultDefense1 = Defense();
	
	int result1 = resultDefense1 + resultOffense1;
	
	if(result1 == 2){
		printf("\n\nCongrats! You win Round %d",k);
		resultMatch = 1;
	}
	
	else if(result1 == 0) {
		
		
		printf("\n\nYou have lost round %d.  %s will be moving on to the next round.",k,opponent);
		resultMatch = 0;
	}
	else {
		printf("\n\nEntering Overtime. Go until you win out");
		resultMatch = Overtime(opponent);
		
		
		
		
		
	}
	
}


else if (userGuess != OneOrTwo){
	
	
	printf("\n\nYou have guessed incorrectly!\nYou will play Defense first");
	
	int resultDefense1 = Defense();
	int resultOffense1 = Offense();
	
	int result1 = resultDefense1 + resultOffense1;
	
	
	if(result1 == 2){
		
		printf("\n\nCongrats! You win Round %d",k);
		resultMatch = 1;
	}
	
	else if(result1 == 0) {
		
		
		printf("\n\nYou have lost round %d.  %s will be moving on to the next round.",k,opponent);
		resultMatch = 0;
	}
	else {
		printf("\n\nEntering Overtime. Go until you win out");
		
		resultMatch = Overtime(opponent);
		
		
		
	}
	
}

k++; // Indexing k to be used for determination of what team you play


if(k==4){
	
	printf("Congrats! You have won the tournament!\nSince you won, could you please give us a 100%% in the class (joke (but it would be cool if you did))");
	
}

}while(resultMatch == 1&&k<4);

	
	


	
	//SemiFinals of tournament
	
	
	//Finals of tournament
	
	
	
	
	
	
}



int Offense(){
	
	
	//Basically copy and paste whatever is in the first offense thing I made into here
	//return the result of the play (1 or 2)
	
	
	
	int randOffense = (rand()%9)+1,userOffense;
	int result;
	
	printf("\nPlaying Offense Now");
	
	do{
	printf("\n\nPlease enter a number 1-10: ");
	scanf("%d",&userOffense);
}while(userOffense<1 || userOffense>10);


if (userOffense >= (randOffense -2 ) && userOffense<=(randOffense+2) ){
	
	printf("\nYou win on offense!");
	result =1;
	
}
	else{
		
		printf("\nYou lost on offense");
		result = 0;
	}
	
	return result;
	
}


int Defense(){
	
	int randDefense = (rand()%9)+1;
	int userChoiceDefense,result;
	
	
	printf("\nPlaying Defense Now");
	
	do{
		
		printf("\nPlease enter a number 1-10: ");
		scanf("%d",&userChoiceDefense);
		
}while(userChoiceDefense<1 || userChoiceDefense >10);
	
	
	if(userChoiceDefense>(randDefense+2) || userChoiceDefense<(randDefense-2)){
		
		printf("\nCongrats! You won on defense! ");
		result = 1;
		
	}
	else{
		
		printf("\nYou lose on defense ");
		result = 0;
	}
	
	return result;
	
}
int Overtime(char opponent[]){
	
	//Call this only in cases where you win on offense and lose on defense
	

	
	
	int infinite = 1,resultMatch,finalResult;
	
	
	while (infinite == 1){
		
		int result1 = Offense();
		int result2 = Defense();
		
		finalResult = result1 + result2;
		
		if (finalResult == 2){
		
		printf("\nCongrats!  You win in Overtime!");
		resultMatch = 1;
		
		
		break;
			
		}
		else if(finalResult == 0){
			
			printf("\nYou have unfortunately lost in overtime.");
			resultMatch = 0;
			
			break;
			
		}
		else{
			
			printf("\n\nGoing again until a winner is declared.");
			
			
		}
		
	}
	
	return resultMatch;
	
}

int Quiz_soccer_game(int round) {
    int answer;

    printf("Welcome to the Football Quiz Game!\n");
    printf("Answer the questions correctly to win!\n\n");

    // Round 1
    printf("1. Who is the top scorer in UEFA Champions League all time?\n 1) Cristiano Ronaldo  2) Lionel Messi  3) Robert Lewandowski\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("2. Who is the top scorer in La Liga?\n 1) Cristiano Ronaldo  2) Lionel Messi  3) Karim Benzema\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 2) {
        return 0;
    }

    printf("3. Who is the top scorer in the World Cup?\n 1) Miroslav Klose  2) Pele  3) Ronaldo\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("4. Who is the top scorer in the Premier League?\n 1) Wayne Rooney  2) Alan Shearer  3) Harry Kane\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 2) {
        return 0;
    }

    printf("5. Who is the top scorer in the Euro?\n 1) Cristiano Ronaldo  2) Michel Platini  3) Antoine Griezmann\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("6. Who is the top scorer in Copa America?\n 1) Zizinho  2) Lionel Messi  3) Norberto Mendez\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1 && answer != 3) {
        return 0;
    }

    printf("\nCongratulations! You have qualified for Round 2!\n\n");

    // Round 2
    printf("1. How many goals did Cristiano Ronaldo score in La Liga?\n 1) 311  2) 450  3) 374\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("2. How many goals did Lionel Messi score in La Liga?\n 1) 474  2) 500  3) 450\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("3. Who won the Ballon d'Or in 2016?\n 1) Cristiano Ronaldo  2) Lionel Messi  3) Luka Modric\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    printf("4. Which national team has won the World Cup the most?\n 1) Brazil  2) Germany  3) Italy\nYour answer: ");
    scanf("%d", &answer);
    if (answer != 1) {
        return 0;
    }

    return 1;
}

int header(){
	
	int gameChoice;
	
	do{
	
	
	printf("Hello! Welcome to game world! Please select 1-4 to choose what game you want to play!\n1.)Tournament Game\n2.)Soccer Quiz\n3.)Penalty Shootout\n4.)No game (exit menu)\nEnter Choice: ");
	scanf("%d",&gameChoice);
	
	while (getchar() != '\n');
}while(gameChoice<1 || gameChoice>4);//Error checking to make sure only number 1-3, no letters or anything
	
	return gameChoice;
	
}

int PenaltyGame() {
    //variables
    int goalKChoice, player_Choice;
    int player_Score = 0, goalKScore = 0;
    char play_Again;
    
    printf("Welcome to the Penalty Kick game!\n");
    do {
        printf("\nIt's your turn to kick! Choose a direction:\n");
        printf("1. Left\n");
        printf("2. Center\n");
        printf("3. Right\n");
        printf("Your choice: ");
        scanf("%d", &player_Choice);
        
        // Goalkeeper's choice (manual pseudo-randomization for simplicity)
        goalKChoice = (player_Choice + 1) % 3 + 1;
        
        // Checking if the goal is scored
        if (player_Choice == goalKChoice) {
            printf("Goalkeeper saved it! No goal.\n");
            goalKScore++;
        } else {
            printf("GOAL! You scored!\n");
            player_Score++;
        }
        
        printf("Player Score: %d, Goalkeeper Saves: %d\n", 
               player_Score, goalKScore);
        printf("Do you want to take another penalty kick? (y/n): ");
        scanf(" %c", &play_Again);
    } while (play_Again == 'y' || play_Again == 'Y');
    
    printf("\nFinal Score: Player %d - %d Goalkeeper\n", 
           player_Score, goalKScore);
    printf("Thanks for playing!\n");
    
    return player_Score;  //returning the player score to the main
}
