
void FUN_006fe550(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  
  *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x34) + 1;
  uVar1 = *(ushort *)(param_1 + 0x34);
  if (199 < uVar1) {
    if (uVar1 == 200) {
      FUN_006f8b60(param_1,"C stack overflow");
    }
    else if (0xe0 < uVar1) {
      FUN_006fdb40(param_1,5);
    }
  }
  iVar2 = FUN_006fe1c0(param_3);
  if (iVar2 == 0) {
    FUN_006fc550(param_1,1);
  }
  *(short *)(param_1 + 0x34) = *(short *)(param_1 + 0x34) + -1;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  return;
}

