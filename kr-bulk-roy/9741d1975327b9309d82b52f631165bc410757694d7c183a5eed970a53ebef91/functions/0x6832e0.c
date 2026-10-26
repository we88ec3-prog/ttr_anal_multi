
void FUN_006832e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x76c) {
    in_ECX[0x3f] = *(int *)(param_1 + 0x14);
    return;
  }
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x41] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x42] + 0x20)) {
      piVar2 = (int *)FUN_004fc740(in_ECX + 0x4b);
      if (*piVar2 != piVar2[1]) {
        if (piVar2[1] - *piVar2 >> 2 != 0) {
          uVar3 = 0;
          do {
            FUN_00681e10(in_ECX[0x3d],in_ECX[0x3e],in_ECX[0x50],
                         (byte)(*(uint *)(in_ECX[0x42] + 0x28) >> 9) & 1);
            uVar3 = uVar3 + 1;
          } while (uVar3 < (uint)(piVar2[1] - *piVar2 >> 2));
        }
        FUN_00749920(in_ECX[0x40]);
        (**(code **)(*(int *)in_ECX[0x40] + 200))();
        return;
      }
    }
  }
  else if (iVar1 == 0x387) {
    FUN_00683fe0();
  }
  return;
}

