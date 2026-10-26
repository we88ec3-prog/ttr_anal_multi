
void FUN_00595d20(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((0xf42d7 < uVar1) && (uVar1 < 0xf434a)) {
    (**(code **)(*in_ECX + 0x18c))(param_1);
    return;
  }
  if ((0xf434a < uVar1) && (uVar1 < 0xf435c)) {
    (**(code **)(*in_ECX + 400))(param_1);
    return;
  }
  if ((1000000 < uVar1) && (uVar1 < 0xf42d7)) {
    (**(code **)(*in_ECX + 0x194))(param_1);
    return;
  }
  if ((0xf435c < uVar1) && (uVar1 < 0xf4442)) {
    (**(code **)(*in_ECX + 0x198))(param_1);
  }
  return;
}

