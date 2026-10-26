
void FUN_0067ed20(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  int in_EDX;
  int *piVar6;
  int *local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942dda;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_8c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  local_7c = param_1;
  local_88 = in_EDX;
  cVar3 = FUN_0067fca0(param_1);
  if (cVar3 != '\0') {
    piVar6 = (int *)(in_EDX + 0x170);
    local_84 = 3;
    do {
      local_8c = piVar6;
      piVar5 = (int *)FUN_00891268(0x1c,uVar4);
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        iVar1 = piVar6[1];
        iVar2 = *piVar6;
        piVar5[1] = -1;
        piVar5[2] = -1;
        piVar5[3] = 0;
        piVar5[4] = 0xf4369;
        *piVar5 = (int)FoxUI::FXUIEventI2::vftable;
        piVar5[5] = iVar2;
        piVar5[6] = iVar1;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar5);
      }
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x10))(1);
      }
      uStack_78 = 0xffffffff;
      uStack_74 = 0xffffffff;
      uStack_70 = 0xffffffff;
      uStack_6c = 0xffffffff;
      uStack_68 = 0;
      uStack_64 = 0;
      uStack_4c = 7;
      uStack_50 = 0;
      uStack_60 = uStack_60 & 0xffff0000;
      uStack_44 = 0xffffffff;
      uStack_40 = 0xffffffff;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0xffffffff;
      local_c = 1;
      FUN_0045d560();
      local_c = 0xffffffff;
      if (7 < uStack_4c) {
        FUN_0089120c(uStack_60);
      }
      piVar6 = local_8c + 0x16;
      local_84 = local_84 + -1;
    } while (local_84 != 0);
    local_8c = piVar6;
    piVar6 = (int *)FUN_00891268(0x1c);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      iVar1 = *(int *)(local_88 + 0x11c);
      iVar2 = *(int *)(local_88 + 0x118);
      piVar6[1] = -1;
      piVar6[2] = -1;
      piVar6[3] = 0;
      piVar6[4] = 0xf4369;
      *piVar6 = (int)FoxUI::FXUIEventI2::vftable;
      piVar6[5] = iVar2;
      piVar6[6] = iVar1;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar6);
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x10))(1);
    }
    piVar6 = (int *)FUN_00891268(0x1c);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6[1] = -1;
      piVar6[2] = -1;
      piVar6[3] = 0;
      piVar6[4] = 0xf4368;
      *piVar6 = (int)FoxUI::FXUIEventI2::vftable;
      piVar6[5] = local_7c;
      piVar6[6] = local_80;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar6);
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x10))(1);
    }
    FUN_0067f930(&uStack_78,local_7c);
    local_c = 4;
    FUN_0045d560();
    local_c = 0xffffffff;
    if (7 < uStack_4c) {
      FUN_0089120c(uStack_60);
    }
    uStack_4c = 7;
    uStack_50 = 0;
    uStack_60 = uStack_60 & 0xffff0000;
    FUN_0067f310();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_8c);
  return;
}

