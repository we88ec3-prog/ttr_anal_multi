
void FUN_00551ff0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char ***_Src;
  undefined4 in_ECX;
  char *pcVar6;
  undefined4 *unaff_EDI;
  char **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00929714;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char **)((uint)local_30[0] & 0xffffff00);
  local_8 = 0;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_004f3d80(local_14);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  iVar3 = FUN_004f7a70();
  if (*(uint *)(iVar3 + 0x4c) < 0x10) {
    pcVar6 = (char *)(iVar3 + 0x38);
  }
  else {
    pcVar6 = *(char **)(iVar3 + 0x38);
  }
  pcVar4 = pcVar6;
  if ((char)((uint)in_ECX >> 0x18) == '\x03') {
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
    FUN_00401fc0(&DAT_00c07bfc,4);
  }
  else {
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
  }
  puVar5 = (undefined4 *)FUN_00891268(0x7c);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[9] = 0;
    puVar5[10] = 0;
    puVar5[0x1b] = 0;
    puVar5[0x1d] = 1;
    puVar5[0x1e] = 0x1e;
    *(undefined1 *)(puVar5 + 0xb) = 0;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 2;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  uVar2 = DAT_00fb90bc;
  _Src = (char ***)local_30[0];
  if (local_1c < 0x10) {
    _Src = local_30;
  }
  puVar5[0x1b] = param_1;
  puVar5[0x1c] = 1;
  puVar5[0x1d] = 0;
  *puVar5 = *unaff_EDI;
  puVar5[1] = unaff_EDI[1];
  puVar5[2] = unaff_EDI[2];
  puVar5[3] = 0;
  puVar5[4] = 0;
  puVar5[6] = uVar2;
  puVar5[5] = 0;
  puVar5[7] = uVar2;
  puVar5[8] = uVar2;
  _strcpy_s((char *)(puVar5 + 0xb),0x40,(char *)_Src);
  FUN_005506b0();
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

