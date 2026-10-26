
char * FUN_007d4c20(void)

{
  char *pcVar1;
  int in_ECX;
  int iVar2;
  int in_EDX;
  undefined4 *puVar3;
  char *pcVar4;
  uint uStack_3c;
  undefined **local_2c [3];
  char *local_20;
  char *local_1c;
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914a21;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  pcVar1 = (char *)FUN_00891268(0x5c);
  if (pcVar1 != (char *)0x0) {
    *(undefined4 *)pcVar1 = *(undefined4 *)(in_EDX + 4);
    *(undefined4 *)(pcVar1 + 4) = *(undefined4 *)(in_EDX + 4);
    local_20 = pcVar1 + 0xc;
    *(undefined4 *)(pcVar1 + 8) = *(undefined4 *)(in_EDX + 4);
    pcVar1[0x58] = '\0';
    pcVar1[0x59] = '\0';
    local_8 = 1;
    if (local_20 != (char *)0x0) {
      pcVar1[0x20] = '\x0f';
      pcVar1[0x21] = '\0';
      pcVar1[0x22] = '\0';
      pcVar1[0x23] = '\0';
      pcVar1[0x1c] = '\0';
      pcVar1[0x1d] = '\0';
      pcVar1[0x1e] = '\0';
      pcVar1[0x1f] = '\0';
      *local_20 = '\0';
      local_1c = local_20;
      local_18 = pcVar1;
      FUN_00402bb0(in_ECX);
      puVar3 = (undefined4 *)(in_ECX + 0x1c);
      pcVar4 = pcVar1 + 0x28;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        pcVar4 = pcVar4 + 4;
      }
    }
    ExceptionList = local_10;
    return pcVar1;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&local_18);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

