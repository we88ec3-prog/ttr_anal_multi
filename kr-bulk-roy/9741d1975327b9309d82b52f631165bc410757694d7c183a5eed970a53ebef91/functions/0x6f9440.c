
int FUN_006f9440(int param_1,int *param_2)

{
  int *piVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_EDI;
  int local_c;
  
  iVar6 = 1 << (*(byte *)(unaff_EDI + 7) & 0x1f);
  iVar7 = 0;
  local_c = 0;
  if (iVar6 != 0) {
    iVar8 = iVar6 << 5;
    do {
      iVar4 = *(int *)(unaff_EDI + 0x10);
      iVar8 = iVar8 + -0x20;
      iVar6 = iVar6 + -1;
      if (*(int *)(iVar4 + 8 + iVar8) != 0) {
        if (((*(int *)(iVar4 + 0x18 + iVar8) == 3) &&
            (dVar2 = *(double *)(iVar4 + 0x10 + iVar8), iVar4 = (int)ROUND(dVar2),
            dVar2 == (double)iVar4)) && (iVar4 - 1U < 0x4000000)) {
          iVar5 = -1;
          for (uVar3 = iVar4 - 1; 0xff < uVar3; uVar3 = uVar3 >> 8) {
            iVar5 = iVar5 + 8;
          }
          piVar1 = (int *)(param_1 + 4 + ((uint)(byte)(&DAT_00c0bfd8)[uVar3] + iVar5) * 4);
          *piVar1 = *piVar1 + 1;
          iVar4 = 1;
        }
        else {
          iVar4 = 0;
        }
        iVar7 = iVar7 + iVar4;
        local_c = local_c + 1;
      }
    } while (iVar6 != 0);
    *param_2 = *param_2 + iVar7;
    return local_c;
  }
  *param_2 = *param_2;
  return 0;
}

