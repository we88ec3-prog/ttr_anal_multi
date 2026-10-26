
undefined4 FUN_008dbdc0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x140);
  if (iVar1 != 0) {
    iVar2 = FUN_008b8f30(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 4),"pshinter");
    if (iVar2 != 0) {
      uVar3 = (**(code **)(iVar1 + 4))(iVar2);
      *(undefined4 *)(*(int *)(param_1 + 0x9c) + 0x24) = uVar3;
    }
  }
  return 0;
}

