#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4


typedef struct{
    float progress;
    int x;
    int y;
    int direction;
    bool is_finished;
    float duration;
}animation;

