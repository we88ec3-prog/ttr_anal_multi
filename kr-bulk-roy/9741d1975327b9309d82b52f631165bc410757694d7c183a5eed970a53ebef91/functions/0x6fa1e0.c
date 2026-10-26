
undefined4 FUN_006fa1e0(int param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  bool bVar6;
  bool bVar7;
  
  iVar4 = *(int *)(unaff_EDI + 8);
  bVar6 = false;
  bVar7 = false;
  if ((iVar4 != 0) && ((*(byte *)(iVar4 + 5) & 3) != 0)) {
    FUN_006f9f70(param_1,iVar4);
  }
  if ((((*(int *)(unaff_EDI + 8) != 0) && ((*(byte *)(*(int *)(unaff_EDI + 8) + 6) & 8) == 0)) &&
      (piVar2 = (int *)FUN_006fea60(3), piVar2 != (int *)0x0)) && (piVar2[2] == 4)) {
    pcVar3 = _strchr((char *)(*piVar2 + 0x10),0x6b);
    bVar6 = pcVar3 != (char *)0x0;
    pcVar3 = _strchr((char *)(*piVar2 + 0x10),0x76);
    bVar7 = pcVar3 != (char *)0x0;
    if ((bVar6) || (bVar7)) {
      *(byte *)(unaff_EDI + 5) = (bVar7 * '\x02' | bVar6) * '\b' | *(byte *)(unaff_EDI + 5) & 0xe7;
      *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(param_1 + 0x2c);
      *(int *)(param_1 + 0x2c) = unaff_EDI;
      if (bVar6) {
        if (bVar7) {
          return 1;
        }
      }
      else if (bVar7) goto LAB_006fa2e8;
    }
  }
  iVar4 = *(int *)(unaff_EDI + 0x1c);
  if (iVar4 != 0) {
    iVar5 = iVar4 << 4;
    do {
      iVar5 = iVar5 + -0x10;
      iVar4 = iVar4 + -1;
      if ((3 < *(int *)(*(int *)(unaff_EDI + 0xc) + 8 + iVar5)) &&
         (iVar1 = *(int *)(*(int *)(unaff_EDI + 0xc) + iVar5), (*(byte *)(iVar1 + 5) & 3) != 0)) {
        FUN_006f9f70(param_1,iVar1);
      }
    } while (iVar4 != 0);
  }
LAB_006fa2e8:
  iVar4 = 1 << (*(byte *)(unaff_EDI + 7) & 0x1f);
  if (iVar4 != 0) {
    iVar5 = iVar4 << 5;
    do {
      iVar5 = iVar5 + -0x20;
      piVar2 = (int *)(*(int *)(unaff_EDI + 0x10) + iVar5);
      iVar4 = iVar4 + -1;
      if (piVar2[2] == 0) {
        if (3 < piVar2[6]) {
          piVar2[6] = 0xb;
        }
      }
      else {
        if (((!bVar6) && (3 < piVar2[6])) && ((*(byte *)(piVar2[4] + 5) & 3) != 0)) {
          FUN_006f9f70(param_1,piVar2[4]);
        }
        if (((!bVar7) && (3 < piVar2[2])) && ((*(byte *)(*piVar2 + 5) & 3) != 0)) {
          FUN_006f9f70(param_1,*piVar2);
        }
      }
    } while (iVar4 != 0);
  }
  if ((!bVar6) && (!bVar7)) {
    return 0;
  }
  return 1;
}

