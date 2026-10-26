
undefined4 FUN_00706540(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = FUN_006f5170();
  if (iVar2 == 0) {
    FUN_006f5f30(param_1,"stack overflow (%s)","too many nested functions");
  }
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 <= puVar4) {
    puVar4 = &DAT_00c0bfc8;
  }
  *puVar1 = *puVar4;
  puVar1[1] = puVar4[1];
  puVar1[2] = puVar4[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x10,1);
  puVar1 = *(undefined4 **)(param_1 + 8);
  puVar4 = puVar1 + -4;
  if (puVar4 != &DAT_00c0bfc8) {
    if (puVar1[-2] == 0) {
      *param_3 = 0;
      return 0;
    }
    if ((puVar4 != &DAT_00c0bfc8) && ((puVar1[-2] == 4 || (puVar1[-2] == 3)))) {
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
      if (puVar1 <= puVar5) {
        puVar5 = &DAT_00c0bfc8;
      }
      *puVar5 = *puVar4;
      puVar5[1] = puVar1[-3];
      puVar5[2] = puVar1[-2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
      uVar3 = FUN_006f53f0(3,param_3);
      return uVar3;
    }
  }
  FUN_006f5f30(param_1,"reader function must return a string");
  return 0;
}

