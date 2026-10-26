
uint FUN_00746c10(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint in_EAX;
  uint uVar3;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x2a) & 1) != 0) {
    (**(code **)(*in_ECX + 0x11c))();
    puVar1 = (undefined4 *)in_ECX[0x19];
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_00746c10();
    }
    uVar3 = in_ECX[10];
    if ((uVar3 & 0x10000) != 0) {
      uVar3 = uVar3 ^ 0x10000;
      in_ECX[10] = uVar3;
    }
    return CONCAT31((int3)(uVar3 >> 8),1);
  }
  return in_EAX & 0xffffff00;
}

