
void FUN_006221d0(void)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  int *piVar7;
  uint uVar8;
  int local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  int *local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092d75e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = in_ECX;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(local_14);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb91d1 == '\0') {
    piVar7 = *(int **)(in_ECX + 0xec);
  }
  else {
    piVar7 = *(int **)(in_ECX + 0xf0);
  }
  (**(code **)(*piVar7 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb9225 == '\0') {
    piVar7 = *(int **)(in_ECX + 0x10c);
  }
  else {
    piVar7 = *(int **)(in_ECX + 0x108);
  }
  (**(code **)(*piVar7 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 2;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb90f9 == '\0') {
    piVar7 = *(int **)(in_ECX + 0xf8);
  }
  else {
    piVar7 = *(int **)(in_ECX + 0xf4);
  }
  (**(code **)(*piVar7 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 3;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  cVar3 = DAT_00fb92c9;
  if (DAT_00fb92c9 == ' ') {
    piVar7 = *(int **)(in_ECX + 0xfc);
  }
  else {
    piVar7 = *(int **)(in_ECX + 0x100);
  }
  (**(code **)(*piVar7 + 0xa0))(1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 4;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb92e5 == '\x03') {
    piVar7 = *(int **)(in_ECX + 0x110);
  }
  else {
    piVar7 = *(int **)(in_ECX + 0x114);
  }
  (**(code **)(*piVar7 + 0xa0))(1);
  local_50 = 0xffffffff;
  if (cVar3 == ' ') {
    piVar7 = (int *)(DAT_00fb1318 + 0xbfec);
  }
  else {
    piVar7 = (int *)(DAT_00fb1318 + 0xbffc);
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x104) + 0x24c);
  local_54 = piVar7;
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710();
  local_60 = 0;
  if (piVar7[1] - *piVar7 >> 4 != 0) {
    local_64 = 0x16;
    local_5c = 0;
    do {
      iVar1 = local_5c;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_8 = 5;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_8 = 0xffffffff;
      }
      if ((int)DAT_00fb92aa == *(int *)(iVar1 + *piVar7)) {
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_8 = 6;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_8 = 0xffffffff;
        }
        if ((int)DAT_00fb92ba == *(int *)(iVar1 + 4 + *piVar7)) {
          local_50 = local_60;
        }
      }
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 7;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      FUN_005740f0(&local_64);
      if (local_68 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar4 = (undefined4 *)(local_68 + 0x10);
      if (7 < *(uint *)(local_68 + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      uVar5 = FUN_00625a50(puVar4);
      local_8 = 8;
      iVar1 = *(int *)(local_58 + 0x104);
      iVar6 = *(int *)(iVar1 + 0x24c);
      if (iVar6 != 0) {
        iVar6 = *(int *)(iVar6 + 0xcc);
        if (iVar6 == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = FUN_0075d370(*(undefined4 *)(iVar6 + 0xe4));
        }
        iVar1 = *(int *)(*(int *)(iVar1 + 0x24c) + 0xcc);
        if (iVar1 != 0) {
          for (piVar7 = *(int **)(iVar1 + 0xa8);
              (piVar7 != *(int **)(iVar1 + 0xac) && (*(int *)(*piVar7 + 0x20) != iVar6));
              piVar7 = piVar7 + 1) {
          }
        }
        FUN_00757800(uVar5);
      }
      local_8 = 0xffffffff;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_5c = local_5c + 0x10;
      local_60 = local_60 + 1;
      piVar7 = local_54;
      in_ECX = local_58;
    } while (local_60 < (uint)(local_54[1] - *local_54 >> 4));
  }
  FUN_0075cd30(*(undefined4 *)(in_ECX + 0x104));
  iVar1 = *(int *)(*(int *)(in_ECX + 0x104) + 0x24c);
  if (iVar1 != 0) {
    FUN_00749920(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
  local_50 = 0xf;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 9;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058f1a0(&DAT_00faaf80);
  uVar8 = ((int)local_50 < 1) - 1 & local_50;
  if (0x27 < (int)uVar8) {
    uVar8 = 0x28;
  }
  piVar7 = *(int **)(local_58 + 0x11c);
  pcVar2 = *(code **)(*piVar7 + 0x128);
  piVar7[0x31] = uVar8;
  (*pcVar2)();
  (**(code **)(*piVar7 + 200))();
  uVar5 = FUN_0040ef80();
  local_8 = 10;
  FUN_00757800(uVar5);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  local_30 = local_30 & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  (**(code **)(**(int **)(local_58 + 0x120) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

