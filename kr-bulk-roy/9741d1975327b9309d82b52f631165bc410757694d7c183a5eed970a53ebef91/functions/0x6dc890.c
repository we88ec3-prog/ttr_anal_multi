
void FUN_006dc890(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puStack_64;
  undefined4 auStack_60 [4];
  undefined4 uStack_50;
  undefined4 uStack_40;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0090f4c9;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_64;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  if (*param_1 < 2) {
    *param_1 = 1;
    if (param_1[4] != 0) {
      (**(code **)(*(int *)(param_1[4] + 8) + 4))(uVar1);
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      (**(code **)(*(int *)(param_1[4] + 4) + 4))(&uStack_2c);
      (**(code **)(*(int *)(param_1[4] + 4) + 0x14))(0x3f800000);
    }
    puStack_64 = (undefined4 *)FUN_00891268(0x8c);
    uStack_c = 0;
    if (puStack_64 == (undefined4 *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0077e550();
    }
    uStack_c = 0xffffffff;
    param_1[3] = iVar2;
    *(undefined4 *)(iVar2 + 0x74) = 0x3f060a92;
    iVar2 = param_1[3];
    *(undefined4 *)(iVar2 + 0x84) = 0x200;
    *(undefined4 *)(iVar2 + 0x88) = 0x200;
    *(undefined4 *)(param_1[3] + 0x7c) = 0x447a0000;
    *(undefined4 *)(param_1[3] + 0x78) = 0x3f800000;
    puStack_64 = (undefined4 *)FUN_00891268(0xe8);
    uStack_c = 1;
    if (puStack_64 == (undefined4 *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0077ebb0();
    }
    param_1[1] = iVar2;
    FUN_0077f030(0,0,0x43160000);
    puStack_64 = (undefined4 *)param_1[3];
    if (puStack_64 != (undefined4 *)0x0) {
      puStack_64[1] = puStack_64[1] + 1;
    }
    uStack_c = 2;
    FUN_0077f8f0();
    uStack_c = 0xffffffff;
    if (puStack_64 != (undefined4 *)0x0) {
      piVar3 = puStack_64 + 1;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        (**(code **)*puStack_64)(1);
      }
    }
    puStack_64 = (undefined4 *)FUN_00891268(0xe8);
    uStack_c = 3;
    if (puStack_64 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0077ebb0();
    }
    uStack_c = 0xffffffff;
    param_1[2] = (int)piVar3;
    (**(code **)(*piVar3 + 0x40))(param_1[1]);
    FUN_0077f030(0,0,0x42700000);
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0x3f800000;
    _memset(auStack_60,0,0x34);
    uStack_40 = 0x3f800000;
    uStack_50 = 0x3f800000;
    auStack_60[0] = 0x3f800000;
    FUN_00790dc0(0x3fb2b8c3);
    FUN_00790e90(0);
    FUN_00790f60(0);
    FUN_00780890();
    FUN_0077efc0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_64);
  return;
}

