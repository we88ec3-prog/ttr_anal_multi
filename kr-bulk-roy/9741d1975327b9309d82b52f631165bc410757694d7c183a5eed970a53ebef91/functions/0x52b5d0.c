
char * FUN_0052b5d0(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *in_ECX;
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
  puStack_c = &LAB_00910151;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_00891268(0x34);
  if (pcVar2 != (char *)0x0) {
    *(undefined4 *)pcVar2 = *(undefined4 *)(pcVar1 + 4);
    *(undefined4 *)(pcVar2 + 4) = *(undefined4 *)(pcVar1 + 4);
    *(undefined4 *)(pcVar2 + 8) = *(undefined4 *)(pcVar1 + 4);
    local_1c = pcVar2 + 0xc;
    pcVar2[0x30] = '\0';
    pcVar2[0x31] = '\0';
    local_8 = 1;
    if (local_1c != (char *)0x0) {
      *local_1c = *in_ECX;
      pcVar2[0x10] = in_ECX[4];
      pcVar2[0x28] = '\a';
      pcVar2[0x29] = '\0';
      pcVar2[0x2a] = '\0';
      pcVar2[0x2b] = '\0';
      pcVar2[0x24] = '\0';
      pcVar2[0x25] = '\0';
      pcVar2[0x26] = '\0';
      pcVar2[0x27] = '\0';
      pcVar2[0x14] = '\0';
      pcVar2[0x15] = '\0';
      param_1 = pcVar2;
      local_18 = local_1c;
      FUN_004026e0(in_ECX + 8,0,0xffffffff);
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

