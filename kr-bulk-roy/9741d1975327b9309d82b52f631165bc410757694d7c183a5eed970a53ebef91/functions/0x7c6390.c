
int FUN_007c6390(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_1c [12];
  int local_10;
  uint local_c;
  
  iVar2 = *(int *)(param_1 + 0x98);
  iVar3 = 0;
  local_10 = 0;
  local_c = 0;
  if (*(int *)(param_1 + 0x9c) - iVar2 >> 2 != 0) {
    do {
      iVar2 = *(int *)(iVar2 + local_c * 4);
      uVar4 = 0;
      if (*(int *)(iVar2 + 0x3c) != 0) {
        do {
          piVar1 = (int *)FUN_007800e0();
          piVar1 = (int *)(**(code **)(*piVar1 + 0x1c))(local_1c);
          if (*piVar1 < iVar3) {
            iVar3 = *piVar1;
          }
          if (local_10 < piVar1[1]) {
            local_10 = piVar1[1];
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(iVar2 + 0x3c));
      }
      iVar2 = *(int *)(param_1 + 0x98);
      local_c = local_c + 1;
    } while (local_c < (uint)(*(int *)(param_1 + 0x9c) - iVar2 >> 2));
  }
  return local_10 / 0xa0;
}

