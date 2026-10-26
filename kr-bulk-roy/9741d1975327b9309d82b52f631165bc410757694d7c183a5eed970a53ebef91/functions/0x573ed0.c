
void FUN_00573ed0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921372;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = param_1[1];
  if ((in_ECX < uVar1) && (uVar2 = *param_1, uVar2 <= in_ECX)) {
    if (uVar1 == param_1[2]) {
      FUN_005742c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined1 *)param_1[1];
    in_ECX = *param_1 + ((int)(in_ECX - uVar2) / 0x1c) * 0x1c;
    local_8 = 0;
  }
  else {
    if (uVar1 == param_1[2]) {
      FUN_005742c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined1 *)param_1[1];
    local_8 = 1;
  }
  if (puVar3 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar3 + 0x14) = 0xf;
    *(undefined4 *)(puVar3 + 0x10) = 0;
    *puVar3 = 0;
    FUN_0040b0b0(in_ECX,0);
  }
  param_1[1] = param_1[1] + 0x1c;
  ExceptionList = local_10;
  return;
}

