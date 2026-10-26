
void FUN_0082dfc0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint local_14;
  uint local_c;
  uint local_8;
  
  uVar1 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x38;
  local_c = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    do {
      uVar8 = *(uint *)(param_1 + 8);
      local_8 = 0;
      if (uVar8 != 0) {
        do {
          iVar2 = (uVar8 * local_c + local_8) * 0x18;
          iVar3 = *(int *)(param_1 + 0x20) + iVar2;
          iVar6 = 99999999;
          local_14 = 0xffffffff;
          if (*(int *)(iVar3 + 0x10) != 0) {
            if (*(int *)(iVar3 + 8) == -1) {
              uVar8 = 0;
              if (uVar1 != 0) {
                piVar7 = (int *)(*(int *)(param_1 + 0x10) + 0x28);
                do {
                  uVar4 = (int)(local_8 - piVar7[-1]) >> 0x1f;
                  uVar5 = (int)(local_c - *piVar7) >> 0x1f;
                  iVar2 = ((local_8 - piVar7[-1] ^ uVar4) - uVar4) +
                          ((local_c - *piVar7 ^ uVar5) - uVar5);
                  if (iVar2 < iVar6) {
                    iVar6 = iVar2;
                    local_14 = uVar8;
                  }
                  uVar8 = uVar8 + 1;
                  piVar7 = piVar7 + 0xe;
                } while (uVar8 < uVar1);
              }
              *(uint *)(iVar3 + 0xc) = local_14;
            }
            else {
              iVar2 = iVar2 + *(int *)(param_1 + 0x20);
              *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
            }
          }
          uVar8 = *(uint *)(param_1 + 8);
          local_8 = local_8 + 1;
        } while (local_8 < uVar8);
      }
      local_c = local_c + 1;
    } while (local_c < *(uint *)(param_1 + 0xc));
  }
  return;
}

