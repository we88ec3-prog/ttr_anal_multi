
void FUN_00767f50(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  
  piVar1 = (int *)unaff_EDI[0x43];
  iVar2 = piVar1[0x2e];
  unaff_EDI[0x4d] = iVar2;
  piVar1[0x31] = iVar2;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  FUN_00749920(unaff_EDI[0x43]);
                    /* WARNING: Could not recover jumptable at 0x00767f98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_EDI + 0x1b0))();
  return;
}

