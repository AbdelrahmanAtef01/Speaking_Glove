#ifndef M16P_H_
#define M16P_H_

void M16P_vidInit(uint16_ baud);
void M16P_vidSetReply(uint8_t state);
void M16P_vidPlayTrack(uint16_ num);
void M16P_vidNextTrack();
void M16P_vidPreviousTrack();
void M16P_vidSetVolume(uint16_ volume);
void M16P_vidSetEQ(uint16_ eq);
void M16P_vidSetPlaybackSource(uint16_ device);
void M16P_vidSleep();
void M16P_vidReset();
void M16P_vidPlayback();
void M16P_vidPause();
void M16P_vidPlayFileInFolder(uint16_ folder, uint16_ file);
void M16P_vidPlayByNumber(uint16_ num);
void M16P_vidGetState();
void M16P_vidGetVolume();
void M16P_vidGetUSum();
void M16P_vidGetTFSum();
void M16P_vidGetFlashSum();
void M16P_vidGetTFCurrent();
void M16P_vidGetUCurrent();
void M16P_vidGetFlashCurrent();
uint8_t M16P_u8GetDataBuffer();
#endif
