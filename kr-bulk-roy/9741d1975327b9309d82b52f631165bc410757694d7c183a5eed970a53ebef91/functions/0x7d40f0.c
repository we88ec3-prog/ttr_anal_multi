
void FUN_007d40f0(char *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char *_Str1;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  uint uVar6;
  
  uVar6 = 0;
  if (*(int *)(unaff_ESI + 0x7c) - *(int *)(unaff_ESI + 0x78) >> 3 != 0) {
    while( true ) {
      iVar3 = *(int *)(*(int *)(unaff_ESI + 0x78) + 4 + uVar6 * 8);
      piVar1 = (int *)(*(int *)(unaff_ESI + 0x78) + uVar6 * 8);
      _Str1 = (char *)(iVar3 + 8);
      if (0xf < *(uint *)(iVar3 + 0x1c)) {
        _Str1 = *(char **)_Str1;
      }
      iVar3 = __stricmp(_Str1,param_1);
      if (iVar3 == 0) break;
      uVar6 = uVar6 + 1;
      if ((uint)(*(int *)(unaff_ESI + 0x7c) - *(int *)(unaff_ESI + 0x78) >> 3) <= uVar6) {
        return;
      }
    }
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      puVar2 = *(undefined4 **)(unaff_ESI + 0x7c);
      puVar4 = (undefined4 *)(*(int *)(unaff_ESI + 0x78) + 8 + uVar6 * 8);
      if (puVar4 != puVar2) {
        puVar5 = puVar4 + -2;
        do {
          *puVar5 = *puVar4;
          puVar5[1] = puVar4[1];
          puVar4 = puVar4 + 2;
          puVar5 = puVar5 + 2;
        } while (puVar4 != puVar2);
      }
      *(int *)(unaff_ESI + 0x7c) = *(int *)(unaff_ESI + 0x7c) + -8;
    }
  }
  return;
}

