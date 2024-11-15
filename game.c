#include "include/game.h"

static int width;
static int height;
static entity_t player = {1, '@', 0, 0};
static const entity_t coin = {2, '$', 0, 0};
static const entity_t bomb = {3, 'o', 0, 0};
static bool game_over = false;
static int score = 0;
static char *map;

void setup(int w, int h)
{
    width = w + 1;
    height = h + 1;
    map = (char *)calloc(width * height, sizeof(char));
    srand((unsigned)time(NULL));
    int num_bombs = (height * width) / 10;
    int num_coins = num_bombs / 5;
    mvaddstr(height, 0, "Your Score: 0");

    pos_t rndp; // random point
    int i;
    for(i = 0; i < num_bombs; i++)
    {
        do
        {
            rndp.x = rand() % width;
            rndp.y = rand() % height;
        }
        while(map[rndp.y * width + rndp.x] != 0); // if not empty

        map[rndp.y * width + rndp.x] = bomb.c; // place the bomb kinda
        e_print_cc(bomb.c, rndp.x, rndp.y, bomb.color);
    }

    for(i = 0; i < num_coins; i++)
    {
        do
        {
            rndp.x = rand() % width;
            rndp.y = rand() % height;
        }
        while(map[rndp.y * width + rndp.x] != 0);

        map[rndp.y * width + rndp.x] = coin.c;
        e_print_cc(coin.c, rndp.x, rndp.y, coin.color);
    }

    do
    {
        rndp.x = rand() % width;
        rndp.y = rand() % height;
    }
    while(map[rndp.y * width + rndp.x] != 0);

    player.x = rndp.x;
    player.y = rndp.y;
    e_print(player);
    refresh();
}

void play()
{
    do
    {
        move_ent();
        refresh();
    }
    while(!game_over);

    free(map);
    mvaddstr(height/2, width/2-6, "You've lost!");
}

void move_ent()
{
    switch(getch())
    {
        case KEY_RIGHT:
            if (can_move(player.x + 1, player.y))
            {
                mvaddch(player.y, player.x, ' ');
                player.x++;
                e_print(player);
                check_collision();
            }
            break;
        case KEY_LEFT:
            if (can_move(player.x - 1, player.y))
            {
                mvaddch(player.y, player.x, ' ');
                player.x--;
                e_print(player);
                check_collision();
            }
            break;
        case KEY_UP:
            if (can_move(player.x, player.y - 1))
            {
                mvaddch(player.y, player.x, ' ');
                player.y--; // board is upside down
                e_print(player);
                check_collision();
            }
            break;
        case KEY_DOWN:
            if (can_move(player.x, player.y + 1))
            {
                mvaddch(player.y, player.x, ' ');
                player.y++;
                e_print(player);
                check_collision();
            }
            break;
        
    }
}

bool can_move(int x, int y)
{
    return x >= 0 && y >= 0 && x < width && y < height;
}

void update_score()
{
    score++;
    char *score_str;
    score_str = itoa(score, 10);
    mvaddstr(height, 12, score_str);
}

void check_collision()
{
    if (map[player.y * width + player.x] == coin.c)
    {
        map[player.y * width + player.x] = ' ';
        update_score();
    }
    else if (map[player.y * width + player.x] == bomb.c)
    {
        game_over = true;
    }
}
