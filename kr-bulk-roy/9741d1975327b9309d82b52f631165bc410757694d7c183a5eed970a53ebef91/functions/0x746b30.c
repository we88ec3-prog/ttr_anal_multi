
undefined4 FUN_00746b30(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if (((uint)in_ECX[10] >> 0xf & 1) != 0) {
    return 0;
  }
  (**(code **)(*in_ECX + 0x124))();
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_00746b30();
  }
  in_ECX[10] = in_ECX[10] | 0x8000;
  return 1;
}

