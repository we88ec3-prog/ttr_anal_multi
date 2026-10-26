
void FUN_008b7da0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *in_EDX;
  int *unaff_ESI;
  uint *unaff_EDI;
  
  uVar1 = *unaff_EDI;
  uVar4 = *unaff_ESI + uVar1;
  uVar2 = unaff_EDI[1];
  iVar3 = unaff_ESI[1];
  *in_EDX = uVar4;
  in_EDX[1] = (uVar4 < uVar1) + uVar2 + iVar3;
  return;
}

