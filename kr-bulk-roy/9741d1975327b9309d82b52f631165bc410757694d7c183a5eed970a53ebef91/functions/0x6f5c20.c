
int FUN_006f5c20(undefined4 param_1)

{
  int *piVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  if (*(int *)(in_EAX + 0x14) == *(int *)(in_EAX + 0x28)) {
    uVar2 = *(undefined4 *)(in_EAX + 0x48);
  }
  else {
    uVar2 = *(undefined4 *)(**(int **)(*(int *)(in_EAX + 0x14) + 4) + 0xc);
  }
  iVar3 = FUN_006fed60(param_1,uVar2);
  piVar1 = *(int **)(in_EAX + 8);
  *piVar1 = iVar3;
  piVar1[2] = 7;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  return iVar3 + 0x18;
}

