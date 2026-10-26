
undefined4 * FUN_004dc390(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009088d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    puVar1 = (undefined4 *)FUN_004dc450(param_1 + 3);
    puVar1[1] = param_2;
    *(undefined1 *)(puVar1 + 8) = *(undefined1 *)(param_1 + 8);
    if (*(char *)((int)local_18 + 0x21) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_004dc390(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_004dc390(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}

