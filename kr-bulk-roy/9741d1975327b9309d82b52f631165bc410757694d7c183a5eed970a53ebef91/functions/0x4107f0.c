
void FUN_004107f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  undefined1 auStack_64 [4];
  int *piStack_60;
  int iStack_5c;
  uint uStack_58;
  uint local_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094205e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (((*(byte *)(param_1 + 0x144) < 10) &&
      (iVar4 = (uint)*(byte *)(param_1 + 0x144) * 0x210 + DAT_00f94304, *(int *)(iVar4 + 0x5c) != 0)
      ) && (iVar4 != 0)) {
    if ((*(byte *)(param_1 + 0x145) < 7) &&
       (iVar1 = iVar4 + 0x110 + (uint)*(byte *)(param_1 + 0x145) * 0x1c, iVar1 != 0)) {
      uVar6 = (uint)*(byte *)(iVar1 + 0x18);
    }
    else {
      uVar6 = 0;
    }
    *(uint *)(param_1 + 0x14c) = uVar6 + *(int *)(param_1 + 0x148);
    *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(iVar4 + 0xd4);
    FUN_00412df0();
    local_c = 1;
    FUN_00759ac0(0);
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    FUN_00412df0();
    local_c = 2;
    FUN_00759ac0(1);
    local_c = 0xffffffff;
    if (7 < uStack_40) {
      FUN_0089120c(local_54);
    }
    local_54 = local_54 & 0xffff0000;
    uStack_40 = 7;
    uStack_44 = 0;
    (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if (iVar4 != 0) {
    FUN_006438f0(iVar4);
  }
  uStack_58 = 0;
  if (*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 4 != 0) {
    piStack_60 = (int *)0x0;
    iStack_5c = 0;
    do {
      piVar7 = piStack_60;
      piVar5 = (int *)(*(int *)(param_1 + 0x124) + iStack_5c);
      if (piVar5[1] - *piVar5 >> 2 != 0) {
        iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4));
        }
        FUN_00473700(*(int *)(param_1 + 0x124) + iStack_5c);
        (**(code **)(**(int **)(iVar4 + 0x250) + 0x94))(*(int *)(param_1 + 0x14c) < (int)piVar7);
        FUN_00473790();
      }
      iStack_5c = iStack_5c + 0x10;
      uStack_58 = uStack_58 + 1;
      piStack_60 = (int *)((int)piStack_60 + 5);
    } while (uStack_58 < (uint)(*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 4));
  }
  piVar7 = *(int **)(param_1 + 0xfc);
  puVar2 = (undefined4 *)piVar7[0x19];
  piStack_60 = piVar7;
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar4 = puVar3[2];
    if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
      piVar7 = piStack_60;
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

