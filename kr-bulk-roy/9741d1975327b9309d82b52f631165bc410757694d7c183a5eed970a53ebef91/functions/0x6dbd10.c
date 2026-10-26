
void FUN_006dbd10(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 auStack_50 [4];
  undefined4 uStack_40;
  undefined4 uStack_30;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00908098;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0x43960000;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x74) = 0x3f1c61aa;
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar2 + 0x84) = 0x200;
  *(undefined4 *)(iVar2 + 0x88) = 0x200;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x7c) = 0x447a0000;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x78) = 0x3f800000;
  FUN_0077f030(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
               *(undefined4 *)(param_1 + 0x24));
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = puVar3[1] + 1;
  }
  local_c = 0;
  FUN_0077f8f0(uVar4);
  local_c = 0xffffffff;
  if (puVar3 != (undefined4 *)0x0) {
    piVar1 = puVar3 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar3)(1);
    }
  }
  (**(code **)(**(int **)(param_1 + 8) + 0x40))(*(undefined4 *)(param_1 + 4));
  iVar2 = *(int *)(param_1 + 8);
  if (((*(float *)(iVar2 + 0x68) != 0.0) || (*(float *)(iVar2 + 0x6c) != 0.0)) ||
     (*(float *)(iVar2 + 0x70) != 60.0)) {
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(iVar2 + 0x70) = 0x42700000;
    *(undefined4 *)(iVar2 + 0xc0) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  _memset(auStack_50,0,0x34);
  uStack_30 = 0x3f800000;
  uStack_40 = 0x3f800000;
  auStack_50[0] = 0x3f800000;
  FUN_00790dc0(0x3fb2b8c3);
  FUN_00790e90(0);
  FUN_00790f60(0);
  FUN_00780890();
  FUN_0077efc0();
  ExceptionList = pvStack_18;
  return;
}

