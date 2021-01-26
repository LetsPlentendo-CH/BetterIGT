#include "nsmbw.h"

char valBuf[20];
char wideBuf[100];

#define NUM_TIMERS 6

int *timers[NUM_TIMERS];
int timerVals[NUM_TIMERS];

int *stateTxt;

int wasPaused = 0;
int currSplit = 0;

void *playerPtr;

void startLevelHook(int sceneID, void *param_2, void *param_3) {
    if (sceneID == 0x7) { // CRSIN
        wasPaused = 0;
        currSplit = 0;
    }
    DoSceneChange(sceneID, param_2, param_3);
}

void *HookPlayerCreate(void *this) {
    playerPtr = this;
    return __ct__7dAcPy_c(this);
}

void STAGE__beforeExecute_hook(void *this) {
    /*char buf[64];
    sprintf(buf, "test %04x\n", globalRemoconMgr->p1->heldButtons);
    OSReport(buf);
    sprintf(buf, "test %f\n", globalRemoconMgr->p1->accZ);
    OSReport(buf);*/
    STAGE__beforeExecute(this);
}

void toWideStr(char *in, char *out) {
    int i = 0;
    while (in[i] != 0) {
        if (in[i] >= '0' && in[i] <= '9') {
            out[i * 2] = 0xFF;
            out[i * 2 + 1] = in[i] - '0' + 0x10;
        } else {
            out[i * 2] = 0x00;
            out[i * 2 + 1] = in[i];
        }
        i++;
    }
    out[i * 2] = 0x00;
    out[i * 2 + 1] = 0x00;
}

void UpdateGameTimer(GameSceneLyt *gameSceneLyt, int exactTimerVal) {
    if (!wasPaused && Timekeeper->isPaused && Timekeeper->startIGT * 4096 >= Timekeeper->timeValue + 0xFFF) {
        wasPaused = 1;
        timerVals[currSplit] = Timekeeper->timeValue;
    }
    if (wasPaused && !Timekeeper->isPaused) {
        wasPaused = 0;
        currSplit++;
        if (currSplit > (NUM_TIMERS - 1)) {
            currSplit = NUM_TIMERS - 1;
        }
    }
    for (int i = 0; i < currSplit + 1; i++) {
        sprintf(valBuf, "%03.3f", (double) (timerVals[i] + 0xFFF) / 4096.0);
        toWideStr(valBuf, wideBuf);
        TextBox_SetString(timers[i], wideBuf, 0);
    }

    sprintf(valBuf, "%03.3f", (double) (exactTimerVal + 0xFFF) / 4096.0);
    toWideStr(valBuf, wideBuf);
    TextBox_SetString(timers[currSplit], wideBuf, 0);

    /*void *currState = *(void **) ((int) playerPtr + 0x391 + 0x10d3 + 0x18 + 0x1c);
    char *stateName = *(char **) ((int) currState + 4);
    toWideStr(stateName, wideBuf);
    TextBox_SetString(stateTxt, wideBuf, 0);*/
}

void gameSceneLoadTxt1(someLytSubstruct *lyt, const char **gameSceneNames, void *txt1Storage, int length) {
    GetTxt1FromNames(lyt, gameSceneNames, txt1Storage, 11);

    char nameBuf[16];
    for (int i = 0; i < 6; i++) {
        sprintf(nameBuf, "T_time_%02d", i);
        timers[i] = GetElementFromLytByName(lyt, nameBuf);
        OSReport("%s\n", nameBuf);
        TextBox_SetString(timers[i], "\0\0", 0);
    }
    stateTxt = GetElementFromLytByName(lyt, "T_state_00");
    TextBox_SetString(stateTxt, "\0\0", 0);
}