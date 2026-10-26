
/* WARNING: Removing unreachable block (ram,0x007a4631) */

void FUN_007a44f0(void)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *in_ECX;
  char *pcVar6;
  uint uVar7;
  uint local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938204;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *in_ECX;
  local_34 = 0;
  uVar7 = uVar3;
  if (in_ECX[1] - iVar4 >> 2 != 0) {
    do {
      local_8 = 0xffffffff;
      pcVar2 = *(char **)(iVar4 + local_34 * 4);
      if (*(int *)(pcVar2 + 0x7c) == 2) {
        pcVar6 = pcVar2;
        if (0xf < *(uint *)(pcVar2 + 0x14)) {
          pcVar6 = *(char **)pcVar2;
        }
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8._0_1_ = 0;
        local_8._1_3_ = 0;
        FUN_00401fc0(&DAT_00c07bfc,4);
        if ((DAT_00fe1770 & 1) == 0) {
          DAT_00fe1770 = DAT_00fe1770 | 1;
          local_8._0_1_ = 1;
          FUN_007b7da0(uVar7);
          _atexit((_func_4879 *)&LAB_00bce790);
          local_8._0_1_ = 0;
        }
        FUN_007b8090();
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_8._0_1_ = 2;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_8._0_1_ = 0;
        }
        FUN_007bcf60();
        pcVar2[0x7c] = '\0';
        pcVar2[0x7d] = '\0';
        pcVar2[0x7e] = '\0';
        pcVar2[0x7f] = '\0';
      }
      iVar4 = *in_ECX;
      local_34 = local_34 + 1;
    } while (local_34 < (uint)(in_ECX[1] - iVar4 >> 2));
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

