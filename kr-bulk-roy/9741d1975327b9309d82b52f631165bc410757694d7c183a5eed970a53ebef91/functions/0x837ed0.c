
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00837ed0(void)

{
  longlong lVar1;
  undefined4 *in_ECX;
  uint uVar2;
  float10 extraout_ST0;
  float10 fVar3;
  
  do {
    if (DAT_00fe3478 == 0 && _DAT_00fe347c == 0) {
      FUN_00838150();
    }
    lVar1 = __allmul(in_ECX[6],in_ECX[7],1000,0);
    fVar3 = (float10)__allmul(in_ECX[8],in_ECX[9],1000,0);
    uVar2 = 0;
    if (in_ECX[0xd] != 0) {
      do {
        FID_conflict__wprintf("  ");
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)in_ECX[0xd]);
      fVar3 = (float10)(double)((float10)lVar1 / extraout_ST0);
    }
    FID_conflict__wprintf
              ("%s\t: call-%d, time-%.3fms, avg-%.3fms, max-%.3fms\n",*in_ECX,in_ECX[0xc],
               (double)fVar3);
    if (in_ECX[2] != 0) {
      FUN_00837ed0();
    }
    in_ECX = (undefined4 *)in_ECX[3];
  } while (in_ECX != (undefined4 *)0x0);
  return;
}

