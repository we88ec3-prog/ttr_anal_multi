
void FUN_0079ba30(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_14d;
  undefined4 local_14c;
  uint local_138;
  undefined4 local_130;
  uint local_11c;
  char local_114 [256];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938292;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  _sprintf(local_114,"Character\t: %d\n",*(undefined4 *)(*(int *)(in_ECX + 0x98) + 0xa010),uVar2);
  pcVar3 = local_114;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_114,(int)pcVar3 - (int)(local_114 + 1));
  _sprintf(local_114,"Effect\t\t: %d\n",*(undefined4 *)(*(int *)(in_ECX + 0x98) + 0x2804c),uVar2);
  pcVar3 = local_114;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_114,(int)pcVar3 - (int)(local_114 + 1));
  _sprintf(local_114,"FieldObj\t\t: %d\n",*(undefined4 *)(*(int *)(in_ECX + 0x98) + 0x24044),uVar2);
  pcVar3 = local_114;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_114,(int)pcVar3 - (int)(local_114 + 1));
  _sprintf(local_114,"Lights\t\t: %d\n",*(int *)(in_ECX + 0x2d0) - *(int *)(in_ECX + 0x2cc) >> 7);
  pcVar3 = local_114;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_114,(int)pcVar3 - (int)(local_114 + 1));
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_8 = 0;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
    local_8 = 0xffffffff;
  }
  uVar4 = FUN_007bd570(&DAT_00fe1ac8);
  local_8 = 1;
  FUN_00401ed0(uVar4,0,0xffffffff);
  local_8 = 0xffffffff;
  if (0xf < local_11c) {
    FUN_0089120c(local_130);
  }
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8 = 2;
    FUN_007d0fb0(&local_14d);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    local_8 = 0xffffffff;
  }
  uVar4 = FUN_007d0f20(&DAT_00fe3220);
  local_8 = 3;
  FUN_00401ed0(uVar4,0,0xffffffff);
  if (0xf < local_138) {
    FUN_0089120c(local_14c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

