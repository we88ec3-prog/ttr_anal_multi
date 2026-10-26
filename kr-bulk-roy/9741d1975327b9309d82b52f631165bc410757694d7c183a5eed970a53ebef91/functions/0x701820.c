
void FUN_00701820(int param_1)

{
  byte bVar1;
  int iVar2;
  FILE *pFVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  int local_14c;
  int iStack_148;
  undefined4 uStack_144;
  byte *local_140;
  int local_13c;
  undefined4 *local_138;
  undefined4 local_134;
  int local_12c;
  char *local_128;
  undefined4 local_124;
  undefined4 local_120;
  code *local_11c;
  byte **local_118;
  int local_114;
  byte local_110 [260];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_14c;
  iVar2 = FUN_00894fab();
  _fputs("lua_debug> ",(FILE *)(iVar2 + 0x40));
  pFVar3 = (FILE *)FUN_00894fab();
  pcVar4 = _fgets((char *)local_110,0xfa,pFVar3);
  while (pcVar4 != (char *)0x0) {
    pcVar4 = "cont\n";
    pbVar5 = local_110;
    do {
      bVar1 = *pbVar5;
      bVar7 = bVar1 < (byte)*pcVar4;
      if (bVar1 != *pcVar4) {
LAB_007018a2:
        iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_007018a9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar7 = bVar1 < (byte)pcVar4[1];
      if (bVar1 != pcVar4[1]) goto LAB_007018a2;
      pbVar5 = pbVar5 + 2;
      pcVar4 = pcVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_007018a9:
    if (iVar2 == 0) break;
    pbVar5 = local_110;
    do {
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
    } while (bVar1 != 0);
    local_13c = (int)pbVar5 - (int)(local_110 + 1);
    local_118 = &local_140;
    local_140 = local_110;
    local_124 = 0;
    local_120 = 0;
    local_134 = 0;
    local_12c = 0;
    local_138 = &local_124;
    local_114 = param_1;
    local_11c = FUN_006f70e0;
    local_128 = "=(debug command)";
    iVar6 = FUN_006fe770(FUN_006fe860,&local_138,*(int *)(param_1 + 8) - *(int *)(param_1 + 0x20));
    iVar2 = *(int *)(param_1 + 0x10);
    local_14c = local_12c;
    (**(code **)(iVar2 + 0xc))(*(undefined4 *)(iVar2 + 0x10),local_134,local_12c,0);
    *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) - local_14c;
    if (iVar6 == 0) {
      iStack_148 = *(int *)(param_1 + 8) + -0x10;
      uStack_144 = 0;
      iVar2 = FUN_006fe770(FUN_006f5a50,&iStack_148,iStack_148 - *(int *)(param_1 + 0x20));
      if (iVar2 != 0) goto LAB_00701979;
    }
    else {
LAB_00701979:
      iVar2 = *(int *)(param_1 + 8);
      if (*(int *)(iVar2 + -8) == 4) {
LAB_007019aa:
        pcVar4 = (char *)(*(int *)(iVar2 + -0x10) + 0x10);
      }
      else {
        iVar2 = FUN_006fb5d0();
        if (iVar2 != 0) {
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          iVar2 = *(int *)(param_1 + 8);
          goto LAB_007019aa;
        }
        pcVar4 = (char *)0x0;
      }
      iVar2 = FUN_00894fab();
      _fputs(pcVar4,(FILE *)(iVar2 + 0x40));
      iVar2 = FUN_00894fab();
      _fputs("\n",(FILE *)(iVar2 + 0x40));
    }
    if (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0xc)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      } while (*(uint *)(param_1 + 8) < *(uint *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
    iVar2 = FUN_00894fab();
    _fputs("lua_debug> ",(FILE *)(iVar2 + 0x40));
    pFVar3 = (FILE *)FUN_00894fab();
    pcVar4 = _fgets((char *)local_110,0xfa,pFVar3);
  }
  __security_check_cookie(local_c ^ (uint)&local_14c);
  return;
}

