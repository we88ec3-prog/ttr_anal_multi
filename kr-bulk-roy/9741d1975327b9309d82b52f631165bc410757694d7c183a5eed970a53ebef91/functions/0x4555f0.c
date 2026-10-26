
void FUN_004555f0(int param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int *in_ECX;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20)) {
      FUN_00455e60();
    }
    else if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
    }
    uVar1 = 0;
    piVar3 = in_ECX + 0x3f;
    while (*(int *)(param_1 + 8) != *(int *)(*piVar3 + 0x20)) {
      uVar1 = uVar1 + 1;
      piVar3 = piVar3 + 1;
      if (2 < (int)uVar1) {
        return;
      }
    }
    if (uVar1 < (uint)(in_ECX[0x61] - in_ECX[0x60] >> 2)) {
      puVar2 = (undefined2 *)(in_ECX[0x60] + uVar1 * 4);
    }
    else {
      puVar2 = (undefined2 *)0x0;
    }
    *(undefined2 *)(in_ECX + 0x5e) = *puVar2;
    *(undefined1 *)((int)in_ECX + 0x17a) = *(undefined1 *)(puVar2 + 1);
    FUN_00455840();
  }
  else if (*(int *)(param_1 + 0x10) == 0x70a) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x46] + 0x20)) {
      FUN_00455ac0();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x47] + 0x20)) {
      FUN_00455b00();
      return;
    }
  }
  return;
}

