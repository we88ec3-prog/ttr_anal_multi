
char * FUN_00719b90(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  int *unaff_FS_OFFSET;
  uint uStack_30;
  undefined **local_20 [3];
  undefined1 *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912111;
  local_10 = *unaff_FS_OFFSET;
  uStack_30 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  *unaff_FS_OFFSET = (int)&local_10;
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
      FUN_00403040(pcVar1,0,0xffffffff);
      *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(pcVar1 + 0x1c);
    }
    *unaff_FS_OFFSET = local_10;
    return pcVar2;
  }
  param_3 = (char *)0x0;
  std::exception::exception((exception *)local_20,&param_3);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

