
uint FUN_0040b480(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *in_ECX;
  
  uVar1 = param_1;
  iVar2 = (**(code **)(*in_ECX + 0x14))();
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int **)(iVar2 + 8)) && (in_ECX[4] != 0)) {
    if ((*(uint *)(in_ECX[4] + 0x28) >> 0x15 & 1) != 0) {
      FUN_00745680();
    }
    piVar3 = (int *)(**(code **)(*in_ECX + 0x14))();
    uVar4 = (**(code **)(*piVar3 + 0x30))(uVar1);
    return uVar4;
  }
  return (uint)in_ECX & 0xffffff00;
}

