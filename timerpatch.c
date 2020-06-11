void sprintf(char *, const char *, ...);
void TextBox_SetString(void *, char *, int);
void *GameSceneLayoutTimerTextBox;
void OSReport(const char *, ...);

char valBuf[20];
char wideBuf[40];

//                   not actually char, but whatever
void UpdateGameTimer(unsigned int *gameSceneLyt, int exactTimerVal) {
    sprintf(valBuf, "%03.3f", (double) (exactTimerVal + 0xFFF) / 4096.0);
    int i = 0;
    while (valBuf[i] != 0) {
        if (valBuf[i] >= '0' && valBuf[i] <= '9') {
            wideBuf[i * 2] = 0xFF;
            wideBuf[i * 2 + 1] = valBuf[i] - '0' + 0x10;
        } else {
            // must be a dot
            wideBuf[i * 2] = 0x00;
            wideBuf[i * 2 + 1] = 0x2E;
        }
        i++;
    }
    OSReport("%s\n", valBuf);
    TextBox_SetString((void *) *(gameSceneLyt + (0x4E0 / 4)), wideBuf, 0);
}