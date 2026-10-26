
undefined4 FUN_0080ba60(int param_1,int param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  char *_Str1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  LPCRITICAL_SECTION local_20;
  int *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c3a8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x8c);
  local_20 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (DAT_00fba860 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return 1;
  }
  piVar5 = *(int **)(param_1 + 0x5c);
  piVar7 = (int *)*piVar5;
  iVar1 = *(int *)(param_2 + 4);
  local_28 = 1000000000;
  local_18 = 0;
  local_24 = 0;
  local_14 = 0;
  local_2c = piVar5;
  local_1c = piVar5;
  if (piVar7 != piVar5) {
    do {
      iVar4 = piVar7[2];
      if ((0 < *(int *)(iVar4 + 0x24)) ||
         ((*(int *)(iVar4 + 8) != 0 &&
          (iVar4 = (**(code **)(**(int **)(iVar4 + 8) + 0x10))(uVar3), iVar4 != 0)))) {
        local_14 = local_14 + 1;
        iVar4 = __stricmp(*(char **)(iVar1 + 8),*(char **)(*(int *)(piVar7[2] + 4) + 8));
        if (iVar4 == 0) {
          cVar2 = FUN_0080c500();
          if (cVar2 != '\0') {
            local_24 = local_24 + 1;
          }
          local_18 = local_18 + 1;
          iVar4 = FUN_0080b830();
          piVar5 = local_2c;
          if (iVar4 < local_28) {
            local_28 = iVar4;
            local_1c = piVar7;
          }
        }
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != piVar5);
  }
  if (local_1c == *(int **)(param_1 + 0x5c)) {
    FUN_006edab0(5,"Sound Ref-1: %d / Channels %d\n",local_18,local_14);
    FUN_006edab0(5,"- Group %s\n",*(undefined4 *)(*(int *)(param_2 + 4) + 8));
    LeaveCriticalSection(local_20);
    ExceptionList = local_10;
    return 1;
  }
  _Str1 = *(char **)(iVar1 + 8);
  if ((local_18 < *(int *)(_Str1 + 0x50)) && (local_24 < *(int *)(_Str1 + 0x54))) {
    FUN_006edab0(5,"Sound Ref3: %d / Channels %d / %d\n",*(undefined4 *)(iVar1 + 0x38),local_14,
                 *(undefined4 *)(param_1 + 0x60));
    FUN_006edab0(5,"- Group %s / %s\n",*(undefined4 *)(*(int *)(param_2 + 4) + 8),
                 *(undefined4 *)(*(int *)(local_1c[2] + 4) + 8));
    LeaveCriticalSection(local_20);
    ExceptionList = local_10;
    return 1;
  }
  iVar4 = __stricmp(_Str1,"Damage");
  if (iVar4 == 0) {
    puVar6 = (undefined4 *)(iVar1 + 0x18);
    local_30 = FUN_0080c1c0(puVar6);
    if ((local_30 == *(int *)(param_1 + 0x4c)) || (cVar2 = FUN_005436a0(), cVar2 != '\0')) {
      local_34 = *(int *)(param_1 + 0x4c);
      piVar5 = &local_34;
    }
    else {
      piVar5 = &local_30;
    }
    if ((*piVar5 != *(int *)(param_1 + 0x4c)) && (*(int *)(*piVar5 + 0x28) != 0)) {
      if (0xf < *(uint *)(iVar1 + 0x2c)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      FUN_006edab0(5,"Sound Key %s: Found recently played sound\n",puVar6);
      goto LAB_0080bd6b;
    }
  }
  iVar4 = FUN_0080b830();
  piVar5 = local_1c;
  iVar1 = local_28;
  if (local_28 < iVar4) {
    if (*(int *)(local_1c[2] + 8) != 0) {
      (**(code **)(**(int **)(local_1c[2] + 8) + 0x24))();
    }
    FUN_006edab0(5,"Sound Ref1: %d / Channels %d / %d ::",local_18,local_14,
                 *(undefined4 *)(param_1 + 0x60));
    puVar6 = (undefined4 *)(*(int *)(piVar5[2] + 4) + 0x18);
    if (0xf < *(uint *)(*(int *)(piVar5[2] + 4) + 0x2c)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_006edab0(5,"Stopping sound %s (%d < %d)\n",puVar6,iVar1,iVar4);
    LeaveCriticalSection(local_20);
    ExceptionList = local_10;
    return 1;
  }
  FUN_006edab0(5,"Sound Ref2 (restrict): %d / Channels %d / %d\n",local_18,local_14,
               *(undefined4 *)(param_1 + 0x60));
  FUN_006edab0(5,"- Group %s / %s\n",*(undefined4 *)(*(int *)(param_2 + 4) + 8),
               *(undefined4 *)(*(int *)(local_1c[2] + 4) + 8));
LAB_0080bd6b:
  LeaveCriticalSection(local_20);
  ExceptionList = local_10;
  return 0;
}

