
void FUN_005b87b0(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009492e6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0059b1f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_14 = 0x2e7;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_20 = 7;
    local_24 = 0;
    local_34 = (uint)local_34._2_2_ << 0x10;
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 1;
    FUN_00757800(&local_34);
    local_8 = 0xffffffff;
    if (7 < local_20) {
      FUN_0089120c(local_34);
    }
    local_34 = local_34 & 0xffff0000;
    local_20 = 7;
    local_24 = 0;
    if ((*(uint *)(*(int *)(in_ECX + 0x24c) + 0x28) >> 8 & 1) != 0) {
      FUN_0068e6f0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x250) + 0x28) >> 8 & 1) != 0) {
      FUN_00696f50(*(int *)(in_ECX + 0x250));
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x27c) + 0x28) >> 8 & 1) != 0) {
      FUN_0068a040();
    }
    if (((*(uint *)(*(int *)(in_ECX + 0x21c) + 0x28) >> 8 & 1) != 0) &&
       (piVar2 = *(int **)(*(int *)(in_ECX + 0x21c) + 0xf4), piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 200))();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x164) + 0x28) >> 8 & 1) != 0) {
      FUN_005ce830(*(int *)(in_ECX + 0x164));
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x260) + 0x28) >> 8 & 1) != 0) {
      FUN_0067b610();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x264) + 0x28) >> 8 & 1) != 0) {
      FUN_00687e60();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x268) + 0x28) >> 8 & 1) != 0) {
      FUN_00680430();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x26c) + 0x28) >> 8 & 1) != 0) {
      FUN_0067d3a0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x270) + 0x28) >> 8 & 1) != 0) {
      FUN_006819a0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x278) + 0x28) >> 8 & 1) != 0) {
      FUN_00679d90();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x294) + 0x28) >> 8 & 1) != 0) {
      FUN_0045d5c0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x298) + 0x28) >> 8 & 1) != 0) {
      FUN_0045d5c0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 600) + 0x28) >> 8 & 1) != 0) {
      FUN_004824c0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x25c) + 0x28) >> 8 & 1) != 0) {
      FUN_00483b40();
    }
    iVar3 = *(int *)(in_ECX + 0x228);
    if ((*(uint *)(iVar3 + 0x28) >> 8 & 1) != 0) {
      FUN_0064bb40(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                   *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14));
    }
    iVar3 = *(int *)(in_ECX + 0x22c);
    if ((*(uint *)(iVar3 + 0x28) >> 8 & 1) != 0) {
      FUN_0064bb40(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                   *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14));
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x29c) + 0x28) >> 8 & 1) != 0) {
      FUN_0045b090();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2ac) + 0x28) >> 8 & 1) != 0) {
      FUN_0047c980(*(int *)(in_ECX + 0x2ac));
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2b0) + 0x28) >> 8 & 1) != 0) {
      FUN_00474fe0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2d4) + 0x28) >> 8 & 1) != 0) {
      FUN_00442590();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2a4) + 0x28) >> 8 & 1) != 0) {
      FUN_00409770();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2a8) + 0x28) >> 8 & 1) != 0) {
      FUN_0040c5b0();
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x2e0) + 0x28) >> 8 & 1) != 0) {
      FUN_0042b8c0(*(int *)(in_ECX + 0x2e0));
    }
    ExceptionList = local_10;
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

