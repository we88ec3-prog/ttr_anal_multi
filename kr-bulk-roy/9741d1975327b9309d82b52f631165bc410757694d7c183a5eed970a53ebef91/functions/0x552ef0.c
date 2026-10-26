
char * FUN_00552ef0(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  uint uStack_30;
  undefined **local_20 [3];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916d81;
  local_10 = ExceptionList;
  uStack_30 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_00891268(0x28);
  if (pcVar2 != (char *)0x0) {
    *(undefined4 *)pcVar2 = param_1;
    *(undefined4 *)(pcVar2 + 4) = param_2;
    local_8 = 1;
    if (pcVar2 + 8 != (char *)0x0) {
      pcVar2[0x1c] = '\x0f';
      pcVar2[0x1d] = '\0';
      pcVar2[0x1e] = '\0';
      pcVar2[0x1f] = '\0';
      pcVar2[0x18] = '\0';
      pcVar2[0x19] = '\0';
      pcVar2[0x1a] = '\0';
      pcVar2[0x1b] = '\0';
      pcVar2[8] = '\0';
      param_3 = pcVar2;
      FUN_00402bb0(pcVar1);
      *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(pcVar1 + 0x1c);
    }
    ExceptionList = local_10;
    return pcVar2;
  }
  param_3 = (char *)0x0;
  std::exception::exception((exception *)local_20,&param_3);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

