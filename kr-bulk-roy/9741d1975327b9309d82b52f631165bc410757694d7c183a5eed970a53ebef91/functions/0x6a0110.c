
void FUN_006a0110(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined1 auStack_74 [4];
  uint uStack_70;
  int iStack_6c;
  uint local_68;
  int iStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935a42;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  ExceptionList = &local_14;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_c = 0xffffffff;
  FUN_005359f0(&DAT_00fe1c2c,&local_68,DAT_00fe1c2c,DAT_00fe1c30);
  DAT_00fe1c24 = 0;
  DAT_00fe1c1c = 0;
  DAT_00fe1c20 = 0;
  iVar1 = *(int *)(param_1 + 0x108);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  iVar1 = *(int *)(param_1 + 0x10c);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0x10c) + 200))();
  iVar1 = *(int *)(param_1 + 0x110);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0x110) + 200))();
  FUN_00749920(*(undefined4 *)(param_1 + 0xec));
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  uStack_70 = 0x14c;
  FUN_005740f0(&uStack_70);
  if (iStack_6c != DAT_00fe5ac8) {
    puVar3 = (undefined4 *)(iStack_6c + 0x10);
    if (7 < *(uint *)(iStack_6c + 0x24)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    uVar4 = FUN_0040e460(puVar3);
    local_c = 2;
    FUN_00757800(uVar4);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x154) = 1;
    if ((DAT_00fe1bd8 & 1) == 0) {
      DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
      local_c = 3;
      FUN_00533f80();
      _atexit((_func_4879 *)&LAB_00bced30);
      local_c = 0xffffffff;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xfc) + 0x24c);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
      FUN_006438f0(iVar1);
    }
    FUN_00757710();
    FUN_005383a0(&DAT_00fe1bec,&iStack_64);
    local_c = 4;
    uStack_70 = 0;
    uVar7 = iStack_60 - iStack_64 >> 2;
    local_68 = uVar7;
    if (uVar7 != 0) {
      do {
        iStack_6c = FUN_00538e60();
        local_c._0_1_ = 5;
        iVar1 = *(int *)(param_1 + 0xfc);
        iVar5 = *(int *)(iVar1 + 0x24c);
        if (iVar5 != 0) {
          iVar5 = *(int *)(iVar5 + 0xcc);
          if (iVar5 == 0) {
            iVar5 = -1;
          }
          else {
            iVar5 = FUN_0075d370(*(undefined4 *)(iVar5 + 0xe4));
          }
          iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
          if (iVar1 != 0) {
            for (piVar6 = *(int **)(iVar1 + 0xa8);
                (piVar6 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar6 + 0x20) != iVar5));
                piVar6 = piVar6 + 1) {
            }
          }
          FUN_00757800(iStack_6c);
          uVar7 = local_68;
        }
        local_c = CONCAT31(local_c._1_3_,4);
        if (7 < uStack_40) {
          FUN_0089120c(uStack_54);
        }
        uStack_70 = uStack_70 + 1;
        uStack_40 = 7;
        uStack_44 = 0;
        uStack_54 = uStack_54 & 0xffff0000;
      } while (uStack_70 < uVar7);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xfc) + 0x24c);
    if (iVar1 != 0) {
      FUN_00749920(iVar1);
    }
    (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
    local_c = 0xffffffff;
    if (iStack_64 != 0) {
      FUN_0089120c(iStack_64);
    }
    iStack_64 = 0;
    iStack_60 = 0;
    uStack_5c = 0;
    FUN_006a05a0(param_1,0);
    FUN_006a0b60();
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_74);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

