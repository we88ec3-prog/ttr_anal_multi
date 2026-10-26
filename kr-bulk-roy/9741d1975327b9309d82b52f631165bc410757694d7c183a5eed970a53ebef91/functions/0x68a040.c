
void FUN_0068a040(void)

{
  float fVar1;
  code *pcVar2;
  int *in_EAX;
  
  if (((uint)in_EAX[10] >> 8 & 1) != 0) {
    if (in_EAX[0x25] == 1) {
      fVar1 = (float)in_EAX[0x24];
      in_EAX[0x24] = (int)(fVar1 + 0.033333335);
      if (fVar1 + 0.033333335 < (float)in_EAX[0x27]) {
        FUN_008fed10();
        FUN_00745100();
        (**(code **)(*(int *)in_EAX[0x20] + 200))();
        return;
      }
      if ((char)in_EAX[0x36] == '\0') {
        FUN_0068a270(in_EAX);
        *(undefined1 *)(in_EAX + 0x36) = 1;
        return;
      }
    }
    else if (in_EAX[0x25] == 2) {
      fVar1 = (float)in_EAX[0x24] + 0.033333335;
      in_EAX[0x24] = (int)fVar1;
      if ((float)in_EAX[0x26] <= fVar1) {
        FUN_0068a350();
        pcVar2 = *(code **)(*in_EAX + 0xd4);
        in_EAX[0x25] = 0;
        (*pcVar2)();
        return;
      }
      fVar1 = fVar1 / (float)in_EAX[0x26];
      if (0.3 <= fVar1) {
        if (0.7 < fVar1) {
          in_EAX[0x2c] = (int)(1.0 - (fVar1 - 0.7) / 0.3);
        }
      }
      else {
        in_EAX[0x2c] = (int)(fVar1 / 0.3);
      }
      FUN_0068a630(in_EAX[0x2c]);
    }
  }
  return;
}

