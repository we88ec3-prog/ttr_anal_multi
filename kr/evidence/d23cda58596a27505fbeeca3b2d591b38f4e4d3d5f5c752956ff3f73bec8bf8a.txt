
undefined2 FUN_005008b0(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00908828;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  local_28 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_20 = 0;
  local_c = 0;
  FUN_00500a00(in_EDX,in_ECX,&local_28);
  if (local_28 == local_24) {
    if (local_28 != (undefined4 *)0x0) {
      FUN_0089120c(local_28,uVar2);
    }
    ExceptionList = local_14;
    return 0;
  }
  uVar1 = *(undefined2 *)*local_28;
  FUN_0089120c(local_28,uVar2);
  ExceptionList = local_14;
  return uVar1;
}

