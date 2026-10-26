
void FUN_0047fa30(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0047fa6c;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar1);
  }
LAB_0047fa6c:
  FUN_007612c0();
                    /* WARNING: Could not recover jumptable at 0x0047fa86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  return;
}

