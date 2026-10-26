
uint FUN_006de6b0(void)

{
  uint uVar1;
  int *in_ECX;
  
  if ((*(int *)in_ECX[8] != 0) && (0 < *(int *)in_ECX[0xc])) {
    return (uint)**(byte **)in_ECX[8];
  }
                    /* WARNING: Could not recover jumptable at 0x006de6cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*in_ECX + 0x18))();
  return uVar1;
}

