
char * FUN_0083f5f0(undefined4 param_1,undefined4 param_2,char *param_3)

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
  puStack_c = &LAB_00904fb1;
  local_10 = ExceptionList;
  uStack_30 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_00891268(0x24);
  if (pcVar2 != (char *)0x0) {
    *(undefined4 *)pcVar2 = param_1;
    *(undefined4 *)(pcVar2 + 4) = param_2;
    local_8 = 1;
    if (pcVar2 + 8 != (char *)0x0) {
      param_3 = pcVar2;
      FUN_00840d80(pcVar2 + 8,pcVar1);
      *(undefined4 *)(pcVar2 + 0x18) = *(undefined4 *)(pcVar1 + 0x10);
      *(undefined4 *)(pcVar2 + 0x1c) = *(undefined4 *)(pcVar1 + 0x14);
      *(undefined4 *)(pcVar2 + 0x20) = *(undefined4 *)(pcVar1 + 0x18);
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

