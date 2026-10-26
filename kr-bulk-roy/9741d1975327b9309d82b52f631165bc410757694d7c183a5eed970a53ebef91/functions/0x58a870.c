
void FUN_0058a870(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f8ee;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch(param_3) {
  case 0x201:
    *(undefined1 *)(param_1 + 0x148) = 1;
    break;
  case 0x202:
    *(undefined1 *)(param_1 + 0x148) = 0;
    break;
  case 0x203:
    *(undefined1 *)(param_1 + 0x14b) = 1;
    break;
  case 0x204:
    *(undefined1 *)(param_1 + 0x149) = 1;
    break;
  case 0x205:
    *(undefined1 *)(param_1 + 0x149) = 0;
    break;
  case 0x206:
    *(undefined1 *)(param_1 + 0x14c) = 1;
    break;
  case 0x207:
    *(undefined1 *)(param_1 + 0x14a) = 1;
    break;
  case 0x208:
    *(undefined1 *)(param_1 + 0x14a) = 0;
    break;
  case 0x209:
    *(undefined1 *)(param_1 + 0x14d) = 1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_00753120(param_2,param_3,param_4,param_5);
  if (*in_ECX == 0) {
    FUN_005cae90(*(undefined4 *)(param_1 + 0x38),param_3,in_ECX);
  }
  ExceptionList = local_10;
  return;
}

