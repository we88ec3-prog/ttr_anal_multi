
void FUN_0065f5b0(void)

{
  ushort uVar1;
  int iVar2;
  int unaff_ESI;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009461ee;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 0x88);
    *(uint *)(unaff_ESI + 0x1a8) = (uint)uVar1;
    FUN_0065f660(unaff_ESI,(uint)uVar1);
    FUN_0065f8a0(unaff_ESI);
    FUN_00660530();
  }
  ExceptionList = local_14;
  return;
}

