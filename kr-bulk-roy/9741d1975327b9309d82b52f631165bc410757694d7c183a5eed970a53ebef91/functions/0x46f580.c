
char * FUN_0046f580(void)

{
  char *pcVar1;
  undefined4 *in_ECX;
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
  puStack_c = &LAB_00917951;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  pcVar1 = (char *)FUN_00891268(0x54);
  if (pcVar1 != (char *)0x0) {
    *(undefined4 *)pcVar1 = DAT_00fc0d78;
    *(undefined4 *)(pcVar1 + 4) = DAT_00fc0d78;
    *(undefined4 *)(pcVar1 + 8) = DAT_00fc0d78;
    local_20 = pcVar1 + 0xc;
    pcVar1[0x50] = '\0';
    pcVar1[0x51] = '\0';
    local_8 = 1;
    if (local_20 != (char *)0x0) {
      *(undefined4 *)local_20 = *in_ECX;
      local_1c = local_20;
      local_18 = pcVar1;
      FUN_0046f6b0(pcVar1 + 0x10);
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

