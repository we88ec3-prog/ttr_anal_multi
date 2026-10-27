
void FUN_004c83c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 0x36c) == 0) {
    local_8 = 0;
    piVar2 = (int *)(param_1 + 0x164);
    do {
      uVar3 = local_8;
      local_c = local_8 & 0xffff;
      piVar1 = (int *)FUN_00826280(&local_c);
      if ((*piVar1 == *(int *)(param_1 + 0x3f4)) && (*piVar2 != 0)) {
        if (*(int *)(*piVar2 + 0x24) != 0) {
          FUN_007be5f0();
        }
        if (*piVar2 != 0) {
          FUN_004c7db0();
          *piVar2 = 0;
          uVar3 = local_8;
        }
      }
      local_8 = uVar3 + 1;
      piVar2 = piVar2 + 1;
    } while ((int)local_8 < 0x80);
  }
  return;
}

