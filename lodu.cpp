#include<iostream>
using namespace std;
#include<windows.h>
#include<conio.h>
class token		//costamize data type
{
public:
	int x,y;
	token()
	{
		x = 0;
		y = 0;
	}
};
token token_add[4][4];		//decalear a 2D array of costamize data type.
token die[4];		//it contain the address of die for all players.
token temp_token[4][4];		//it store the default address of token in thier house. 
bool flag = false,sound = true;		//this variable use for the movement of token.
char name[4][25] = {"player1","player2","player3","player4"},charac[4] = {254,232,234,224},token_value[4] = { 254,232,234,224};
int player,die_value,player_turn = 0,temp_die;//player turn show that which player move thier thier token.
//player variable ask the user for the player. die_value store the value that come for the rotation of fie.
int token_mover;	//it contain the token number like 1,2,3 & 4.
int freq = 200;//set the frequancy of the sound.I set initial feq of 200
int p1_end_in_y = 26,p2_end_in_x = 25,p3_end_in_x = 25,p4_end_in_y = 22;//it show the token seperate in the end.
int winner[4] = {};
void gotoxy(int x,int y)//make the function to move the corser on the screen.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void shape()//make the shape of lodu.
{
	for(int i = 1 + 5;i<=50-11;i++)		//make vartcal lines
	{
		gotoxy(5,4+i);
		cout<<(char)178;
	}
	for(int i = 1 + 5;i<=50-11;i++)		//make vartcal lines
	{
		gotoxy(23,4+i);
		cout<<(char)178;
	}
	for(int i = 1 + 5;i<=50-11;i++)		//make vartcal lines
	{
		gotoxy(32,4+i);
		cout<<(char)178;
	}
	for(int i = 1 + 5;i<=50-11;i++)		//make vartcal lines
	{
		gotoxy(50,4+i);
		cout<<(char)178;
	}
	gotoxy(5,5+5);		//make horizontal lines
	for(int i = 0;i<=45;i++)
		cout<<(char)178;
	gotoxy(5,23);		//make horizontal lines
	for(int i = 0;i<=45;i++)
		cout<<(char)178;
	gotoxy(5,32);		//make horizontal lines
	for(int i = 0;i<=45;i++)
		cout<<(char)178;
	for(int i = 5+5;i<=23;i = i + 1)		//make vartcal lines
	{
		gotoxy(26,i);
		cout<<(char)178;
		gotoxy(29,i);
		cout<<(char)178;
	}
	for(int i = 32;i<=50 - 7;i = i + 1)		//make vartcal lines
	{
		gotoxy(26,i);
		cout<<(char)178;
		gotoxy(29,i);
		cout<<(char)178;
	}
	for(int i = 5+5;i<=23;i = i + 2)		//make horizontal lines
	{
		for(int j = 23;j<=32;j++)
		{
			gotoxy(j,i);
			cout<<(char)178;
		}
		
	}
	for(int i = 32;i<=50 - 7;i = i + 2)		//make horizontal lines
	{
		for(int j = 23;j<=32;j++)
		{
			gotoxy(j,i);
			cout<<(char)178;
		}
	}
	gotoxy(5,44);
	for(int i = 1;i<=46;i++)
		cout<<(char)178;
	for(int i = 1;i<= 45;i++)		//make horizontal lines
	{
		gotoxy(4+i,26);
		if(i <= 19 || i >= 29)
			cout<<(char)178;
		gotoxy(4+i,29);
		if(i <= 19 || i >= 29)
			cout<<(char)178;
	}
	for(int i = 23;i<= 32;i++)		//make vartical lines
	{
		gotoxy(8,i);
		cout<<(char)178;
		gotoxy(11,i);
		cout<<(char)178;
		gotoxy(14,i);
		cout<<(char)178;
		gotoxy(17,i);
		cout<<(char)178;
		gotoxy(20,i);
		cout<<(char)178;
		gotoxy(23,i);
		cout<<(char)178;
		gotoxy(32,i);
		cout<<(char)178;
		gotoxy(35,i);
		cout<<(char)178;
		gotoxy(38,i);
		cout<<(char)178;
		gotoxy(41,i);
		cout<<(char)178;
		gotoxy(44,i);
		cout<<(char)178;
		gotoxy(47,i);
		cout<<(char)178;
	}
	//from here we start to make shalter where the player will save from other players
	gotoxy(9,24);
		cout<<(char)43<<(char)43;
	gotoxy(9,25);
		cout<<(char)43<<(char)43;
	gotoxy(30,13 );
		cout<<(char)43<<(char)43;
	gotoxy(24,15);
		cout<<(char)43<<(char)43;
	gotoxy(42,24);
		cout<<(char)43<<(char)43;
	gotoxy(42,25 );
		cout<<(char)43<<(char)43;
	gotoxy(45,30);
		cout<<(char)43<<(char)43;
	gotoxy(45,31);
		cout<<(char)43<<(char)43;
	gotoxy(12,30);
		cout<<(char)43<<(char)43;
	gotoxy(12,31);
		cout<<(char)43<<(char)43;
	gotoxy(24,41);
		cout<<(char)43<<(char)43;
	gotoxy(30,39);
		cout<<(char)43<<(char)43;
	for(int i = 13;i<=22;i += 2)
	{
		gotoxy(27,i);
		cout<<(char)43<<(char)43;
	}
	for(int i = 33;i<=42;i += 2)
	{
		gotoxy(27,i);
		cout<<(char)43<<(char)43;
	}
	for(int i = 9;i<=22;i += 3)
	{
		gotoxy(i,27);
		cout<<(char)43<<(char)43;
		gotoxy(i,28);
		cout<<(char)43<<(char)43;
	}
	for(int i = 33;i<=47;i += 3)
	{
		gotoxy(i,27);
		cout<<(char)43<<(char)43;
		gotoxy(i,28);
		cout<<(char)43<<(char)43;
	}
	if(winner[0] == 3)
	{
		gotoxy(10,15);
		cout<<"Winner";
	}
	if(winner[1] == 3)
	{
		gotoxy(35,15);
		cout<<"Winner";
	}
	if(winner[2] == 3)
	{
		gotoxy(10,39);
		cout<<"Winner";
	}
	if(winner[3] == 3)
	{
		gotoxy(35,39);
		cout<<"Winner";
	}
	//from here we end to make shalter where the player will save from other players
	//from here we start to make blocks where the dice will rotate.
	gotoxy(6,12);
	cout<<(char)178<<(char)178<<(char)178;
	gotoxy(8,11);
	cout<<(char)178;
	gotoxy(47,12);
	cout<<(char)178<<(char)178<<(char)178;
	gotoxy(47,11);
	cout<<(char)178;
	gotoxy(6,42);
	cout<<(char)178<<(char)178<<(char)178;
	gotoxy(8,43);
	cout<<(char)178;
	gotoxy(47,42);
	cout<<(char)178<<(char)178<<(char)178;
	gotoxy(47,43);
	cout<<(char)178;
	//here the block's code is end..
	{//display token 
		for(int y = 0;y<player;y++)
		{
			for(int x = 0;x<4;x++)
			{
				gotoxy(token_add[y][x].x,token_add[y][x].y);
				cout<<token_value[y];
			}
		}
	}
	{//display the value of die
	int temp = 0;
		//for(int i = 0;i<player;i++)
		{
			gotoxy(die[player_turn].x,die[player_turn].y);
			cout<<die_value;
		}
	}
	{//from here we give some information about the game....
		gotoxy(55,10);
		cout<<"Information:";
		gotoxy(55,11);
		cout<<"-------------";
		gotoxy(55,13);
		cout<<"1) we make a small block in all sections,";
		gotoxy(55+3,14);
		cout<<"which are able to rotate the dice.";
		gotoxy(55,15);
		cout<<"2) we use '+' sign in the game that save the player";
		gotoxy(58,16);
		cout<<"from other player.";
		gotoxy(55,17);
		cout<<"3) we make the block around the token,";
		gotoxy(58,18);
		cout<<"when you press 'O' butten then the player will move.";
		gotoxy(58,19);
		cout<<"you may move the block in those player that you want to move.";
		gotoxy(55,20);
		cout<<"4) you may choce the character,";
		gotoxy(58,21);
		cout<<"that you want to use as a player";
		gotoxy(55,22);
		cout<<"5) you may change the name of the player,";
		gotoxy(58,23);
		cout<<" like you change 'Michael' to 'Liu' etc";
		gotoxy(55,24);
		cout<<"6) we give 500 point to the winner";
		gotoxy(55,29);
		cout<<"Controls:";
		gotoxy(55,30);
		cout<<"----------";
		gotoxy(55,31);
		cout<<"Use the following keys:";
		gotoxy(55,32);
		cout<<"W - up\tS - down";
		gotoxy(55,33);
		cout<<"A - left\tD - right";
		gotoxy(55,34);
		cout<<"O - ok\tQ - exit";
		gotoxy(55,35);
		cout<<"it is importent to know that O key is use for ";
		gotoxy(55,36);
		cout<<"1)select the token";
		gotoxy(55,37);
		cout<<"2)rotate the die";
		gotoxy(55,38);
		cout<<"3)select the token to move";
	}
	{//here we display the name of players
		if(player <= 2)
		{
			gotoxy(6,9);
			cout<<name[0];		//display player1
			gotoxy(41,9);
			cout<<name[1];		//display plyer2	
		}
		if(player == 3)
		{
			gotoxy(6,9);
			cout<<name[0];		//display player1
			gotoxy(41,9);
			cout<<name[1];		//display plyer2
			gotoxy(6,45);
			cout<<name[2];		//display player3	
		}
		if(player == 4)
		{
			gotoxy(6,9);
			cout<<name[0];		//display player1
			gotoxy(41,9);
			cout<<name[1];		//display plyer2
			gotoxy(6,45);
			cout<<name[2];		//display player3
			gotoxy(41,45);
			cout<<name[3];		//display player4	
		}
	}//end of the block that display the player name. 
//	cout<<(char)219.......178-block;
}
void character()//make the character for the token value.
{
	int token_a[3][4];
	token_a[0][0] = 254;		//assign values to pinter array
	token_a[0][1] = 232;
	token_a[0][2] = 234;
	token_a[0][3] = 224;
	token_a[1][0] = 248;
	token_a[1][1] = 235;
	token_a[1][2] = 237;
	token_a[1][3] = 225;
	token_a[2][0] = 236;
	token_a[2][1] = 231;
	token_a[2][2] = 227;
	token_a[2][3] = 233;
	int block_move_in_x = 10,block_move_in_y = 14;
	char ch;
	int n = 1;
	do			//this loop will exectute maximum 4 time
	{
		do
		{		//this loop help to select the token for all the players
			gotoxy(10,13);
			cout<<"move the block to select charcter as a token for player  "<<name[n-1];
			{//it make block in which character will display
					for(int x = 10;x<=26;x++)
				{//it make horizontal lines for the block in which character will display.
					gotoxy(x,14);
					cout<<(char)178;
					gotoxy(x,16);
					cout<<(char)178;
					gotoxy(x,18);
					cout<<(char)178;
				}
				for(int y = 14;y<=18;y++)
				{//it make vartical lines for the block in which character will display.
					gotoxy(10,y);
					cout<<(char)178;
					gotoxy(14,y);
					cout<<(char)178;
					gotoxy(18,y);
					cout<<(char)178;
					gotoxy(22,y);
					cout<<(char)178;
					gotoxy(26,y);
					cout<<(char)178;
				}
			}
			{//it make character in the block
				int diff_in_y = 15;
				for(int y = 0;y<2;y++)
				{
					int diff_in_x = 12;
					for(int x = 0;x<4;x++)
					{
						gotoxy(x + diff_in_x,y + diff_in_y);
						diff_in_x += 3;
						cout<<(char)token_a[y][x];
					}
					diff_in_y += 1;
				}
			}
	 		{//it make a block around the character or token
	 			gotoxy(block_move_in_x,block_move_in_y+1);
	 			cout<<"|";
	 			gotoxy(block_move_in_x + 4,block_move_in_y + 1);
	 			cout<<"|";
	 			gotoxy(block_move_in_x+1,block_move_in_y);
	 			cout<<"___";
			}
			ch = getche();
			system("cls");
			if(ch == 'w' || ch == 'W')
			{
				if(block_move_in_y - 2 > 13)
					block_move_in_y -= 2;
			}
			else if(ch == 'a' || ch == 'A')
			{
				if(block_move_in_x - 4 >= 10)
					block_move_in_x -= 4;
			}
			else if(ch == 'd' || ch == 'D')
			{
				if(block_move_in_x + 4 <  26)
					block_move_in_x += 4;
			}
			else if(ch == 's' || ch == 'S')
			{
				if(block_move_in_y + 2 < 18)
					block_move_in_y += 2;
			}
			else if(ch == 'o' || ch == 'O')
			{
				int y;
				if(block_move_in_y == 14)
				{
					token_value[n-1] = token_a[0][(block_move_in_x - 10)/4];		//the formula [(block_move_in_x - 10)/4] make the value
					for(int x = 0;x<3;x++)		//swip the value of token			//0,1,2,3 from 10,14,18,22. the 0,1,2,3 is the idex value of token_a.
					{
						for(y = (block_move_in_x - 10)/4;y<4;y++)
						{
							token_a[x][y] = token_a[x][y+1];
						}
						token_a[x][y-1] = token_a[x+1][0];
					}
				}
				else																
					token_value[n-1] = token_a[1][(block_move_in_x - 10)/4];
				for(int x = 1;x<3;x++)		//swip the value of token
				{
					for(y = (block_move_in_x - 10)/4;y<4;y++)
					{
						token_a[x][y] = token_a[x][y+1];
					}
					token_a[x][y-1] = token_a[x+1][0];
				}
				n++;
			}
		}while(ch != 'o' && ch != 'O');
	}while(n <= player);
}bool rotation_checker = false;
void token_killer()	//it kill the token when other player  move thier token on the player of other player .
{
	for(int row = 0;row < player;row++)
	{
		if(row != player_turn)
		{
			for(int col = 0;col<4;col++)
			{
				if((token_add[player_turn][token_mover].y == token_add[row][col].y) && (token_add[player_turn][token_mover].x == token_add[row][col].x))
				{//this condition check all the address of the tokens of other players
					if(!(token_add[player_turn][token_mover].x == 10 && token_add[player_turn][token_mover].y == 24))
					{
						if(!(token_add[player_turn][token_mover].x == 24 && token_add[player_turn][token_mover].y == 15))
						{
							if(!(token_add[player_turn][token_mover].x == 30 && token_add[player_turn][token_mover].y == 13))
							{
								if(!(token_add[player_turn][token_mover].x == 42 && token_add[player_turn][token_mover].y == 24))
								{
									if(!(token_add[player_turn][token_mover].x == 45 && token_add[player_turn][token_mover].y == 30))
									{
										if(!(token_add[player_turn][token_mover].x == 30 && token_add[player_turn][token_mover].y == 39))
										{
											if(!(token_add[player_turn][token_mover].x == 24 && token_add[player_turn][token_mover].y == 41))
											{
												if(!(token_add[player_turn][token_mover].x == 12 && token_add[player_turn][token_mover].y == 30))
												{
													token_add[row][col].x = temp_token[row][col].x;
													token_add[row][col].y = temp_token[row][col].y;
													Beep(freq,500);
												}
											}
										}
									}
								}
							}
						}
					}
				}	
			}
		}
	}
}
void die_6()//it move the token from thire house to the plateform where it will move.
{
		if((token_add[player_turn][token_mover].x == 8 && token_add[player_turn][token_mover].y == 16) || (token_add[player_turn][token_mover].x == 14 && token_add[player_turn][token_mover].y == 16))
		{//this condition check the address of player's 1 token
			token_add[player_turn][token_mover].x = 10;
			token_add[player_turn][token_mover].y = 24;
		}
		else if((token_add[player_turn][token_mover].x == 8 && token_add[player_turn][token_mover].y == 18) || (token_add[player_turn][token_mover].x == 14 && token_add[player_turn][token_mover].y == 18))
		{//this condition check the address of player's 1 token
			token_add[player_turn][token_mover].x = 10;
			token_add[player_turn][token_mover].y = 24;
		}
		else if((token_add[player_turn][token_mover].x == 41 && token_add[player_turn][token_mover].y == 16) || (token_add[player_turn][token_mover].x == 47 && token_add[player_turn][token_mover].y == 16))
		{//this condition check the address of player's 2 token
			token_add[player_turn][token_mover].x = 30;
			token_add[player_turn][token_mover].y = 13;
		}
		else if((token_add[player_turn][token_mover].x == 41 && token_add[player_turn][token_mover].y == 18) || (token_add[player_turn][token_mover].x == 47 && token_add[player_turn][token_mover].y == 18))
		{//this condition check the address of player's 2 token
			token_add[player_turn][token_mover].x = 30;
			token_add[player_turn][token_mover].y = 13;
		}
		else if((token_add[player_turn][token_mover].x == 8 && token_add[player_turn][token_mover].y == 35) || (token_add[player_turn][token_mover].x == 14 && token_add[player_turn][token_mover].y == 35))
		{//this condition check the address of player's 3 token
			token_add[player_turn][token_mover].x = 24;
			token_add[player_turn][token_mover].y = 41;
		}
		else if((token_add[player_turn][token_mover].x == 8 && token_add[player_turn][token_mover].y == 39) || (token_add[player_turn][token_mover].x == 14 && token_add[player_turn][token_mover].y == 39))
		{//this condition check the address of player's 3 token
			token_add[player_turn][token_mover].x = 24;
			token_add[player_turn][token_mover].y = 41;
		}
		else if((token_add[player_turn][token_mover].x == 41 && token_add[player_turn][token_mover].y == 35) || (token_add[player_turn][token_mover].x == 47 || token_add[player_turn][token_mover].y == 35))
		{//this condition check the address of player's 4 token
			token_add[player_turn][token_mover].x = 45;
			token_add[player_turn][token_mover].y = 30;
		}
		else if((token_add[player_turn][token_mover].x == 41 && token_add[player_turn][token_mover].y == 39) || (token_add[player_turn][token_mover].x == 47 || token_add[player_turn][token_mover].y == 39))
		{//this condition check the address of player's 4 token
			token_add[player_turn][token_mover].x = 45;
			token_add[player_turn][token_mover].y = 30;
		}
		else
			flag = true;
}
void token_move()//it move the token in the plateform.
{
	if(token_add[player_turn][token_mover].x == 27 && token_add[player_turn][token_mover].y == 21)		//it move teh token at tha last block for the player2 
	{
		if(sound)
			Beep(freq,250);
		token_add[player_turn][token_mover].y = 24; 
	}
	if(token_add[player_turn][token_mover].y == 24 && token_add[player_turn][token_mover].x == 22)//it checl the corner of the player's home
	{
		if(sound)
			Beep(freq,250);
			token_add[player_turn][token_mover].x = 24;
			token_add[player_turn][token_mover].y = 21;
	}
	else if(token_add[player_turn][token_mover].y == 21 && token_add[player_turn][token_mover].x == 30)//it checl the corner of the player's home
	{
		if(sound)
			Beep(freq,250);
			token_add[player_turn][token_mover].x = 33;
			token_add[player_turn][token_mover].y = 24;
	}
	else if(token_add[player_turn][token_mover].y == 30 && token_add[player_turn][token_mover].x == 33)//it checl the corner of the player's home
	{
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].x = 30;
			token_add[player_turn][token_mover].y = 33;
	}
	else if(token_add[player_turn][token_mover].y == 33 && token_add[player_turn][token_mover].x == 24)//it checl the corner of the player's home
	{
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].x = 21;
			token_add[player_turn][token_mover].y = 30;
	}
	else if((token_add[player_turn][token_mover].y == 24 ) && token_add[player_turn][token_mover].x < 22)//following conditions cause to move the token
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x += 3;
	}
	else if(token_add[player_turn][token_mover].y == 27 && (token_add[player_turn][token_mover].x >= 6 && token_add[player_turn][token_mover].x <= 21) && player_turn == 0 )//it move player 1 inside the home
	{//it move the token into house
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].x += 3;
			temp_die--;
	}
	else if(token_add[player_turn][token_mover].x == 27 && (token_add[player_turn][token_mover].y >= 10 && token_add[player_turn][token_mover].y <= 21 - 2) && player_turn == 1)//it mive the player 2 inside the home
	{//it move the token to their house
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].y += 2;
			temp_die--;
	}
	else if(token_add[player_turn][token_mover].x == 27 && (token_add[player_turn][token_mover].y <= 43 && token_add[player_turn][token_mover].y >= 31) && player_turn ==2)//it move the player 3 inside thier house
	{//it move the token to their house
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].y -= 2;
			temp_die--;
	}
	else if(token_add[player_turn][token_mover].y == 27 && (token_add[player_turn][token_mover].x <= 48 && token_add[player_turn][token_mover].x >= 30) && player_turn == 3)//it move the player 4 inside their house
	{//it move the token to their house
			if(sound)
				Beep(freq,250);
			token_add[player_turn][token_mover].x -= 3;
			temp_die--;
	}
	else if(token_add[player_turn][token_mover].x == 27 && token_add[player_turn][token_mover].y == 21)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y == 24;
	}
	else if((token_add[player_turn][token_mover].y <= 24 && token_add[player_turn][token_mover].y >= 12) && token_add[player_turn][token_mover].x == 24)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y -= 2;
	}
	else if(token_add[player_turn][token_mover].y <= 12 && (token_add[player_turn][token_mover].x >= 24 && token_add[player_turn][token_mover].x < 30))
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x += 3;
	}
	else if((token_add[player_turn][token_mover].y >= 10 && token_add[player_turn][token_mover].y <= 21) && token_add[player_turn][token_mover].x == 30)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y += 2;
	}
	else if(token_add[player_turn][token_mover].y == 24 && (token_add[player_turn][token_mover].x >= 33 && token_add[player_turn][token_mover].x < 47))
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x += 3;
	}
	else if((token_add[player_turn][token_mover].y >= 24 && token_add[player_turn][token_mover].y <= 28) && token_add[player_turn][token_mover].x == 48)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y += 3;
	}
	else if(token_add[player_turn][token_mover].y == 30 && (token_add[player_turn][token_mover].x <= 48 && token_add[player_turn][token_mover].x > 33))
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x -= 3;
	}
	else if((token_add[player_turn][token_mover].y <= 41 && token_add[player_turn][token_mover].y >= 33) && token_add[player_turn][token_mover].x == 30)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y += 2;
	}
	else if(token_add[player_turn][token_mover].y == 43 && (token_add[player_turn][token_mover].x >= 24 + 2 && token_add[player_turn][token_mover].x <= 30))
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x -= 3;
	}
	else if((token_add[player_turn][token_mover].y <= 43 && token_add[player_turn][token_mover].y >= 35) && token_add[player_turn][token_mover].x == 24)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y -= 2;
	}
	else if(token_add[player_turn][token_mover].y == 30 && (token_add[player_turn][token_mover].x >= 9 && token_add[player_turn][token_mover].x <= 21))
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x -= 3;
	}
	else if((token_add[player_turn][token_mover].x <= 30 && token_add[player_turn][token_mover].y >= 22) && token_add[player_turn][token_mover].x == 6)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y -= 3;
	}
	//following condition move the token in thier house.
	if(token_add[player_turn][token_mover].y == 24 && token_add[player_turn][token_mover].x == 6)		//it will execute a single time when token is at left side of plateform.
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y = 24;
		token_add[player_turn][token_mover].x += 1;
	}
	else if(token_add[player_turn][token_mover].x == 24 && token_add[player_turn][token_mover].y == 27)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y = p1_end_in_y;
		p1_end_in_y ++;
		winner[0]++;
	}
	else if(token_add[player_turn][token_mover].x == 27 && token_add[player_turn][token_mover].y == 24)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x = p2_end_in_x;
		p2_end_in_x++;
		winner[1]++;
	}
	else if(token_add[player_turn][token_mover].x == 27 && token_add[player_turn][token_mover].y == 31)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].x = p3_end_in_x;
		p3_end_in_x++;
		winner[2]++;
	}
	else if(token_add[player_turn][token_mover].x == 30 && token_add[player_turn][token_mover].y == 27)
	{
			if(sound)
				Beep(freq,250);
		token_add[player_turn][token_mover].y = p4_end_in_y;
		p4_end_in_y ++;
		winner[3]++;
	}
}
void play()//exect game is start from here.
{
	char ch;
	int a = 0;
	do
	{
		system("cls");
		shape();
		ch = getch();
		if(ch == 'o' || ch == 'O')
		{
			
			die_value = rand()%6 + 1;//it prodeuce die value randomly
			do
			{//this loop cause to move the token
				system("cls");
				shape();//following I produce a block around the token
				gotoxy(token_add[player_turn][a].x - 1,token_add[player_turn][a].y);
				cout<<"|";
				gotoxy(token_add[player_turn][a].x + 1,token_add[player_turn][a].y);
				cout<<"|";
				gotoxy(token_add[player_turn][a].x,token_add[player_turn][a].y  - 1);
				cout<<"_";
				ch = getch();
				switch(ch)
				{
					case 'w':	//this cases move the block on the other token of the selected player
					case 'W':
					case 'A':
					case 'a':
					case 'd':
					case 'D':
					case 's':
					case 'S':
						a++;
						if(a > 3)
							a = 0;
						break;
					case 'O':
					case 'o'://the following condition move th token to the outside of the home.
						token_mover = a;
						if(die_value == 6)
						{
							die_6();
						}
						system("cls");
						shape();
						temp_die = die_value;
						if(flag || (die_value < 6))
						{	//this loop exetue when the token is out of their house.
							for(int i = 1;i<=die_value;i++)		//it move the token to the values of die				
							{
								token_move();
								system("cls");
								shape();
								for(int y = 1;y<=99999999;y++);		//it  will show a small dely when token will move.
							}
							flag = false;
						}
						token_killer();
						if(die_value != 6)	//for this condition player can't change untill the die value come from other then 6.
							player_turn++;
						if(player_turn > player - 1)		//when the die's turn reach to max value.
						player_turn = 0;
						break;
				}
				token_mover = 0;
				//die_value = 0;
			}while((ch != 'o' && ch != 'O') && (ch != 'q' && ch != 'Q'));
		}
		system("cls");
	}while(ch != 'q' || ch != 'Q');
	if(ch == 'q' || ch == 'Q')
	{
		gotoxy(10,15);
		cout<<"thanks to play with me.I hope you enjoyed my game.";
	}
}                  
void sub_menu()//it hold the sub manu.
{
	system("cls");
	{//assign values of token address for player1
		token_add[0][0].x = 8;
		token_add[0][0].y = 16;
		token_add[0][1].x = 14;
		token_add[0][1].y = 16;
		token_add[0][2].x = 8;
		token_add[0][2].y = 18;
		token_add[0][3].x = 14;
		token_add[0][3].y = 18;
	}
	{//assign values of token address for player2
		token_add[1][0].x = 41;
		token_add[1][0].y = 16;
		token_add[1][1].x = 47;
		token_add[1][1].y = 16;
		token_add[1][2].x = 41;
		token_add[1][2].y = 18;
		token_add[1][3].x = 47;
		token_add[1][3].y = 18;
	}
	{//assign value of token address for player3
		token_add[2][0].x = 8;
		token_add[2][0].y = 35;
		token_add[2][1].x = 14;
		token_add[2][1].y = 35;
		token_add[2][2].x = 8;
		token_add[2][2].y = 39;
		token_add[2][3].x = 14;
		token_add[2][3].y = 39;
	}
	{//assign value of token address for player4
		token_add[3][0].x = 41;
		token_add[3][0].y = 35;
		token_add[3][1].x = 47;
		token_add[3][1].y = 35;
	 	token_add[3][2].x = 41;
		token_add[3][2].y = 39;
		token_add[3][3].x = 47;
		token_add[3][3].y = 39;
	}
	for(int row = 0;row < 4;row++)		//it assign the values of token_add
	{
		for(int col = 0;col<4;col++)
		{
			temp_token[row][col].x = token_add[row][col].x;
			temp_token[row][col].y = token_add[row][col].y;
		}
	}
	{//assign the addresses of die where the die rotate.
		die[0].x = 7;
		die[0].y = 11;
		die[1].x = 48;
		die[1].y = 11;
		die[2].x = 7;
		die[2].y = 43;
		die[3].x = 48;
		die[3].y = 43; 
	}
	char block;
	token p1;
		//178 character I want to used
	p1.x = 51;
	p1.y = 11;
	do
	{
		
		gotoxy(10,10);
		cout<<"how many player want to play ?(enter 2-4) ";
		gotoxy(51,11);
		for(int i = 51;i<=63;i++)
			cout<<(char)178;
		for(int i = 51;i<= 63;i += 4)
		{
			gotoxy(i,12);
			cout<<(char)178;
		}
		gotoxy(51,13);
		for(int i = 51;i<=63;i++)
			cout<<(char)178;
		gotoxy(53,12);
		cout<<"2";
		gotoxy(57,12);
		cout<<"3";
		gotoxy(61,12);
		cout<<"4";
		//now i make a block.
		gotoxy(p1.x,p1.y);
		cout<<"_____";
		gotoxy(p1.x,p1.y+1);
		cout<<"|";
		gotoxy(p1.x+4,p1.y+1);
		cout<<"|";
		block = getch();
		switch(block)
		{
			case 'd':
			case 'D':
				if(p1.x < 59)
					p1.x += 4;
					break;
			case 'a':
			case 'A':
				if(p1.x > 51)
					p1.x -= 4;
				break;
			case 'o':
			case 'O':
				if(p1.x == 51)
					player = 2;
				else if(p1.x == 55)
					player = 3;
				else
					player = 4;
				break;
		}	
	}while(block != 'o' && block != 'O');
	if(player >= 2 && player <= 4)
	{
		system("cls");
		gotoxy(10,11);
		cout<<"do you want to enter name of players ?(enter y-yes n-no) ";
		char ch;
		ch = getche();
		if(ch == 'y' || ch == 'Y')
		{
			for(int i = 0;i<player;i++)
			{
				system("cls");
				gotoxy(10,12);
				cout<<"enter name of player "<<i+1<<" ";
				gotoxy(33,12);
				cout<<"|";
				gotoxy(33,11);
				for(int i  = 1;i<15;i++)
					cout<<"_";
				gotoxy(47,12);
				cout<<"|";
				gotoxy(34,12);
				for(int i  = 1;i<14;i++)
					cout<<"_";
				gotoxy(34,12);
				int y = 0;
				do
				{
					y++;
					name[i][y - 1] = getche();
				}while(name[i][y - 1] != 13);
			}system("cls");
			character();
			//system("cls");
			play();
		}
		else if(ch == 'q' || ch == 'Q')
		{
			gotoxy(10,15);
			cout<<"thanks to play with me.I hope you enjoyed my game.";
		}
		else
		{
			system("cls");
			character();
			system("cls");
			play();
		}
	}
}
void load()		//this function display a loading message
{
	gotoxy(15,10);
	cout<<"loading...";
	gotoxy(15,11);
	for(int i = 1;i<=10;i++)
	{
		for(int t = 1;t<=100000000;t++);		//this loop make some time differance
		cout<<(char)177;
	}
}
void menu()
{
	char ch = 's';
	token men;
	men.x = 9;	//declear variables for block
	men.y = 14;	//declear variables for block
	do
	{
		system("cls");
		gotoxy(10,9);
		cout<<"Welcome players";
		gotoxy(10,11);
		cout<<"main menu.";
		gotoxy(10,12);
		cout<<"------------";
		gotoxy(10,15);
		cout<<"Start";
		gotoxy(10,17);
		cout<<"Setting";
		gotoxy(10,19);
		cout<<"about";
		gotoxy(men.x,men.y);
		for(int i = 0;i<=8;i++)
			cout<<"_";
		gotoxy(men.x,men.y+1);
		cout<<"|";
		gotoxy(men.x + 8,men.y+1);
		cout<<"|";
		ch  = getch();	//move the block
		switch(ch)
		{
			case 's':
			case 'S':
				if(men.y < 18)
					men.y += 2;
				break;
			case 'W':
			case 'w':
				if(men.y > 14)
					men.y -= 2;
				break;
			case 'o':
			case 'O':
				if(men.y == 14)	//when user want to enter in submenu.
					sub_menu();
				else if(men.y == 16)//when user want to change the settings
				{
					char ch1;
					token add_in_setting;
					add_in_setting.x = 19;
					add_in_setting.y = 13;
					do
					{
						system("cls");
						gotoxy(10,11);
						cout<<"Settings";
						gotoxy(20,12);
						cout<<"sound";
						gotoxy(20,15);
						cout<<"volume";
						gotoxy(20,18);
						cout<<"back";
						gotoxy(add_in_setting.x,add_in_setting.y+1);
						cout<<"|";
						gotoxy(add_in_setting.x,add_in_setting.y);
						for(int i = 1;i<=8;i++)
							cout<<"_";
						gotoxy(add_in_setting.x + 7,add_in_setting.y + 1);
						cout<<"|";
						if(add_in_setting.y == 13 || add_in_setting.y == 16)
						{
							gotoxy(add_in_setting.x +1,add_in_setting.y+1);
							cout<<"<";
							gotoxy(add_in_setting.x + 6,add_in_setting.y +1);
							cout<<">";
						}
						if(add_in_setting.y == 16)
						{
							gotoxy(add_in_setting.x+3,add_in_setting.y+1);
							cout<<freq / 100;
						}
						else if(add_in_setting.y == 13)
						{
							gotoxy(add_in_setting.x+3,add_in_setting.y+1);
							if(sound)
								cout<<"on";
							else
								cout<<"off";
						}
						ch1 = getch();
						switch(ch1)	//switch for menu that held in setting
						{
							case 's':
							case 'S':
								if(add_in_setting.y < 16)
									add_in_setting.y += 3;
								else if(add_in_setting.y == 16)
									add_in_setting.y += 1;
								break;
							case 'w':
							case 'W':
								if(add_in_setting.y == 17)
									add_in_setting.y -= 1;
								else if(add_in_setting.y > 13)
									add_in_setting.y -= 3;
								break;
							case 'd':
							case 'D':
								if(add_in_setting.y == 16 && freq <= 400)
									freq += 100;
								else if(add_in_setting.y == 13)
									sound = !sound;
								break;
							case 'A':
							case 'a':
								if(add_in_setting.y == 16 && freq > 100)
									freq -= 100;
								else if(add_in_setting.y == 13)
									sound = !sound;
								break;
							case 'o':
							case 'O':
								if(add_in_setting.y == 17)
									menu();
						}
					}while(ch1 != 'O' || ch1 != 'o');
				}
				else if(men.y == 18)//when user want to know about the game.
				{
					char block;
					do
					{
						system("cls");
						gotoxy(10,15);
						cout<<"credit:";
						gotoxy(10,16);
						cout<<"lodu team:";
						gotoxy(20,17);
						cout<<"M.Haris(Developer)";
						gotoxy(20,18);
						cout<<"Mushaid";
						gotoxy(20,19);
						cout<<"Saad";
						gotoxy(20,20);
						cout<<"ahsan";
						gotoxy(20,21);
						cout<<"afaq";
						gotoxy(10,22);
						cout<<"version:";
						gotoxy(20,23);
						cout<<"4.6.2-2178-(RLS)-(Production)-armv6(CCFG-177 | PCFG: 100)";
						gotoxy(30,24);
						cout<<"copyright@ 2020 by M.Haris";
						gotoxy(30,25);
						cout<<"All rights reserve";
						gotoxy(50,27);
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						gotoxy(50,28);
						cout<<(char)178;
						gotoxy(55,28);
						cout<<(char)178;
						gotoxy(51,28);
						cout<<"Back";
						gotoxy(50,29);
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						cout<<(char)178;
						block = getch();
						if(block == 'o' || block == 'O')
							menu();
					}while(block != 'o' && block != 'O');
				}
				
		}
		
		
	}while(ch != 'o' && ch != 'O');
}
int main()//values of token and die are assign in main body.
{
	load();
	menu();
	gotoxy(0,45);
}
