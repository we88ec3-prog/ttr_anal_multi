
void FUN_00683c50(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920dbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0061f620();
  FUN_0045ca30();
  FUN_00685430();
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058eb30(L"CorrectEquipCheck",(undefined1 *)(in_ECX + 0x13c));
  (**(code **)(**(int **)(in_ECX + 0x108) + 0xa0))(*(undefined1 *)(in_ECX + 0x13c));
  (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
  ExceptionList = local_10;
  return;
}

