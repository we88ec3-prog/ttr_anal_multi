
void FUN_006eeed0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,char ****param_7,void *param_8,int param_9,
                 int param_10,size_t param_11)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined4 uVar7;
  lconv *plVar8;
  void *pvVar9;
  char ****_Str;
  size_t sVar10;
  uint uVar11;
  undefined *puVar12;
  void *pvVar13;
  char ****ppppcVar14;
  undefined4 *puVar15;
  undefined1 auStack_94 [4];
  void *pvStack_90;
  size_t local_8c;
  int local_88;
  char cStack_84;
  undefined2 uStack_83;
  void *local_80;
  uint local_7c;
  int local_78 [2];
  int local_70;
  uint local_6c [2];
  int local_64;
  int *local_60 [2];
  undefined4 local_58;
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
  puStack_10 = &LAB_0090f368;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  local_58 = param_2;
  local_70 = param_9;
  local_80 = param_8;
  local_64 = param_5;
  local_88 = param_10;
  local_8c = param_11;
  uVar7 = FUN_004318d0(local_6c);
  local_c = 0;
  local_60[0] = (int *)FUN_006efcf0(uVar7,uVar6);
  uVar6 = local_6c[0];
  local_c = 0xffffffff;
  if (local_6c[0] != 0) {
    local_7c = local_6c[0];
    std::_Lockit::_Lockit((_Lockit *)local_78,0);
    iVar2 = *(int *)(uVar6 + 4);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      *(int *)(uVar6 + 4) = iVar2 + -1;
    }
    iVar2 = *(int *)(uVar6 + 4);
    FUN_0087dd6f();
    puVar15 = (undefined4 *)(~-(uint)(iVar2 != 0) & local_7c);
    if (puVar15 != (undefined4 *)0x0) {
      (**(code **)*puVar15)(1);
    }
  }
  piVar4 = local_60[0];
  FUN_0042fd00(local_38);
  local_c = 1;
  uVar5 = (**(code **)(*piVar4 + 8))();
  local_7c = CONCAT31(local_7c._1_3_,uVar5);
  uStack_40 = 0xf;
  sStack_44 = 0;
  apppcStack_54[0] = (char ***)((uint)apppcStack_54[0] & 0xffffff00);
  local_c = CONCAT31(local_c._1_3_,2);
  if ((*(char *)param_7 == '+') || (local_78[0] = 0, *(char *)param_7 == '-')) {
    local_78[0] = 1;
  }
  plVar8 = _localeconv();
  cStack_84 = *plVar8->decimal_point;
  uStack_83 = 0x65;
  pvVar9 = _memchr(param_7,0x65,param_11);
  pvStack_90 = _memchr(param_7,(int)cStack_84,param_11);
  if (pvStack_90 == (void *)0x0) {
    local_88 = 0;
  }
  ppppcVar14 = (char ****)local_38[0];
  if (uStack_24 < 0x10) {
    ppppcVar14 = local_38;
  }
  if (*(char *)ppppcVar14 != '\x7f') {
    ppppcVar14 = (char ****)local_38[0];
    if (uStack_24 < 0x10) {
      ppppcVar14 = local_38;
    }
    if ('\0' < *(char *)ppppcVar14) {
      FUN_00401fc0(param_7,param_11);
      pvVar13 = pvStack_90;
      if (pvVar9 == (void *)0x0) {
        FUN_00429630(local_88,0x30);
        pvVar13 = pvStack_90;
      }
      else {
        if (pvStack_90 == (void *)0x0) {
          FUN_00429630(local_80,0x30);
          local_80 = pvVar13;
        }
        FUN_004329c0((int)pvVar9 - (int)param_7,local_88,0x30);
      }
      if (pvVar13 == (void *)0x0) {
        FUN_00429630(local_80,0x30);
      }
      else {
        FUN_004329c0(((int)pvVar13 - (int)param_7) + 1,local_70,0x30);
        FUN_004329c0((int)pvVar13 - (int)param_7,local_80,0x30);
        local_70 = 0;
      }
      local_80 = (void *)0x0;
      ppppcVar14 = (char ****)local_38[0];
      if (uStack_24 < 0x10) {
        ppppcVar14 = local_38;
      }
      _Str = (char ****)apppcStack_54[0];
      if (uStack_40 < 0x10) {
        _Str = apppcStack_54;
      }
      sVar10 = _strcspn((char *)_Str,&cStack_84);
      cVar1 = *(char *)ppppcVar14;
      param_11 = sStack_44;
      while (((sStack_44 = param_11, cVar1 != '\x7f' && ('\0' < cVar1)) &&
             ((uint)(int)cVar1 < sVar10 - local_78[0]))) {
        sVar10 = sVar10 - (int)cVar1;
        FUN_004329c0(sVar10,1,0);
        if ('\0' < *(char *)((int)ppppcVar14 + 1)) {
          ppppcVar14 = (char ****)((int)ppppcVar14 + 1);
        }
        param_11 = sStack_44;
        cVar1 = *(char *)ppppcVar14;
      }
      param_7 = (char ****)apppcStack_54[0];
      if (uStack_40 < 0x10) {
        param_7 = apppcStack_54;
      }
      local_88 = 0;
      local_8c = param_11;
    }
  }
  uVar6 = *(uint *)(local_64 + 0x20);
  uVar11 = local_88 + param_11 + local_70 + (int)local_80;
  if (((*(int *)(local_64 + 0x24) < 0) || ((*(int *)(local_64 + 0x24) < 1 && (uVar6 == 0)))) ||
     (uVar6 <= uVar11)) {
    pvStack_90 = (void *)0x0;
  }
  else {
    pvStack_90 = (void *)(uVar6 - uVar11);
  }
  uVar6 = *(uint *)(local_64 + 0x14) & 0x1c0;
  if (uVar6 != 0x40) {
    if (uVar6 == 0x100) {
      if (local_78[0] != 0) {
        puVar15 = (undefined4 *)FUN_006efa50(param_1,local_78,param_3,param_4,param_7,1);
        param_3 = *puVar15;
        param_4 = puVar15[1];
        param_7 = (char ****)((int)param_7 + 1);
        param_11 = param_11 - 1;
        local_8c = param_11;
      }
      puVar15 = (undefined4 *)FUN_006ef840(param_1,local_78,param_3,param_4,param_6,pvStack_90);
      param_3 = *puVar15;
      param_4 = puVar15[1];
    }
    else {
      puVar15 = (undefined4 *)FUN_006ef840(param_1,local_78,param_3,param_4,param_6,pvStack_90);
      param_3 = *puVar15;
      param_4 = puVar15[1];
    }
    pvStack_90 = (void *)0x0;
  }
  pvVar9 = _memchr(param_7,(int)cStack_84,param_11);
  if (pvVar9 != (void *)0x0) {
    iVar2 = ((int)pvVar9 - (int)param_7) + 1;
    puVar15 = (undefined4 *)
              FUN_006efac0(param_1,local_78,param_3,param_4,param_7,(int)pvVar9 - (int)param_7,
                           local_7c);
    puVar15 = (undefined4 *)FUN_006ef840(param_1,local_78,*puVar15,puVar15[1],0x30,local_80);
    uVar7 = *puVar15;
    uVar3 = puVar15[1];
    uVar5 = (**(code **)(*local_60[0] + 4))();
    local_6c[0] = CONCAT31(local_6c[0]._1_3_,uVar5);
    puVar15 = (undefined4 *)FUN_006ef840(param_1,local_60,uVar7,uVar3,local_6c[0],1);
    puVar15 = (undefined4 *)FUN_006ef840(param_1,local_6c,*puVar15,puVar15[1],0x30,local_70);
    param_3 = *puVar15;
    param_7 = (char ****)((int)param_7 + iVar2);
    param_11 = local_8c - iVar2;
    param_4 = puVar15[1];
    local_8c = param_11;
  }
  pvVar9 = _memchr(param_7,0x65,param_11);
  if (pvVar9 != (void *)0x0) {
    iVar2 = ((int)pvVar9 - (int)param_7) + 1;
    puVar15 = (undefined4 *)
              FUN_006efac0(param_1,local_6c,param_3,param_4,param_7,(int)pvVar9 - (int)param_7,
                           local_7c);
    puVar15 = (undefined4 *)FUN_006ef840(param_1,local_6c,*puVar15,puVar15[1],0x30,local_88);
    local_88 = 0;
    puVar12 = &DAT_00bf94d4;
    if ((*(byte *)(local_64 + 0x14) & 4) == 0) {
      puVar12 = &DAT_00bf94d8;
    }
    puVar15 = (undefined4 *)FUN_006efa50(param_1,local_6c,*puVar15,puVar15[1],puVar12,1);
    param_3 = *puVar15;
    param_7 = (char ****)((int)param_7 + iVar2);
    param_11 = local_8c - iVar2;
    param_4 = puVar15[1];
    local_8c = param_11;
  }
  puVar15 = (undefined4 *)FUN_006efac0(param_1,local_6c,param_3,param_4,param_7,param_11,local_7c);
  puVar15 = (undefined4 *)FUN_006ef840(param_1,local_60,*puVar15,puVar15[1],0x30,local_88);
  uVar7 = *puVar15;
  uVar3 = puVar15[1];
  *(undefined4 *)(local_64 + 0x20) = 0;
  *(undefined4 *)(local_64 + 0x24) = 0;
  FUN_006ef840(param_1,local_58,uVar7,uVar3,param_6,pvStack_90);
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
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

