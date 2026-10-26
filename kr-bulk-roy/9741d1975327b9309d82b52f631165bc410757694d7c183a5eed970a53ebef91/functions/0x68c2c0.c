
void FUN_0068c2c0(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x42] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (iVar1 == ((int *)in_ECX[0x3f])[8]) {
      (**(code **)(*(int *)in_ECX[0x3f] + 0xa0))(1);
      uVar2 = 0;
    }
    else {
      if (iVar1 != *(int *)(in_ECX[0x40] + 0x20)) {
        return;
      }
      (**(code **)(*(int *)in_ECX[0x3f] + 0xa0))(0);
      uVar2 = 1;
    }
    (**(code **)(*(int *)in_ECX[0x40] + 0xa0))(uVar2);
  }
  return;
}

