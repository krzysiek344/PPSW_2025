

#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_NR 2
#define MAX_KEYWORD_STRING_LTH 10
#define DELIMITER_CHAR ' '

typedef enum {CALLIB, GOTO} KeywordCode;
typedef enum {KEYWORD, NUMBER, STRING} TokenType;
typedef enum Result {OK, ERROR} Result;

typedef struct {
    KeywordCode eCode;
    char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

typedef union {
    KeywordCode eKeyword;
    unsigned int uiNumber;
    char* pcString;
} TokenValue;

typedef struct {
    TokenType eType;
    TokenValue uValue;
} Token;

// Zmienne globalne (mozesz je zadeklarowac extern, jesli chcesz trzymac je w .c)
extern Token asToken[MAX_TOKEN_NR];
extern unsigned char ucTokenNr;

// Glówna funkcja dekodujaca
void DecodeMsg(char *pcString);


