
undefined4 * FUN_007cd0d0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int in_ECX;
  uint uStack_3c;
  undefined **local_2c [3];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914c61;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  puVar3 = (undefined4 *)FUN_00891268(0x2c);
  local_18 = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = *(undefined4 *)(in_ECX + 4);
    puVar3[1] = *(undefined4 *)(in_ECX + 4);
    puVar3[2] = *(undefined4 *)(in_ECX + 4);
    local_20 = puVar3 + 3;
    *(undefined2 *)(puVar3 + 10) = 0;
    local_8 = 1;
    if (local_20 != (undefined4 *)0x0) {
      pcVar2 = *(char **)param_1;
      puVar3[7] = 0;
      puVar3[8] = 0xf;
      *(undefined1 *)local_20 = 0;
      pcVar4 = pcVar2;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      local_1c = local_20;
      FUN_00402a70(pcVar2,(int)pcVar4 - (int)(pcVar2 + 1));
    }
    ExceptionList = local_10;
    return puVar3;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&param_1);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

