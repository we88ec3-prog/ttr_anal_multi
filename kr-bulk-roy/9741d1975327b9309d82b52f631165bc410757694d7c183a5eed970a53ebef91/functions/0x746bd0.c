
undefined4 FUN_00746bd0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x2a) & 1) == 0) {
    (**(code **)(*in_ECX + 0x118))();
    puVar1 = (undefined4 *)in_ECX[0x19];
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_00746bd0();
    }
    in_ECX[10] = in_ECX[10] | 0x10000;
    return 1;
  }
  return 0;
}

