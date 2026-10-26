
uint FUN_005480e0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  undefined1 local_29;
  ushort uStack_1e;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093fe2c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar3 = in_ECX * 3;
  piVar1 = *(int **)(param_1 + 0xc + in_ECX * 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = piVar1[0x38];
    iVar5 = piVar1[0x39];
    local_29 = 0;
    if ((DAT_00fb7a20 & 1) == 0) {
      DAT_00fb7a20 = DAT_00fb7a20 | 1;
      local_c = 0;
      FUN_00548da0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
      _atexit(FUN_00bcd370);
    }
    local_c = 0xffffffff;
    FUN_00548ff0(&DAT_00fb7a28,*(undefined4 *)(param_1 + ((in_ECX != 2) + 2) * 0xc),in_ECX + -1,
                 param_2);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    uVar3 = (uint)*(ushort *)(piVar1 + 0x22);
    if ((((uVar3 < 10) && (uVar3 = uVar3 * 0x210 + DAT_00f94304, *(int *)(uVar3 + 0x5c) != 0)) &&
        (uVar3 != 0)) && (uVar3 + 500 != 0)) {
      if (((piVar1[0x56] == 0) || (*(int *)(piVar1[0x56] + 0x2c) == 0)) ||
         (iVar4 = FUN_004c9ed0(), iVar4 != 0)) {
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x8000;
      }
      else if ((*(ushort *)(param_2 + 2) & 0x7fff) != 0) {
        iVar4 = FUN_0054f270(*(undefined1 *)((uint)(*(char *)(uVar3 + 0x1f6) != '\0') + uVar3 + 500)
                             ,piVar1[0xfa]);
        if (iVar4 == 0) {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x8000;
        }
        else {
          local_29 = 1;
        }
      }
      if (((piVar1[0x56] == 0) || (*(int *)(piVar1[0x56] + 0x30) == 0)) ||
         (iVar4 = FUN_004c9ed0(), iVar4 != 0)) {
        uVar3 = 0x7fff;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x7fff;
      }
      else if ((*(ushort *)(param_2 + 2) & 0x8000) == 0) {
        uVar3 = *(ushort *)(param_2 + 2) & 0x7fff;
        *(short *)(param_2 + 2) = (short)uVar3;
      }
      else {
        if (*(char *)(param_2 + 4) != (char)iVar5) {
          (**(code **)(*piVar1 + 0x58))(*(char *)(param_2 + 4));
          local_29 = 1;
        }
        if (piVar1[0x56] == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(piVar1[0x56] + 0x28);
        }
        uVar3 = iVar5 << 0xf;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0x7fff | (ushort)uVar3;
      }
      uStack_1e = (ushort)((uint)iVar2 >> 0x10);
      if (((*(ushort *)(param_2 + 2) ^ uStack_1e) & 0x8000) != 0) {
        local_29 = 1;
      }
      ExceptionList = local_14;
      return CONCAT31((int3)(uVar3 >> 8),local_29);
    }
  }
  ExceptionList = local_14;
  return uVar3 & 0xffffff00;
}

