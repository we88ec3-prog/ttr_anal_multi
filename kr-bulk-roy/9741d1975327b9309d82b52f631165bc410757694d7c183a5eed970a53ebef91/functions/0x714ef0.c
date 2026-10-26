
undefined4 * FUN_00714ef0(char *param_1,char *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uStack_34;
  undefined **local_24 [3];
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905aa1;
  local_10 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_00891268(0x118);
  local_18 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    param_1 = (char *)(puVar1 + 2);
    puVar1[1] = param_2;
    local_8 = 1;
    if (param_1 != (char *)0x0) {
      puVar3 = param_3;
      pcVar4 = param_1;
      for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        pcVar4 = pcVar4 + 4;
      }
      puVar1[0x42] = param_3[0x40];
      param_2 = param_1;
      FUN_00715060(puVar1 + 0x43,param_3 + 0x41);
    }
    ExceptionList = local_10;
    return puVar1;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_24,&param_1);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

