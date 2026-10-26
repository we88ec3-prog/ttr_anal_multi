
void FUN_006a1ef0(int param_1)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 **ppuVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puStack_84;
  undefined4 *puStack_80;
  uint local_7c;
  undefined4 uStack_78;
  int local_74;
  undefined4 uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093c612;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_84;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  iVar7 = 0;
  local_7c = 0;
  *(int *)(in_ECX + 300) = param_1;
  puVar8 = (undefined4 *)(in_ECX + 0xf8);
  local_74 = in_ECX;
  do {
    (**(code **)(*(int *)*puVar8 + 0xa0))(iVar7 == param_1,uVar3);
    (**(code **)(*(int *)*puVar8 + 200))();
    iVar7 = iVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (iVar7 < 3);
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    uStack_c = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    uStack_c = 0xffffffff;
  }
  cVar2 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
  puVar8 = (undefined4 *)DAT_00f8d91c[1];
  puStack_84 = DAT_00f8d91c;
  while (puVar6 = puVar8, cVar2 == '\0') {
    if ((int)puVar6[3] < *(int *)(local_74 + 0x128)) {
      puVar8 = (undefined4 *)puVar6[2];
      puVar6 = puStack_84;
    }
    else {
      puVar8 = (undefined4 *)*puVar6;
    }
    cVar2 = *(char *)((int)puVar8 + 0x15);
    puStack_84 = puVar6;
  }
  if ((puStack_84 == DAT_00f8d91c) || (*(int *)(local_74 + 0x128) < (int)puStack_84[3])) {
    puStack_80 = DAT_00f8d91c;
    ppuVar4 = &puStack_80;
  }
  else {
    ppuVar4 = &puStack_84;
  }
  if ((*ppuVar4 == DAT_00f8d91c) || ((*ppuVar4)[4] == 0)) {
    FUN_00757710();
    (**(code **)(**(int **)(local_74 + 0x104) + 200))();
  }
  else {
    iVar7 = *(int *)(local_74 + 300);
    puStack_84 = (undefined4 *)0x3f800000;
    puStack_80 = (undefined4 *)0x0;
    if (iVar7 == 0) {
      uStack_78 = 0x3df5c28f;
    }
    else if (iVar7 == 1) {
      uStack_78 = 0x3e75c28f;
    }
    else if (iVar7 == 2) {
      uStack_78 = 0x3ef5c28f;
    }
    else {
      uStack_78 = 0;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    cVar2 = FUN_004d9d20(DAT_00f94308,0xc);
    if (cVar2 != '\0') {
      puStack_84 = (undefined4 *)0x3f000000;
    }
    puStack_80 = (undefined4 *)FUN_0068ace0();
    if ((int)puStack_80 <= 0x7fffffff) {
      if ((int)puStack_80 < -0x80000000) {
        puStack_80 = (undefined4 *)0x80000000;
      }
    }
    else {
      puStack_80 = (undefined4 *)0x7fffffff;
    }
    FUN_008fed10();
    if ((float)puStack_84 == 0.5) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c = 2;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c = 0xffffffff;
      }
      local_7c = 0x14;
      FUN_005740f0(&local_7c);
      if (puStack_84 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar5 = FUN_004068f0();
      uStack_c = 3;
      uVar3 = 1;
    }
    else {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack_c = 4;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        uStack_c = CONCAT31(uStack_c._1_3_,3);
      }
      puStack_84 = (undefined4 *)0x13;
      FUN_005740f0(&puStack_84);
      if (puStack_80 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      uVar5 = FUN_004068f0();
      uStack_c = 5;
      uVar3 = 2;
    }
    uStack_70 = (uint)uStack_70._2_2_ << 0x10;
    uStack_5c = 7;
    uStack_60 = 0;
    local_7c = uVar3;
    FUN_00402800(uVar5);
    uStack_c = 6;
    if ((uVar3 & 2) != 0) {
      uVar3 = uVar3 & 0xfffffffd;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      uStack_40 = 7;
      uStack_44 = 0;
      uStack_54 = uStack_54 & 0xffff0000;
    }
    uStack_c = CONCAT31(uStack_c._1_3_,8);
    if ((uVar3 & 1) != 0) {
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 7;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffff0000;
    }
    FUN_00757800(&uStack_70);
    (**(code **)(**(int **)(local_74 + 0x104) + 200))();
    if (7 < uStack_5c) {
      FUN_0089120c(uStack_70);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_84);
  return;
}

