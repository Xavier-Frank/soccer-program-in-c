#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


// function signatures
void collect_game_results(void); // this function collects the points acquired by each team
void view_results(void); // this function retrives head to head results of the teams
void display_menu(void); // this is the displays the menu for navigation 
void collect_game_results_menu(void); //menu for collecting game results

int main(void)
{

    display_menu();

}

void display_menu(void){
    system("cls");
    int option;

        printf("\n\t||=====================================================================|| \n");
        printf("\n\t||=========================   MAIN MENU     ===========================|| \n");
        printf("\n\t||=====================================================================|| \n");
        printf("\n");
        printf("\tSelect an Option to Continue\n");
        printf("\n\t\t[1] -> Store games results of Team A, B, C, D\n");
        printf("\t\t[2] -> View Results of Each Team\n");
        printf("\t\t[3] -> Exit the Program\n");
        printf("\n\tEnter an option: ");
        scanf(" %d",&option);

        switch (option)
        {
        case 1:
            printf("\n\tLoading the selected view...");
            sleep(1);
            collect_game_results_menu();
            break;
        case 2: 
            printf("\n\tLoading the selected view...");
            sleep(1);
            view_results();
            break;
        case 3: 
            system("cls");
            printf("Closing the applicaiton...");
            sleep(2);
            printf("\n Operation Succesful");
            exit(0); 
            break;   
        default: printf("\tInvalid choice! Please Try Again:\n");
            display_menu();
            break;
        }
}

void collect_game_results_menu(void){
    system("cls");
    int option;

    system("cls");
    printf("\n\t||=====================================================================|| \n");
    printf("\n\t||========================= ON TO THE FIELD...=========================|| \n");
    printf("\n\t||=====================================================================|| \n");
    printf("\n");
    printf("\tSelect an Option to Continue\n");
    printf("\n\t\t[1] -> Store games results of Team A, B, C, D\n");
    printf("\t\t[2] -> Go Back to Main Menu\n");
    printf("\t\t[3] -> View Results\n");
    printf("\t\t[4] -> Exit the Program\n");
    printf("\n\tEnter an option: ");
    scanf(" %d",&option);

    switch (option)
        {
        case 1:
            printf("\n\tLoading the selected view...");
            sleep(2);
            collect_game_results();
            break;
        case 2: 
            printf("\n\tLoading the selected view...");
            sleep(1);
            display_menu();
            break;
        case 3:
            printf("\n\tLoading the selected view...");
            sleep(1);
            view_results();
            break;
        case 4: 
            system("cls");
            printf("Closing the applicaiton...");
            sleep(1);
            printf("\n Operation Succesful");
            exit(0); 
            break;   
        default: printf("\tInvalid choice! Please Try Again:\n");
            display_menu();
            break;
        }

}

void collect_game_results(void){
    //clear the screen for better view
    system("cls");

    // All variables used in this method
    int score[4][3];
    char outcome;
    char teamA[10] = "Team A";char teamB[10] = "Team B";char teamC[10] = "Team C";char teamD[10] = "Team D";
    int match_points=1;
    int total_points_teamA, total_points_teamB, total_points_teamC, total_points_teamD = 0;
	int i,j;
    int number_of_goals_by_teamA_vs_B, number_of_goals_by_teamA_vs_C, number_of_goals_by_teamA_vs_D,
     number_of_goals_by_teamB_vs_C, number_of_goals_by_teamB_vs_D, number_of_goals_by_teamB_vs_A,
     number_of_goals_by_teamC_vs_A, number_of_goals_by_teamC_vs_B,number_of_goals_by_teamC_vs_D,
     number_of_goals_by_teamD_vs_A, number_of_goals_by_teamD_vs_B, number_of_goals_by_teamD_vs_C = 0;
    int total_goals_by_A, total_goals_by_B, total_goals_by_C, total_goals_by_D = 0;

    int teamA_number_of_wins, teamB_number_of_wins,teamC_number_of_wins,teamD_number_of_wins = 0;
    int teamA_number_of_draws, teamB_number_of_draws,teamC_number_of_draws,teamD_number_of_draws = 0; 
    int teamA_number_of_losses, teamB_number_of_losses,teamC_number_of_losses,teamD_number_of_losses = 0; 


    // Create a file pointer to work with files
    FILE *filepointer;

    //opening file in write mode to save game details
    filepointer = fopen("scores.dat", "w+");

    //check if operation was succesful
    if (filepointer == NULL)
    {
        printf("Error opening the file, application is rerouting back to menu");
        sleep(2);
        collect_game_results_menu();

    }

    printf("\n\t||=====================================================================|| \n");
    printf("\n\t||===================== Enter Results for Each Match  =================|| \n");
    printf("\n\t||=====================================================================|| \n");
    printf("\n\t\t\t\t -- Initial Table Overview --\n");
    printf("\n\t\t Teams \t\t No. of Matches \t Goals \t\t Points \n");
    printf("\t\t A \t\t\t 3 \t\t 0 \t\t 0 \n\t\t B \t\t\t 3 \t\t 0 \t\t 0\n");
    printf("\t\t C \t\t\t 3 \t\t 0 \t\t 0 \n\t\t D \t\t\t 3 \t\t 0 \t\t 0\n");
    printf("\n\tNOTE: Enter 'W' if first the team Won, 'D' if both teams Drew, 'L' if the first team Lost\n");

    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if(i==0 && j ==0){
                int num;

	 		    printf("\n\t Enter the results of Team A Vs. Team B \n");
	 	        printf("\tTeam A -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);
                //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamA_number_of_wins +=1; //increment number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamA_number_of_draws +=1; //increment number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamA_number_of_losses +=1; //increment number of losses
                }
//	 		    condition to check if the input is either W, D or L
                else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }

                printf("\n\t Enter the number of goals scored by Team A:");
	 	        scanf("%d", &number_of_goals_by_teamA_vs_B);
                
            }

            else if(i==0 && j ==1){

	 		    printf("\n\t Enter the results of Team A Vs. Team C \n");
	 	        printf("\tTeam A -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

             //set results in the array for a win, draw or loss
                 if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamA_number_of_wins +=1; //increment number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamA_number_of_draws +=1;
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamA_number_of_losses +=1;
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored  by Team A:");
	 	        scanf("%d", &number_of_goals_by_teamA_vs_C); 		
		 }
          else if(i==0 && j ==2){

	 		    printf("\n\t Enter the results of Team A Vs. Team D \n");
	 	        printf("\tTeam A -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

             //set results in the array for a win, draw or loss
                 if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamA_number_of_wins +=1; //increment number of wins for team A
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamA_number_of_draws +=1; //increment number of draws for team A
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamA_number_of_losses +=1; //increment number of losses for team A
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team A:");
	 	        scanf("%d", &number_of_goals_by_teamA_vs_D);
        }
        else if(i==1 && j ==0){

	 		    printf("\n\t Enter the results of Team B Vs. Team A \n");
	 	        printf("\tTeam B -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamB_number_of_wins +=1; //increment number of wins for team B
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamB_number_of_draws +=1; //increament number of draws for team B
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamB_number_of_losses +=1; //increament number of losses for team B
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team B:");
	 	        scanf("%d", &number_of_goals_by_teamB_vs_A);
            
        }
        else if(i==1 && j ==1){

	 		    printf("\n\t Enter the results of Team B Vs. Team C \n");
	 	        printf("\tTeam B -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
               if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamB_number_of_wins +=1; //increment number of wins for team B
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamB_number_of_draws +=1; //increament number of draws for team B
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamB_number_of_losses +=1; //increament number of losses for team B
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team B:");
	 	        scanf("%d", &number_of_goals_by_teamB_vs_C);
        }
        else if(i==1 && j ==2){

	 		    printf("\n\t Enter the results of Team B Vs. Team D \n");
	 	        printf("\tTeam B -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamB_number_of_wins +=1; //increment number of wins for team B
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamB_number_of_draws +=1; //increament number of draws for team B
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamB_number_of_losses +=1; //increament number of losses for team B
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team B:");
	 	        scanf("%d", &number_of_goals_by_teamB_vs_D);
        }
        else if(i==2 && j == 0){

	 		    printf("\n\t Enter the results of Team C Vs. Team A \n");
	 	        printf("\tTeam C -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamC_number_of_wins +=1; // increment team C number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamC_number_of_draws +=1; // increment team C number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamC_number_of_losses +=1; // increment team C number of losses
                }

//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team C:");
	 	        scanf("%d", &number_of_goals_by_teamC_vs_A);
        }

        else if(i==2 && j == 1){

	 		    printf("\n\t Enter the results of Team C Vs. Team B \n");
	 	        printf("\tTeam C -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamC_number_of_wins +=1; // increment team C number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamC_number_of_draws +=1; // increment team C number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamC_number_of_losses +=1; // increment team C number of losses
                }

//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team C:");
	 	        scanf("%d", &number_of_goals_by_teamC_vs_B);
        }

         else if(i==2 && j == 2){

	 		    printf("\n\t Enter the results of Team C Vs. Team D \n");
	 	        printf("\tTeam C -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamC_number_of_wins +=1; // increment team C number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamC_number_of_draws +=1; // increment team C number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamC_number_of_losses +=1; // increment team C number of losses
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team C:");
	 	        scanf("%d", &number_of_goals_by_teamC_vs_D);
        }
         else if(i==3 && j == 0){

	 		    printf("\n\t Enter the results of Team D Vs. Team A \n");
	 	        printf("\tTeam D -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
                if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamD_number_of_wins +=1; //increment team D number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamD_number_of_draws +=1; //increment team D number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamD_number_of_losses +=1; //increment team D number of losses
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team D:");
	 	        scanf("%d", &number_of_goals_by_teamD_vs_A);
        }

        else if(i==3 && j == 1){

	 		    printf("\n\t Enter the results of Team D Vs. Team B \n");
	 	        printf("\tTeam D -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
               if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamD_number_of_wins +=1; //increment team D number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamD_number_of_draws +=1; //increment team D number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamD_number_of_losses +=1; //increment team D number of losses
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team D:");
	 	        scanf("%d", &number_of_goals_by_teamD_vs_B);
        }
        else if(i==3 && j == 2){

	 		    printf("\n\t Enter the results of Team D Vs. Team C: \n");
	 	        printf("\tTeam D -> Won/Drew/Lost: Enter ('W'/'D'/'L'):");
	 		    scanf(" %c", &outcome);

            //set results in the array for a win, draw or loss
               if (outcome == 'W')
                {
                    match_points = 1 * 3;
                    score[i][j] = match_points;
                    teamD_number_of_wins +=1; //increment team D number of wins
                }
                else if (outcome == 'D')
                {
                    match_points = 1 * 2;
                    score[i][j] = match_points;
                    teamD_number_of_draws +=1; //increment team D number of draws
                }
                else if (outcome == 'L'){

                    match_points = 1 * 0;
                    score[i][j] = match_points;
                    teamD_number_of_losses +=1; //increment team D number of losses
                }
//	 		    condition to check if the input is either W, D or L
                 else{
                printf("\n\tKindly Enter 'W' for a Win, 'D' if both teams Drew, 'L' if the first team Lost\n");
                printf("\n\tReturning to menu...");
                sleep(2);
	 			collect_game_results();

                }
                printf("\n\t Enter the number of goals scored by Team D:");
	 	        scanf("%d", &number_of_goals_by_teamD_vs_C);
        }
        else
        {
            printf("Limit Reached");
            printf("\n\tReturning to menu...");
            sleep(1);
	 		collect_game_results();

        }  
    }
}
//Calculate points for each team
total_points_teamA = score[0][0] + score[0][1] + score[0][2];
total_points_teamB = score[1][0] + score[1][1] + score[1][2];
total_points_teamC = score[2][0] + score[2][1] + score[2][2];
total_points_teamD = score[3][0] + score[3][1] + score[3][2];

//calculate the total number of goals for each team
total_goals_by_A = number_of_goals_by_teamA_vs_B + number_of_goals_by_teamA_vs_C + number_of_goals_by_teamA_vs_D;
total_goals_by_B = number_of_goals_by_teamB_vs_A + number_of_goals_by_teamB_vs_C + number_of_goals_by_teamB_vs_D;
total_goals_by_C = number_of_goals_by_teamC_vs_A + number_of_goals_by_teamC_vs_B + number_of_goals_by_teamC_vs_D;
total_goals_by_D = number_of_goals_by_teamD_vs_A + number_of_goals_by_teamD_vs_B + number_of_goals_by_teamD_vs_C;

//writing all the match statistics to the score.dat file

fprintf(filepointer, "A Report on the Football Stats\n");
fprintf(filepointer, "The following teams registered for the league:\n%s\t%s\t%s\t%s", teamA, teamB, teamC, teamD);
fprintf(filepointer, "\n Stats of %s: Total Points:%d, \t Total goals scored:%d, \t No. of Wins: %d, \t No. of draws: %d, \t No. of losses: %d\n", teamA, total_points_teamA, total_goals_by_A, teamA_number_of_wins, teamA_number_of_draws,teamA_number_of_losses);
fprintf(filepointer,"\n Stats of %s: Total Points:%d, \t Total goals scored:%d, \t No. of Wins: %d, \t No. of draws: %d, \t No. of losses: %d\n", teamB, total_points_teamB, total_goals_by_B, teamB_number_of_wins, teamB_number_of_draws, teamB_number_of_losses);
fprintf(filepointer, "\n Stats of %s: Total Points:%d, \t Total goals scored:%d, \t No. of Wins: %d, \t No. of draws: %d, \t No. of losses: %d\n", teamC, total_points_teamC, total_goals_by_C, teamC_number_of_wins, teamC_number_of_draws, teamC_number_of_losses);
fprintf(filepointer, "\n Stats of %s: Total Points:%d, \t Total goals scored:%d, \t No. of Wins: %d, \t No. of draws: %d, \t No. of losses: %d\n", teamD, total_points_teamD, total_goals_by_D, teamD_number_of_wins, teamD_number_of_draws, teamD_number_of_losses);

fclose(filepointer);

collect_game_results_menu();
}

void view_results(void){

    printf("\n\t||=====================================================================|| \n");
    printf("\n\t||=================== Results of All FootBall Matches  ================|| \n");
    printf("\n\t||=====================================================================|| \n");
    printf("\n\t\t\t\t -- Final Table Overview --\n");
    printf("\n\t\t\t Results posted on score.dat file, Check the folder where you saved the soccer.c file");
    

}

