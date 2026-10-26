
undefined4 FUN_004a3110(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_00542210();
  iVar3 = 0;
  if ((int *)*piVar2 != (int *)0x0) {
    iVar3 = *(int *)*piVar2;
  }
  uVar1 = piVar2[2];
  if (*(uint *)(iVar3 + 8) <= uVar1) {
    return *(undefined4 *)(*(int *)(iVar3 + 4) + (uVar1 - *(uint *)(iVar3 + 8)) * 4);
  }
  return *(undefined4 *)(*(int *)(iVar3 + 4) + uVar1 * 4);
}

