
void FUN_007b82d0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *in_ECX;
  undefined1 auStack_6c [3];
  char local_69;
  int local_68;
  int local_64;
  int local_60 [2];
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  int local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914e80;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff88;
  ExceptionList = &local_14;
  local_68 = param_2;
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = local_58[0] & 0xffffff00;
  pcVar4 = in_ECX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  local_c = 0;
  local_64 = *(int *)(param_1 + 8);
  FUN_007b86f0(local_60,local_58);
  local_69 = local_60[0] != local_64;
  local_c = 0xffffffff;
  if (0xf < local_44) {
    FUN_0089120c(local_58[0],uVar3);
  }
  if (local_69 == '\0') {
    if (0 < *(int *)(param_1 + 0x30)) {
      *(undefined4 *)(local_68 + 0x44) = 1;
    }
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffffff00;
    pcVar4 = in_ECX;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
    local_20 = local_68;
    local_c = 1;
    iVar2 = **(int **)(param_1 + 8);
    iVar5 = FUN_00719b90(iVar2,*(undefined4 *)(iVar2 + 4),local_3c);
    if (*(int *)(param_1 + 0xc) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    *(int *)(iVar2 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    FUN_007d1080(local_60,**(int **)(param_1 + 8) + 8,**(int **)(param_1 + 8));
    if (0xf < local_28) {
      FUN_0089120c(local_3c[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

