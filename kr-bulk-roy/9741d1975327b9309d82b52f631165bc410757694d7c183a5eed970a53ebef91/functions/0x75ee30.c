
void FUN_0075ee30(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 ******ppppppuVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  undefined4 uVar10;
  char *_Str1;
  int *in_ECX;
  undefined4 *puVar11;
  char ******_Str2;
  undefined4 *local_54;
  int *local_50;
  undefined4 *local_4c;
  int local_48;
  undefined4 *****local_44 [4];
  undefined4 local_34;
  uint local_30;
  char *****local_28 [4];
  undefined4 local_18;
  uint local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_50 = in_ECX;
  FUN_004297b0();
  ppppppuVar4 = (undefined4 ******)local_44[0];
  if (local_30 < 0x10) {
    ppppppuVar4 = local_44;
  }
  iVar5 = FUN_0072e2e0(ppppppuVar4);
  if (0xf < local_30) {
    FUN_0089120c(local_44[0]);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44[0] = (undefined4 *****)((uint)local_44[0] & 0xffffff00);
  while( true ) {
    if (iVar5 == 0) {
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    local_48 = 0;
    local_4c = (undefined4 *)0x0;
    FUN_00429860(&local_48);
    FUN_00429860(&local_4c);
    piVar6 = (int *)(**(code **)(*in_ECX + 0x28))(local_48);
    if (piVar6 == (int *)0x0) break;
    local_48 = 0;
    FUN_00429860(&local_48);
    iVar7 = (**(code **)(*piVar6 + 4))();
    if ((local_48 != iVar7) ||
       (cVar3 = (**(code **)(*piVar6 + 0x14))(iVar5), puVar2 = local_4c, cVar3 == '\0')) break;
    puVar11 = (undefined4 *)((undefined4 *)local_50[2])[1];
    piVar6 = local_50 + 1;
    cVar3 = *(char *)((int)puVar11 + 0x15);
    puVar1 = (undefined4 *)local_50[2];
    while (cVar3 == '\0') {
      if ((undefined4 *)puVar11[3] < local_4c) {
        puVar8 = (undefined4 *)puVar11[2];
        puVar11 = puVar1;
      }
      else {
        puVar8 = (undefined4 *)*puVar11;
      }
      puVar1 = puVar11;
      puVar11 = puVar8;
      cVar3 = *(char *)((int)puVar8 + 0x15);
    }
    local_4c = puVar1;
    if ((puVar1 == (undefined4 *)local_50[2]) || (puVar2 < (undefined4 *)puVar1[3])) {
      local_54 = (undefined4 *)local_50[2];
      ppuVar9 = &local_54;
    }
    else {
      ppuVar9 = &local_4c;
    }
    if (*ppuVar9 == (undefined4 *)local_50[2]) {
      uVar10 = FUN_0057ef20();
      FUN_0082f200(piVar6,uVar10);
    }
    FUN_004297b0();
    _Str2 = (char ******)local_28[0];
    if (local_14 < 0x10) {
      _Str2 = local_28;
    }
    for (iVar5 = *(int *)(iVar5 + 0x40); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      _Str1 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        _Str1 = *(char **)_Str1;
      }
      iVar7 = __stricmp(_Str1,(char *)_Str2);
      if (iVar7 == 0) goto LAB_0075efc3;
    }
    iVar5 = 0;
LAB_0075efc3:
    if (0xf < local_14) {
      FUN_0089120c(local_28[0]);
    }
    local_14 = 0xf;
    local_18 = 0;
    local_28[0] = (char *****)((uint)local_28[0] & 0xffffff00);
    in_ECX = local_50;
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

