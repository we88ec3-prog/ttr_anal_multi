
void FUN_0042d0d0(int param_1,char param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char unaff_BL;
  int local_5c;
  int local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945628;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffff98);
  iVar3 = param_1;
  if ((*(byte *)(param_1 + 0x28) & 0x10) == 0) {
    if (*(int *)(param_1 + 0x60) == 0) goto LAB_0042d147;
    iVar3 = FUN_00745c20();
  }
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) &&
      ((*(uint *)(iVar3 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar3 + 0x60) != 0)) {
    FUN_0074a010(iVar3);
  }
LAB_0042d147:
  *(char *)(param_1 + 0x159) = param_2;
  if (param_2 == '\0') {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 4;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_c = 0xffffffff;
    }
    local_5c = DAT_00fb7258;
    if (DAT_00fb7258 != 0) {
      iVar3 = *(int *)(param_1 + 0xf8);
      if (*(char *)(iVar3 + 0x141) == '\0') {
        FUN_00757710();
      }
      else {
        FUN_006edb10("Not supported operation");
      }
      *(undefined4 *)(iVar3 + 0x168) = 0;
      *(undefined4 *)(iVar3 + 0x160) = 0;
      *(undefined4 *)(iVar3 + 0x164) = 0;
      *(undefined4 *)(iVar3 + 0x14c) = 0;
      (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
      FUN_00420070();
      local_c = 5;
      iVar3 = *(int *)(param_1 + 0xfc);
      if (*(char *)(iVar3 + 0x141) == '\0') {
        FUN_00757710();
      }
      else {
        FUN_006edb10("Not supported operation");
      }
      *(undefined4 *)(iVar3 + 0x168) = 0;
      *(undefined4 *)(iVar3 + 0x160) = 0;
      *(undefined4 *)(iVar3 + 0x164) = 0;
      *(undefined4 *)(iVar3 + 0x14c) = 0;
      local_c = 0xffffffff;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      uStack_54 = uStack_54 & 0xffff0000;
      uStack_40 = 7;
      uStack_44 = 0;
      (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
      local_5c = CONCAT31(local_5c._1_3_,0 < *(int *)(local_5c + 0x24));
      (**(code **)(**(int **)(param_1 + 0x104) + 0xa0))(local_5c);
      (**(code **)(**(int **)(param_1 + 0x108) + 0xa0))(unaff_BL == '\0');
    }
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    uVar2 = DAT_00f93930;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 1;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_5c = 0x235;
    FUN_005740f0(&local_5c);
    if (local_58 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_004f6a30(uVar2);
    FUN_004ed610();
    local_c = 3;
    iVar3 = *(int *)(param_1 + 0xf8);
    if (*(char *)(iVar3 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar3 + 0x168) = 0;
    *(undefined4 *)(iVar3 + 0x160) = 0;
    *(undefined4 *)(iVar3 + 0x164) = 0;
    *(undefined4 *)(iVar3 + 0x14c) = 0;
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  }
  FUN_0042dc60(param_1);
  *(char *)(param_1 + 0x159) = param_2;
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

