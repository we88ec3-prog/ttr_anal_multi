
void FUN_005d6240(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  undefined1 auStack_88 [20];
  undefined4 uStack_74;
  undefined1 *puStack_60;
  undefined1 *puStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093f2f8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_60;
  ExceptionList = &local_14;
  if (*(int *)(unaff_EDI + 0x118) == 0) {
    FUN_00757710();
    FUN_00757710();
    goto LAB_005d65a0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    uStack_74 = 0x5d62a7;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x104) + 0x24c);
  local_58 = 0;
  if (iVar1 == 0) {
LAB_005d63a8:
    pcVar2 = *(code **)(**(int **)(unaff_EDI + 0x114) + 0x90);
LAB_005d63b7:
    local_c = 0xffffffff;
    uStack_74 = 0x5d63b9;
    (*pcVar2)();
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == -1)) goto LAB_005d63a8;
    iVar1 = *(int *)(*(int *)(unaff_EDI + 0x104) + 0x24c);
    if (iVar1 == 0) {
LAB_005d631d:
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xcc);
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xdc);
      }
      if (iVar1 == 0) goto LAB_005d631d;
      iVar1 = *(int *)(iVar1 + 0x20);
    }
    local_58 = *(undefined4 *)(*(int *)(*(int *)(unaff_EDI + 0x118) + 0x54) + 8 + iVar1 * 0xc);
    if ((DAT_00fab100 & 1) == 0) {
      DAT_00fab100 = DAT_00fab100 | 1;
      local_c = 1;
      FUN_0049d6a0();
      uStack_74 = 0x5d635e;
      _atexit((_func_4879 *)&LAB_00bcce20);
    }
    local_c = 0xffffffff;
    if (((DAT_00fab104 & 0x20) != 0) || (DAT_00fab128 != '\0')) {
      pcVar2 = *(code **)(**(int **)(unaff_EDI + 0x114) + 0x90);
      goto LAB_005d63b7;
    }
    uStack_74 = 0x5d638d;
    (**(code **)(**(int **)(unaff_EDI + 0x114) + 0x90))();
  }
  puStack_60 = auStack_88;
  FUN_00412df0();
  local_c = 2;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,2);
  }
  puStack_5c = &DAT_00000105;
  FUN_005740f0(&puStack_5c);
  if (puStack_60 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar3 = (undefined4 *)(puStack_60 + 0x10);
  if (7 < *(uint *)(puStack_60 + 0x24)) {
    puVar3 = (undefined4 *)*puVar3;
  }
  local_c = 0xffffffff;
  FUN_00424c80(puVar3);
  local_c = 4;
  uStack_74 = 0x5d6470;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    uStack_74 = 0x5d6485;
    FUN_0089120c();
  }
  puStack_60 = auStack_88;
  FUN_00412df0();
  local_c = 5;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 6;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,5);
  }
  puStack_60 = (undefined1 *)0x105;
  FUN_005740f0(&puStack_60);
  if (puStack_5c == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar3 = (undefined4 *)(puStack_5c + 0x10);
  if (7 < *(uint *)(puStack_5c + 0x24)) {
    puVar3 = (undefined4 *)*puVar3;
  }
  local_c = 0xffffffff;
  FUN_00424c80(puVar3);
  local_c = 7;
  uStack_74 = 0x5d6543;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    uStack_74 = 0x5d655c;
    FUN_0089120c();
  }
  uStack_40 = 7;
  uStack_44 = 0;
  uStack_54 = uStack_54 & 0xffff0000;
LAB_005d65a0:
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x10c) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_60);
  return;
}

