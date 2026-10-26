
void FUN_0053b7e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0x5ed8);
  if (iVar1 != 0) {
    uVar4 = 0;
    uVar3 = *(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28) >> 2;
    if (uVar3 != 0) {
      do {
        if (*(int *)(*(int *)(iVar1 + 0x28) + uVar4 * 4) != 0) {
          *(undefined1 *)(*(int *)(*(int *)(iVar1 + 0x28) + uVar4 * 4) + 8) = 0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4404);
  ExceptionList = local_10;
  return;
}

