
void FUN_007198f0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *in_ECX;
  char *in_EDX;
  int *unaff_FS_OFFSET;
  undefined1 local_a4 [4];
  int local_a0;
  undefined1 *local_9c;
  char local_95;
  uint local_94 [4];
  undefined4 local_84;
  uint local_80;
  uint local_78 [4];
  undefined4 local_68;
  uint local_64;
  undefined1 *local_5c;
  char local_58 [64];
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915bc3;
  local_10 = *unaff_FS_OFFSET;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_a0 = param_1;
  local_9c = (undefined1 *)FUN_00891268(0x38,local_18);
  if (local_9c == (undefined1 *)0x0) {
    local_9c = (undefined1 *)0x0;
  }
  else {
    *(undefined4 *)(local_9c + 0x14) = 0xf;
    *(undefined4 *)(local_9c + 0x10) = 0;
    *local_9c = 0;
    *(undefined4 *)(local_9c + 0x30) = 0xf;
    *(undefined4 *)(local_9c + 0x2c) = 0;
    local_9c[0x1c] = 0;
  }
  pcVar4 = in_ECX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar4 - (int)(in_ECX + 1));
  pcVar4 = in_EDX;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar4 - (int)(in_EDX + 1));
  _strcpy_s(local_58,0x40,in_EDX);
  FUN_007198b0(local_58);
  pcVar4 = local_58;
  local_80 = 0xf;
  local_84 = 0;
  local_94[0] = local_94[0] & 0xffffff00;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_58,(int)pcVar4 - (int)(local_58 + 1));
  iVar3 = local_a0;
  local_8 = 0;
  iVar2 = *(int *)(local_a0 + 8);
  FUN_007b86f0(&local_a0,local_94);
  local_95 = local_a0 != iVar2;
  local_8 = 0xffffffff;
  if (0xf < local_80) {
    FUN_0089120c(local_94[0]);
  }
  if (local_95 == '\0') {
    pcVar4 = local_58;
    local_64 = 0xf;
    local_68 = 0;
    local_78[0] = local_78[0] & 0xffffff00;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_58,(int)pcVar4 - (int)(local_58 + 1));
    local_5c = local_9c;
    local_8 = 1;
    iVar2 = **(int **)(iVar3 + 8);
    iVar5 = FUN_00719b90(iVar2,*(undefined4 *)(iVar2 + 4),local_78);
    if (*(int *)(iVar3 + 0xc) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
    *(int *)(iVar2 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    FUN_007d1080(local_a4,**(int **)(iVar3 + 8) + 8,**(int **)(iVar3 + 8));
    if (0xf < local_64) {
      FUN_0089120c(local_78[0]);
    }
  }
  else if (local_9c != (undefined1 *)0x0) {
    FUN_00718e80();
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

