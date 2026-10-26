
char * FUN_00845250(char *param_1)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uStack_38;
  undefined **local_28 [3];
  char *local_1c;
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906c71;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  pcVar3 = (char *)FUN_00891268(0x18);
  if (pcVar3 != (char *)0x0) {
    *(undefined4 *)pcVar3 = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(pcVar3 + 4) = *(undefined4 *)(in_ECX + 4);
    local_1c = pcVar3 + 0xc;
    *(undefined4 *)(pcVar3 + 8) = *(undefined4 *)(in_ECX + 4);
    pcVar3[0x14] = '\0';
    pcVar3[0x15] = '\0';
    local_8 = 1;
    if (local_1c != (char *)0x0) {
      *(undefined4 *)local_1c = *(undefined4 *)pcVar2;
      piVar1 = *(int **)(pcVar2 + 4);
      *(int **)(pcVar3 + 0x10) = piVar1;
      if (piVar1 != (int *)0x0) {
        param_1 = pcVar3;
        local_18 = local_1c;
        iVar4 = (**(code **)(*piVar1 + 8))();
        if (iVar4 == 0) {
          uVar5 = (**(code **)(**(int **)(pcVar3 + 0x10) + 0xc))();
          *(undefined4 *)(pcVar3 + 0x10) = uVar5;
        }
        *(int *)(*(int *)(pcVar3 + 0x10) + 4) = *(int *)(*(int *)(pcVar3 + 0x10) + 4) + 1;
      }
    }
    ExceptionList = local_10;
    return pcVar3;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_28,&param_1);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

