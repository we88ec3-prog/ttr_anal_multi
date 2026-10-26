
void FUN_006a2340(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  float local_84;
  int local_80;
  uint local_7c;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c576;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_84;
  ExceptionList = &local_14;
  local_7c = 0;
  local_74 = in_ECX;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_84 = *(float *)(in_ECX + 0x128);
  FUN_008438c0(&local_84);
  if ((local_80 == DAT_00f8d91c) || (*(int *)(local_80 + 0x10) == 0)) {
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
  }
  else {
    iVar3 = *(int *)(in_ECX + 300);
    local_84 = 1.0;
    local_80 = 0;
    if (iVar3 == 0) {
      local_78 = 0x3df5c28f;
    }
    else if (iVar3 == 1) {
      local_78 = 0x3e75c28f;
    }
    else if (iVar3 == 2) {
      local_78 = 0x3ef5c28f;
    }
    else {
      local_78 = 0;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    cVar2 = FUN_004d9d20(DAT_00f94308,0xc);
    if (cVar2 != '\0') {
      local_84 = 0.5;
    }
    local_80 = FUN_0068ace0();
    if (local_80 <= 0x7fffffff) {
      if (local_80 < -0x80000000) {
        local_80 = -0x80000000;
      }
    }
    else {
      local_80 = 0x7fffffff;
    }
    FUN_008fed10();
    if (local_84 == 0.5) {
      local_7c = 0x14;
      iVar3 = FUN_00585620();
      FUN_005740f0(&local_7c);
      if (local_84 == *(float *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = FUN_004068f0();
      local_c = 2;
      uVar5 = 1;
    }
    else {
      local_84 = 2.66247e-44;
      iVar3 = FUN_00585620();
      FUN_005740f0(&local_84);
      if (local_80 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar4 = FUN_004068f0();
      local_c = 3;
      uVar5 = 2;
    }
    local_70 = (uint)local_70._2_2_ << 0x10;
    local_5c = 7;
    local_60 = 0;
    local_7c = uVar5;
    FUN_00402800(uVar4);
    local_c = 4;
    if ((uVar5 & 2) != 0) {
      uVar5 = uVar5 & 0xfffffffd;
      if (7 < local_40) {
        FUN_0089120c(local_54);
      }
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
    }
    local_c = CONCAT31(local_c._1_3_,6);
    if ((uVar5 & 1) != 0) {
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      local_24 = 7;
      local_28 = 0;
      local_38 = local_38 & 0xffff0000;
    }
    FUN_00757800(&local_70);
    (**(code **)(**(int **)(local_74 + 0x104) + 200))();
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_84);
  return;
}

