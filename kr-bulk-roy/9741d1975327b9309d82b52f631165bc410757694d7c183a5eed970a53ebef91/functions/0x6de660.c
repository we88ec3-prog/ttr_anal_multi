
uint FUN_006de660(void)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  int *in_ECX;
  
  if ((*(int *)in_ECX[8] != 0) && (piVar1 = (int *)in_ECX[0xc], 0 < *piVar1)) {
    *piVar1 = *piVar1 + -1;
    pbVar2 = *(byte **)in_ECX[8];
    *(byte **)in_ECX[8] = pbVar2 + 1;
    return (uint)*pbVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x006de687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*in_ECX + 0x1c))();
  return uVar3;
}

