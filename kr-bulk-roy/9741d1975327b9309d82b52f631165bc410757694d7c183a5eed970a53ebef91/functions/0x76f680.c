
void FUN_0076f680(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *unaff_ESI;
  int iVar9;
  
  piVar1 = (int *)unaff_ESI[0x20];
  if ((piVar1 != (int *)0x0) && (iVar9 = unaff_ESI[0x3b], iVar9 != 0)) {
    iVar2 = unaff_ESI[2];
    iVar3 = unaff_ESI[3];
    iVar4 = unaff_ESI[4];
    if (*(char *)((int)unaff_ESI + 0xf7) == '\0') {
      iVar5 = *(int *)(iVar9 + 0x14);
      iVar8 = piVar1[5];
      iVar9 = *(int *)(iVar9 + 0xc);
      iVar6 = piVar1[3];
      iVar7 = (**(code **)(*unaff_ESI + 0x174))();
      unaff_ESI[0x3c] = (iVar8 - iVar6) + iVar7 * 2 + (iVar5 - iVar9);
      iVar9 = *(int *)(unaff_ESI[0x3b] + 0x14);
      iVar5 = *(int *)(unaff_ESI[0x3b] + 0xc);
      iVar8 = (**(code **)(*unaff_ESI + 0x174))();
      iVar9 = iVar3 + iVar8 * 2 + (iVar9 - iVar5);
      (**(code **)(*(int *)unaff_ESI[0x20] + 0x94))(0);
      *(undefined1 *)((int)unaff_ESI + 0xf7) = 1;
    }
    else {
      iVar9 = unaff_ESI[0x3c] + iVar3;
      (**(code **)(*piVar1 + 0x94))(1);
      *(undefined1 *)((int)unaff_ESI + 0xf7) = 0;
    }
    (**(code **)(*unaff_ESI + 0xbc))(iVar2,iVar3,iVar4,iVar9);
  }
  return;
}

