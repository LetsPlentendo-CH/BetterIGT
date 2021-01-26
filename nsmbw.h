#include "main.elf.h"
#include "remocon.h"

void sprintf(char *, const char *, ...);
void TextBox_SetString(void *, char *, int);
void *GameSceneLayoutTimerTextBox;
void OSReport(const char *, ...);
void GetTxt1FromNames(someLytSubstruct *, const char **, void *, int);
void *GetElementFromLytByName(someLytSubstruct *, const char *);

void DoSceneChange(int, void *, void *);

void nw4r_lyt_TextBox_SetVtxColor(void *, unsigned int, unsigned int);

void *__ct__7dAcPy_c(void *);
void STAGE__beforeExecute(void *);

extern RemoconMgr *globalRemoconMgr;
extern TimeKeeper *Timekeeper;