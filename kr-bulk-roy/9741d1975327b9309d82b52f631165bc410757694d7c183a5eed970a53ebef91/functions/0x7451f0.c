
void FUN_007451f0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined **local_34 [3];
  undefined **local_28 [4];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c8c0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  in_ECX[1] = DAT_00fba828;
  local_8 = 0;
  *in_ECX = FoxUI::FXUICmdTarget::vftable;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0x15] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  in_ECX[0x14] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(in_ECX[0x14] + 4) = in_ECX[0x14];
  *(undefined4 *)(in_ECX[0x14] + 8) = in_ECX[0x14];
  *(undefined1 *)(in_ECX[0x14] + 0x14) = 1;
  *(undefined1 *)(in_ECX[0x14] + 0x15) = 1;
  local_8._0_1_ = 1;
  in_ECX[0x1a] = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    in_ECX[0x19] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(in_ECX[0x19] + 4) = in_ECX[0x19];
    local_8 = CONCAT31(local_8._1_3_,2);
    in_ECX[0x1e] = 0;
    iVar2 = FUN_00891268(0xc,uVar1);
    if (iVar2 != 0) {
      in_ECX[0x1d] = iVar2;
      *(int *)iVar2 = iVar2;
      *(undefined4 *)(in_ECX[0x1d] + 4) = in_ECX[0x1d];
      in_ECX[0x12] = 0xffffffff;
      in_ECX[8] = 0xffffffff;
      in_ECX[6] = 0;
      in_ECX[0xf] = 0;
      in_ECX[0x10] = 0;
      in_ECX[0x11] = 0;
      in_ECX[9] = 0;
      in_ECX[0x18] = 0;
      in_ECX[7] = 0;
      in_ECX[0x1c] = 0;
      *(undefined2 *)(in_ECX + 0x17) = 0;
      in_ECX[10] = 0x180;
      ExceptionList = local_10;
      return;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_18);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

