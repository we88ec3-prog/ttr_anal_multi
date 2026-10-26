
char * FUN_008537e0(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  int in_ECX;
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
  puStack_c = &LAB_009181a1;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_00891268(0x24);
  if (pcVar2 != (char *)0x0) {
    *(undefined4 *)pcVar2 = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(pcVar2 + 4) = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(pcVar2 + 8) = *(undefined4 *)(in_ECX + 4);
    local_1c = pcVar2 + 0xc;
    pcVar2[0x20] = '\0';
    pcVar2[0x21] = '\0';
    local_8 = 1;
    if (local_1c != (char *)0x0) {
      *(undefined4 *)local_1c = *(undefined4 *)pcVar1;
      param_1 = pcVar2;
      local_18 = local_1c;
      FUN_008520c0(pcVar2 + 0x10);
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

