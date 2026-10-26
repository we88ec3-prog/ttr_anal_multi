
void FUN_006899f0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xfc);
  iVar2 = iVar1;
  if (iVar1 <= in_EAX) {
    iVar2 = in_EAX;
  }
  iVar3 = *(int *)(param_1 + 0x100);
  if ((iVar2 < iVar3) && (iVar3 = in_EAX, in_EAX < iVar1)) {
    iVar3 = iVar1;
  }
  FUN_0068ac30();
  (**(code **)(**(int **)(param_1 + 0x11c) + 200))();
  *(int *)(param_1 + 0x104) = iVar3;
  return;
}

