
void FUN_004a2c10(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  void **ppvVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  LPCWSTR lpCaption;
  undefined4 *puVar10;
  LPCWSTR ***lpText;
  int unaff_EDI;
  undefined4 *local_38;
  undefined4 *local_34;
  LPCWSTR **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917706;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = *(int *)(unaff_EDI + 0x10);
  local_14 = uVar6;
  ppvVar5 = &local_10;
  local_10 = ExceptionList;
  while( true ) {
    ExceptionList = ppvVar5;
    if (iVar3 == 0) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar7 = FUN_004a3110(uVar6);
    local_30[0] = (LPCWSTR **)((uint)local_30[0] & 0xffff0000);
    local_1c = 7;
    local_20 = 0;
    FUN_004026e0(uVar7,0,0xffffffff);
    local_8 = 0;
    if (*(int *)(unaff_EDI + 0x10) != 0) {
      puVar8 = *(undefined4 **)(*(int *)(unaff_EDI + 4) + *(int *)(unaff_EDI + 0xc) * 4);
      if (7 < (uint)puVar8[5]) {
        FUN_0089120c(*puVar8);
      }
      puVar8[5] = 7;
      puVar8[4] = 0;
      *(undefined2 *)puVar8 = 0;
      *(int *)(unaff_EDI + 0xc) = *(int *)(unaff_EDI + 0xc) + 1;
      if (*(uint *)(unaff_EDI + 8) <= *(uint *)(unaff_EDI + 0xc)) {
        *(undefined4 *)(unaff_EDI + 0xc) = 0;
      }
      piVar1 = (int *)(unaff_EDI + 0x10);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined4 *)(unaff_EDI + 0xc) = 0;
      }
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    cVar2 = *(char *)((int)DAT_00fe5b10[1] + 0x2d);
    puVar8 = (undefined4 *)DAT_00fe5b10[1];
    local_38 = DAT_00fe5b10;
    while (puVar10 = puVar8, cVar2 == '\0') {
      if ((int)puVar10[3] < 0x199) {
        puVar8 = (undefined4 *)puVar10[2];
        puVar10 = local_38;
      }
      else {
        puVar8 = (undefined4 *)*puVar10;
      }
      cVar2 = *(char *)((int)puVar8 + 0x2d);
      local_38 = puVar10;
    }
    if ((local_38 == DAT_00fe5b10) || (0x199 < (int)local_38[3])) {
      local_34 = DAT_00fe5b10;
      ppuVar9 = &local_34;
    }
    else {
      ppuVar9 = &local_38;
    }
    puVar8 = *ppuVar9;
    if (puVar8 == DAT_00fe5b10) break;
    lpCaption = (LPCWSTR)(puVar8 + 4);
    if (7 < (uint)puVar8[9]) {
      lpCaption = *(LPCWSTR *)lpCaption;
    }
    lpText = (LPCWSTR ***)local_30[0];
    if (local_1c < 8) {
      lpText = local_30;
    }
    MessageBoxW((HWND)0x0,(LPCWSTR)lpText,lpCaption,0);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    iVar3 = *(int *)(unaff_EDI + 0x10);
    ppvVar5 = ExceptionList;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

