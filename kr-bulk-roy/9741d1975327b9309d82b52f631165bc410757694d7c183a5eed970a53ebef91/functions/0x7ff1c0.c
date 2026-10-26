
void FUN_007ff1c0(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int *_Str1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 auStack_70 [92];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093728e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar4 = 0;
  local_74 = 1;
  if (param_2 == (undefined4 *)0x0) {
    param_2 = &local_9c;
  }
  local_78 = 0x3f800000;
  local_7c = 0x3f800000;
  local_80 = 0x3f800000;
  local_84 = 0x3f800000;
  local_88 = 0;
  local_8c = 0;
  local_90 = 0;
  local_94 = 0;
  local_98 = 0;
  local_9c = 0;
  iVar1 = (**(code **)(*param_1 + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff50);
  iVar1 = *(int *)(iVar1 + 4);
  if (iVar1 == -0x5eed0000) {
    uVar2 = FUN_0077ef30(param_2);
    FUN_0077e910(auStack_70,uVar2);
    iVar1 = param_1[0x37] - param_1[0x36] >> 2;
    uVar4 = 0;
    if (0 < iVar1) {
      do {
        if (uVar4 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar2 = *(undefined4 *)(param_1[0x36] + uVar4 * 4);
        }
        else {
          uVar2 = 0;
        }
        FUN_007ff1c0(uVar2,auStack_70,param_3);
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < iVar1);
    }
    uVar4 = (**(code **)(*param_1 + 0x34))();
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        puVar6 = auStack_70;
        uVar2 = param_3;
        uVar3 = (**(code **)(*param_1 + 0x30))(uVar5,puVar6,param_3);
        FUN_007ff1c0(uVar3,puVar6,uVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
  }
  else if (iVar1 == -0x5edf0000) {
    if (param_1[0x1f] - param_1[0x1e] >> 2 != 0) {
      do {
        FUN_007ff1c0(*(undefined4 *)(param_1[0x1e] + uVar4 * 4),param_2,param_3);
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(param_1[0x1f] - param_1[0x1e] >> 2));
      ExceptionList = local_14;
      return;
    }
  }
  else if (iVar1 == -0x5edc0000) {
    _Str1 = param_1 + 2;
    if (0xf < (uint)param_1[7]) {
      _Str1 = (int *)*_Str1;
    }
    iVar1 = __strnicmp((char *)_Str1,"_CM",3);
    if (iVar1 == 0) {
      iVar1 = FUN_00891268(0x44);
      uStack_c = 0;
      if (iVar1 != 0) {
        FUN_007e9420(iVar1,param_1);
      }
      uStack_c = 0xffffffff;
      FUN_007bb350();
      ExceptionList = local_14;
      return;
    }
  }
  ExceptionList = local_14;
  return;
}

