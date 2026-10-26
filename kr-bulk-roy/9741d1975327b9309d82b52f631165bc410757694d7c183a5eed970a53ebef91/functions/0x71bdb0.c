
int * FUN_0071bdb0(void)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[1];
  uVar4 = in_EAX + 3U & 0xfffffffc;
  uVar2 = iVar1 + uVar4;
  if (uVar2 < 0x1001) {
    unaff_EDI[1] = uVar2;
    return (int *)(iVar1 + 4 + *unaff_EDI);
  }
  uVar2 = uVar4;
  if (uVar4 < 0x1001) {
    uVar2 = 0x1000;
  }
  piVar3 = (int *)(*(code *)PTR_FUN_00d63d48)(uVar2 + 4);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  *piVar3 = *unaff_EDI;
  *unaff_EDI = (int)piVar3;
  unaff_EDI[1] = uVar4;
  return piVar3 + 1;
}

