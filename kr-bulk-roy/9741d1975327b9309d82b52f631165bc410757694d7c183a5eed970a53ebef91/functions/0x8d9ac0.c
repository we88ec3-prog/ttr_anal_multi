
int FUN_008d9ac0(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint local_28;
  uint local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(in_ECX + 4);
  local_8 = *(int *)(iVar1 + 0x68);
  local_20 = (int *)(in_EAX * 0x10 + *(int *)(iVar1 + 0x1a0));
  uVar4 = 0;
  local_10 = *(uint **)(iVar1 + 0x184);
  if (*(uint *)(iVar1 + 0x17c) != 0) {
    local_24 = (uint)*(ushort *)(param_1 + 0xc);
    do {
      if ((*local_10 == local_24) && (local_10[1] == (uint)*(ushort *)(param_1 + 0xe))) {
        uVar4 = local_10[2];
        local_c = 4;
        if ((uVar4 & 1) != 0) {
          local_c = 5;
        }
        if ((uVar4 & 2) != 0) {
          local_c = local_c + 1;
        }
        if ((uVar4 & 4) != 0) {
          local_c = local_c + 1;
        }
        iVar3 = FUN_008b97e0(local_8,*(int *)(iVar1 + 0x1b0) + local_10[6]);
        if ((iVar3 == 0) &&
           (iVar3 = FUN_008babe0(local_8,local_10[7] * local_c), piVar2 = local_20, iVar3 == 0)) {
          FUN_008d96e0(*(undefined4 *)(local_8 + 0x20),*(undefined4 *)(local_8 + 0x24),*local_20,
                       &local_28,&local_18);
          FUN_008baca0(local_8);
          if (local_18 == 0) {
            return 6;
          }
          local_10 = (uint *)0x0;
          local_c = 0;
          local_20 = (int *)0x0;
          local_1c = 0;
          local_24 = 0;
          iVar3 = piVar2[1];
          if (*(int *)(iVar1 + 0x130) != *(int *)(iVar1 + 300)) {
            iVar3 = FUN_008b7dc0(iVar3,*(int *)(iVar1 + 300),*(int *)(iVar1 + 0x130));
          }
          *(int *)(in_ECX + 0x38) = iVar3;
          local_14 = FUN_008b7dc0((uint)*(ushort *)(param_1 + 0xc) << 8,piVar2[1],
                                  *(undefined4 *)(iVar1 + 0x130));
          iVar3 = FUN_008b97e0(local_8,*(int *)(iVar1 + 0xbc) + local_28);
          if ((iVar3 == 0) && (iVar3 = FUN_008babe0(local_8,local_18), iVar3 == 0)) {
            local_18 = *(int *)(local_8 + 0x20);
            iVar3 = FUN_008d97f0(&local_18,*(undefined4 *)(local_8 + 0x24),local_14,&local_10,
                                 &local_c,&local_20,&local_1c,&local_14,&local_24);
            local_28 = local_c + local_1c;
            if (0x7fffffff < local_28) {
              FUN_008baca0(local_8);
              return 0x17;
            }
            if (iVar3 == 0) {
              *(int *)(in_ECX + 0x1c) = local_1c << 6;
              *(int *)(in_ECX + 0x20) = (int)local_10 << 6;
              *(int **)(in_ECX + 0x50) = local_20;
              *(int *)(in_ECX + 0x4c) = local_1c;
              *(int *)(in_ECX + 0x24) = local_c << 6;
              *(int *)(in_ECX + 0x18) = (int)local_20 * 0x40;
              *(int *)(in_ECX + 0x54) = (int)local_20 + 7 >> 3;
              *(int *)(in_ECX + 0x2c) = (int)local_20 * -0x40 >> 1;
              *(undefined4 *)(in_ECX + 0x48) = 0x62697473;
              *(undefined1 *)(in_ECX + 0x5e) = 1;
              *(uint *)(in_ECX + 0x28) = (local_14 >> 2) + 0x20U & 0xffffffc0;
              *(undefined4 *)(in_ECX + 0x30) = 0;
              *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x20);
              *(uint **)(in_ECX + 100) = local_10;
              *(uint *)(in_ECX + 0x68) = local_28;
              local_20 = (int *)(in_ECX + 0x4c);
              iVar3 = FUN_008bb1d0();
              if (iVar3 == 0) {
                iVar3 = FUN_008d9a40(local_24);
              }
            }
            FUN_008baca0(local_8);
          }
        }
        return iVar3;
      }
      uVar4 = uVar4 + 1;
      local_10 = local_10 + 9;
    } while (uVar4 < *(uint *)(iVar1 + 0x17c));
  }
  return 6;
}

