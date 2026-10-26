
void FUN_007b8fd0(char *param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined1 local_6c [4];
  int local_68;
  int local_64;
  int local_60;
  uint local_5c [4];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_40;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  char local_20 [8];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bccb;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffffff00;
  pcVar4 = param_1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_18 = uVar3;
  FUN_00402a70(param_1,(int)pcVar4 - (int)(param_1 + 1));
  local_68 = in_ECX + 0x6c;
  local_8 = 0;
  local_64 = FUN_007b6f30(local_3c);
  if (local_64 != *(int *)(in_ECX + 0x70)) {
    cVar2 = FUN_0049ae30(uVar3);
    if (cVar2 == '\0') {
      piVar5 = &local_64;
      goto LAB_007b9067;
    }
  }
  local_60 = *(int *)(in_ECX + 0x70);
  piVar5 = &local_60;
LAB_007b9067:
  iVar1 = *piVar5;
  local_8 = 0xffffffff;
  if (0xf < local_28) {
    FUN_0089120c(local_3c[0]);
  }
  if (iVar1 == *(int *)(in_ECX + 0x70)) {
    __splitpath(param_1,(char *)0x0,(char *)0x0,(char *)0x0,local_20);
    local_60 = FUN_00891268(0x38);
    local_8 = 1;
    if (local_60 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_007e3250(*(undefined4 *)(in_ECX + 0x68));
    }
    local_8 = 0xffffffff;
    FUN_007e33c0();
    local_48 = 0xf;
    local_4c = 0;
    local_5c[0] = local_5c[0] & 0xffffff00;
    pcVar4 = param_1;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70(param_1,(int)pcVar4 - (int)(param_1 + 1));
    iVar1 = local_68;
    local_8 = 2;
    local_40 = uVar6;
    uVar6 = FUN_00552de0(local_5c);
    FUN_007e2910(iVar1,local_6c,uVar6);
    if (0xf < local_48) {
      FUN_0089120c(local_5c[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

