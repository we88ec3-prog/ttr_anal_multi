
void FUN_007b74c0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c545;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  if (DAT_00fc1280 != 0) {
    do {
      iVar6 = DAT_00fc1280;
      FUN_004d8460(uVar2);
      piVar3 = (int *)FUN_008634e0();
      if ((int *)*piVar3 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)*piVar3;
      }
      uVar4 = (uint)piVar3[2] >> 2;
      if (*(uint *)(iVar5 + 8) <= uVar4) {
        uVar4 = uVar4 - *(uint *)(iVar5 + 8);
      }
      puVar1 = *(undefined4 **)(*(int *)(*(int *)(iVar5 + 4) + uVar4 * 4) + (piVar3[2] & 3U) * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
        iVar6 = DAT_00fc1280;
      }
      if (iVar6 == 0) goto LAB_007b756f;
      DAT_00fc1280 = iVar6 + -1;
    } while (DAT_00fc1280 != 0);
    DAT_00fc127c = 0;
  }
LAB_007b756f:
  FUN_007b6d70();
  FUN_0089120c(DAT_00fc1270);
  DAT_00fc1270 = 0;
  local_8 = 2;
  FUN_007b7c60(*DAT_00fc1264,DAT_00fc1264);
  FUN_0089120c(DAT_00fc1264);
  ExceptionList = local_10;
  return;
}

