
void FUN_00698a30(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint local_64;
  int local_60;
  int local_5c;
  int *local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38;
  uint local_24;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c9b6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  local_60 = param_1;
  iVar5 = *(int *)(*(int *)(param_1 + 0xf4) + 0xcc);
  if (iVar5 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)(iVar5 + 0xa8);
  }
  piVar4 = (int *)*puVar2;
  local_58 = (int *)puVar2[1];
  iVar5 = 0;
  local_64 = CONCAT31(local_64._1_3_,1);
  do {
    if (piVar4 == local_58) {
      local_5c = iVar5;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0;
        FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      local_c = 0xffffffff;
      if (DAT_00f9424c < iVar5) {
        local_64 = local_64 & 0xffffff00;
      }
      FUN_00412df0();
      iVar5 = local_60;
      local_c = 1;
      FUN_00759ac0(0);
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      (**(code **)(**(int **)(iVar5 + 0x100) + 200))();
      FUN_00412df0();
      iVar5 = local_60;
      local_c = 2;
      FUN_00759ac0(0);
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      (**(code **)(**(int **)(iVar5 + 0x108) + 200))();
      FUN_00412df0();
      iVar5 = local_60;
      local_c = 3;
      FUN_00759ac0(0);
      local_c = 0xffffffff;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      uStack_54 = uStack_54 & 0xffff0000;
      uStack_40 = 7;
      uStack_44 = 0;
      (**(code **)(**(int **)(iVar5 + 0x104) + 200))();
      (**(code **)(**(int **)(iVar5 + 0xfc) + 0x90))(local_64);
      ExceptionList = pvStack_18;
      __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff98);
      return;
    }
    iVar1 = *piVar4;
    iVar3 = *(int *)(*(int *)(iVar1 + 0x24c) + 0x24c);
    if (((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0xcc), iVar3 == 0)) ||
       (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 == 0)) {
LAB_00698afa:
      iVar3 = *(int *)(*(int *)(iVar1 + 0x250) + 0x24c);
      if (iVar3 == 0) goto LAB_00698b28;
      iVar3 = *(int *)(iVar3 + 0xcc);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xdc);
      }
      if ((iVar3 == 0) || (*(int *)(iVar3 + 0x20) == -1)) goto LAB_00698b28;
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar1 + 0x24c) + 0x24c);
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar3 + 0xcc);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(iVar3 + 0xdc);
        }
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != -1)) goto LAB_00698afa;
      }
LAB_00698b28:
      local_64 = local_64 & 0xffffff00;
    }
    if ((*(int *)(iVar1 + 0x25c) != 0) &&
       (iVar3 = *(int *)(*(int *)(iVar1 + 0x250) + 0x24c), iVar3 != 0)) {
      iVar3 = *(int *)(iVar3 + 0xcc);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xdc);
      }
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != -1)) {
        iVar5 = iVar5 + *(int *)(*(int *)(*(int *)(iVar1 + 0x25c) + 0x54) + 8 +
                                *(int *)(iVar3 + 0x20) * 0xc);
      }
    }
    piVar4 = piVar4 + 1;
  } while( true );
}

