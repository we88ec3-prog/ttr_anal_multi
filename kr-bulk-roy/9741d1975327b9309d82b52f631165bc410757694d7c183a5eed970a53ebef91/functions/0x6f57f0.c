
void FUN_006f57f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar3 = (int *)FUN_006f50f0();
  iVar1 = *(int *)(param_1 + 8);
  puVar4 = (undefined4 *)FUN_006f9d20(param_1);
  *puVar4 = *(undefined4 *)(iVar1 + -0x10);
  puVar4[1] = *(undefined4 *)(iVar1 + -0xc);
  puVar4[2] = *(undefined4 *)(iVar1 + -8);
  if (((3 < *(int *)(*(int *)(param_1 + 8) + -8)) &&
      ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + -0x10) + 5) & 3) != 0)) &&
     (iVar1 = *piVar3, (*(byte *)(iVar1 + 5) & 4) != 0)) {
    iVar2 = *(int *)(param_1 + 0x10);
    *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfb;
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x28);
    *(int *)(iVar2 + 0x28) = iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x20;
  return;
}

