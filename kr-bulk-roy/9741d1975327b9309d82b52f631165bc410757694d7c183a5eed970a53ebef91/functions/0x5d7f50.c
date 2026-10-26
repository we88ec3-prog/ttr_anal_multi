
void FUN_005d7f50(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  undefined4 local_24 [2];
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ebac;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  FUN_005d7240(0xffffffff,param_1,0,0);
  *(undefined4 *)(in_ECX + 0x2b0) = param_2;
  *(undefined4 *)(in_ECX + 0x2b4) = param_3;
  if (*(int *)(in_ECX + 0x25c) != 0) {
    iVar1 = *(int *)(in_ECX + 700);
    if (iVar1 == 1) {
      *(undefined4 *)(in_ECX + 0x2b8) = *(undefined4 *)(*(int *)(in_ECX + 600) + 0x24);
      goto LAB_005d7ff4;
    }
    if (iVar1 == 3) {
      *(undefined4 *)(in_ECX + 0x2b8) = *(undefined4 *)(*(int *)(in_ECX + 600) + 0x30);
      goto LAB_005d7ff4;
    }
    if (iVar1 == 4) {
      *(undefined4 *)(in_ECX + 0x2b8) = *(undefined4 *)(*(int *)(in_ECX + 600) + 0x2c);
      goto LAB_005d7ff4;
    }
  }
  *(undefined4 *)(in_ECX + 0x2b8) = 0xffffffff;
LAB_005d7ff4:
  FUN_005d8980(param_1);
  FUN_005d80f0(uVar3);
  FUN_005d83f0();
  FUN_005d8260();
  local_1c = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_24[0] = param_1;
  FUN_0082ef00(local_24);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  cVar2 = FUN_004d9d20(DAT_00f94308,0xc);
  if ((cVar2 != '\0') && (param_4 != '\0')) {
    param_4 = param_4 + '\x01';
  }
  FUN_005d8be0(param_4);
  ExceptionList = local_14;
  return;
}

