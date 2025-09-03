# LEAGUE 3
in this league   we have 1 turn  to get both our agents behind the best cover then shoot the opposing enemy with the least protection from cover.

## Rules
The game is played on  a **grid**
Eacch player ccontrols a team  of **agents.**
Objective 3: Taking cover
![[Pasted image 20250724133053.png]]
our agents can shoot ennnemy agents! in this next league, we willhave to deal with `cover` 

## Cover
Each tile of the **grid** is given to your program through the standard input. For each column of each row we've given  a `tileType` . It can now hoave one of  `three` possible.
- `0` an empty tile.
- `1`a tile containing `low cover`
- `2` a tile containijng `high cover`
Tiles with **cover** are impasssable, and agents will  automaticallly path arounnd them when  a `MOVE` action.

![[Pasted image 20250724133407.png]]

An agent that benefits from a cover will gain damage reduction against enemy shots.
Low covers  provide `50%` protection, and high Covers provide `75%` protection.

> For instance, on  agent within optimal  range and  a soaking power of 24 will only deal 6
> wetness to an ennemy behing  high cover.

To benefit from a cover, the agent must be orthogonally to it, and the enemy shot must come from the opposite side of the cover tile. The cover is ignored if both agents are adjaentj to the cover.  
In the case where multiple covers can  be  considered, only the **highest** cover will count.

![[Pasted image 20250724133741.png]]
![[Pasted image 20250724133750.png]]![[Pasted image 20250724133757.png]]
![[Pasted image 20250724133804.png]]

![[Pasted image 20250724133817.png]]

### Run  & Gun
From this league onwards, we agents  may  perform `both` a`move` and `shoot` action on
the  same turn. Separate both actions by a semicolon and the assigned agent will first perform the  `move` then immediatelly attempt to `shoot` from the new position.
Example: `1; Move 6 3; SHOOT 4`

In  this league, we will have agents on either  side of the screen. They will both be confronted by two enemy agents in range.  They will also be `1 MOVE` away fromtiles  with cover. To beat this league, we  must move both agents behind the highest availablle cover and have them shoot the enemy within range  behind the lowest cover.

> [!SUCCESS]
    > In this league, you will have exactly **1 turn** to get both your agents behind the best of two adjacent tiles behind cover then shoot the opposing enemy with the least protection from cover (of the two closest enemies).

> [!ERROR]
    > Either of our agents moves to the incorrect location or fails to  shoot the  correct foe.
    > the program does not provide a command in the  allocated time or one of the commands is invalid. 
    
    