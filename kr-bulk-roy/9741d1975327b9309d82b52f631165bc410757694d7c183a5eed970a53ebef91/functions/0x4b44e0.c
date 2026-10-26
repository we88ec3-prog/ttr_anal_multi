
undefined4 FUN_004b44e0(int param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (param_2 < 2) {
    uVar5 = 0;
  }
  else {
    uVar5 = (param_2 - 2) / 3;
  }
  if (uVar5 != 0) {
    pbVar6 = (byte *)(param_1 + 2);
    do {
      bVar2 = *pbVar6;
      iVar3 = FUN_0040f060();
      if (((int)(uint)bVar2 >> 3 == 0) &&
         (pbVar1 = (byte *)((uint)bVar2 * 3 + 0xb8 + iVar3), pbVar1 != (byte *)0x0)) {
        *pbVar1 = *pbVar6;
        bVar2 = pbVar6[2];
        pbVar1[1] = pbVar6[1];
        pbVar1[2] = bVar2;
      }
      else {
        FUN_006edb60(&DAT_00c06d5c);
      }
      pbVar6 = pbVar6 + 3;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  uVar4 = FUN_0040f060();
  FUN_004e0650(uVar4);
  return 0;
}

