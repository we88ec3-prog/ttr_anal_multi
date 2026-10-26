
void FUN_005f5ed0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf436e) {
    if (uVar1 == 0xf436d) {
      (**(code **)(*in_ECX + 0x1b0))
                (*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0x1c));
      return;
    }
    if (uVar1 == 0x5e6) {
      (**(code **)(*(int *)in_ECX[0x3b] + 0x128))();
      return;
    }
    if (uVar1 == 0x70a) {
      (**(code **)(*in_ECX + 0x1ac))(*(int *)(param_1 + 0x14) + 1,0);
      return;
    }
  }
  else if (uVar1 == 0xf436e) {
    (**(code **)(*in_ECX + 0x1b4))
              (*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x1c));
  }
  else if (uVar1 == 0xf4376) {
    iVar2 = FUN_0040afc0();
    (**(code **)(*in_ECX + 0x1ac))(*(undefined4 *)(iVar2 + 0x14),1);
    return;
  }
  return;
}

