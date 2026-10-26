
undefined2 FUN_008d0fa0(int param_1,uint param_2)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x10) <= param_2) &&
     (param_2 < *(int *)(param_1 + 0x14) + *(uint *)(param_1 + 0x10))) {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x18) + param_2 * 2);
  }
  return uVar1;
}

