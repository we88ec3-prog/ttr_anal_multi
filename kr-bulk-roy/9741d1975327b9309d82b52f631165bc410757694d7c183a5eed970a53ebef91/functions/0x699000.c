
void FUN_00699000(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf43c0) {
    if (uVar1 == 0xf43bf) {
LAB_00699086:
      FUN_00698a30(in_ECX);
      return;
    }
    if (uVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
        FUN_00414680();
        FUN_004a4660();
        return;
      }
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
        FUN_00698d40();
        return;
      }
    }
    else if (uVar1 == 0xf43be) {
      FUN_0040afc0();
      if (*(int *)(in_ECX[0x3d] + 0xcc) != 0) {
        FUN_0063d020();
      }
      FUN_00749920(in_ECX[0x3d]);
      (**(code **)(*(int *)in_ECX[0x3d] + 200))();
      iVar2 = FUN_0046aa50();
      if (iVar2 == 0) {
        (**(code **)(*in_ECX + 0xd4))();
        return;
      }
      goto LAB_00699086;
    }
  }
  else if (uVar1 == 0xf43c1) {
    (**(code **)(*in_ECX + 0xd4))();
  }
  return;
}

