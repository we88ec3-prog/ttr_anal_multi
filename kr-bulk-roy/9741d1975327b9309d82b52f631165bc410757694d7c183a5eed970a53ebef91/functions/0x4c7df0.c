
undefined4 FUN_004c7df0(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 in_XMM0_Da;
  int local_20;
  int *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093963e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1[0xdc] == 0) {
    uVar9 = param_1[0x23];
    if (uVar9 == 0) {
      uVar9 = param_1[0x22];
    }
    local_20 = FUN_00891268(0x170,DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    local_c = 0;
    if (local_20 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_007a4c50(local_20,uVar9 & 0xffff);
    }
    local_c = 0xffffffff;
    local_20 = 0;
    local_1c = (int *)0x0;
    FUN_004ca460(&local_20,uVar6);
    piVar2 = param_1 + 0x57;
    local_c = 1;
    FUN_004e0f60();
    piVar5 = local_1c;
    local_c = 0xffffffff;
    if (local_1c != (int *)0x0) {
      LOCK();
      iVar7 = local_1c[1] + -1;
      local_1c[1] = iVar7;
      UNLOCK();
      if (iVar7 == 0) {
        (**(code **)*local_1c)();
        piVar1 = piVar5 + 2;
        LOCK();
        iVar7 = *piVar1 + -1;
        *piVar1 = iVar7;
        UNLOCK();
        if (iVar7 == 0) {
          (**(code **)(*piVar5 + 4))();
        }
      }
    }
    FUN_007a6ea0(*piVar2,1,(short)param_1[0xe2]);
    if (param_2 != '\0') {
      *(undefined1 *)(*piVar2 + 0x20) = 1;
      FUN_007a8e70(*piVar2);
    }
    pcVar3 = *(code **)(*param_1 + 0x44);
    param_1[0xdc] = 1;
    (*pcVar3)(param_1 + 0x28,1);
    (**(code **)(*param_1 + 0x58))((char)param_1[0x2c]);
    if (((param_1[0xea] == 0) &&
        (*(char *)(param_1 + 0xe9) = (char)param_1[0x2c], param_1[0xdc] != 0)) && (*piVar2 != 0)) {
      iVar7 = *(int *)(*piVar2 + 4);
      FUN_00444a90((char)param_1[0x2c]);
      (**(code **)(iVar7 + 0xc))(in_XMM0_Da);
    }
    (**(code **)(*param_1 + 0x5c))(param_1[0x2d]);
    (**(code **)(*param_1 + 0x68))(param_1[0xe3],0x3f800000);
    iVar7 = FUN_00891268(0x30);
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_007b4000();
    }
    param_1[0xda] = iVar7;
    *(undefined4 *)(iVar7 + 0x24) = 1;
    puVar8 = (undefined4 *)(**(code **)(*param_1 + 0x4c))();
    uVar6 = puVar8[1];
    uVar4 = puVar8[2];
    iVar7 = param_1[0xda];
    *(undefined4 *)(iVar7 + 0x10) = *puVar8;
    *(undefined4 *)(iVar7 + 0x14) = uVar6;
    *(undefined4 *)(iVar7 + 0x18) = uVar4;
    iVar7 = param_1[0xda];
    local_20 = 0x42800000;
    local_1c = (int *)0x40c00000;
    *(undefined4 *)(iVar7 + 0x1c) = 0x42800000;
    *(undefined4 *)(iVar7 + 0x20) = 0x40c00000;
    iVar7 = FUN_007b4ed0(param_1[0xda]);
    *(undefined4 *)(iVar7 + 0xc) = 0x3f800000;
  }
  ExceptionList = local_14;
  return 1;
}

