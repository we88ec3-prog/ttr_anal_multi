
undefined4 FUN_004eae00(int param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929afc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 4) == *(int *)(in_ECX + 0x5ec4)) {
    *(uint *)(in_ECX + 0x5edc) = (uint)*(byte *)(param_1 + 0x1d4);
    *(undefined4 *)(in_ECX + 0x5ed8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_ECX + 0x5ec8) = *(undefined4 *)(param_1 + 0xc);
    *(uint *)(in_ECX + 0x5ed0) = (uint)*(ushort *)(param_1 + 2);
    *(uint *)(in_ECX + 0x5ecc) = (uint)*(ushort *)(param_1 + 0x12);
    *(undefined4 *)(in_ECX + 0x5ed4) = *(undefined4 *)(param_1 + 0x14);
    psVar3 = (short *)(param_1 + 0x42);
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160((short *)(param_1 + 0x42),(int)psVar3 - (param_1 + 0x44) >> 1);
    uVar4 = 0;
    if (*(int *)(in_ECX + 0x5f04) != 0) {
      do {
        if (*(uint *)(in_ECX + 0x5f08) < 8) {
          iVar5 = in_ECX + 0x5ef4;
        }
        else {
          iVar5 = *(int *)(in_ECX + 0x5ef4);
        }
        if (*(short *)(iVar5 + uVar4 * 2) == 0xb4) {
          if (*(uint *)(in_ECX + 0x5f08) < 8) {
            iVar5 = in_ECX + 0x5ef4;
          }
          else {
            iVar5 = *(int *)(in_ECX + 0x5ef4);
          }
          *(undefined2 *)(iVar5 + uVar4 * 2) = 0x27;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 0x5f04));
    }
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  FUN_004f7280(&DAT_00fb7470,*(undefined4 *)(param_1 + 4),param_1 + 0x18,0xffffffff);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_10;
  return 0;
}

