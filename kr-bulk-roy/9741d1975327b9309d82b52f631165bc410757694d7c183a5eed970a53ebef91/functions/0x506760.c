
undefined4 * FUN_00506760(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d540;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    puVar1 = (undefined4 *)FUN_005068a0(param_1 + 3);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 0xb) = *(undefined1 *)(param_1 + 0xb);
    if (*(char *)((int)local_18 + 0x2d) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_00506760(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_00506760(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}

