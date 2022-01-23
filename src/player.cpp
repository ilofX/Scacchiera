//
//Created by Nicolo' Tesser on 22/12/2021
//

#include <iostream>
#include "player.h"

player::player(char n, board& t) : color{n},scacchiera{t} {
	if(n == 'b' || n == 'w' || n == 'B' || n == 'W'){
		color = n;
	}else{
		throw InvalidColorException();
	}
}

/// <summary>
/// used to get the player color or team
/// </summary>
char player::get_color(){
	return color;
}


