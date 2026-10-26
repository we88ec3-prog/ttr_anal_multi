
void FUN_004d7b00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int *unaff_FS_OFFSET;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919518;
  local_10 = *unaff_FS_OFFSET;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_38 = param_1;
  iVar3 = 1;
  switch(*(char *)(in_ECX + 4)) {
  case '\0':
  case '\t':
    iVar3 = 0;
    break;
  case '\x02':
  case '\x03':
    iVar3 = 2;
    break;
  case '\x06':
    iVar3 = 4;
    break;
  case '\a':
    iVar3 = 3;
    break;
  case '\n':
  case '\v':
    iVar3 = 6;
    break;
  case '\f':
    iVar3 = 7;
    break;
  case -1:
  case '\x01':
    iVar3 = 5;
  }
  local_3c = in_ECX;
  if (*(char *)(in_ECX + 4) != '\x01') {
    uVar2 = FUN_004d74c0(param_1);
    local_8 = 0;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_20) {
      FUN_0089120c(local_34);
    }
    local_20 = 7;
    local_24 = 0;
    local_34 = local_34 & 0xffff0000;
  }
  iVar1 = local_38 + iVar3 * 0x18;
  FUN_00804260(&local_3c);
  local_40 = local_3c;
  local_44 = iVar3;
  FUN_007b6e80(&local_44);
  if (0x32 < *(uint *)(iVar1 + 0x3c)) {
    FUN_004d7c70(local_38);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

