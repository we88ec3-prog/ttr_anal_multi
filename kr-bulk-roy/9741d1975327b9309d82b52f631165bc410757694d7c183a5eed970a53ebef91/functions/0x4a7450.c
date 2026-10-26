
void FUN_004a7450(void)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  FUN_007545b0();
  iVar1 = unaff_EDI[0x59];
  iVar2 = *(int *)(unaff_EDI[0x58] + 0x14) + 0xf;
  (**(code **)(*(int *)unaff_EDI[0x59] + 0xbc))
            (*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
             iVar2 + *(int *)(iVar1 + 0xc));
  (**(code **)(*unaff_EDI + 0xbc))(unaff_EDI[2],unaff_EDI[3],unaff_EDI[4],iVar2 + unaff_EDI[3]);
  return;
}

