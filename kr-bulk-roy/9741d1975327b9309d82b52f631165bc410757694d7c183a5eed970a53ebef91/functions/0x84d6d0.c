
undefined4 FUN_0084d6d0(int param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iStack_4c;
  int iStack_48;
  undefined4 *puStack_44;
  int iStack_40;
  int iStack_3c;
  int iVar3;
  undefined4 *puVar4;
  int iStack_2c;
  undefined4 local_1c [6];
  
  iStack_48 = *(int *)(param_1 + 0x88);
  iStack_3c = 0;
  local_1c[0] = *(undefined4 *)(in_ECX + 0x18);
  iStack_40 = 4;
  puStack_44 = local_1c;
  iStack_4c = 0x84d6fd;
  FUN_00721910();
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    iVar2 = in_ECX + 8;
  }
  else {
    iVar2 = *(int *)(in_ECX + 8);
  }
  if ((iVar2 != 0) && (iStack_2c != 0)) {
    iStack_4c = 0;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar2,iStack_2c);
  }
  if ((*(int *)(in_ECX + 0x40) != 0) && (*(int *)(in_ECX + 0x44) != 0)) {
    iStack_4c = 0;
    iVar2 = 4;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffffcc);
    if (puStack_44 != (undefined4 *)0x0) {
      iStack_40 = (*(int **)(in_ECX + 0x48))[1] - **(int **)(in_ECX + 0x48) >> 2;
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_40,4,0);
      puVar4 = (undefined4 *)0x0;
      if (puStack_44 != (undefined4 *)0x0) {
        iStack_48 = 0;
        do {
          FUN_005f7e40(iStack_40);
          iVar1 = *(int *)(iStack_48 + *(int *)(in_ECX + 0x48));
          if ((iVar1 != 0) && (iVar3 = iStack_40, 0 < iStack_40)) {
            do {
              FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar1,4,0);
              iVar1 = iVar1 + 4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          iVar1 = iStack_48 + 0x10 + *(int *)(in_ECX + 0x48);
          if (iVar1 != 0) {
            FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar1,4,0);
          }
          iStack_48 = iStack_48 + 0x18;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        } while (puVar4 < puStack_44);
      }
    }
    iStack_3c = (*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0xc;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_3c,4,0);
    if (iStack_4c != 0) {
      if ((*(int *)(in_ECX + 0x28) != 0) && (iStack_4c * 0xc != 0)) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),*(int *)(in_ECX + 0x28),iStack_4c * 0xc,0);
      }
    }
    iStack_40 = (*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58)) / 0x14;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_40,4,0);
    if (iVar2 != 0) {
      if ((*(int *)(in_ECX + 0x58) != 0) && (iVar2 * 0x14 != 0)) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),*(int *)(in_ECX + 0x58),iVar2 * 0x14,0);
      }
    }
    if (in_ECX + 0x3c != 0) {
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x3c,4,0);
    }
    iStack_4c = 0;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_4c,4,0);
    FUN_00857200(param_1);
    FUN_00857bf0(*(undefined4 *)(in_ECX + 0x44));
    return 1;
  }
  return 0;
}

