
undefined4 * FUN_0072ecc0(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(int **)(in_EAX + 0x18) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(in_EAX + 0x18) + 0x30))(), iVar1 != 0)) {
    if (*(uint *)(iVar1 + 0x34) < 0x10) {
      return (undefined4 *)(iVar1 + 0x20);
    }
    return *(undefined4 **)(iVar1 + 0x20);
  }
  return (undefined4 *)0x0;
}

