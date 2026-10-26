
void FUN_00748830(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar5 = FUN_00443da0();
  iVar1 = unaff_EDI[3];
  iVar5 = *(int *)(iVar5 + 4);
  iVar6 = FUN_00443da0();
  iVar2 = unaff_EDI[1];
  iVar6 = *(int *)(iVar6 + 4);
  piVar7 = (int *)FUN_00443da0();
  iVar3 = unaff_EDI[2];
  iVar4 = *piVar7;
  piVar7 = (int *)FUN_00443da0();
  *unaff_ESI = *unaff_EDI - *piVar7;
  unaff_ESI[1] = iVar2 - iVar6;
  unaff_ESI[2] = iVar3 - iVar4;
  unaff_ESI[3] = iVar1 - iVar5;
  return;
}

