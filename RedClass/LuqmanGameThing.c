//Battle Simulator log-in.
//Purpose of this assignment/warmup is :
//A user is created with a struct and has the following variables :
//users name,the users age, the users amount of wins/loses and the amount of games the user has played.
//At the beginning of the program, the user has the option to choose their profile.
//Once selected, the user has the choice to either view their stats or play a match.
//Selections of what the user chooses will be coded with an enum including switch and case.
//at the end of a match( a match will have 4 rounds) the Winner will be displayed and an option to play again
//will appear.
//If yes, play again
//if not,  ask the user if they would like to quit or back to main menu.
//stats and scores should be updated all the time.
//How the actual gamew works:
//all you do is generate a random number for the two user, whover has the greater number wins.




bool buttonCheck(TNxtButtons button)
{
	if(button == nNxtButtonPressed)
	{
		return true;
	}
	return false;
}
void buttonUnpressed(TNxtButtons button)
{
	while(buttonCheck(button))
	{
	}
}
struct Player
{
	string name;
	int age;
	int wins;
	int loses;
	int gamesPlayed;

}
struct Curser
{
	int x;
	int y;
	int size;

}

struct cardNumber
{
	int x;
	int y;
	int cardValue;
}
struct DrawCard
{
	int x;
	int y;
	int width;
	int height;
}
struct card
{
	DrawCard draw;
	cardNumber cardNumber;
};

enum inGame
{
	gameOver,
	playGame,
	Draw,
	checkCard,
};
enum Menus
{
	MenuSelect,
	ViewStats,
	Play,
	ChoosingPlayers,
};
task main()
{
	card playerCard;
	playerCard.draw.x = 45;
	playerCard.draw.y = 10;
	playerCard.draw.width = 14;
	playerCard.draw.height = 20;
	playerCard.cardNumber.x = 47;
	int cardx= playerCard.cardNumber.x;
	playerCard.cardNumber.y = 20;
	int cardy=playerCard.cardNumber.y;
	int cardValue = random(20);
	playerCard.cardNumber.cardValue = cardValue;

	card compCard;
	compCard.draw.x = 45;
	compCard.draw.y = 40;
	compCard.draw.width = 14;
	compCard.draw.height = 20;
	compCard.cardNumber.x = 47;
	compCard.cardNumber.y  = 54;
	compCard.cardNumber.cardValue = random(20);

	Player players[3];
	players[0].name = "Luqman";
	players[0].age = 25;
	players[0].wins = 10;
	players[0].loses = 0;
	players[0].gamesPlayed = 10;

	players[1].name = "Hainam";
	players[1].age = 25;
	players[1].wins = 25;
	players[1].loses = 10;
	players[1].gamesPlayed = 35;

	players[2].name = "Kendrick";
	players[2].age = 12;
	players[2].wins = 19;
	players[2].loses = 8;
	players[2].gamesPlayed = 27;

	Curser menuSelector;
	int xCurserPosition = 20;
	int yCurserPosition = 45;
	int sizeOfCurser = 5;
	int curserPosition = 0;
	bool mainGame = true;
	bool menuSelect = true;

	int  playerChoice = 0;
	int chosenPlayer =0;

	bool inGame = true;
	bool chosePlayer = false;
	//creating player scoreCharts
	int userScore[5];
	int computerScore[5];
	//the card the user is holding in hand


	while(mainGame)
	{
		eraseDisplay();

		string playerNames[3];
		(Menus)curserPosition =MenuSelect;
		for(int i = 0; i < 3; i++)
		{
			playerNames[i] = players[i].name;

		}
		menuSelector.x = xCurserPosition;
		menuSelector.y = yCurserPosition;
		menuSelector.size = sizeOfCurser;
		switch((Menus)curserPosition)
		{eraseDisplay();
		/*case*/case MenuSelect://case that controls menu selection
			if(nNxtButtonPressed == kEnterButton)
			{	curserPosition = 1;
				eraseDisplay();
				nxtDisplayCenteredTextLine(curserPosition, "ViewStats");
			}
			if(nNxtButtonPressed == kExitButton)
			{curserPosition=2;
				eraseDisplay();
				nxtDisplayCenteredTextLine(1, "Play");
			}
			//choosing 1 of the two options
			if(nNxtButtonPressed == kRightButton)
			{
				buttonUnpressed(kRightButton);
				menuSelector.x = 7;
				playerChoice = curserPosition;
				(Menus)curserPosition = ChoosingPlayers;
				break;
			}//----end of menuselect case
		/*case*/case ChoosingPlayers://case that lets you choose your profile
			for(int i=0;i < 3;i++)	//displaying players names/profile
			{
				nxtDisplayCenteredTextLine(i,"%s",players[i].name);
				nxtDisplayCenteredTextLine(5,"Select profile");
			}
			eraseEllipse(menuSelector.x,menuSelector.y, menuSelector.x + menuSelector.size,menuSelector.y + menuSelector.size);
			//erasing only the curser to prevent from the whole screen from disappearing and so the names on the scren dont flicker.^
			if(buttonCheck(kEnterButton) && curserPosition > 0)
			{
				buttonUnpressed(kEnterButton);
				curserPosition -= 1;
				menuSelector.y +=8;
			}
			else if(buttonCheck(kExitButton) &&curserPosition < 2)
			{
				buttonUnpressed(kExitButton);
				curserPosition += 1;
				menuSelector.y -=8;
			}
			else if(buttonCheck(kRightButton))
			{
				buttonUnpressed(kRightButton);
				chosenPlayer = curserPosition;
				//determines wether to go into  Play menu or into ViewStats menu
				if((Menus)playerChoice == ViewStats)
				{
					(Menus)curserPosition = ViewStats;
				}
				else
				{
					(Menus)curserPosition = Play;
				}
				eraseDisplay();
				break;
			}
			drawEllipse(menuSelector.x,menuSelector.y,menuSelector.x + menuSelector.size,menuSelector.y + menuSelector.size);
			delay(1);
			//end of choosingPlayers case
		/*case*/case ViewStats:

			nxtDisplayTextLine(0,"name: %s", players[chosenPlayer].name);
			nxtDisplayTextLine(1,"age: %i", players[chosenPlayer].age);
			nxtDisplayTextLine(2,"wins:%i", players[chosenPlayer].wins);
			nxtDisplayTextLine(3,"loses:%i", players[chosenPlayer].loses);
			nxtDisplayTextLine(4,"games played:%i ", players[chosenPlayer].gamesPlayed);
			nxtDisplayTextLine(6,"<- Main Menu");


			if(buttonCheck(kLeftButton))//back to menu
			{
				buttonUnpressed(kLeftButton);
				(Menus)curserPosition = MenuSelect;
				break;
			}
		/*case*/case Play:
			if(chosePlayer == false)
			{
				(Menus)curserPosition = ChoosingPlayers;
				chosePlayer = true;
			}
			else
			{
				inGame = playGame;
				switch(inGame)//seperate switch for playing the game (not the same as the main switch, switching between menus
				{
				/*case*/case playGame:

					nxtFillRect(playerCard.draw.x,playerCard.draw.y,playerCard.draw.x + playerCard.draw.width,playerCard.draw.y + playerCard.draw.height);
					displayStringAt(cardx,cardy,"%i",cardValue );
					displayStringAt(0,7,"%s",players[chosenPlayer].name);
					nxtFillRect(compCard.draw.x,compCard.draw.y,compCard.draw.x + compCard.draw.width, compCard.draw.y + compCard.draw.height);
					displayStringAt(compCard.cardNumber.x,compCard.cardNumber.y, "%i", compCard.cardNumber.cardValue);
					displayStringAt(0,57,"Computer");
					displayStringAt(0,30,"press up to draw");
					if(nNxtButtonPressed == kEnterButton)
					{
					nxtDrawRect(playerCard.draw.x,playerCard.draw.y,playerCard.draw.x + playerCard.draw.width,playerCard.draw.y + playerCard.draw.height);
					displayStringAt(cardx,cardy,"%i",cardValue );
					displayStringAt(0,7,"%s",players[chosenPlayer].name);
					nxtDrawRect(compCard.draw.x,compCard.draw.y,compCard.draw.x + compCard.draw.width, compCard.draw.y + compCard.draw.height);
					displayStringAt(compCard.cardNumber.x,compCard.cardNumber.y, "%i", compCard.cardNumber.cardValue);
					displayStringAt(0,57,"Computer");
					}
       /*case*/case Draw:
        bool drawCardFam = true;
        if(drawCardFam)
        {
          eraseRect(playerCard.draw.x,playerCard.draw.y,playerCard.draw.x + playerCard.draw.width,playerCard.draw.y + playerCard.draw.height);
        	if((playerCard.y + playercard.Height)/2 > 0 )
        	{
        		playerCard.Y -=1;
        	}
        	else
        	{
        		play()
        	}
        	nxtFillRect(playerCard.draw.x,playerCard.draw.y,playerCard.draw.x + playerCard.draw.width,playerCard.draw.y + playerCard.draw.height);

        	player
        }
       	nxtDrawRect(playerCard.draw.x,playerCard.draw.y,playerCard.draw.x + playerCard.draw.width,playerCard.draw.y + playerCard.draw.height);
        displayStringAt(cardx,cardy,"%i", cardValue);
        nxtDrawRect(compCard.draw.x,compCard.draw.y,compCard.draw.x + compCard.draw.width, compCard.draw.y + compCard.draw.height);
				}//end of inGame Switch

			}//end of else

					}//end of MainMenu switch and case



					}//end of mainGame

					}//end of task main
