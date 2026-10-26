
void FUN_00838eb0(uint param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) * 4);
  if (((uint)(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10)) < param_1) &&
     (iVar1 = *(int *)(in_EAX + 0x14) + 1, *(int *)(in_EAX + 0x14) = iVar1,
     iVar1 == *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2)) {
    uVar2 = *(uint *)(in_EAX + 0x5c);
    if (*(uint *)(in_EAX + 0x5c) < param_1) {
      uVar2 = param_1;
    }
    FUN_00839220(uVar2);
  }
  iVar1 = *(int *)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) * 4);
  if (*(int *)(iVar1 + 8) != 0) {
    (**(code **)(**(int **)(iVar1 + 8) + 4))(*(int **)(iVar1 + 8));
  }
  *param_2 = *(undefined4 *)(iVar1 + 8);
  (**(code **)(**(int **)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) * 4) + 4))(param_1,param_3)
  ;
  return;
}

