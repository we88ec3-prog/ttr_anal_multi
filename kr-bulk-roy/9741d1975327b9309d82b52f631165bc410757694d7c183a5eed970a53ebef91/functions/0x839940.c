
void FUN_00839940(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *in_ECX;
  undefined4 *unaff_EDI;
  undefined **local_168 [3];
  undefined **local_158 [3];
  char *local_14c;
  int *local_148;
  undefined1 local_144 [168];
  undefined4 local_9c;
  undefined4 local_7c;
  int local_70;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090e775;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_148 = in_ECX;
  local_14 = uVar2;
  FUN_00849850(unaff_EDI);
  local_8 = 0;
  *unaff_EDI = gbDxRenderer::vftable;
  unaff_EDI[0x3a] = 0;
  unaff_EDI[0x3b] = in_ECX;
  local_14c = (char *)(unaff_EDI + 0x3c);
  FUN_008637f0(uVar2);
  local_8._0_1_ = 1;
  unaff_EDI[0x4c] = local_148;
  if (local_148 != (int *)0x0) {
    (**(code **)(*local_148 + 4))(local_148);
  }
  local_14c = (char *)(unaff_EDI + 0x4d);
  local_8._0_1_ = 2;
  FUN_008637f0(uVar2);
  local_8._0_1_ = 3;
  unaff_EDI[0x5d] = local_148;
  if (local_148 != (int *)0x0) {
    (**(code **)(*local_148 + 4))(local_148);
  }
  local_14c = (char *)(unaff_EDI + 0x5e);
  local_8._0_1_ = 4;
  FUN_008637f0();
  local_8._0_1_ = 5;
  FUN_00842f30(unaff_EDI + 0x6f);
  local_8._0_1_ = 6;
  unaff_EDI[0x6e] = local_148;
  if (local_148 != (int *)0x0) {
    (**(code **)(*local_148 + 4))(local_148);
  }
  FUN_008392d0();
  local_8._0_1_ = 8;
  FUN_00838bf0(unaff_EDI + 0xd4,local_148);
  unaff_EDI[0xec] = 0;
  unaff_EDI[0xed] = 0;
  unaff_EDI[0xee] = 0;
  local_8._0_1_ = 10;
  unaff_EDI[0xf2] = 0;
  iVar3 = FUN_00891268(0x90);
  if (iVar3 != 0) {
    unaff_EDI[0xf1] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(unaff_EDI[0xf1] + 4) = unaff_EDI[0xf1];
    *(undefined4 *)(unaff_EDI[0xf1] + 8) = unaff_EDI[0xf1];
    *(undefined1 *)(unaff_EDI[0xf1] + 0x88) = 1;
    *(undefined1 *)(unaff_EDI[0xf1] + 0x89) = 1;
    local_8._0_1_ = 0xb;
    unaff_EDI[0xf6] = 0;
    iVar3 = FUN_00891268(0x90);
    if (iVar3 == 0) {
      local_14c = (char *)0x0;
      std::exception::exception((exception *)local_168,&local_14c);
      local_168[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_168,&DAT_00c857a8);
    }
    unaff_EDI[0xf5] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(unaff_EDI[0xf5] + 4) = unaff_EDI[0xf5];
    *(undefined4 *)(unaff_EDI[0xf5] + 8) = unaff_EDI[0xf5];
    *(undefined1 *)(unaff_EDI[0xf5] + 0x88) = 1;
    *(undefined1 *)(unaff_EDI[0xf5] + 0x89) = 1;
    local_8._0_1_ = 0xc;
    unaff_EDI[0xfa] = 0;
    iVar3 = FUN_00891268(0x90);
    if (iVar3 == 0) {
      local_148 = (int *)0x0;
      std::exception::exception((exception *)local_158,(char **)&local_148);
      local_158[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_158,&DAT_00c857a8);
    }
    unaff_EDI[0xf9] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(unaff_EDI[0xf9] + 4) = unaff_EDI[0xf9];
    *(undefined4 *)(unaff_EDI[0xf9] + 8) = unaff_EDI[0xf9];
    *(undefined1 *)(unaff_EDI[0xf9] + 0x88) = 1;
    *(undefined1 *)(unaff_EDI[0xf9] + 0x89) = 1;
    unaff_EDI[0x103] = 0xf;
    unaff_EDI[0x102] = 0;
    *(undefined1 *)(unaff_EDI + 0xfe) = 0;
    unaff_EDI[0x105] = 0;
    unaff_EDI[0x106] = 0;
    unaff_EDI[0x107] = 0;
    local_8._0_1_ = 0xf;
    unaff_EDI[0x10a] = 0;
    unaff_EDI[0x110] = 0;
    uVar4 = FUN_00820120();
    unaff_EDI[0x10f] = uVar4;
    *(undefined4 *)uVar4 = uVar4;
    *(undefined4 *)(unaff_EDI[0x10f] + 4) = unaff_EDI[0x10f];
    local_8._0_1_ = 0x10;
    unaff_EDI[0x11a] = 0;
    iVar3 = FUN_00891268(0x24);
    if (iVar3 != 0) {
      unaff_EDI[0x119] = iVar3;
      *(int *)iVar3 = iVar3;
      *(undefined4 *)(unaff_EDI[0x119] + 4) = unaff_EDI[0x119];
      local_8 = CONCAT31(local_8._1_3_,0x11);
      piVar1 = (int *)unaff_EDI[0x3b];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      piVar1 = (int *)unaff_EDI[0x3b];
      unaff_EDI[0x10b] = 0;
      unaff_EDI[0x10c] = 0;
      unaff_EDI[0x109] = 0;
      unaff_EDI[0xfc] = 0;
      unaff_EDI[0xfd] = 0;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x1c))(piVar1,local_144);
        if (local_70 == 0) {
          OutputDebugStringA(
                            "\n G-BLENDER ERROR : YOUR VIDEO_DEVICE COULD NOT SUPPORT <D3DDEVCAPS2_STREAMOFFSET>\n"
                            );
        }
        unaff_EDI[0x117] = local_9c;
        unaff_EDI[0x118] = local_7c;
      }
      unaff_EDI[0x113] = 0;
      unaff_EDI[0x112] = 0;
      unaff_EDI[0x114] = 0;
      FUN_0083dfa0(unaff_EDI,0x13f4);
      piVar1 = (int *)unaff_EDI[0x10f];
      piVar5 = (int *)*piVar1;
      *piVar1 = (int)piVar1;
      *(undefined4 *)(unaff_EDI[0x10f] + 4) = unaff_EDI[0x10f];
      unaff_EDI[0x110] = 0;
      if (piVar5 != (int *)unaff_EDI[0x10f]) {
        do {
          piVar1 = (int *)*piVar5;
          FUN_0089120c(piVar5);
          piVar5 = piVar1;
        } while (piVar1 != (int *)unaff_EDI[0x10f]);
      }
      D3DXCreateEffectPool(unaff_EDI + 0xfc);
      unaff_EDI[0x115] = 0;
      unaff_EDI[0x116] = 0;
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  local_148 = (int *)0x0;
  std::exception::exception((exception *)local_158,(char **)&local_148);
  local_158[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_158,&DAT_00c857a8);
}

