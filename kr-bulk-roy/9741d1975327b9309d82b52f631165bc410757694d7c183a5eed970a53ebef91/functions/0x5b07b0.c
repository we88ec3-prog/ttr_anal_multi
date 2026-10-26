
void FUN_005b07b0(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
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
  puStack_c = &LAB_009494b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005b87b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_14 = 0x2e8;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_34 = (uint)local_34._2_2_ << 0x10;
    local_20 = 7;
    local_24 = 0;
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
    iVar2 = *(int *)(in_ECX + 0x304);
    local_20 = 7;
    local_24 = 0;
    if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0)) {
      FUN_0064c710(iVar2);
    }
    piVar3 = *(int **)(in_ECX + 0x2fc);
    if ((piVar3 != (int *)0x0) && (((uint)piVar3[10] >> 8 & 1) != 0)) {
      (**(code **)(*piVar3 + 0x170))();
    }
    if (*(int *)(in_ECX + 0x300) != 0) {
      FUN_006971d0(*(int *)(in_ECX + 0x300));
    }
    ExceptionList = local_10;
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

