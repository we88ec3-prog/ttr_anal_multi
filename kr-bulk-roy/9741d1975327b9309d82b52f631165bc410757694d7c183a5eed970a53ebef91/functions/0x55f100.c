
void FUN_0055f100(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puVar1 = DAT_00fc1b3c;
  puStack_c = &LAB_0090fdf6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  if (DAT_00fc1b3c != (undefined4 *)0x0) {
    if (0xf < (uint)DAT_00fc1b3c[0xc]) {
      FUN_0089120c(DAT_00fc1b3c[7],uVar2);
    }
    puVar1[0xc] = 0xf;
    puVar1[0xb] = 0;
    *(undefined1 *)(puVar1 + 7) = 0;
    if (7 < (uint)puVar1[5]) {
      FUN_0089120c(*puVar1,uVar2);
    }
    puVar1[5] = 7;
    puVar1[4] = 0;
    *(undefined2 *)puVar1 = 0;
    FUN_0089120c(puVar1,uVar2);
    DAT_00fc1b3c = (undefined4 *)0x0;
  }
  if (DAT_00fc1b1c != 0) {
    FUN_0055f320();
    DAT_00fc1b1c = 0;
  }
  if (DAT_00fc1b20 != (int *)0x0) {
    (**(code **)(*DAT_00fc1b20 + 8))();
    DAT_00fc1b20 = (int *)0x0;
  }
  FUN_00542210();
  iVar3 = FUN_004d8460();
  if (local_18 != *(uint *)(iVar3 + 8)) {
    do {
      if (local_20 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *local_20;
      }
      uVar5 = local_18 >> 2;
      uVar4 = local_18 & 3;
      uVar2 = uVar5;
      if (*(uint *)(iVar3 + 8) <= uVar5) {
        uVar2 = uVar5 - *(uint *)(iVar3 + 8);
      }
      if (*(int *)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + uVar4 * 4) != 0) {
        if (local_20 == (int *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *local_20;
        }
        uVar2 = uVar5;
        if (*(uint *)(iVar3 + 8) <= uVar5) {
          uVar2 = uVar5 - *(uint *)(iVar3 + 8);
        }
        puVar1 = *(undefined4 **)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + uVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          if (0xf < (uint)puVar1[0xc]) {
            FUN_0089120c(puVar1[7]);
          }
          puVar1[0xc] = 0xf;
          puVar1[0xb] = 0;
          *(undefined1 *)(puVar1 + 7) = 0;
          if (7 < (uint)puVar1[5]) {
            FUN_0089120c(*puVar1);
          }
          puVar1[5] = 7;
          puVar1[4] = 0;
          *(undefined2 *)puVar1 = 0;
          FUN_0089120c(puVar1);
        }
        if (local_20 == (int *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *local_20;
        }
        if (*(uint *)(iVar3 + 8) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(iVar3 + 8);
        }
        *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + uVar5 * 4) + uVar4 * 4) = 0;
      }
      local_18 = local_18 + 1;
      iVar3 = FUN_004d8460();
    } while (local_18 != *(uint *)(iVar3 + 8));
  }
  local_8 = local_8 & 0xffffff00;
  FUN_00513450();
  FUN_007b6d70();
  FUN_0089120c(DAT_00fc1b24);
  DAT_00fc1b24 = 0;
  ExceptionList = local_10;
  return;
}

