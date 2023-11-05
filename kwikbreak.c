#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

char *zero_ascii =
    " ### "
    " # # "
    " # # "
    " # # "
    " ### ";

char *one_ascii = 
    " ##  "
    "  #  "
    "  #  "
    "  #  "
    " ### ";

char *two_ascii = 
    " ### "
    "   # "
    " ### "
    " #   "
    " ### ";

char *three_ascii = 
    " ### "
    "   # "
    " ### "
    "   # "
    " ### ";

char *four_ascii = 
    " # # "
    " # # "
    " ### "
    "   # "
    "   # ";

char *five_ascii = 
    " ### "
    " #   "
    " ### "
    "   # "
    " ### ";

char *six_ascii = 
    " ### "
    " #   "
    " ### "
    " # # "
    " ### ";

char *seven_ascii = 
    " ### "
    "   # "
    "   # "
    "   # "
    "   # ";

char *eight_ascii =
    " ### "
    " # # "
    " ### "
    " # # "
    " ### ";

char *nine_ascii =
    " ### "
    " # # "
    " ### "
    "   # "
    "   # ";

char *colon_ascii =
    "  #  "
    "  #  "
    "     "
    "  #  "
    "  #  ";

#define NUM_LENGTH 10

#define LINES 5
#define WIDTH 5

int convert_to_time(int mins){
    int seconds = mins / 60;
    return seconds;
}

int seconds_boundry(int secs){
    if(secs < 0){
        secs = 59;
    }
    return secs;
}

void print_chars(char *ascii_array[NUM_LENGTH], int number_of_chars, int char_index[4]){
    for(int i = 0; i < 4; i++){
        if(char_index[i] > 9){
            assert(0);
        }
    }
    for(int i = 0; i < LINES; i++){
        for(int index = 0; index < number_of_chars; index++){
            if(index == 2){
                for(int j = 0; j < WIDTH; j++){
                    printf("%c", colon_ascii[i * WIDTH + j]);
                }
            }
            for(int j = 0; j < WIDTH; j++){
                printf("%c", ascii_array[char_index[index]][i * WIDTH + j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void print_break(){
    printf(
        "####   #  #  ###  ####  #  #    ###   ####  ####  ####  #  #\n"
        "#  #   #  #   #   #     # #     #  #  #  #  #     #  #  # # \n"
        "#  #   #  #   #   #     ##      ###   ####  ###   ####  ##  \n"
        "#  #   #  #   #   #     # #     #  #  # #   #     #  #  # # \n"
        "#####  ####  ###  ####  #  #    ###   #  #  ####  #  #  #  #\n"
    );
    printf("\n\n\n");
}

void count_down(char *ascii_array[NUM_LENGTH], int time){
    int mins = time;
    int secs = convert_to_time(time);
    while(mins >= 0 || secs >= 0){
        system("clear");
        print_break();
        secs = seconds_boundry(secs);
        char *mins_str = malloc(sizeof(char) * 4);
        char *secs_str = malloc(sizeof(char) * 4);
        sprintf(mins_str, "%02d", mins);
        sprintf(secs_str, "%02d", secs);
        int char_index[4] = {mins_str[0] - '0', mins_str[1] - '0', secs_str[0] - '0', secs_str[1] - '0'};
        print_chars(ascii_array, 4, char_index);
        if(secs == 0){
            mins--;
        }
        secs--;
        sleep(1);
    }
}

int main(int argc, char *argv[]){
    char *filename = argv[0];
    if(argc < 2){
        fprintf(stderr, "usage: %s <time in minutes>\n", filename);
        exit(1);
    }
    int time = atoi(argv[1]);

    char *ascii_array[NUM_LENGTH] = {
        zero_ascii, one_ascii, two_ascii, three_ascii, four_ascii,
        five_ascii, six_ascii, seven_ascii, eight_ascii, nine_ascii
    };
    count_down(ascii_array, time);
    return 0;
}
