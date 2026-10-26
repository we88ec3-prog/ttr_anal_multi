
void FUN_0064e390(void)

{
  int in_ECX;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00920dbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14._1_3_ = (undefined3)((uint)in_ECX >> 8);
  local_14 = CONCAT31(local_14._1_3_,(char)(*(uint *)(*(int *)(in_ECX + 0x100) + 0x28) >> 9)) &
             0xffffff01;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058ea80(L"MoveLock",local_14);
  ExceptionList = local_10;
  return;
}

