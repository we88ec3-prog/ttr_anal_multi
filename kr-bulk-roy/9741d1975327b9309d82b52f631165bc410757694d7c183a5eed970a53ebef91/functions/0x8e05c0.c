
void FUN_008e05c0(int param_1,uint *param_2)

{
  uint uVar1;
  short *psVar2;
  
  uVar1 = *param_2;
  *param_2 = 0;
  if ((uVar1 < 0xff) && (uVar1 = uVar1 + 1, uVar1 < 0x100)) {
    psVar2 = (short *)(*(int *)(param_1 + 0x10) + uVar1 * 2);
    while (*psVar2 == 0) {
      uVar1 = uVar1 + 1;
      psVar2 = psVar2 + 1;
      if (0xff < uVar1) {
        return;
      }
    }
    *param_2 = uVar1;
  }
  return;
}

