
void FUN_007961e0(void)

{
  int *in_EAX;
  int extraout_ECX;
  int iVar1;
  int *in_EDX;
  int extraout_EDX;
  int iVar2;
  float *unaff_ESI;
  undefined4 *unaff_EDI;
  float10 fVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *in_EAX;
  iVar2 = *in_EDX;
  if (iVar1 != iVar2) {
    fVar3 = (float10)FUN_00796000(*unaff_ESI,*(undefined4 *)(iVar1 + 0x2c),
                                  *(undefined4 *)(iVar2 + 0x2c));
    *unaff_ESI = (float)fVar3;
    iVar1 = extraout_ECX;
    iVar2 = extraout_EDX;
  }
  FUN_00780e30(&local_14,*(undefined4 *)(iVar2 + 0x50),iVar1 + 0x40,iVar2 + 0x30,iVar2 + 4,
               *unaff_ESI);
  if (unaff_EDI != &local_14) {
    unaff_EDI[3] = local_8;
    *unaff_EDI = local_14;
    unaff_EDI[1] = local_10;
    unaff_EDI[2] = local_c;
  }
  return;
}

