
void FUN_0042fe90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,char *param_7,uint param_8)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 uVar6;
  char ****ppppcVar7;
  rsize_t _DstSize;
  undefined4 *puVar8;
  int iVar9;
  undefined1 auStack_64 [4];
  uint local_60;
  int iStack_5c;
  char ***local_58 [2];
  undefined4 local_50;
  int local_4c;
  uint local_48;
  undefined4 local_44;
  int *local_40 [2];
  char ***local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090b890;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_50 = param_1;
  local_44 = param_2;
  local_4c = param_5;
  local_60 = param_8;
  uVar6 = FUN_004318d0(&local_48);
  local_c = 0;
  local_40[0] = (int *)FUN_00430690(uVar6,uVar5);
  local_c = 0xffffffff;
  if (local_48 != 0) {
    std::_Lockit::_Lockit((_Lockit *)local_58,0);
    iVar9 = *(int *)(local_48 + 4);
    if ((iVar9 != 0) && (iVar9 != -1)) {
      *(int *)(local_48 + 4) = iVar9 + -1;
    }
    iVar9 = *(int *)(local_48 + 4);
    FUN_0087dd6f();
    puVar8 = (undefined4 *)(~-(uint)(iVar9 != 0) & local_48);
    if (puVar8 != (undefined4 *)0x0) {
      (**(code **)*puVar8)(1);
    }
  }
  FUN_0042fd00(local_38);
  local_c = 1;
  cVar1 = *param_7;
  if ((cVar1 == '+') || (cVar1 == '-')) {
    iStack_5c = 1;
  }
  else if ((cVar1 == '0') && ((param_7[1] == 'x' || (param_7[1] == 'X')))) {
    iStack_5c = 2;
  }
  else {
    iStack_5c = 0;
  }
  ppppcVar7 = (char ****)local_38[0];
  if (uStack_24 < 0x10) {
    ppppcVar7 = local_38;
  }
  if (*(char *)ppppcVar7 != '\x7f') {
    ppppcVar7 = (char ****)local_38[0];
    if (uStack_24 < 0x10) {
      ppppcVar7 = local_38;
    }
    if ('\0' < *(char *)ppppcVar7) {
      local_58[0] = local_38[0];
      if (uStack_24 < 0x10) {
        local_58[0] = (char ***)local_38;
      }
      cVar1 = *(char *)local_58[0];
      uVar5 = local_60;
      while (((cVar1 != '\x7f' && ('\0' < cVar1)) && ((uint)(int)cVar1 < uVar5 - iStack_5c))) {
        uVar5 = uVar5 - (int)cVar1;
        _DstSize = (local_60 - uVar5) + 1;
        _memmove_s(param_7 + uVar5 + 1,_DstSize,param_7 + uVar5,_DstSize);
        local_60 = local_60 + 1;
        param_7[uVar5] = '\0';
        if ('\0' < *(char *)((int)local_58[0] + 1)) {
          local_58[0] = (char ***)((int)local_58[0] + 1);
        }
        cVar1 = *(char *)local_58[0];
      }
    }
  }
  uVar5 = *(uint *)(local_4c + 0x20);
  if (((*(int *)(local_4c + 0x24) < 0) || ((*(int *)(local_4c + 0x24) < 1 && (uVar5 == 0)))) ||
     (uVar5 <= local_60)) {
    iVar9 = 0;
  }
  else {
    iVar9 = uVar5 - local_60;
  }
  uVar5 = *(uint *)(local_4c + 0x14) & 0x1c0;
  if (uVar5 != 0x40) {
    if (uVar5 == 0x100) {
      puVar8 = (undefined4 *)FUN_0042fd20(local_50,local_58,param_3,param_4,param_7,iStack_5c);
      param_7 = param_7 + iStack_5c;
      local_60 = local_60 - iStack_5c;
      puVar8 = (undefined4 *)FUN_00430960(local_50,local_58,*puVar8,puVar8[1],param_6,iVar9);
      param_3 = *puVar8;
      param_4 = puVar8[1];
    }
    else {
      puVar8 = (undefined4 *)FUN_00430960(local_50,local_58,param_3,param_4,param_6,iVar9);
      param_3 = *puVar8;
      param_4 = puVar8[1];
    }
    iVar9 = 0;
  }
  uVar4 = (**(code **)(*local_40[0] + 8))();
  uVar3 = local_50;
  puVar8 = (undefined4 *)FUN_0042fdf0(local_50,local_40,param_3,param_4,param_7,local_60,uVar4);
  uVar6 = *puVar8;
  uVar2 = puVar8[1];
  *(undefined4 *)(local_4c + 0x20) = 0;
  *(undefined4 *)(local_4c + 0x24) = 0;
  FUN_00430960(uVar3,local_44,uVar6,uVar2,param_6,iVar9);
  if (0xf < uStack_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

