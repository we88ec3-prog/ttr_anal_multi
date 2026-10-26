
void FUN_00504370(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  int unaff_EDI;
  undefined **local_184 [3];
  int local_170;
  undefined4 local_16c;
  char *local_168;
  undefined4 local_164;
  undefined1 local_160 [164];
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009242a3;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  iVar3 = FUN_00891268(0xb8,local_14);
  if (iVar3 == 0) {
    local_168 = (char *)0x0;
    std::exception::exception((exception *)local_184,&local_168);
    local_184[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_184,&DAT_00c857a8);
  }
  *(int *)(unaff_EDI + 4) = iVar3;
  *(int *)iVar3 = iVar3;
  *(int *)(*(int *)(unaff_EDI + 4) + 4) = *(int *)(unaff_EDI + 4);
  *(int *)(*(int *)(unaff_EDI + 4) + 8) = *(int *)(unaff_EDI + 4);
  *(undefined1 *)(*(int *)(unaff_EDI + 4) + 0xb4) = 1;
  *(undefined1 *)(*(int *)(unaff_EDI + 4) + 0xb5) = 1;
  local_8 = 0;
  FUN_00504740(unaff_EDI);
  FUN_00505570(unaff_EDI);
  FUN_004ff920(&local_bc);
  local_bc = 0xea61;
  local_b8 = 2;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8._0_1_ = 1;
  local_16c = 0x30e;
  FUN_005740f0(&local_16c);
  if (local_170 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_170 + 0x10);
    if (7 < *(uint *)(local_170 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    local_164 = local_bc;
    FUN_005064d0(local_160);
    local_8._0_1_ = 3;
    uVar5 = FUN_00506310(&local_164);
    FUN_00505f70(unaff_EDI,uVar5);
    local_8._0_1_ = 1;
    FUN_005045c0(local_160);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_005045c0(&local_bc);
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

