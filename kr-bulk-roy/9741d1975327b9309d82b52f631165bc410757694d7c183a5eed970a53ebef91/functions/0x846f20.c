
undefined4 FUN_00846f20(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EDI;
  int iVar4;
  int iStack_54;
  int iStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined1 *puStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 local_20 [7];
  
  iStack_34 = param_1;
  uStack_38 = 0x846f3b;
  FUN_007802f0();
  puStack_3c = in_ECX + 0x15;
  if (puStack_3c != (undefined4 *)0x0) {
    iStack_34 = 0;
    uStack_38 = 0x1c;
    puStack_40 = *(undefined1 **)(param_1 + 0x88);
    iStack_44 = 0x846f53;
    FUN_00721910();
  }
  puStack_40 = *(undefined1 **)(param_1 + 0x88);
  local_20[0] = in_ECX[0x1d];
  iStack_34 = 0;
  uStack_38 = 4;
  puStack_3c = local_20;
  iStack_44 = 0x846f6f;
  FUN_00721910();
  if (unaff_EDI != 0) {
    iStack_44 = 0x846f82;
    FUN_007bb350();
  }
  iStack_50 = *(undefined4 *)(param_1 + 0x88);
  iStack_44 = 0;
  uStack_48 = 4;
  puStack_4c = &stack0xffffffd0;
  iStack_54 = 0x846f9e;
  FUN_00721910();
  if (puStack_40 != (undefined1 *)0x0) {
    iStack_54 = 0x846fb1;
    FUN_007bb350();
  }
  puStack_3c = (undefined4 *)((int)(in_ECX[0x20] - in_ECX[0x1f]) / 100);
  iStack_54 = 0;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&puStack_3c);
  puStack_40 = (undefined1 *)0x0;
  if (puStack_4c != (undefined1 *)0x0) {
    iStack_50 = 0;
    do {
      puVar2 = (undefined4 *)(in_ECX[0x1f] + iStack_50);
      uStack_48 = puVar2[4];
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&uStack_48,4,0);
      puVar1 = puVar2;
      if (0xf < (uint)puVar2[5]) {
        puVar1 = (undefined4 *)*puVar2;
      }
      if (puVar1 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar1,4,0);
      }
      if (puVar2 + 7 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar2 + 7,0x34,0);
      }
      if (puVar2 + 0x14 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar2 + 0x14,4,0);
      }
      iStack_54 = (int)(puVar2[0x16] - puVar2[0x15]) >> 3;
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_54,4,0);
      iVar3 = puVar2[0x15];
      if ((iVar3 != 0) && (iVar4 = iStack_44, 0 < iStack_44)) {
        do {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar3,8,0);
          iVar3 = iVar3 + 8;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iStack_50 = iStack_50 + 100;
      puStack_40 = puStack_40 + 1;
      in_ECX = puStack_3c;
    } while (puStack_40 < puStack_4c);
  }
  return 1;
}

