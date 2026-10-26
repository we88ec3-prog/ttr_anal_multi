
undefined4 FUN_00573fc0(void)

{
  uint uVar1;
  undefined4 in_EAX;
  int *piVar2;
  int iVar3;
  
  FUN_00542210();
  piVar2 = (int *)FUN_0050b4b0(in_EAX);
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

