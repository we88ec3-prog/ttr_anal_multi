
void FUN_006aec80(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int *piVar5;
  int unaff_EDI;
  int *local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  uint local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093c260;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_60;
  ExceptionList = &local_14;
  if (in_ECX == 0) {
    FUN_00757710(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
  }
  else {
    local_5c = in_ECX;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    uVar4 = 0;
    uVar2 = *(int *)(DAT_00fab130 + 0x5f00) - *(int *)(DAT_00fab130 + 0x5efc) >> 2;
    if (uVar2 != 0) {
      local_60 = *(int **)(DAT_00fab130 + 0x5efc);
      piVar5 = local_60;
      do {
        if (*(int *)*piVar5 == in_ECX) {
          piVar5 = (int *)local_60[uVar4];
          goto LAB_006aed34;
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar4 < uVar2);
    }
    piVar5 = (int *)0x0;
LAB_006aed34:
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    piVar1 = DAT_00f93930;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    local_60 = piVar1;
    FUN_008438c0(&local_60);
    if (local_58 == DAT_00fab14c) {
      local_60 = (int *)0x0;
    }
    else {
      local_60 = *(int **)(local_58 + 0x10);
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 3;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    FUN_004f6a30(local_5c);
    FUN_00757710();
    uVar3 = FUN_00665560();
    local_c = 4;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    uVar3 = FUN_00665560();
    local_c = 5;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    uVar3 = FUN_00665560();
    local_c = 6;
    FUN_00757800(uVar3);
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    if (*local_60 == *piVar5) {
      uVar3 = 0xff00ff00;
    }
    else {
      uVar3 = 0xffffffff;
    }
    *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = uVar3;
    *(undefined4 *)(*(int *)(unaff_EDI + 0x24c) + 0x154) = uVar3;
    *(undefined4 *)(*(int *)(unaff_EDI + 0x250) + 0x154) = uVar3;
    *(undefined4 *)(*(int *)(unaff_EDI + 0x254) + 0x154) = uVar3;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_60);
  return;
}

