
void FUN_0042f300(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,char ****param_7,int param_8,int param_9,int param_10,
                 size_t param_11)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  lconv *plVar6;
  char ****_Str;
  size_t sVar7;
  uint uVar8;
  undefined4 *puVar9;
  void *pvVar10;
  undefined *puVar11;
  int iVar12;
  char ****ppppcVar13;
  size_t local_94;
  void *pvStack_90;
  int local_8c;
  mbstate_t local_88;
  undefined4 *local_84;
  int local_80;
  char acStack_7c [4];
  char cStack_78;
  undefined2 uStack_77;
  void *apvStack_74 [2];
  undefined4 uStack_6c;
  int local_68;
  int local_64;
  int *local_60;
  undefined4 local_5c;
  uint local_58;
  char ***apppcStack_54 [4];
  size_t sStack_44;
  uint uStack_40;
  char ***local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00910ed8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  local_5c = param_2;
  local_68 = param_9;
  local_80 = param_8;
  local_64 = param_5;
  local_8c = param_10;
  local_94 = param_11;
  uVar5 = FUN_004318d0(&local_58);
  local_c = 0;
  local_60 = (int *)FUN_00430690(uVar5,uVar4);
  local_c = 0xffffffff;
  if (local_58 != 0) {
    local_84 = (undefined4 *)local_58;
    std::_Lockit::_Lockit((_Lockit *)&local_88,0);
    iVar12 = *(int *)((int)local_84 + 4);
    if ((iVar12 != 0) && (iVar12 != -1)) {
      *(int *)((int)local_84 + 4) = iVar12 + -1;
    }
    local_84 = (undefined4 *)(~-(uint)(*(int *)((int)local_84 + 4) != 0) & (uint)local_84);
    FUN_0087dd6f();
    if (local_84 != (undefined4 *)0x0) {
      (**(code **)*local_84)(1);
    }
  }
  FUN_0042fd00(local_38);
  local_c = 1;
  uVar4 = (**(code **)(*local_60 + 8))();
  local_84 = (undefined4 *)(uVar4 & 0xffff);
  uStack_40 = 0xf;
  sStack_44 = 0;
  apppcStack_54[0] = (char ***)((uint)apppcStack_54[0] & 0xffffff00);
  local_c = CONCAT31(local_c._1_3_,2);
  uStack_6c = 0;
  local_88 = 0;
  acStack_7c[0] = '0';
  __Mbrtowc((wchar_t *)&uStack_6c,acStack_7c,1,&local_88,(_Cvtvec *)(param_1 + 8));
  if ((*(char *)param_7 == '+') || (local_88 = 0, *(char *)param_7 == '-')) {
    local_88 = 1;
  }
  plVar6 = _localeconv();
  cStack_78 = *plVar6->decimal_point;
  uStack_77 = 0x65;
  apvStack_74[0] = _memchr(param_7,0x65,param_11);
  pvStack_90 = _memchr(param_7,(int)cStack_78,param_11);
  if (pvStack_90 == (void *)0x0) {
    local_8c = 0;
  }
  ppppcVar13 = (char ****)local_38[0];
  if (uStack_24 < 0x10) {
    ppppcVar13 = local_38;
  }
  if (*(char *)ppppcVar13 != '\x7f') {
    ppppcVar13 = (char ****)local_38[0];
    if (uStack_24 < 0x10) {
      ppppcVar13 = local_38;
    }
    if ('\0' < *(char *)ppppcVar13) {
      FUN_00401fc0(param_7,param_11);
      pvVar10 = apvStack_74[0];
      if (apvStack_74[0] == (void *)0x0) {
        FUN_00429630(local_8c,0x30);
      }
      else {
        if (pvStack_90 == (void *)0x0) {
          FUN_00429630(local_80,0x30);
          local_80 = 0;
        }
        FUN_004329c0((int)pvVar10 - (int)param_7,local_8c,0x30);
      }
      if (pvStack_90 == (void *)0x0) {
        FUN_00429630(local_80,0x30);
      }
      else {
        iVar12 = (int)pvStack_90 - (int)param_7;
        FUN_004329c0(iVar12 + 1,local_68,0x30);
        FUN_004329c0(iVar12,local_80,0x30);
        local_68 = 0;
      }
      local_80 = 0;
      ppppcVar13 = (char ****)local_38[0];
      if (uStack_24 < 0x10) {
        ppppcVar13 = local_38;
      }
      _Str = (char ****)apppcStack_54[0];
      if (uStack_40 < 0x10) {
        _Str = apppcStack_54;
      }
      sVar7 = _strcspn((char *)_Str,&cStack_78);
      cVar1 = *(char *)ppppcVar13;
      param_11 = sStack_44;
      while (((sStack_44 = param_11, cVar1 != '\x7f' && ('\0' < cVar1)) &&
             ((uint)(int)cVar1 < sVar7 - local_88))) {
        sVar7 = sVar7 - (int)cVar1;
        FUN_004329c0(sVar7,1,0);
        if ('\0' < *(char *)((int)ppppcVar13 + 1)) {
          ppppcVar13 = (char ****)((int)ppppcVar13 + 1);
        }
        param_11 = sStack_44;
        cVar1 = *(char *)ppppcVar13;
      }
      param_7 = (char ****)apppcStack_54[0];
      if (uStack_40 < 0x10) {
        param_7 = apppcStack_54;
      }
      local_8c = 0;
      local_94 = param_11;
    }
  }
  uVar4 = *(uint *)(local_64 + 0x20);
  uVar8 = param_11 + local_8c + local_68 + local_80;
  if (((*(int *)(local_64 + 0x24) < 0) || ((*(int *)(local_64 + 0x24) < 1 && (uVar4 == 0)))) ||
     (uVar4 <= uVar8)) {
    pvStack_90 = (void *)0x0;
  }
  else {
    pvStack_90 = (void *)(uVar4 - uVar8);
  }
  uVar4 = *(uint *)(local_64 + 0x14) & 0x1c0;
  if (uVar4 != 0x40) {
    if (uVar4 == 0x100) {
      if (local_88 != 0) {
        puVar9 = (undefined4 *)FUN_0042fd20(param_1,apvStack_74,param_3,param_4,param_7,1);
        param_3 = *puVar9;
        param_4 = puVar9[1];
        param_7 = (char ****)((int)param_7 + 1);
        param_11 = param_11 - 1;
        local_94 = param_11;
      }
      puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,param_3,param_4,param_6,pvStack_90);
      param_3 = *puVar9;
      param_4 = puVar9[1];
    }
    else {
      puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,param_3,param_4,param_6,pvStack_90);
      param_3 = *puVar9;
      param_4 = puVar9[1];
    }
    pvStack_90 = (void *)0x0;
  }
  pvVar10 = _memchr(param_7,(int)cStack_78,param_11);
  if (pvVar10 != (void *)0x0) {
    iVar12 = ((int)pvVar10 - (int)param_7) + 1;
    puVar9 = (undefined4 *)
             FUN_0042fdf0(param_1,apvStack_74,param_3,param_4,param_7,(int)pvVar10 - (int)param_7,
                          local_84);
    puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,*puVar9,puVar9[1],uStack_6c,local_80);
    uVar5 = *puVar9;
    uVar2 = puVar9[1];
    uVar3 = (**(code **)(*local_60 + 4))();
    puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,uVar5,uVar2,uVar3,1);
    puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,*puVar9,puVar9[1],uStack_6c,local_68);
    param_3 = *puVar9;
    param_7 = (char ****)((int)param_7 + iVar12);
    param_11 = local_94 - iVar12;
    param_4 = puVar9[1];
    local_94 = param_11;
  }
  pvVar10 = _memchr(param_7,0x65,param_11);
  if (pvVar10 != (void *)0x0) {
    iVar12 = ((int)pvVar10 - (int)param_7) + 1;
    puVar9 = (undefined4 *)
             FUN_0042fdf0(param_1,apvStack_74,param_3,param_4,param_7,(int)pvVar10 - (int)param_7,
                          local_84);
    puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,*puVar9,puVar9[1],uStack_6c,local_8c);
    local_8c = 0;
    puVar11 = &DAT_00bf94d4;
    if ((*(byte *)(local_64 + 0x14) & 4) == 0) {
      puVar11 = &DAT_00bf94d8;
    }
    puVar9 = (undefined4 *)FUN_0042fd20(param_1,apvStack_74,*puVar9,puVar9[1],puVar11,1);
    param_3 = *puVar9;
    param_7 = (char ****)((int)param_7 + iVar12);
    param_11 = local_94 - iVar12;
    param_4 = puVar9[1];
    local_94 = param_11;
  }
  puVar9 = (undefined4 *)FUN_0042fdf0(param_1,apvStack_74,param_3,param_4,param_7,param_11,local_84)
  ;
  puVar9 = (undefined4 *)FUN_00430960(param_1,apvStack_74,*puVar9,puVar9[1],uStack_6c,local_8c);
  uVar5 = *puVar9;
  uVar2 = puVar9[1];
  *(undefined4 *)(local_64 + 0x20) = 0;
  *(undefined4 *)(local_64 + 0x24) = 0;
  FUN_00430960(param_1,local_5c,uVar5,uVar2,param_6,pvStack_90);
  if (0xf < uStack_40) {
    FUN_0089120c(apppcStack_54[0]);
  }
  uStack_40 = 0xf;
  sStack_44 = 0;
  apppcStack_54[0] = (char ***)((uint)apppcStack_54[0] & 0xffffff00);
  if (0xf < uStack_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

