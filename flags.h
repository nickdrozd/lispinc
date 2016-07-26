extern int DEBUG;
extern int INFO;
extern int STATS;
extern int TAIL;
extern int LIB;
extern int STEP;

// it would be nice if these didn't need newlines
#define nlchar "\n"

#define _DEBUG ".debug"nlchar
#define _INFO ".info"nlchar
#define _STATS ".stats"nlchar
#define _TAIL ".tail"nlchar
#define _STEP ".step"nlchar

#define _HELP ".help"nlchar
#define _QUIT ".quit"nlchar


/* flag manipulation */
void toggle_val(int* flag);
void switch_flag(char* flag_name);

/* from read.c */
int streq(char* str1, char* str2);