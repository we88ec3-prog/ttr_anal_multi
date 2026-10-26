
int FUN_00746b80(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *in_ECX;
  
  if (((uint)in_ECX[10] >> 0xf & 1) == 0) {
    return ((uint)in_ECX[10] >> 0x17) << 8;
  }
  (**(code **)(*in_ECX + 0x120))();
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_00746b80();
  }
  uVar3 = in_ECX[10];
  if ((uVar3 & 0x8000) != 0) {
    uVar3 = uVar3 ^ 0x8000;
    in_ECX[10] = uVar3;
  }
  return CONCAT31((int3)(uVar3 >> 8),1);
}

