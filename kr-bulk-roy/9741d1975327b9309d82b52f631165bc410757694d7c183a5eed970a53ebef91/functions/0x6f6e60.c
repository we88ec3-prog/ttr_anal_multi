
void FUN_006f6e60(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  char *in_EDX;
  int iVar4;
  char *local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  code *local_224;
  undefined4 *local_220;
  undefined4 local_218;
  FILE *local_214;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_234;
  iVar4 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 0xc) >> 4) + 1;
  local_218 = 0;
  local_234 = in_EDX;
  if (in_EDX == (char *)0x0) {
    if (*(uint *)(*(int *)(in_ECX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_ECX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar1 = *(undefined4 **)(in_ECX + 8);
    uVar2 = FUN_006fec70();
    *puVar1 = uVar2;
    puVar1[2] = 4;
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
    local_214 = (FILE *)FUN_00894fab();
    in_EDX = local_234;
  }
  else {
    FUN_006f5580();
    local_214 = _fopen(in_EDX,"r");
    if (local_214 == (FILE *)0x0) {
      FUN_006f6db0(&DAT_00c05a74,iVar4);
      __security_check_cookie(local_c ^ (uint)&local_234);
      return;
    }
  }
  iVar3 = FID_conflict__getc(local_214);
  if (iVar3 == 0x23) {
    local_218 = 1;
    do {
      iVar3 = FID_conflict__getc(local_214);
      if (iVar3 == -1) goto LAB_006f6fdf;
    } while (iVar3 != 10);
    iVar3 = FID_conflict__getc(local_214);
  }
  if ((iVar3 == 0x1b) && (in_EDX != (char *)0x0)) {
    local_214 = _freopen(in_EDX,"rb",local_214);
    if (local_214 == (FILE *)0x0) {
      FUN_006f6db0("reopen",iVar4);
      __security_check_cookie(local_c ^ (uint)&local_234);
      return;
    }
    do {
      iVar3 = FID_conflict__getc(local_214);
      if (iVar3 == -1) break;
    } while (iVar3 != 0x1b);
    local_218 = 0;
  }
LAB_006f6fdf:
  _ungetc(iVar3,local_214);
  if (((*(int *)(*(int *)(in_ECX + 8) + -8) != 4) && (iVar3 = FUN_006fb5d0(), iVar3 != 0)) &&
     (*(uint *)(*(int *)(in_ECX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_ECX + 0x10) + 0x44))) {
    FUN_006fb3a0();
  }
  local_220 = &local_218;
  local_22c = 0;
  local_228 = 0;
  local_224 = FUN_006f6d40;
  local_230 = FUN_006fe990();
  iVar3 = _ferror(local_214);
  if (local_234 != (char *)0x0) {
    _fclose(local_214);
  }
  if (iVar3 == 0) {
    FUN_006f5270();
    __security_check_cookie(local_c ^ (uint)&local_234);
    return;
  }
  FUN_006f5220();
  FUN_006f6db0(&DAT_00c42814,iVar4);
  __security_check_cookie(local_c ^ (uint)&local_234);
  return;
}

