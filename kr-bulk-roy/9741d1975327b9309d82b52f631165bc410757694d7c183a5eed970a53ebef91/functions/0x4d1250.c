
void FUN_004d1250(uint param_1,short param_2)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00939dee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((short)param_1 == 0x1c) {
    uVar2 = *(ushort *)(in_ECX + 0x22);
    if ((DAT_00fd9260 & 1) == 0) {
      DAT_00fd9260 = DAT_00fd9260 | 1;
      local_8 = 0;
      FUN_004c6790(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit(FUN_00bcdd60);
    }
    local_8 = 0xffffffff;
    param_1 = (uint)uVar2;
    FUN_004c6720(&param_1);
    if ((in_ECX != DAT_00fd9268) && (piVar1 = in_ECX + param_2 * 2 + 4, piVar1 != (int *)0x0)) {
      (**(code **)(*in_ECX + 0x68))(piVar1[1],0x3f800000);
      iVar3 = *piVar1;
      *(short *)(in_ECX + 0xe2) = (short)iVar3;
      if ((in_ECX[0x57] != 0) && (in_ECX[0xdc] != 0)) {
        FUN_007a6ea0(in_ECX[0x57],1,(short)iVar3);
      }
      if (in_ECX[0x109] != 0) {
        if (*(int *)(in_ECX[0x109] + 0x24) != 0) {
          FUN_007be5f0();
        }
        if (in_ECX[0x109] != 0) {
          FUN_004c7db0();
          in_ECX[0x109] = 0;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

