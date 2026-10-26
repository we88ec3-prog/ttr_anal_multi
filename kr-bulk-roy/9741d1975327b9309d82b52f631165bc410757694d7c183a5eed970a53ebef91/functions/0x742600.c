
void FUN_00742600(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  char cVar4;
  wchar_t *_Str2;
  uint uVar5;
  undefined4 *puVar6;
  wchar_t *_Str1;
  undefined4 *puVar7;
  bool bVar8;
  int iVar9;
  
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar8 = true;
  cVar4 = *(char *)((int)puVar6 + 0x39);
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar4 == '\0') {
    uVar1 = puVar6[7];
    _Str2 = (wchar_t *)(puVar6 + 3);
    if (7 < (uint)puVar6[8]) {
      _Str2 = *(wchar_t **)_Str2;
    }
    uVar2 = *(uint *)(param_3 + 0x1c);
    uVar5 = uVar2;
    if (uVar1 <= uVar2) {
      uVar5 = uVar1;
    }
    if (*(uint *)(param_3 + 0x20) < 8) {
      _Str1 = (wchar_t *)(param_3 + 0xc);
    }
    else {
      _Str1 = *(wchar_t **)(param_3 + 0xc);
    }
    uVar5 = __wcsnicmp(_Str1,_Str2,uVar5);
    if (uVar5 == 0) {
      if (uVar2 < uVar1) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(uVar2 != uVar1);
      }
    }
    bVar8 = (int)uVar5 < 0;
    if (bVar8) {
      puVar7 = (undefined4 *)*puVar6;
    }
    else {
      puVar7 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar7;
    cVar4 = *(char *)((int)puVar7 + 0x39);
  }
  if (bVar8) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar8 = true;
      iVar9 = param_3;
      goto LAB_007426ab;
    }
    FUN_00742a50();
  }
  iVar9 = param_3;
  cVar4 = FUN_007418b0();
  if (cVar4 == '\0') {
    FUN_0073f080(iVar9 + 0xc);
    FUN_0089120c(iVar9);
    *param_2 = puVar3;
    *(undefined1 *)(param_2 + 1) = 0;
    return;
  }
LAB_007426ab:
  puVar6 = (undefined4 *)FUN_00742720(&param_3,bVar8,iVar9);
  *param_2 = *puVar6;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}

