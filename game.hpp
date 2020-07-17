#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAXLENGTH 60

void initGrid(int x, int y);
void drawGrid();
void unitForGrid(int x, int y);
void drawSnake();
void drawFood();
void random(int&, int&); 

#endif
