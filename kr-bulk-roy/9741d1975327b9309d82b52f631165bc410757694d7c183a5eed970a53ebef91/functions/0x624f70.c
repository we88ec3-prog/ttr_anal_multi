
void FUN_00624f70(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_1c;
  undefined4 local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f70e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0xb;
  FUN_0082ef00(&local_18);
  if (local_1c == *(int *)(in_ECX + 0x50)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_1c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar2;
  FUN_00625c60(uVar1);
  FUN_00625d50();
  FUN_006c09c0(0x834);
  FUN_006c09c0(0x898);
  FUN_006c09c0(0xc1c);
  FUN_006c09c0(0xc80);
  FUN_006c09c0(110000);
  FUN_006c09c0(120000);
  FUN_006c09c0(140000);
  FUN_006c09c0(150000);
  FUN_006c09c0(710000);
  FUN_006c09c0(720000);
  local_11 = '\0';
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058f0c0(&local_11);
  (**(code **)(**(int **)(in_ECX + 0x104 + (uint)(local_11 == '\0') * 4) + 0xa0))(1);
  ExceptionList = local_10;
  return;
}

