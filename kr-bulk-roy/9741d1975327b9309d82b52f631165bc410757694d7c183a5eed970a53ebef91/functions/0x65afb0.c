
char * FUN_0065afb0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int *in_EDX;
  int local_48;
  undefined1 local_44 [4];
  undefined4 *local_40;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined **local_24 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009124e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar5 = *(char **)(param_1 + 4);
  if ((*(char **)(pcVar5 + 4))[0x21] == '\0') {
    pcVar3 = *(char **)(pcVar5 + 4);
    do {
      if (*(int *)(pcVar3 + 0xc) < *in_EDX) {
        pcVar4 = *(char **)(pcVar3 + 8);
      }
      else {
        pcVar4 = *(char **)pcVar3;
        pcVar5 = pcVar3;
      }
      pcVar3 = pcVar4;
    } while (pcVar4[0x21] == '\0');
  }
  if ((pcVar5 == *(char **)(param_1 + 4)) || (*in_EDX < *(int *)(pcVar5 + 0xc))) {
    iVar1 = *in_EDX;
    local_2c = 0;
    local_30 = (undefined4 *)FUN_00891268(0x34,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_30 == (undefined4 *)0x0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_24,&param_1);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *local_30 = local_30;
    local_30[1] = local_30;
    local_30[2] = local_30;
    *(undefined1 *)(local_30 + 0xc) = 1;
    *(undefined1 *)((int)local_30 + 0x31) = 1;
    local_8 = 0;
    local_48 = iVar1;
    FUN_0065bbf0(local_44);
    local_8._0_1_ = 1;
    FUN_0065c900(&local_48);
    FUN_0065c160(pcVar2,pcVar5);
    local_14 = local_44;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0065b910(*local_40,local_40);
    FUN_0089120c(local_40);
    local_8 = 3;
    FUN_0065b910(*local_30,local_30);
    FUN_0089120c(local_30);
    pcVar5 = param_1;
  }
  ExceptionList = local_10;
  return pcVar5 + 0x10;
}

