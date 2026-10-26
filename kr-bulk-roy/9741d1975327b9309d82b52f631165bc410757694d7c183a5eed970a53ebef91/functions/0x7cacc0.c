
undefined4 FUN_007cacc0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int *_Str;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 auStack_c4 [6];
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined4 *puStack_a4;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [92];
  
  local_64 = 1;
  if (param_2 == (undefined4 *)0x0) {
    param_2 = &local_8c;
  }
  local_68 = 0x3f800000;
  local_6c = 0x3f800000;
  local_70 = 0x3f800000;
  local_74 = 0x3f800000;
  local_78 = 0;
  local_7c = 0;
  local_80 = 0;
  local_84 = 0;
  local_88 = 0;
  local_8c = 0;
  iVar1 = (**(code **)(*param_1 + 4))();
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == -0x5eed0000) {
    FUN_0077ef30();
    puStack_a4 = (undefined4 *)auStack_60;
    uStack_a8 = 0x7cae0c;
    FUN_0077e910();
    iVar1 = param_1[0x37] - param_1[0x36] >> 2;
    uVar7 = 0;
    if (0 < iVar1) {
      do {
        if (uVar7 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uStack_a8 = *(undefined4 *)(param_1[0x36] + uVar7 * 4);
        }
        else {
          uStack_a8 = 0;
        }
        puStack_a4 = (undefined4 *)auStack_60;
        uStack_ac = 0x7cae57;
        iVar4 = FUN_007cacc0();
        if (iVar4 != 0) {
          return 1;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < iVar1);
    }
    uVar7 = (**(code **)(*param_1 + 0x34))();
    uVar5 = 0;
    if (uVar7 != 0) {
      do {
        puStack_a4 = (undefined4 *)auStack_60;
        uStack_ac = 0x7cae8b;
        uStack_a8 = uVar5;
        uStack_a8 = (**(code **)(*param_1 + 0x30))();
        uStack_ac = 0x7cae91;
        iVar1 = FUN_007cacc0();
        if (iVar1 != 0) {
          return 1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar7);
    }
  }
  else if (iVar1 == -0x5edf0000) {
    uVar7 = 0;
    if (param_1[0x1f] - param_1[0x1e] >> 2 != 0) {
      do {
        uStack_a8 = *(undefined4 *)(param_1[0x1e] + uVar7 * 4);
        uStack_ac = 0x7cadd5;
        puStack_a4 = param_2;
        iVar1 = FUN_007cacc0();
        if (iVar1 != 0) {
          return 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(param_1[0x1f] - param_1[0x1e] >> 2));
      return 0;
    }
  }
  else if (iVar1 == -0x5edc0000) {
    _Str = param_1 + 2;
    if (0xf < (uint)param_1[7]) {
      _Str = (int *)*_Str;
    }
    puStack_a4 = (undefined4 *)0x7cad80;
    pcVar2 = _strstr((char *)_Str,"_BX");
    if (pcVar2 == (char *)0x0) {
      puVar6 = auStack_c4;
      for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *param_2;
        param_2 = param_2 + 1;
        puVar6 = puVar6 + 1;
      }
      uVar3 = FUN_007caa30(param_1);
      return uVar3;
    }
  }
  return 0;
}

