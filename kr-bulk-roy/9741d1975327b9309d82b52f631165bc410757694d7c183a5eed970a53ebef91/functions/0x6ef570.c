
void FUN_006ef570(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,char *param_7,uint param_8)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  char ****ppppcVar6;
  rsize_t _DstSize;
  undefined4 *puVar7;
  int iVar8;
  undefined1 auStack_64 [4];
  uint local_60;
  int local_5c [2];
  int local_54;
  uint local_50;
  char ***apppcStack_4c [2];
  undefined4 local_44;
  int *local_40 [2];
  char ***local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00908030;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_44 = param_2;
  local_54 = param_5;
  local_60 = param_8;
  uVar5 = FUN_004318d0(&local_50);
  local_c = 0;
  local_40[0] = (int *)FUN_006efcf0(uVar5,uVar4);
  uVar4 = local_50;
  local_c = 0xffffffff;
  if (local_50 != 0) {
    std::_Lockit::_Lockit((_Lockit *)local_5c,0);
    iVar8 = *(int *)(uVar4 + 4);
    if ((iVar8 != 0) && (iVar8 != -1)) {
      *(int *)(uVar4 + 4) = iVar8 + -1;
    }
    iVar8 = *(int *)(uVar4 + 4);
    FUN_0087dd6f();
    puVar7 = (undefined4 *)(~-(uint)(iVar8 != 0) & uVar4);
    if (puVar7 != (undefined4 *)0x0) {
      (**(code **)*puVar7)(1);
    }
  }
  FUN_0042fd00(local_38);
  local_c = 1;
  cVar1 = *param_7;
  if ((cVar1 == '+') || (cVar1 == '-')) {
    local_5c[0] = 1;
  }
  else if ((cVar1 == '0') && ((param_7[1] == 'x' || (param_7[1] == 'X')))) {
    local_5c[0] = 2;
  }
  else {
    local_5c[0] = 0;
  }
  ppppcVar6 = (char ****)local_38[0];
  if (uStack_24 < 0x10) {
    ppppcVar6 = local_38;
  }
  if (*(char *)ppppcVar6 != '\x7f') {
    ppppcVar6 = (char ****)local_38[0];
    if (uStack_24 < 0x10) {
      ppppcVar6 = local_38;
    }
    if ('\0' < *(char *)ppppcVar6) {
      apppcStack_4c[0] = local_38[0];
      if (uStack_24 < 0x10) {
        apppcStack_4c[0] = (char ***)local_38;
      }
      cVar1 = *(char *)apppcStack_4c[0];
      uVar4 = local_60;
      while (((cVar1 != '\x7f' && ('\0' < cVar1)) && ((uint)(int)cVar1 < uVar4 - local_5c[0]))) {
        uVar4 = uVar4 - (int)cVar1;
        _DstSize = (local_60 - uVar4) + 1;
        _memmove_s(param_7 + uVar4 + 1,_DstSize,param_7 + uVar4,_DstSize);
        local_60 = local_60 + 1;
        param_7[uVar4] = '\0';
        if ('\0' < *(char *)((int)apppcStack_4c[0] + 1)) {
          apppcStack_4c[0] = (char ***)((int)apppcStack_4c[0] + 1);
        }
        cVar1 = *(char *)apppcStack_4c[0];
      }
    }
  }
  uVar4 = *(uint *)(local_54 + 0x20);
  if (((*(int *)(local_54 + 0x24) < 0) || ((*(int *)(local_54 + 0x24) < 1 && (uVar4 == 0)))) ||
     (uVar4 <= local_60)) {
    iVar8 = 0;
  }
  else {
    iVar8 = uVar4 - local_60;
  }
  uVar4 = *(uint *)(local_54 + 0x14) & 0x1c0;
  if (uVar4 != 0x40) {
    if (uVar4 == 0x100) {
      puVar7 = (undefined4 *)FUN_006efa50(param_1,apppcStack_4c,param_3,param_4,param_7,local_5c[0])
      ;
      local_60 = local_60 - local_5c[0];
      param_7 = param_7 + local_5c[0];
      puVar7 = (undefined4 *)FUN_006ef840(param_1,local_5c,*puVar7,puVar7[1],param_6,iVar8);
      param_3 = *puVar7;
      param_4 = puVar7[1];
    }
    else {
      puVar7 = (undefined4 *)FUN_006ef840(param_1,local_5c,param_3,param_4,param_6,iVar8);
      param_3 = *puVar7;
      param_4 = puVar7[1];
    }
    iVar8 = 0;
  }
  uVar3 = (**(code **)(*local_40[0] + 8))();
  local_50 = CONCAT31(local_50._1_3_,uVar3);
  puVar7 = (undefined4 *)FUN_006efac0(param_1,local_40,param_3,param_4,param_7,local_60,local_50);
  uVar5 = *puVar7;
  uVar2 = puVar7[1];
  *(undefined4 *)(local_54 + 0x20) = 0;
  *(undefined4 *)(local_54 + 0x24) = 0;
  FUN_006ef840(param_1,local_44,uVar5,uVar2,param_6,iVar8);
  if (0xf < uStack_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

