
int FUN_005082b0(int param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_24 [3];
  undefined4 local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d4ea;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  iVar3 = FUN_00891268(0x14,uVar2);
  if (iVar3 != 0) {
    *(int *)(param_2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(param_2 + 4) + 4) = *(int *)(param_2 + 4);
    *(int *)(*(int *)(param_2 + 4) + 8) = *(int *)(param_2 + 4);
    *(undefined1 *)(*(int *)(param_2 + 4) + 0x10) = 1;
    *(undefined1 *)(*(int *)(param_2 + 4) + 0x11) = 1;
    local_8 = 0;
    local_18 = 1;
    local_14 = (char *)0x1;
    do {
      pcVar1 = local_14;
      if (((uint)*(ushort *)(param_1 + 0xe) & 1 << ((char)local_14 - 1U & 0x1f)) != 0) {
        uVar4 = FUN_006bde40(&local_14);
        FUN_00436890(param_2,uVar4);
      }
      local_14 = pcVar1 + 1;
    } while ((int)local_14 < 10);
    ExceptionList = local_10;
    return param_2;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

