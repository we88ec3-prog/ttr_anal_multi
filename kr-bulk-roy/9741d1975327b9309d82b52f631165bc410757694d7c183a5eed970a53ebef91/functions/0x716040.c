
void FUN_00716040(char *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 **ppuVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int in_EDX;
  int *unaff_FS_OFFSET;
  undefined1 auStack_74 [4];
  undefined1 *local_70;
  char *local_6c;
  char *local_68;
  undefined1 *local_64;
  int local_60 [2];
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined1 *local_20;
  uint local_1c;
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00915c7e;
  local_14 = *unaff_FS_OFFSET;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  *unaff_FS_OFFSET = (int)&local_14;
  local_68 = param_2;
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = local_58[0] & 0xffffff00;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_60[0] = in_EDX;
  FUN_00402a70(param_1,(int)pcVar3 - (int)(param_1 + 1));
  local_c = 0;
  local_64 = (undefined1 *)FUN_007b6f30(local_58);
  if (local_64 != *(undefined1 **)(in_EDX + 4)) {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 == '\0') {
      ppuVar4 = &local_64;
      goto LAB_007160f7;
    }
  }
  local_70 = *(undefined1 **)(in_EDX + 4);
  ppuVar4 = &local_70;
LAB_007160f7:
  puVar5 = *ppuVar4;
  local_c = 0xffffffff;
  if (0xf < local_44) {
    FUN_0089120c(local_58[0]);
  }
  if (puVar5 == *(undefined1 **)(in_EDX + 4)) {
    puVar5 = (undefined1 *)FUN_00891268(0x6c);
    local_70 = puVar5;
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(puVar5 + 0x14) = 0xf;
      *(undefined4 *)(puVar5 + 0x10) = 0;
      *puVar5 = 0;
      *(undefined4 *)(puVar5 + 0x30) = 0xf;
      *(undefined4 *)(puVar5 + 0x2c) = 0;
      puVar5[0x1c] = 0;
      local_c = 3;
      *(undefined4 *)(puVar5 + 0x38) = 0;
      FUN_00718cf0();
    }
    local_c = 0xffffffff;
    pcVar3 = local_6c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_6c,(int)pcVar3 - (int)(local_6c + 1));
    pcVar3 = local_68;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_68,(int)pcVar3 - (int)(local_68 + 1));
    *(undefined4 *)(puVar5 + 0x38) = param_3;
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffffff00;
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(param_1,(int)pcVar3 - (int)(param_1 + 1));
    local_c = 4;
    local_20 = puVar5;
    uVar6 = FUN_00552de0(local_3c);
    FUN_007e2910(local_60[0],local_60,uVar6);
    if (0xf < local_28) {
      FUN_0089120c(local_3c[0]);
    }
  }
  *unaff_FS_OFFSET = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

