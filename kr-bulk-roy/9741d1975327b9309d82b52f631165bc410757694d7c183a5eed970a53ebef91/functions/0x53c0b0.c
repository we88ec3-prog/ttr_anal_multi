
int FUN_0053c0b0(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  uint uVar11;
  int unaff_EDI;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094787e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar6 = *(int *)(unaff_EDI + 8) - *(int *)(unaff_EDI + 4) >> 1;
  local_14 = 0;
  uVar11 = 0;
  iVar4 = 0;
  if (uVar6 != 0) {
    do {
      psVar9 = *(short **)(unaff_EDI + 4);
      sVar1 = psVar9[uVar11];
      uVar3 = *(int *)(unaff_EDI + 8) - (int)psVar9 >> 1;
      uVar7 = 0;
      if (uVar3 != 0) {
        do {
          if (*psVar9 == sVar1) {
            if ((DAT_00fb1378 & 1) == 0) {
              DAT_00fb1378 = DAT_00fb1378 | 1;
              local_8 = 0;
              FUN_00539c20(uVar2);
              _atexit((_func_4879 *)&LAB_00bccfb0);
              local_8 = 0xffffffff;
            }
            iVar4 = FUN_0053a9d0(sVar1);
            if (iVar4 != 0) {
              iVar10 = 0;
              iVar8 = *(int *)(iVar4 + 0x2c) - *(int *)(iVar4 + 0x28) >> 2;
              if (iVar8 != 0) {
                piVar5 = *(int **)(iVar4 + 0x28);
                do {
                  if (*(char *)(*piVar5 + 10) != '\0') {
                    iVar10 = iVar10 + 1;
                  }
                  piVar5 = piVar5 + 1;
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
              local_14 = local_14 + iVar10;
            }
            break;
          }
          uVar7 = uVar7 + 1;
          psVar9 = psVar9 + 1;
        } while (uVar7 < uVar3);
      }
      uVar11 = uVar11 + 1;
      iVar4 = local_14;
    } while (uVar11 < uVar6);
  }
  ExceptionList = local_10;
  return iVar4;
}

