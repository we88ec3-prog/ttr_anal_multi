
void FUN_0075f990(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x128))();
  for (puVar1 = *(undefined4 **)in_ECX[0x19]; puVar1 != (undefined4 *)in_ECX[0x19];
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[2] == in_ECX[0x29]) goto LAB_0075f9c5;
  }
  (**(code **)(*in_ECX + 0x70))(in_ECX[0x29]);
LAB_0075f9c5:
  if ((param_1 == 0) || (param_1 == 1)) {
    uVar2 = *(uint *)(in_ECX[0x29] + 0x28);
    if ((uVar2 & 0x100) != 0) {
      *(uint *)(in_ECX[0x29] + 0x28) = uVar2 ^ 0x100;
    }
  }
  else if (param_1 == 2) {
    *(uint *)(in_ECX[0x29] + 0x28) = *(uint *)(in_ECX[0x29] + 0x28) | 0x100;
    return;
  }
  return;
}

