
void FUN_00786880(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  uint local_10;
  int local_c;
  int local_8;
  
  if (param_1 != in_ECX) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    local_c = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 4;
    if (0 < local_c) {
      local_8 = 0;
      do {
        uVar4 = *(int *)(param_1 + 0x14) + local_8;
        uVar1 = *(uint *)(in_ECX + 0x18);
        if ((uVar4 < uVar1) && (uVar2 = *(uint *)(in_ECX + 0x14), uVar2 <= uVar4)) {
          if (uVar1 == *(uint *)(in_ECX + 0x1c)) {
            FUN_007880a0();
          }
          uVar4 = (uVar4 - uVar2 & 0xfffffff0) + *(int *)(in_ECX + 0x14);
        }
        else if (uVar1 == *(uint *)(in_ECX + 0x1c)) {
          FUN_007880a0();
        }
        puVar3 = *(undefined4 **)(in_ECX + 0x18);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = gbKey<float>::vftable;
          puVar3[1] = *(undefined4 *)(uVar4 + 4);
          puVar3[2] = *(undefined4 *)(uVar4 + 8);
          puVar3[3] = *(undefined4 *)(uVar4 + 0xc);
        }
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 0x10;
        local_10 = local_10 & 0xffffff00;
        FUN_0078a340(*(int *)(in_ECX + 0x14),*(int *)(in_ECX + 0x18),
                     *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 4,local_10);
        local_8 = local_8 + 0x10;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  return;
}

