
void FUN_008645b0(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_10 [4];
  uint local_c;
  uint local_8;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_008433e0(param_1 + 0x44,*(int *)(param_1 + 0x40));
    local_c = *(uint *)(iVar1 + 8);
    local_8 = 0;
    if (local_c != 0) {
      do {
        param_1 = 0;
        FUN_0083edb0(local_10,&param_1);
        if ((((param_1 != 0) &&
             (uVar2 = param_1 & 0xffff,
             uVar2 < (uint)((*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0x10)) / 0x11c))) &&
            (*(uint *)(*(int *)(iVar1 + 0x20) + uVar2 * 4) == param_1 >> 0x10)) &&
           (iVar3 = uVar2 * 0x11c + *(int *)(iVar1 + 0x10), iVar3 != 0)) {
          FUN_008433e0(iVar3,*(undefined4 *)(iVar1 + 0x40));
        }
        local_8 = local_8 + 1;
      } while (local_8 < local_c);
    }
  }
  return;
}

