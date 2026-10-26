
undefined4 * FUN_006ea440(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [15];
  
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar1 = *(int *)(iVar1 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (iVar1 == 0) {
    _memset(local_40,0,0x38);
    puVar3 = local_40;
    puVar4 = param_1;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    return param_1;
  }
  puVar3 = (undefined4 *)(iVar1 + 0x10);
  puVar4 = param_1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return param_1;
}

