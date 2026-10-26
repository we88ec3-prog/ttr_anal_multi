
undefined4 FUN_008f18d0(undefined4 param_1,int param_2,uint param_3,ushort param_4,int param_5)

{
  uint uVar1;
  undefined1 local_8 [4];
  
  uVar1 = 0;
  if ((param_4 & 0x10) == 0) {
    if (param_3 != 0) {
      do {
        FUN_008eac30(uVar1 + param_2,local_8);
        *(uint *)(param_5 + uVar1 * 4) = (uint)param_4;
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_3);
    }
  }
  else if (param_3 != 0) {
    do {
      FUN_008eac50(uVar1 + param_2,0);
      *(uint *)(param_5 + uVar1 * 4) = (uint)param_4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
    return 0;
  }
  return 0;
}

