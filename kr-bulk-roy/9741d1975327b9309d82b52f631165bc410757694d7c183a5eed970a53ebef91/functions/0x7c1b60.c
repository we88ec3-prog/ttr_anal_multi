
char * FUN_007c1b60(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 *in_ECX;
  uint uStack_38;
  undefined **local_28 [3];
  char *local_1c;
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914d51;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_00891268(0x40);
  if (pcVar2 != (char *)0x0) {
    *(undefined4 *)pcVar2 = *(undefined4 *)(pcVar1 + 4);
    *(undefined4 *)(pcVar2 + 4) = *(undefined4 *)(pcVar1 + 4);
    *(undefined4 *)(pcVar2 + 8) = *(undefined4 *)(pcVar1 + 4);
    local_1c = pcVar2 + 0x10;
    pcVar2[0x38] = '\0';
    pcVar2[0x39] = '\0';
    local_8 = 1;
    if (local_1c != (char *)0x0) {
      *(undefined4 *)local_1c = *in_ECX;
      *(undefined4 *)(pcVar2 + 0x14) = in_ECX[1];
      pcVar2[0x2c] = '\x0f';
      pcVar2[0x2d] = '\0';
      pcVar2[0x2e] = '\0';
      pcVar2[0x2f] = '\0';
      pcVar2[0x28] = '\0';
      pcVar2[0x29] = '\0';
      pcVar2[0x2a] = '\0';
      pcVar2[0x2b] = '\0';
      pcVar2[0x18] = '\0';
      param_1 = pcVar2;
      local_18 = local_1c;
      FUN_00402bb0(in_ECX + 2);
    }
    ExceptionList = local_10;
    return pcVar2;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_28,&param_1);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

