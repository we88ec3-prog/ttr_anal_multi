
undefined4 * FUN_005c78c0(int param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  undefined4 *puVar9;
  
  iVar4 = param_3;
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar2 = true;
  cVar1 = *(char *)((int)puVar6 + 0x2d);
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    pwVar7 = (wchar_t *)(puVar6 + 3);
    if (7 < (uint)puVar6[8]) {
      pwVar7 = *(wchar_t **)pwVar7;
    }
    if (*(uint *)(iVar4 + 0x20) < 8) {
      pwVar8 = (wchar_t *)(iVar4 + 0xc);
    }
    else {
      pwVar8 = *(wchar_t **)(iVar4 + 0xc);
    }
    iVar5 = __wcsicmp(pwVar8,pwVar7);
    bVar2 = 0 < iVar5;
    if (bVar2) {
      puVar9 = (undefined4 *)*puVar6;
    }
    else {
      puVar9 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar9;
    cVar1 = *(char *)((int)puVar9 + 0x2d);
  }
  if (bVar2) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar6 = (undefined4 *)FUN_005c7a10(&param_3,1,iVar4);
      *param_2 = *puVar6;
      *(undefined1 *)(param_2 + 1) = 1;
      return param_2;
    }
    FUN_00574e80();
  }
  pwVar7 = (wchar_t *)(puVar3 + 3);
  if (*(uint *)(iVar4 + 0x20) < 8) {
    pwVar8 = (wchar_t *)(iVar4 + 0xc);
  }
  else {
    pwVar8 = *(wchar_t **)(iVar4 + 0xc);
  }
  if (7 < (uint)puVar3[8]) {
    pwVar7 = *(wchar_t **)pwVar7;
  }
  iVar5 = __wcsicmp(pwVar7,pwVar8);
  if (0 < iVar5) {
    puVar6 = (undefined4 *)FUN_005c7a10(&param_3,bVar2,iVar4);
    *param_2 = *puVar6;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
  if (7 < *(uint *)(iVar4 + 0x20)) {
    FUN_0089120c(*(undefined4 *)(iVar4 + 0xc));
  }
  *(undefined4 *)(iVar4 + 0x20) = 7;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  *(undefined2 *)(iVar4 + 0xc) = 0;
  FUN_0089120c(iVar4);
  *param_2 = puVar3;
  *(undefined1 *)(param_2 + 1) = 0;
  return param_2;
}

