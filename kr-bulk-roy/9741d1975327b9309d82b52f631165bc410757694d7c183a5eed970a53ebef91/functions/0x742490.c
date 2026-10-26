
void FUN_00742490(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  wchar_t *_Str2;
  uint uVar6;
  undefined4 *puVar7;
  wchar_t *_Str1;
  undefined4 *puVar8;
  bool bVar9;
  
  iVar4 = param_3;
  puVar7 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar9 = true;
  cVar5 = *(char *)((int)puVar7 + 0x9d);
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar5 == '\0') {
    uVar1 = puVar7[7];
    _Str2 = (wchar_t *)(puVar7 + 3);
    if (7 < (uint)puVar7[8]) {
      _Str2 = *(wchar_t **)_Str2;
    }
    uVar2 = *(uint *)(iVar4 + 0x1c);
    uVar6 = uVar2;
    if (uVar1 <= uVar2) {
      uVar6 = uVar1;
    }
    if (*(uint *)(iVar4 + 0x20) < 8) {
      _Str1 = (wchar_t *)(iVar4 + 0xc);
    }
    else {
      _Str1 = *(wchar_t **)(iVar4 + 0xc);
    }
    uVar6 = __wcsnicmp(_Str1,_Str2,uVar6);
    if (uVar6 == 0) {
      if (uVar2 < uVar1) {
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = (uint)(uVar2 != uVar1);
      }
    }
    bVar9 = (int)uVar6 < 0;
    if (bVar9) {
      puVar8 = (undefined4 *)*puVar7;
    }
    else {
      puVar8 = (undefined4 *)puVar7[2];
    }
    puVar3 = puVar7;
    puVar7 = puVar8;
    cVar5 = *(char *)((int)puVar8 + 0x9d);
  }
  if (bVar9) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar7 = (undefined4 *)FUN_00742890(&param_3,1,iVar4);
      *param_2 = *puVar7;
      *(undefined1 *)(param_2 + 1) = 1;
      return;
    }
    FUN_00742ab0();
  }
  cVar5 = FUN_007418b0();
  if (cVar5 != '\0') {
    puVar7 = (undefined4 *)FUN_00742890(&param_3,bVar9,iVar4);
    *param_2 = *puVar7;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  FUN_0073e5e0();
  if (7 < *(uint *)(iVar4 + 0x20)) {
    FUN_0089120c(*(undefined4 *)(iVar4 + 0xc));
  }
  *(undefined4 *)(iVar4 + 0x20) = 7;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  *(undefined2 *)(iVar4 + 0xc) = 0;
  FUN_0089120c(iVar4);
  *param_2 = puVar3;
  *(undefined1 *)(param_2 + 1) = 0;
  return;
}

